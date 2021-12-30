#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

// the function MessageBox() is used to make a message box in the window

int main()
{

    char str[30];
    cout << "Enter some string  : ";
    cin.getline(str,30);
    // LPCSTR is the format of the string which is displayed in the message box
    MessageBox(0,(LPCSTR)str,"Message Box Generator",MB_OKCANCEL);
                                                    // MB is the style of the buttons that appear in the bottom of the message box in the window

    return 0;
}
