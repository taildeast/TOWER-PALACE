#include<iostream>
#include<windows.h>
#include<conio.h>  // 키보드 입력을 확인하는 kbhit 함수를 사용하기 위한 헤더 
using namespace std;
#define WIDTH 100 // 가로  길이 
#define HEIGHT 30 // 세로 길이 
#define HIDDEN 0 // 커서 옵션 함수에 쓰이기 위한 값 
#define SHOW 1 // enum으로 히든은 0 쇼는 1로 설정해도 상관 없는 부분 
int MenuStart =  38; // 화면을 보였을때 앞쪽 커서의 x 값 
int MenuEnd =  59; // 뒷쪽 커서의 x 값 
int MenuY =  15; // 첫번째 메뉴의 y값 

void gotoxy(int x,int y)  // x,y로 입력받은 곳으로 커서를 이동시키기 위한 함수 
{
	COORD XY = {x,y}; // COORD 구조체의 설정 COORD구조체는 콘솔창의 좌표를 저장하기 위한 구조체
	// 원래는 int가 아닌 short가 기본 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),XY);
	// 커서의 위치를 설정 하는 함수 
	// 앞의 매개변수인 GetStdHandle 즉 현재 핸들값을 XY 위의 COORD  구조체안의 값으로 변경
	//STD_OUTPUT_HANDLE은  표준 출력 장치 즉 화면을 뜻한다. 
	//쉽게 말해 화면이란 핸들값에서 커서를 XY의 위치로 둬라 이런 뜻이된다. 
}

void CursorView(char show) // 커서 보임의 유무를 만들 함수 
{
	HANDLE hConsole; //핸들값 
    CONSOLE_CURSOR_INFO ConsoleCursor; //커서의 정보를 담을 구조체 

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 핸들값에는 출력장치의 핸들값 

    ConsoleCursor.bVisible = show; // true면 보이고 false면 보이지 않는다. 현재 show는 1로 보인다는 뜻 
    ConsoleCursor.dwSize = 1; // 커서의 두께를 설정 1`100까지 설정가능 1이 기본 

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);// 위에서 설정한 커서의 정보를 앞의 매개인자로 넘겨준다
	//현재 앞의 매개인자는 출력장치의 핸들값이므로 커서의 정보가 콘솔창의 출력 
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
void Hdraw()//세로축을 그리는 함수 
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

void TitleDraw()//타이틀 화면을 그리는 함수 
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

void CursorDraw() //커서를 그리는 함수 
{
	gotoxy(MenuStart,MenuY);
	cout<<"☞";		
	gotoxy(MenuEnd,MenuY);
	cout<<"☜"; 
}
void CursorClear() //커서를 지워줄 함수 , 지워지는 것처럼 보이게 만드는 함수 
{
	gotoxy(MenuStart,MenuY);
	cout<<"  ";		
	gotoxy(MenuEnd,MenuY);
	cout<<"  "; 
}
void MapDraw() // 그리는 함수의 총괄 
{
	Wdraw();
	Hdraw();
	TitleDraw();
	CursorDraw();
	Sleep(20);
}
void GameStart()
{ 
	system("cls");
	cout<<"대충 게임 시작 화면"<<endl;
	system("pause");
	system("cls");
}
void GameRecord()
{ 	
	system("cls");
	cout<<"대충 게임 기록 화면"<<endl;
	system("pause");
	system("cls");
}
void GameExit()
{ 
	system("cls");
	cout<<"대충 게임 종료 화면"<<endl;
	system("pause");
	system("cls");
}
void SelectMenu() //메뉴 선택을 위한 함수 
{
	int key = 0;
	while(1)
	{
		if(kbhit()) //kbhit() != 0 이랑 같은 뜻. 즉 kbhit가 1일때만 작동. 키보드가 입력받았을때만 작동한다는 뜻 
		{
			key = getch(); // 입력되었을때의 값을 키로 넣는다 
			if(key == 224) // 224 는 방향키의 아스키코드이다 
			{
				key = getch(); // 다시한번 검사 , 방향키는 4개가 모두 224의 값을 가지기에 한번 더 체크를 하는 것 
			}
			switch(key)
			{
				case 72: // 방향키 위의 아스키 값 
					if(MenuY > 15) // 첫번째 메뉴의 y위치가 15이기 때문에 더 못 올라가게 하기 위함 
					{
						CursorClear();
						MenuY -= 2; // 값이 줄어야 위로 올라간다. 2중 배열과 같은 구조이기 때문에 
					}
					break;
				case 80://방향키 아래의 아스키 값 
					if(MenuY < 19)
					{
						CursorClear();
						MenuY += 2;
					}
					break;
				case 13: // 엔터의 아스키 값 
					if(MenuY == 15) GameStart();
					if(MenuY == 17) GameRecord();
					if(MenuY == 19) GameExit();
					break;
			}
		}
		else break;
	}
}
int main(void)
{
	system("mode con:cols=100 lines=30"); // 컴파일러창의 크기를 조절하는 부분 
	//cols가 가로 lines가 세로인데 띄어쓰기가 있으면 오류가 나니 조심 
	CursorView(HIDDEN); // 커서는 안보이도록 이부분을 SHOW로 고친다면 정신 사나워 진다 
	while(1)
	{
		MapDraw();
		SelectMenu();
	}
}
