#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

void C_to_F(){
	
	float Ctemp, Ftemp;
	
	cout << "Celsius Temperature   : ";
	cin >> Ctemp;
	
	Ftemp = (Ctemp*1.8) + 32;
	
	cout << "Farenheit Temoerature : " << Ftemp;
	
	}

void F_to_C(){
	
	float Ctemp, Ftemp;
	
	cout << "Farenheit Temperature : ";
	cin >> Ftemp;
	
	Ctemp = (Ftemp-32)*0.5556;
	
	cout << "Celsius Temoerature   : " << Ctemp;
	
	
}

int main(){
	string choice;
	
	cout << "\t\t\t\t\tTemperature Converter\n\n";
	cout << "1. Degree Celsius to Farenheit\n2. Farenheit to Degree Celsius\n\n\t\t\t\t\tChoose<1/2> :";
	getline(cin, choice);
	
	if (choice == "1"){
		C_to_F();
	}
	if (choice == "2"){
		F_to_C();
	}
	
	getch();
	return 0;
}
