#include <iostream>

using namespace std;

int main()
{
    int size = 10;
    int num[size] ={1,2,3,4,5,6,7,8,9,0};
    
    for(auto var: num)
    {
        cout << "The number is : " << var << endl;
    }

    return 0;
}