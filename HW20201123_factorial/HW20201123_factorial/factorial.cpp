#include <iostream>
using namespace std;

int factorial(int num)
{
    if (num <= 1) {
        return 1;
    }
    return num * factorial(num - 1);
}


int main()
{
    int input;
    cin >> input;
    cout<<factorial(input);
}