#include <iostream>
using namespace std;

int Lv = 1;
int Exp = 100;
int Total_Exp;

void LV(int ex) 
{
    Total_Exp += ex;
    while(1)
    {
        if(Total_Exp >= Exp)
        {
            Lv++;
            Total_Exp -= Exp;
        }
        else    break;
    }
    cout<<"Lv : "<<Lv<<"  exp : "<<Total_Exp<<endl;
}

int main(void) 
{
    LV(5);
    LV(95);
    LV(2951);
}
