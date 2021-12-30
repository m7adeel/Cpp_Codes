#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <cctype>
#include <conio.h>

using namespace std;

// data stores
// int
vector<int> s_int;
vector<string> n_int;
// bool
vector<bool> s_bool;
vector <string> n_bool;
// strings
vector<string> s_string;
vector<string> n_string;
// floats
vector<float> s_float;
vector <string> n_float;
// characters
vector<char> s_char;
vector<string> n_char;

string removing_space(string b){
	// news is short for new string
	string news;
	for (int i = 0 ; i < b.length() ; i++){
		if(b.at(i) != ' '){
			news = news + b.at(i);
		}
	}
	return news;
}

int string_to_num(string b,int power,int start,int end){
	int num;
	string given;

	/*for(int i = start ; i < end ; i++)
	{
		given += b.at(i);
	}

	num = stoi(b);
	*/
	for (int i = start ; i < end; i ++){
		if (b.at(i) == '0'){
			num = num + 0*pow(10,power);
			power = power - 1;
		}
		if (b.at(i) == '1'){
			num = num + 1*pow(10,power);
			power = power - 1;
		}
		if (b.at(i) == '2'){
			num = num + 2*pow(10,power);
			power = power - 1;
		}
		if (b.at(i) == '3'){
			num = num + 3*pow(10,power);
			power = power - 1;
		}
		if (b.at(i) == '4'){
			num = num + 4*pow(10,power);
			power = power - 1;
		}
		if (b.at(i) == '5'){
			num = num + 5*pow(10,power);
			power = power - 1;
		}
		if (b.at(i) == '6'){
			num = num + 6*pow(10,power);
			power = power - 1;
		}
		if (b.at(i) == '7'){
			num = num + 7*pow(10,power);
			power = power - 1;
		}
		if (b.at(i) == '8'){
			num = num + 8*pow(10,power);
			power = power - 1;
		}
		if (b.at(i) == '9'){
			num = num + 9*pow(10,power);
			power = power - 1;
		}
	}
	return num;
}

double addfunction(string b){
	bool found = 0;
	int found_at;
	int num1=0,num2=0;
	double result;
	int power;

	b = removing_space(b);
	for (int i = 0 ; i < b.length() ; i++){
		if (b.at(i) == '+'){
			found_at = i;
			found = 1;
		}
	}
	power = (found_at - 1);
	num1 = string_to_num(b,power,0,found_at);
	power = b.length() - found_at - 2;
	num2 = string_to_num(b,power,found_at,b.length());
	result = num1 + num2;
	return result;
}

double subfunction(string b){
	bool found = 0;
	int found_at;
	int num1=0,num2=0;
	double result;
	int power;

	b = removing_space(b);
	for (int i = 0 ; i < b.length() ; i++){
		if (b.at(i) == '-'){
			found_at = i;
			found = 1;
		}
	}
	power = (found_at - 1);
	num1 = string_to_num(b,power,0,found_at);
	power = b.length() - found_at - 2;
	num2 = string_to_num(b,power,found_at,b.length());
	result = num1 - num2;
	return result;
}

double mulfunction(string b){
	bool found = 0;
	int found_at;
	int num1=0,num2=0;
	double result;
	int power;

	b = removing_space(b);
	for (int i = 0 ; i < b.length() ; i++){
		if (b.at(i) == '*'){
			found_at = i;
			found = 1;
		}
	}
	power = (found_at - 1);
	num1 = string_to_num(b,power,0,found_at);
	power = b.length() - found_at - 2;
	num2 = string_to_num(b,power,found_at,b.length());
	result = num1 * num2;
	return result;
}

double divfunction(string b){
	bool found = 0;
	int found_at;
	int num1=0,num2=0;
	double result;
	int power;

	b = removing_space(b);
	for (int i = 0 ; i < b.length() ; i++){
		if (b.at(i) == '/'){
			found_at = i;
			found = 1;
		}
	}
	power = (found_at - 1);
	num1 = string_to_num(b,power,0,found_at);
	power = b.length() - found_at - 2;
	num2 = string_to_num(b,power,found_at,b.length());
	result = num1 / (num2+0.0);
	return result;
}

// perform searches
void search_n_int(string a)
{
    int found_at = 0;
    //for(string i: n_int)
    //{
        //if(i == a)
        //{
        //    cout << i << " = ";
        //    break;
        //}
        //found_at++;
    //}
    cout << s_int[found_at];
}

void search_n_string(string a)
{
    int found_at = 0;
    for(string i: n_string)
    {
        if(i == a)
        {
            cout << i << " = ";
            break;
        }
        found_at++;
    }
    cout << s_string[found_at];
}

int main(){
	bool end = 0;
	string a;
	bool echo = 0;

	while(!end){
		getline(cin,a);

		if(tolower(a.at(0)) == 'e' && tolower(a.at(1)) == 'c' && tolower(a.at(2)) == 'h' && tolower(a.at(3)) == 'o' && a.at(4) == ' ')
		{
			for (int i =5 ; i <a.length()  ; i++){
				cout << a.at(i);
			}
			cout << endl;
			echo = 1;
		}

		if(tolower(a.at(0)) == 'i' && tolower(a.at(1)) == 'n' && tolower(a.at(2)) == 'p' && tolower(a.at(3)) == 'u' && tolower(a.at(4) == 't'))
		{

		}

		if(a.length() == 4 ? (tolower(a.at(0)) == 'e' && tolower(a.at(1)) == 'n' && tolower(a.at(2)) == 'd' && tolower(a.at(3)) == ' ') : (tolower(a.at(0)) == 'e' && tolower(a.at(1)) == 'n' && tolower(a.at(2)) == 'd') )
		{
			end = 1;
		}
		if (!echo)
		{
			for (int i = 0 ; i < a.length() ; i ++)
			{
				if (a.at(i) == '+')
				{
					cout << addfunction(a) << endl;
				}
				if (a.at(i) == '-')
				{
					cout << subfunction(a) << endl;
				}
				if (a.at(i) == '*')
				{
					cout << mulfunction(a) << endl;
				}
				if (a.at(i) == '/')
				{
					cout << divfunction(a) << endl;
				}
			}
		}
		if(a.at(0) == 'm' && a.at(1) == 'a' && a.at(2) == 'k' && a.at(3) == 'e' && a.at(4) == 'd' && a.at(5) == 'i' && a.at(6) == 'r' )
		{
			string dir_name = "mkdir ";
			for(int i = 7 ; i < a.length() ; i++)
			{
				dir_name = dir_name + a.at(i);
			}
			system(dir_name.c_str());
		}
		if(a.at(0) == 'r' && a.at(1) == 'e' && a.at(2) == 'm' && a.at(3) == 'o' && a.at(4) == 'v' && a.at(5) == 'e' && a.at(6) == 'd' && a.at(7) == 'i' && a.at(8) == 'r' )
		{
			string dir_name = "rmdir ";
			for(int i = 9 ; i < a.length() ; i++)
			{
				dir_name = dir_name + a.at(i);
			}
			system(dir_name.c_str());
		}

		if(a.at(0) == 'c' && a.at(1) == 'l' && a.at(2) == 'e' && a.at(3) == 'a' && a.at(4) == 'r')
		{
			system("CLS");
		}

		// creation of data stores
		// integer data type
		if(a.at(0) == 'i' && a.at(1) == 'n' && a.at(2) == 't' && a.at(3) == ' ')
		{
			string name;
			int value;
			bool is_value = false;
			for(int i = 4 ; i < a.length() ; i++)
			{
				if(a.at(i) == '='){is_value = true; continue;}
				if(!is_value)
					name+= a.at(i);
				else
				{
					value = string_to_num(a,a.length()-i-1,i,a.length()-1);
					break;
				}
			}
			s_int.push_back(value);
			n_int.push_back(name);
		}

        // string data type
        if(a.at(0) == 's' && a.at(1) == 't' && a.at(2) == 'r' && a.at(3) == 'i' && a.at(4) =='n' && a.at(5) == 'g' && a.at(6) == ' ')
		{
			string name;
			string value;
			bool is_value = false;
			for(int i = 7 ; i < a.length() ; i++)
			{
				if(a.at(i) == '='){is_value = true; continue;}
				if(!is_value)
					name+= a.at(i);
				else
				{
					value = name;
					break;
				}
			}
			s_string.push_back(value);
			n_string.push_back(name);
		}

		// float


		// getting a specific data type
		search_n_int(a);
		search_n_string(a);


		/*if(a.at(0) == 'c' && a.at(1) == 'd')
		{    	//work on this part
			string function ;
			// creating of file at that place
			function = "copy my_interpreter.exe ";
			for (int i = 3; i<a.length();i++)
			{
				function = function + a.at(i);
			}
			system(function.c_str());
			function = "start ";
			for (int i = 3 ; i < a.length() ; i++)
			{
				function = function + a.at(i);
			}
			function = function + "\my_interpreter";
			system(function.c_str());
			end = 1;
		}*/



		echo = 0;
	}

	cout << "Press Enter to End the Program......";
	getch();
	return 0;
}
