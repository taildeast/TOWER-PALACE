#include <iostream>

using namespace std;

int Lv = 0;
int Exp = 0;

void LV(int ex) {
	if (ex + Exp < 100) {
		Exp = +ex;
		cout << "LV : " << Lv <<" exp : "<<Exp<< endl;
	}
	else if (ex + Exp == 100) {
		Exp = 0;
		Lv++;
		cout << "LV : " << Lv << " exp : " << Exp << endl;
	}
	else if (ex + Exp > 100)
	{
		Exp = (ex + Exp - 100);
		Lv++;
			for (;;) {
				if (Exp > 100) {
					Exp -=100;
					Lv++;
				}
		       else if (Exp < 100) {
					cout << "LV : " << Lv << " exp : " << Exp << endl;
					break;
				}
			   else if (Exp == 100) {
					Exp =0;
					Lv++;
					cout << "LV : " << Lv << " exp : " << Exp << endl;
					break;
				}
			}
	}

}


void main() {
	LV(5);
	LV(95);
	LV(2951);
}