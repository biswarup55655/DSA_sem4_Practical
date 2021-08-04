#include<iostream>
using namespace std;
int size;
int maxElement(int a[])
{
    static int i = 0, max =- 9999;
    if(i < size)
    {
        if(max < a[i])
        max = a[i];
        i++;
        maxElement(a);
    }
    return max;
}

int main()
{   int max, i;
    cout<<"\nEnter the size of the array: ";
    cin>>size;
    cout<<"\nEnter elements :";
    int arr[size];
    for(i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    max = maxElement(arr);
    cout<<"\nLargest element of the array is : " << max;
    return 0;
}
