#include <iostream>
using namespace std;
int decimalToBinary(int num)
{
    if (num == 0)
        return 0;
    else
        return (num % 2 + 10 * decimalToBinary(num / 2));
}
int main()
{
    int num;
    cout<<"Enter the decimal number: ";
    cin>>num;
    cout << decimalToBinary(num);
    return 0;
}
