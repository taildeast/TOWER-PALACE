
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10  // 플레이어와 몬스터를 합친 최대 수 

typedef struct character
{
	char Name[20];//이름 
	int Atk;//공격력 
	int Life;//생명력 
	int MaxExp;//경험치 통 
	int GetExp;//얻은, 혹은 얻을수 있는 경험치 
	int Level;
	int Check;
	int g_exp;
	int g_hp;	
}Stat;

void Init(Stat* list[],int* M_List)
{
	list[0]=(Stat*)malloc(sizeof(Stat));
	FILE* f = fopen("rsp.txt","r");
	if(f == NULL)
	{
		printf("실패\n");
		system("pause");	
	}
	else
	{
		fscanf(f,"%d %d %d",&list[0]->Atk, &list[0]->Life , &list[0]->MaxExp);
		fscanf(f,"%d %d %d",&list[0]->GetExp, &list[0]->Level , &list[0]->Check);
		
		fscanf(f,"%d",M_List);
		for(int i = 1 ; i < (*M_List)+1 ; i++)
		{
			list[i] = (Stat*)malloc(sizeof(Stat));
			fscanf(f,"%s %d %d %d",list[i]->Name,&list[i]->Atk, &list[i]->Life , &list[i]->MaxExp);
			fscanf(f,"%d %d %d",&list[i]->GetExp, &list[i]->Level , &list[i]->Check);			
		}				
	}
	
	printf("플레이어 이름 입력 : ");
	scanf("%s",list[0]->Name);
	system("pause");		
	for(int i = 0 ; i <*M_List+1; i++)
	{
		list[i]->g_hp=list[i]->Life;//게임 내 체력을 제일 처음에 맥스체력으로 초기화 
		list[i]->g_exp=0;
	}	
}
void Show_Main(int* select)
{
	system("cls");
	printf("======DunGeon======\n");
	printf("  1.던전 입장\n");
	printf("  2.Player 정보\n");
	printf("  3.Save\n");
	printf("  4.Load\n");	
	printf("  5.종료\n");	
	printf("  입력 : ");
	scanf("%d",select);	
}

void Show_Stat(Stat* list[],int Number)
{
	if(Number == 0)
	{
	printf("======%s(%dLv)======\n",list[Number]->Name,list[Number]->Level);
	printf("공격력 = %d      생명력 = %d/%d\n",list[Number]->Atk,list[Number]->g_hp,list[Number]->Life);
	printf("경험치 = %d/%d   GetExp = %d\n",list[Number]->g_exp,list[Number]->MaxExp,list[Number]->GetExp);
	printf("======================\n\n");
	}
	else
	{
	printf("======%s(%dLv)======\n",list[Number]->Name,list[Number]->Level);
	printf("공격력 = %d      생명력 = %d/%d\n",list[Number]->Atk,list[Number]->g_hp,list[Number]->Life);
	printf("경험치 = %d/%d   GetExp = %d\n",list[Number]->g_exp,list[Number]->MaxExp,list[Number]->GetExp);		
	}
}

int Show_Dungeon(Stat* list[])
{
	int select_m;
	system("cls");
	printf("======던전 입구======\n");
	for(int i = 1; i<=7 ;i++)
	{
		printf("   %d.%d층 던전 : [%s]\n",i,i,list[i]->Name);
	}
	printf("   8.돌아가기\n");
	printf("선택 : ");
	scanf("%d",&select_m);
	return select_m;
}

void Level_Up(Stat* list[],int Number)
{
	int rAtk;
	int rLife;	
	while(1)
	{
		if(list[Number]->g_exp >= list[Number]->MaxExp) ///////////이부분을 함수로 레벨업처리 함수로 몬스터한테 넣어줄것 
		{

			list[Number]->Level ++;
			list[Number]->g_exp-=list[Number]->MaxExp;
			rAtk=rand()%5+1;
			rLife=rand()%11+1;
			list[Number]->Atk+=rAtk;
			list[Number]->Life+=rLife;
			list[Number]->MaxExp+=3;
			list[Number]->g_hp=list[0]->Life;
			printf("%s 레벨 업 !!\n",list[Number]->Name);
			printf("공격력 %d 증가!!\n",rAtk);
			printf("생명력 %d 증가!!\n",rLife);
		}
		else break;
	}

}

void File_Check(Stat* list[],char* buf[])
{
	FILE* f;
	char slot_check[11]; // 저장슬롯의 여부를 확인할 변수 
	for(int i=0 ; i < 10 ; i++)
		{
			sprintf(buf,"SaveFile%d.txt",i+1); 
			f = fopen(buf,"r");
			if(f == NULL)
			{
				slot_check[i]='X'; // f가 열리는것에 실패했다는 것은 파일이 없다는 것이므로 x를 입력 
			}
			else 
			{
				slot_check[i]='O'; // f가 열렸다는 것은 파일이 있다는 것이므로 o을 입력 
			}
			printf("%d번슬롯 : (파일여부 : %c)\n",i+1,slot_check[i]);
			fclose(f);	
		}
	printf("선택 : ");		
}

void Start_Game(Stat* list[],int* D_N)
{
	int user;
	int mon;
	srand(time(NULL));
	list[*D_N]->g_hp=list[*D_N]->Life; 	
	while(1)
	{
		system("cls");
		Show_Stat(list,0);
		Show_Stat(list,*D_N);
		printf("[%s]님의 입력\n",list[0]->Name);
		printf("가위 : 0, 바위 : 1, 보 : 2\n");
		printf("입력 : ");
	
		while(1)
		{
			scanf("%d",&user);
			if(user>2||user<0)
				{
				printf("잘못 입력하셨습니다/ 다시 입력해주세요");
				}
			else break;	
		}
		mon=rand()%3;
		printf("%s : %s\n",list[0]->Name, (user == 0 ? "가위" : user == 1 ? "바위":"보"));
		printf("%s : %s\n",list[*D_N]->Name, (mon == 0 ? "가위" : mon == 1 ? "바위":"보"));
		if(user == mon)
		{
			printf("무승부\n");
			system("pause");
		}
		else if
		(user == 0 && mon == 1 ||
		 user == 1 && mon == 2 ||
		 user == 2 && mon == 0)
		{
			printf("졌습니다\n");
			system("pause");
			if((list[0]->g_hp - list[*D_N]->Atk) > 0)
			{
				list[0]->g_hp-=list[*D_N]->Atk;
			}
			else
			{
				system("cls");
				printf("%s 승리!!\n",list[*D_N]->Name);
				printf("%s가 경험치를 %d 만큼 얻었습니다\n",list[*D_N]->Name,list[0]->GetExp);
				list[*D_N]->g_exp += list[0]->GetExp;
				Level_Up(list,*D_N);
				printf("Game Over\n");
				system("pause");
				exit(1);		
			}
		}
		else
		{
			printf("이겼습니다\n");
			system("pause");			
			if((list[*D_N]->g_hp - list[0]->Atk) > 0)
			{
				list[*D_N]->g_hp-=list[0]->Atk;
			}
			else
			{
				system("cls");
				printf("%s 승리!!\n",list[0]->Name);
				printf("%s가 경험치를 %d 만큼 얻었습니다\n",list[0]->Name,list[*D_N]->GetExp);
				list[0]->g_exp+=list[*D_N]->GetExp;	
				Level_Up(list,0);
				system("pause");
			break;			
			}//안쪽  else의 끝 
		} // 바깥 elsed의 끝	
	} //while의 끝 
}// 함수의 끝 

void Save_Game(Stat* list[],int* M_List)
{
	system("cls");
	char buf[256];
	FILE* sf;
	int sel_save; // 저장 슬롯을 입력받을 변수 
	printf("=======[[Save]]=======\n");
	File_Check(list,buf);
	
	scanf("%d",&sel_save);
	sprintf(buf,"SaveFile%d.txt",sel_save);
	sf = fopen(buf,"w");	
	for(int i = 0 ; i < (*M_List)+1 ; i++)
	{	
		fprintf(sf,"%s %d %d %d %d %d ",list[i]->Name,list[i]->Atk,list[i]->g_hp,list[i]->g_exp,list[i]->GetExp,list[i]->Level);
		fprintf(sf,"%d %d %d\n",list[i]->MaxExp,list[i]->Life,list[i]->Check);
		if(i == 0)
		{
			fprintf(sf,"%d\n",*M_List);	
		}
	}
	fclose(sf);
}


void Load_Game(Stat* list[],int* M_List)
{
	system("cls");////////////////////파일 여부를 확인 하는 함수도 하나 만들것. 
	char buf[256];
	FILE* lf;
	int sel_load; // 저장 슬롯을 입력받을 변수 
	
	printf("=======[[Load]]=======\n");
	File_Check(list,buf);
	scanf("%d",&sel_load);
	sprintf(buf,"SaveFile%d.txt",sel_load);
	lf = fopen(buf,"r");
	if(lf==NULL)
	{
		printf("해당 저장 파일이 없습니다\n");
		system("pause");
	}
	else
	{
		for(int i = 0 ; i < (*M_List)+1 ; i++)
		{	
			fscanf(lf,"%s %d %d %d %d %d ",list[i]->Name,&list[i]->Atk,&list[i]->g_hp,&list[i]->g_exp,&list[i]->GetExp,&list[i]->Level);
			fscanf(lf,"%d %d %d",&list[i]->MaxExp,&list[i]->Life,&list[i]->Check);
			if(i == 0)
			{
				fscanf(lf,"%d",(M_List));
			}
		}	
	}
	fclose(lf);
}
void main()
{
	Stat* list[MAX];
	int select;
	int M_List;
	Init(list,&M_List);	
	while(1)
	{
		Show_Main(&select);
		switch(select)
		{
			case 1:
				while(1)
				{
					int Dungeon_Num;
					Dungeon_Num=Show_Dungeon(list);
					if(Dungeon_Num == 8)
					{
						break;
					}
					else if(Dungeon_Num>0 || Dungeon_Num <8)
					{
						Start_Game(list,&Dungeon_Num);
					}					
				}
				break;
			case 2:
				system("cls");
				Show_Stat(list,0);
				printf("=========Enemy=========\n");
				for(int i = 1 ; i < M_List+1 ; i++)
				{
					Show_Stat(list,i);
				}
				system("pause");			
				break;
			case 3:
				Save_Game(list,&M_List);
				break;
			case 4:
				Load_Game(list,&M_List);
				break;
			case 5:
				exit(1);
				break;												
		}
	}
	
}
