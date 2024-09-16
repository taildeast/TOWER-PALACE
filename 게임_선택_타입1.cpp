#include<iostream>
#include<windows.h>
#include<conio.h>  // Ű���� �Է��� Ȯ���ϴ� kbhit �Լ��� ����ϱ� ���� ��� 
using namespace std;
#define WIDTH 100 // ����  ���� 
#define HEIGHT 30 // ���� ���� 
#define HIDDEN 0 // Ŀ�� �ɼ� �Լ��� ���̱� ���� �� 
#define SHOW 1 // enum���� ������ 0 ��� 1�� �����ص� ��� ���� �κ� 
int MenuStart =  38; // ȭ���� �������� ���� Ŀ���� x �� 
int MenuEnd =  59; // ���� Ŀ���� x �� 
int MenuY =  15; // ù��° �޴��� y�� 

void gotoxy(int x,int y)  // x,y�� �Է¹��� ������ Ŀ���� �̵���Ű�� ���� �Լ� 
{
	COORD XY = {x,y}; // COORD ����ü�� ���� COORD����ü�� �ܼ�â�� ��ǥ�� �����ϱ� ���� ����ü
	// ������ int�� �ƴ� short�� �⺻ 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),XY);
	// Ŀ���� ��ġ�� ���� �ϴ� �Լ� 
	// ���� �Ű������� GetStdHandle �� ���� �ڵ鰪�� XY ���� COORD  ����ü���� ������ ����
	//STD_OUTPUT_HANDLE��  ǥ�� ��� ��ġ �� ȭ���� ���Ѵ�. 
	//���� ���� ȭ���̶� �ڵ鰪���� Ŀ���� XY�� ��ġ�� �ֶ� �̷� ���̵ȴ�. 
}

void CursorView(char show) // Ŀ�� ������ ������ ���� �Լ� 
{
	HANDLE hConsole; //�ڵ鰪 
    CONSOLE_CURSOR_INFO ConsoleCursor; //Ŀ���� ������ ���� ����ü 

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �ڵ鰪���� �����ġ�� �ڵ鰪 

    ConsoleCursor.bVisible = show; // true�� ���̰� false�� ������ �ʴ´�. ���� show�� 1�� ���δٴ� �� 
    ConsoleCursor.dwSize = 1; // Ŀ���� �β��� ���� 1`100���� �������� 1�� �⺻ 

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);// ������ ������ Ŀ���� ������ ���� �Ű����ڷ� �Ѱ��ش�
	//���� ���� �Ű����ڴ� �����ġ�� �ڵ鰪�̹Ƿ� Ŀ���� ������ �ܼ�â�� ��� 
}

void Wdraw() //�������� �׸��� �Լ� 
{
	int loop;
	for(loop = 0 ; loop < WIDTH-1 ; loop++ )
	{
		gotoxy(loop,0);
		if(loop == 0) cout<<"��";
		else if(loop == WIDTH-2) cout<<"��";
		else cout<<"��";
		gotoxy(loop,HEIGHT-1);
		if(loop == 0) cout<<"��";
		else if(loop == WIDTH-2) cout<<"��";
		else cout<<"��";
	}
}
void Hdraw()//�������� �׸��� �Լ� 
{
	int loop;
	for(loop = 1 ; loop <HEIGHT-1 ; loop++ )
	{
		gotoxy(0,loop);
		cout<<"��";
		gotoxy(WIDTH-2,loop);
		cout<<"��";
	}
}

void TitleDraw()//Ÿ��Ʋ ȭ���� �׸��� �Լ� 
{
	gotoxy(6,5);
	cout<<"���� ���� ��    ��    �� ���� ����     ����   ��   ��       ��   ���� ����"<<endl;
	gotoxy(6,6);
	cout<<"  ��   ��  ��  ��  ���  ��  ��     ��  ��     ��  �� ��  �� ��     ��  �� ��     ��    "<<endl;
	gotoxy(6,7);
	cout<<"  ��   ��  ��   ���  ���   ���� ���       ���   ���� ��     ���� ��     ����"<<endl;
	gotoxy(6,8);
	cout<<"  ��   ��  ��    ��    ��    ��     �� ��      ��     ��  �� ��     ��  �� ��     ��    "<<endl;
	gotoxy(6,9);
	cout<<"  ��   ����    ��    ��    ���� ��  ��     ��     ��  �� ���� ��  �� ���� ����"<<endl;
	gotoxy(42,15);
	cout<<"[  ���� ����  ]";
	gotoxy(42,17);
	cout<<"[   ��   ��   ]";
	gotoxy(42,19);
	cout<<"[  ���� ����  ]";
}

void CursorDraw() //Ŀ���� �׸��� �Լ� 
{
	gotoxy(MenuStart,MenuY);
	cout<<"��";		
	gotoxy(MenuEnd,MenuY);
	cout<<"��"; 
}
void CursorClear() //Ŀ���� ������ �Լ� , �������� ��ó�� ���̰� ����� �Լ� 
{
	gotoxy(MenuStart,MenuY);
	cout<<"  ";		
	gotoxy(MenuEnd,MenuY);
	cout<<"  "; 
}
void MapDraw() // �׸��� �Լ��� �Ѱ� 
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
	cout<<"���� ���� ���� ȭ��"<<endl;
	system("pause");
	system("cls");
}
void GameRecord()
{ 	
	system("cls");
	cout<<"���� ���� ��� ȭ��"<<endl;
	system("pause");
	system("cls");
}
void GameExit()
{ 
	system("cls");
	cout<<"���� ���� ���� ȭ��"<<endl;
	system("pause");
	system("cls");
}
void SelectMenu() //�޴� ������ ���� �Լ� 
{
	int key = 0;
	while(1)
	{
		if(kbhit()) //kbhit() != 0 �̶� ���� ��. �� kbhit�� 1�϶��� �۵�. Ű���尡 �Է¹޾������� �۵��Ѵٴ� �� 
		{
			key = getch(); // �ԷµǾ������� ���� Ű�� �ִ´� 
			if(key == 224) // 224 �� ����Ű�� �ƽ�Ű�ڵ��̴� 
			{
				key = getch(); // �ٽ��ѹ� �˻� , ����Ű�� 4���� ��� 224�� ���� �����⿡ �ѹ� �� üũ�� �ϴ� �� 
			}
			switch(key)
			{
				case 72: // ����Ű ���� �ƽ�Ű �� 
					if(MenuY > 15) // ù��° �޴��� y��ġ�� 15�̱� ������ �� �� �ö󰡰� �ϱ� ���� 
					{
						CursorClear();
						MenuY -= 2; // ���� �پ�� ���� �ö󰣴�. 2�� �迭�� ���� �����̱� ������ 
					}
					break;
				case 80://����Ű �Ʒ��� �ƽ�Ű �� 
					if(MenuY < 19)
					{
						CursorClear();
						MenuY += 2;
					}
					break;
				case 13: // ������ �ƽ�Ű �� 
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
	system("mode con:cols=100 lines=30"); // �����Ϸ�â�� ũ�⸦ �����ϴ� �κ� 
	//cols�� ���� lines�� �����ε� ���Ⱑ ������ ������ ���� ���� 
	CursorView(HIDDEN); // Ŀ���� �Ⱥ��̵��� �̺κ��� SHOW�� ��ģ�ٸ� ���� �糪�� ���� 
	while(1)
	{
		MapDraw();
		SelectMenu();
	}
}
