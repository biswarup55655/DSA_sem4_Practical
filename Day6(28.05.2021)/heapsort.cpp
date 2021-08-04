#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i +1 ;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
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
    for (int i = n / 2 -1; i >= 0; i--)
        heapify(arr, n, i);
    int j=0;
    for (int i = n-1 ; i >= 0; i--) {
        swap(arr[0], arr[i]);
        cout<<"pass"<<j++<<":";
        printArray(arr,n);
        heapify(arr, i, 0);
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
