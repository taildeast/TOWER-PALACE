#include<iostream>
#include<windows.h> // system 사용 
#include<string> //스트링 출력용
using namespace std;

//플레이어 변수
int Lv; //레벨
int Exp; //경험치
int MaxHp; //최대체력 > 틀별한 이벤트가 없는한 올라가지않음 시작치 100고정
int Hp; //게임내에서 사용될 체력(가변)
int Atk;//공격력
//공격시 데미지 계산법  rand() % 10 + Atk - Def
int Def;//방어력
string Name;//플레이어 이름
int Money;//상점시스템을 넣는다면 소지금

//몬스터변수
int M_Atk;//몬스터 공격력
int M_Def;//몬스터 방어력
string M_Name;//몬스터 이름

//기타
int Floor; //현제 플레이어의 층


//함수 이름
void LvUp(int ex); //레벨업함수 >경험치 습득할때 호출
void Death_Check(); //사망체크 체력이 0이하면 게임오버함수 호출
void GameOver(); //게임오버 함수


void main() {
	system("cls");// 화면을 정리하는 함수 windows 헤더 필요 
}