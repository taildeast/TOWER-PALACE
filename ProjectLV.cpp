#include <iostream>

using namespace std;

int Lv = 0;
int Exp = 0;

void LV(int ex)
{
	Exp += ex;
	while (Exp >= 100)
	{
		Exp -= 100;
		Lv++;
	}
	cout << "LV : " << Lv << " exp : " << Exp << endl;
}

void main() {
	LV(5);
	LV(95);
	LV(2951);
}