
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10  // �÷��̾�� ���͸� ��ģ �ִ� �� 

typedef struct character
{
	char Name[20];//�̸� 
	int Atk;//���ݷ� 
	int Life;//����� 
	int MaxExp;//����ġ �� 
	int GetExp;//����, Ȥ�� ������ �ִ� ����ġ 
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
		printf("����\n");
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
	
	printf("�÷��̾� �̸� �Է� : ");
	scanf("%s",list[0]->Name);
	system("pause");		
	for(int i = 0 ; i <*M_List+1; i++)
	{
		list[i]->g_hp=list[i]->Life;//���� �� ü���� ���� ó���� �ƽ�ü������ �ʱ�ȭ 
		list[i]->g_exp=0;
	}	
}
void Show_Main(int* select)
{
	system("cls");
	printf("======DunGeon======\n");
	printf("  1.���� ����\n");
	printf("  2.Player ����\n");
	printf("  3.Save\n");
	printf("  4.Load\n");	
	printf("  5.����\n");	
	printf("  �Է� : ");
	scanf("%d",select);	
}

void Show_Stat(Stat* list[],int Number)
{
	if(Number == 0)
	{
	printf("======%s(%dLv)======\n",list[Number]->Name,list[Number]->Level);
	printf("���ݷ� = %d      ����� = %d/%d\n",list[Number]->Atk,list[Number]->g_hp,list[Number]->Life);
	printf("����ġ = %d/%d   GetExp = %d\n",list[Number]->g_exp,list[Number]->MaxExp,list[Number]->GetExp);
	printf("======================\n\n");
	}
	else
	{
	printf("======%s(%dLv)======\n",list[Number]->Name,list[Number]->Level);
	printf("���ݷ� = %d      ����� = %d/%d\n",list[Number]->Atk,list[Number]->g_hp,list[Number]->Life);
	printf("����ġ = %d/%d   GetExp = %d\n",list[Number]->g_exp,list[Number]->MaxExp,list[Number]->GetExp);		
	}
}

int Show_Dungeon(Stat* list[])
{
	int select_m;
	system("cls");
	printf("======���� �Ա�======\n");
	for(int i = 1; i<=7 ;i++)
	{
		printf("   %d.%d�� ���� : [%s]\n",i,i,list[i]->Name);
	}
	printf("   8.���ư���\n");
	printf("���� : ");
	scanf("%d",&select_m);
	return select_m;
}

void Level_Up(Stat* list[],int Number)
{
	int rAtk;
	int rLife;	
	while(1)
	{
		if(list[Number]->g_exp >= list[Number]->MaxExp) ///////////�̺κ��� �Լ��� ������ó�� �Լ��� �������� �־��ٰ� 
		{

			list[Number]->Level ++;
			list[Number]->g_exp-=list[Number]->MaxExp;
			rAtk=rand()%5+1;
			rLife=rand()%11+1;
			list[Number]->Atk+=rAtk;
			list[Number]->Life+=rLife;
			list[Number]->MaxExp+=3;
			list[Number]->g_hp=list[0]->Life;
			printf("%s ���� �� !!\n",list[Number]->Name);
			printf("���ݷ� %d ����!!\n",rAtk);
			printf("����� %d ����!!\n",rLife);
		}
		else break;
	}

}

void File_Check(Stat* list[],char* buf[])
{
	FILE* f;
	char slot_check[11]; // ���彽���� ���θ� Ȯ���� ���� 
	for(int i=0 ; i < 10 ; i++)
		{
			sprintf(buf,"SaveFile%d.txt",i+1); 
			f = fopen(buf,"r");
			if(f == NULL)
			{
				slot_check[i]='X'; // f�� �����°Ϳ� �����ߴٴ� ���� ������ ���ٴ� ���̹Ƿ� x�� �Է� 
			}
			else 
			{
				slot_check[i]='O'; // f�� ���ȴٴ� ���� ������ �ִٴ� ���̹Ƿ� o�� �Է� 
			}
			printf("%d������ : (���Ͽ��� : %c)\n",i+1,slot_check[i]);
			fclose(f);	
		}
	printf("���� : ");		
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
		printf("[%s]���� �Է�\n",list[0]->Name);
		printf("���� : 0, ���� : 1, �� : 2\n");
		printf("�Է� : ");
	
		while(1)
		{
			scanf("%d",&user);
			if(user>2||user<0)
				{
				printf("�߸� �Է��ϼ̽��ϴ�/ �ٽ� �Է����ּ���");
				}
			else break;	
		}
		mon=rand()%3;
		printf("%s : %s\n",list[0]->Name, (user == 0 ? "����" : user == 1 ? "����":"��"));
		printf("%s : %s\n",list[*D_N]->Name, (mon == 0 ? "����" : mon == 1 ? "����":"��"));
		if(user == mon)
		{
			printf("���º�\n");
			system("pause");
		}
		else if
		(user == 0 && mon == 1 ||
		 user == 1 && mon == 2 ||
		 user == 2 && mon == 0)
		{
			printf("�����ϴ�\n");
			system("pause");
			if((list[0]->g_hp - list[*D_N]->Atk) > 0)
			{
				list[0]->g_hp-=list[*D_N]->Atk;
			}
			else
			{
				system("cls");
				printf("%s �¸�!!\n",list[*D_N]->Name);
				printf("%s�� ����ġ�� %d ��ŭ ������ϴ�\n",list[*D_N]->Name,list[0]->GetExp);
				list[*D_N]->g_exp += list[0]->GetExp;
				Level_Up(list,*D_N);
				printf("Game Over\n");
				system("pause");
				exit(1);		
			}
		}
		else
		{
			printf("�̰���ϴ�\n");
			system("pause");			
			if((list[*D_N]->g_hp - list[0]->Atk) > 0)
			{
				list[*D_N]->g_hp-=list[0]->Atk;
			}
			else
			{
				system("cls");
				printf("%s �¸�!!\n",list[0]->Name);
				printf("%s�� ����ġ�� %d ��ŭ ������ϴ�\n",list[0]->Name,list[*D_N]->GetExp);
				list[0]->g_exp+=list[*D_N]->GetExp;	
				Level_Up(list,0);
				system("pause");
			break;			
			}//����  else�� �� 
		} // �ٱ� elsed�� ��	
	} //while�� �� 
}// �Լ��� �� 

void Save_Game(Stat* list[],int* M_List)
{
	system("cls");
	char buf[256];
	FILE* sf;
	int sel_save; // ���� ������ �Է¹��� ���� 
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
	system("cls");////////////////////���� ���θ� Ȯ�� �ϴ� �Լ��� �ϳ� �����. 
	char buf[256];
	FILE* lf;
	int sel_load; // ���� ������ �Է¹��� ���� 
	
	printf("=======[[Load]]=======\n");
	File_Check(list,buf);
	scanf("%d",&sel_load);
	sprintf(buf,"SaveFile%d.txt",sel_load);
	lf = fopen(buf,"r");
	if(lf==NULL)
	{
		printf("�ش� ���� ������ �����ϴ�\n");
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
