#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>

using namespace std;

string remove_spaces(string lot_spaces)
{
	string one_space;
	
	for(int i = 0; i < (lot_spaces.length()) ; i++)
	{
		if(!(lot_spaces[i] == ' ' && lot_spaces[i+1] == ' '))	// If two seperate spaces are encountered then one of them is not counted
		{
			one_space += lot_spaces[i];
		}
	}
	
	return one_space;
}

string replace_newLine_space(string text)
{
	string one_line;
	
		for(int i = 0; i < (text.length()) ; i++)
	{
		if(text[i] == '\n')	// If a new line comes then it is replaced with space
		{
			one_line += ' ';
		}
		else
		{
			one_line += text[i];
		}
	}
	
	return one_line;
}

int main()
{
	string file_name;
	int choice;
	
	cout << "Enter the name of file without extension(Note the file should be a txt file) : ";
	getline(cin,file_name);
	
	file_name+=".txt";
	// Taking the content in the file and using it
	ifstream file;
	file.open(file_name.c_str());
	string text,work_text;
	
	while(getline(file,text))
	{
		work_text += text;
	}
	
	file.close();
	// end of input from the file
	
	cout << "\n1. Remove Spaces \n2. Remove Extra Lines\nChoice : ";
	cin >> choice;
	
	while(choice < 1 || choice > 2)
	{
		cout << "Enter a Valid Choice : ";
		cin >> choice;
	}
	
	switch(choice)
	{
		case 1:
			work_text = remove_spaces(work_text);
			break;
		
		case 2:
			replace_newLine_space(work_text);
			break;
	}
	// output to the file 
	ofstream file2;
	file2.open(file_name.c_str());
	
	file2 << work_text << endl;
	
	file2.close();
	// end of output to the file
	return 0;
}
