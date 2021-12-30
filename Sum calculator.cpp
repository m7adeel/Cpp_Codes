#include<iostream>

using namespace std;

int main(){
	
	int sum=0;
	int number,tnumbers;
	
	cout << "How many numbers Do you want to add?  ";
	cin >> tnumbers;
	
	for (int n=0; n<tnumbers; n++){
		cout << "Enter "<< n+1 << " Number :";
		cin >> number;
		sum += number;
	}
	
	cout << "\nSum = "<< sum << endl;
	
	return 0;
}


