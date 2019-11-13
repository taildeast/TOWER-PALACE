#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

#define WIDTH 100
#define HEIGHT 30
#define HIDDEN 0
#define SHOW 1
#define MENU_START 39
#define MENU_END 58
#define MENU_START_Y 15

int Menu_Start = 39;
int Menu_End = 58;
int Menu_Start_Y = 15;

void gotoxy(int x,int y)
{
	COORD XY = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),XY);
}

void CursorView(char show)
{
	HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}

void Wdraw()
{
	int loop;
	for(loop = 0 ; loop < WIDTH-1 ; loop++ )
	{
		gotoxy(loop,0);
		if(loop == 0) cout<<"┌";
		else if(loop == WIDTH-2) cout<<"┐";
		else cout<<"─";
		gotoxy(loop,HEIGHT-1);
		if(loop == 0) cout<<"└";
		else if(loop == WIDTH-2) cout<<"┘";
		else cout<<"─";
	}
}
void Hdraw()
{
	int loop;
	for(loop = 1 ; loop <HEIGHT-1 ; loop++ )
	{
		gotoxy(0,loop);
		cout<<"│";
		gotoxy(WIDTH-2,loop);
		cout<<"│";
	}
}

void TitleDraw()
{
	gotoxy(6,5);
	cout<<"■■■ ■■■ ■    ■    ■ ■■■ ■■■     ■■■   ■   ■       ■   ■■■ ■■■"<<endl;
	gotoxy(6,6);
	cout<<"  ■   ■  ■  ■  ■■  ■  ■     ■  ■     ■  ■ ■  ■ ■     ■  ■ ■     ■    "<<endl;
	gotoxy(6,7);
	cout<<"  ■   ■  ■   ■■  ■■   ■■■ ■■       ■■   ■■■ ■     ■■■ ■     ■■■"<<endl;
	gotoxy(6,8);
	cout<<"  ■   ■  ■    ■    ■    ■     ■ ■      ■     ■  ■ ■     ■  ■ ■     ■    "<<endl;
	gotoxy(6,9);
	cout<<"  ■   ■■■    ■    ■    ■■■ ■  ■     ■     ■  ■ ■■■ ■  ■ ■■■ ■■■"<<endl;
	gotoxy(42,15);
	cout<<"[  게임 시작  ]";
	gotoxy(42,17);
	cout<<"[   기   록   ]";
	gotoxy(42,19);
	cout<<"[  게임 종료  ]";
}

void MenuCursor()
{
	gotoxy(Menu_Start,Menu_Start_Y);
	cout<<"☞";		
	gotoxy(Menu_End,Menu_Start_Y);
	cout<<"☜"; 
}
void MapDraw()
{
	Wdraw();
	Hdraw();
	TitleDraw();
	MenuCursor();
	Sleep(20);
}
void SelectMenuCursor()
{
	int key=0;
	while(1)
	{
		if(kbhit())
		{
			key = getch();
			if(key == 224)
			{
				key = getch();
				switch(key)
				{
					case 72:	
						if(Menu_Start_Y > 15)
						{			
						if(Menu_Start_Y == 19 || Menu_Start_Y == 17)
						{
							gotoxy(Menu_Start,Menu_Start_Y);
							cout<<"  ";
							gotoxy(Menu_End,Menu_Start_Y);
							cout<<"  ";
						}		
							Menu_Start_Y-=2;
						}
						break;
					case 80:
						if(Menu_Start_Y < 19)
						{
							if(Menu_Start_Y == 15 || Menu_Start_Y == 17)
							{
								gotoxy(Menu_Start,Menu_Start_Y);
								cout<<"  ";
								gotoxy(Menu_End,Menu_Start_Y);
								cout<<"  ";
							}
							Menu_Start_Y+=2;
							break;
						}
			//		case 13: 
				}
			}
		}
		else break;
		
	}
}

int main(void)
{
	system("mode con:cols=100 lines=30");
	CursorView(HIDDEN);
	while(1)
	{
		MapDraw();
		SelectMenuCursor();
	}
}
