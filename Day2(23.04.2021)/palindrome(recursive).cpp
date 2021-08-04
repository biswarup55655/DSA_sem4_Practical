#include <iostream>
#include <math.h>
using namespace std;
int reverse(int num)
{
    int digit = (int)log10(num);
    if(num == 0)
        return 0;

    return ((num%10 * pow(10, digit)) + reverse(num/10));
}

int isPalindrome(int num)
{

    if(num == reverse(num))
    {
        return 1;
    }

    return 0;
}

int main()
{
    int num;
    cout<< "Enter any number: ";
    cin >> num;

    if(isPalindrome(num) == 1)
    {
        cout<< num<< " is palindrome number.\n";
    }
    else
    {
        cout<< num <<" is not palindrome number.\n";
    }

    return 0;
}
