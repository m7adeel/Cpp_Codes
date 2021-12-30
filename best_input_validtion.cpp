#include <iostream>
#include <cstring>  // to deal with character array and strings
#include <cctype>   // to use isdigit and other functions

using namespace std;

bool condition(char *text,int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        // If number at i index is not a digit return true to execute the while loop
        if(!isdigit(*(text+i)))
        {
            return 1;
        }
    }
    // if all are digits then donot run the loop
    return 0;
}

int main()
{
    // first of all we take input using a character array
    char input[20];
    cout << "Enter the Number : ";
    cin.getline(input,20);

    // After this we refer to the condition function to check the type of input
    while(condition(input,strlen(input)))
    {
        // taking values again so we can process data without any problem
        cout << "Enter a correct value : ";
        cin.getline(input,20);
    }
    /* rest of the code will go over here
       Using stoi() function we will convert the char array to integer
       and then perform further processing*/


    return 0;
}