#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>

// next task is to modify information about books

using namespace std;

string book[1000][4];
int book_counter=1;

void pline(){
	cout << "\n----------------------------------------------------------------------------------------------------------------------------------\n";
}

void peline(){
	cout << "\n==================================================================================================================================\n";
}



void Add_book(){
	
	cout << "\n\n\n\t\t\tEnter Book's Name  :  ";
	cin >> book[book_counter][1];
	cout << "\t\t\tEnter Book's Author:  ";
	cin >> book[book_counter][2];
	cout<< "\t\t\tEnter Page in Book :  ";
	cin >> book[book_counter][3];
	cout << "\t\t\tEnter Edition      :  ";
	cin >> book[book_counter][4];
	
	book_counter++;
	
}

void View_book(){

	
	int i;
	
	cout << "Enter Book Number :  ";
	cin >> i;
	
	cout << "\nBook's Name   : " << book[i][1];
	cout << "\nBook's Author : " << book[i][2];
	cout << "\nPages in Book : " << book[i][3];
	cout << "\nEdition       : " << book[i][4]; 
	
	getch();
}

void View_booklist(){
	system("CLS");
	
	int i=1;
	
	peline();
	cout << "\t\t\t\t\tAll Books";
	peline();
	cout << "Book Number\t\t\tBook Name\t\t\tBook Author";
	peline();
	if (book_counter != 1){
	while (i < book_counter){
		cout << i << "\t\t\t\t" << book[i][1] << "\t\t\t\t"<< book[i][2]<<endl;
		i++;
	}
	}else{
		cout << "No Books are stored";
	}
	pline();
	getch();
	
}

void modify_book(){
	int i,choice;
	bool n=1;
	
	cout << "\n\n\n\t\t\t\tEnter Book Number : ";
	cin >> i;
	while (n){
	cout << "\n\n\t\t\t1. Modify Book Name\n\t\t\t2. Modify Book Author\n\t\t\t3. Modify Book Pages\n\t\t\t4. Modify Book Edition\n\t\t\t5. Modification Completed\n\t\tChoie : ";
	cin >> choice;
	
	switch (choice){
		case(1):
			cout << "Enter New Name : ";
			cin >> book[i][1];
			break;
		case(2):
			cout << "Enter New Author : ";
			cin >> book[i][2];
			break;
		case(3):
			cout << "Enter New Number of Pages : ";
			cin >> book[i][3];
			break;
		case(4):
			cout << "Enter New Edition : ";
			cin >> book[i][4];
			break;
		case(5):
			n = 0;
			break;
					
		
	}
}
}


int main(){
	
	string choice;
	
	while(1==1){
		system("CLS");
	cout << "\t\t\t\t\t\t\t\t  ==================";
	cout << "\n\t\t\t\t\t\t\t\t\tLibrary\n";
	cout << "\t\t\t\t\t\t\t\t  ==================\n\n";
	pline();
	cout << "\t\t\t1. Add Book \n\t\t\t2. View Book\n\t\t\t3. View All Books\n\t\t\t4. Modify Book\n\t\t\t5. Exit";
	pline();
	cout << "\n\n\t\t\t\t Choice  :  ";
	getline(cin,choice);
	
	if(choice == "1" || choice == "Add Book"){
		Add_book();
	}
	if(choice == "2" || choice == "View Book"){
		View_book();
	}
	if(choice == "3" || choice == "View All Books"){
		View_booklist();
	}
	if(choice == "4" || choice == "Modify"){
		modify_book();
	}
	if(choice == "5" || choice == "Exit"){
		return 0;
	}
}
}
