#include<iostream>
#include<windows.h>
using namespace std;

#define X 5
#define Y 7
#define WIDTH 100
#define HEIGHT 30
#define HIDDEN 0
#define SHOW 1

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

void MapDraw()
{
	Wdraw();
	Hdraw();
	TitleDraw();
	Sleep(20);
}
int main(void)
{
	system("mode con:cols=100 lines=30");
	CursorView(HIDDEN);
	while(1)
	{
		MapDraw();
	}
}
