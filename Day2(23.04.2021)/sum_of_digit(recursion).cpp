#include <iostream>
using namespace std;
int sum(int n)
{
    if (n == 0)
    return 0;
    return (n % 10 + sum(n / 10));
}
int main()
{
    int num;
    cout << "Enter the number: ";
    cin>>num;
    int result = sum(num);
    cout << "Sum of digits in "<< num <<" is "<<result << endl;
    return 0;
}
