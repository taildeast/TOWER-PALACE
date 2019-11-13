#include<iostream>
#include<windows.h>
using namespace std;

#define WIDTH 100
#define HEIGHT 30
#define HIDDEN 0
#define SHOW 1

void gotoxy(int x,int y) //커서를 움직이기 위한 함수 
{
	COORD XY = {x,y}; // COORD 구조체 형태의 자료형
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),XY); 
	// 실패하면 0을 리턴. 첫번째 인자는 커서의 위치, 두번째 인자는 커서가 들어갈 곳
	// 첫번째 인자 GetStdHandle(STD_OUTPUT_HANDLE)은 모니터를 뜻하고 STD_INPUT_HANDLE은 키보드를 뜻함 
}

void CursorView(char show) // 커서를 보이게 할지 아닐지 만드는 함수 
{
	HANDLE hConsole; 
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show; // true면 보이고 false면 보이지 않게 
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}

void Wdraw() //가로축을 그리는 함수 
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
void Hdraw() //세로축을 그리는 함수 
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

void TitleDraw() // 타이틀화면을 그리는 함수 
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

void SelectMenu() // 메뉴 선택 커서를 그리는 함수
//이후 이곳에서 게임 메뉴를 선택하게 만들면 될거 같음 
{
	gotoxy(39,15);
	cout<<"☞";		
	gotoxy(58,15);
	cout<<"☜"; 
}
void MapDraw() // 위의 출력함수들을 한곳으로 모아서 관리 
{
	Wdraw();
	Hdraw();
	TitleDraw();
	SelectMenu();
	Sleep(20);
}
int main(void)
{
	system("mode con:cols=100 lines=30"); // 컴파일러 창의 크기를 결정  cols는 가로 lines는 세로 
	CursorView(HIDDEN); // 커서는 숨기게 
	while(1)
	{
		MapDraw();
	}
}
