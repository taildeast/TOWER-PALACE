#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h> 
#include<stdlib.h>
using namespace std;
#define WIDTH 100
#define HEIGHT 30
#define HIDDEN 0
#define SHOW 1 
int MenuStart =  38;
int MenuEnd =  59;
int MenuX = 22; 
int MenuY = 15;

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
void InOption()
{
	system("mode con:cols=100 lines=30"); 
	CursorView(HIDDEN);
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

void WDraw() 
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
void HDraw()
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

void CursorDraw(int S_X,int E_X,int Y)
{
	gotoxy(S_X,Y);
	cout<<"��";		
	gotoxy(E_X,Y);
	cout<<"��"; 
}
void CursorClear(int S_X,int E_X,int Y)
{
	gotoxy(S_X,Y);
	cout<<"  ";		
	gotoxy(E_X,Y);
	cout<<"  "; 
}

void SelectYN(int &flag)
{
	int key = 0;
	while(1)
	{
		if(kbhit())
		{
			key = getch(); 
			if(key == 224) 
			{
				key = getch();  
			}
			switch(key)
			{
				case 75: 
					if(MenuX > 22) 
					{
						CursorClear(MenuX,MenuX+11,MenuY-2);
						MenuX -= 43; 
					}
					break;
				case 77:
					if(MenuX < 65)
					{
						CursorClear(MenuX,MenuX+11,MenuY-2);
						MenuX += 43;
					}
					break;
				case 13: 
					if(MenuX == 22) 
					{
						system("cls");
						exit(1);
					}
					if(MenuX == 65) flag = 1;
					break;
			}
		}
		else break;
	}
}


void GameExitTitle()
{
	WDraw();
	HDraw();
	gotoxy(36, 10);
	cout<<"[ ������ ���� �Ͻðڽ��ϱ�? ]";
	gotoxy(25,MenuY-2);
	cout<<"[ Yes ]";
	gotoxy(68,MenuY-2);
	cout<<"[ N o ]";
	CursorDraw(MenuX, MenuX +11,MenuY-2);
}
void GameExitDraw()
{
	int ExitFlag = 0;
	while(!ExitFlag)
	{
		GameExitTitle();
		SelectYN(ExitFlag);
	}
	system("cls");
}

void Count_Draw(int i)
{
	switch(i)
	{
		case 9:
			cout<<"������";
					gotoxy(44,11);
			cout<<"��      ��";
					gotoxy(44,12);
			cout<<"��      ��";
					gotoxy(44,13);
			cout<<"������";
					gotoxy(44,14);
			cout<<"        ��";
					gotoxy(44,15);
			cout<<"        ��";
					gotoxy(44,16);
			cout<<"        ��";
					gotoxy(44,17);
			cout<<"        ��";
			break;
		case 8:
			cout<<"������";
					gotoxy(44,11);
			cout<<"��      ��";
					gotoxy(44,12);
			cout<<"��      ��";
					gotoxy(44,13);
			cout<<"������";
					gotoxy(44,14);
			cout<<"��      ��";
					gotoxy(44,15);
			cout<<"��      ��";
					gotoxy(44,16);
			cout<<"��      ��";
					gotoxy(44,17);
			cout<<"������";
			break;
		case 7:
			cout<<"������";
					gotoxy(44,11);
			cout<<"��      ��";
					gotoxy(44,12);
			cout<<"��      ��";
					gotoxy(44,13);
			cout<<"��      ��";
					gotoxy(44,14);
			cout<<"        ��";
					gotoxy(44,15);
			cout<<"        ��";
					gotoxy(44,16);
			cout<<"        ��";
					gotoxy(44,17);
			cout<<"        ��";
			break;
		case 6:
			cout<<"��       ";
					gotoxy(44,11);
			cout<<"��        ";
					gotoxy(44,12);
			cout<<"��        ";
					gotoxy(44,13);
			cout<<"������";
					gotoxy(44,14);
			cout<<"��      ��";
					gotoxy(44,15);
			cout<<"��      ��";
					gotoxy(44,16);
			cout<<"��      ��";
					gotoxy(44,17);
			cout<<"������";
			break;
		case 5:
			cout<<"������";
					gotoxy(44,11);
			cout<<"��        ";
					gotoxy(44,12);
			cout<<"��        ";
					gotoxy(44,13);
			cout<<"������";
					gotoxy(44,14);
			cout<<"        ��";
					gotoxy(44,15);
			cout<<"        ��";
					gotoxy(44,16);
			cout<<"        ��";
					gotoxy(44,17);
			cout<<"������";
			break;
		case 4:
			cout<<"��      ��";
					gotoxy(44,11);
			cout<<"��      ��";
					gotoxy(44,12);
			cout<<"��      ��";
					gotoxy(44,13);
			cout<<"������";
					gotoxy(44,14);
			cout<<"        ��";
					gotoxy(44,15);
			cout<<"        ��";
					gotoxy(44,16);
			cout<<"        ��";
					gotoxy(44,17);
			cout<<"        ��";
			break;
		case 3:
			cout<<"������";
					gotoxy(44,11);
			cout<<"        ��";
					gotoxy(44,12);
			cout<<"        ��";
					gotoxy(44,13);
			cout<<"������";
					gotoxy(44,14);
			cout<<"        ��";
					gotoxy(44,15);
			cout<<"        ��";
					gotoxy(44,16);
			cout<<"        ��";
					gotoxy(44,17);
			cout<<"������";
			break;
		case 2:
			cout<<"������";
					gotoxy(44,11);
			cout<<"        ��";
					gotoxy(44,12);
			cout<<"        ��";
					gotoxy(44,13);
			cout<<"������";
					gotoxy(44,14);
			cout<<"��        ";
					gotoxy(44,15);
			cout<<"��        ";
					gotoxy(44,16);
			cout<<"��        ";
					gotoxy(44,17);
			cout<<"������";
			break;
		case 1:
			cout<<"  ���    ";
					gotoxy(44,11);
			cout<<"��  ��    ";
					gotoxy(44,12);
			cout<<"    ��    ";
					gotoxy(44,13);
			cout<<"    ��    ";
					gotoxy(44,14);
			cout<<"    ��    ";
					gotoxy(44,15);
			cout<<"    ��    ";
					gotoxy(44,16);
			cout<<"    ��    ";
					gotoxy(44,17);
			cout<<"������";
			break;
		case 0:	
			cout<<"������";
					gotoxy(44,11);
			cout<<"��      ��";
					gotoxy(44,12);
			cout<<"��      ��";
					gotoxy(44,13);
			cout<<"��      ��";
					gotoxy(44,14);
			cout<<"��      ��";
					gotoxy(44,15);
			cout<<"��      ��";
					gotoxy(44,16);
			cout<<"��      ��";
					gotoxy(44,17);
			cout<<"������";
			break;
	}
}

void GameOver_Draw()
{
	system("cls");// ȭ���� ���� windows ��� �ʿ� 
	int i;
	char check;
	for( i = 10; i>=0; i--)
	{
		WDraw();
		HDraw();
		gotoxy(WIDTH*0.28,HEIGHT*0.2);
		cout<<"[[ ���ڷ� ���� �̸� ��(��) ����Ͽ����ϴ� !! ]]"<<endl;
		gotoxy(WIDTH*0.28+5,HEIGHT*0.2+2);
		cout<<"[[ �絵�� �Ͻðڽ��ϱ�? ( Y / N ) ]]"<<endl;
		gotoxy(44,10);
		Count_Draw(i);
		Sleep(1000); // ���ǽð� 1�� 
		if(kbhit()!=0)  // Ű���尡 �ԷµǸ� ���߰� �ϱ����Ͽ� 
		{
			system("cls"); // ���� �������� ����� 
			break; // for���� Ż�� 
		}
	}
	if( i == -1) 
	{
		system("cls");
		GameExitDraw();
	}
	while(1)
		{
			check = getch();
			if(check == 'Y' || check == 'y')
			{
				//ü���� ȸ���ϴ� �ڵ� 
				break;	
			}
			else if(check == 'N' || check == 'n')
			{	
				GameExitDraw();
			}
			else
			{
				cout<<"[[ �߸� �Է��ϼ̽��ϴ�( Y / N �� �Է��Ͻʽÿ�) ]]"<<endl;
			}
		}
}
