#include <iostream>
using namespace std;
void buildMaxHeap(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[(i - 1) / 2])
        {
            int j = i;
            while (arr[j] > arr[(j - 1) / 2])
            {
                swap(arr[j], arr[(j - 1) / 2]);
                j = (j - 1) / 2;
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i <  n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);
    int count=0;
    for (int i = n - 1; i > 0; i--)
    {
        int j = 0;
        swap(arr[0], arr[i]);
        cout<<"pass"<<count++<<":";
        printArray(arr,n);
        int index;
        do
        {
            index = (2 * j + 1);
            if (arr[index] < arr[index + 1] && index < (i - 1))
                index++;
            if (arr[j] < arr[index] && index < i)
                swap(arr[j], arr[index]);
            j = index;
        } while (index < i);
    }
}
int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Original array  : ";
    printArray(arr, n);
    cout<<"\n";
    heapSort(arr, n);
    cout << "\nSorted array is  : ";
    printArray(arr, n);
    cout<<"\n";
}
