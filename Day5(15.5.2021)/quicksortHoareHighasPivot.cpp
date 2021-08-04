#include<iostream>
using namespace std;
int t=1 , com=0;
void swap(int &a , int &b){
	int temp=a;
	a=b;
	b=temp;
}
int partition(int a[] , int low , int h , int n){
	int pivot=a[h];
	int l=low-1;
	int r=h;
	int subpass=1;
	while(++com && l<r){
		do{
			++l;
		}while(  l<=r && ++com  && a[l]<pivot);

		do{
			--r;
		}while(r>=l && ++com  && a[r]>pivot);
		if(l<r)
		swap(a[l] , a[r]);
		cout<<"subpass "<<subpass++<<":";
		for(int i=0 ; i<n ; ++i)
			cout<<a[i]<<" ";
			cout<<endl<<endl;
	}
	swap(a[l] , a[h]);
	cout<<"pass "<<t++<<":";
	for(int i=0 ; i<n ; ++i)
		cout<<a[i]<<" ";
		cout<<endl<<endl;
	return l;
}
void quick_sort(int a[] , int low , int h , int n){
	int j;
	if(low<h){
		j=partition(a , low , h , n);
		quick_sort(a , low , j-1 , n);
		quick_sort(a , j+1 , h , n);
	}
}
int main(){
	int n;
	cout << "Enter the number of elements of the array " << endl;
	cin>>n;
	int a[n];
	cout << "Enter the elements of the array " << endl;
	for(int i=0 ; i<n ; ++i)
		cin>>a[i];
	quick_sort(a , 0 , n-1 , n);
	cout<<"Total number of comparison is"<<endl;
	cout<<com<<endl;
	cout<<"The sorted array is"<<endl;
	for(int i=0 ; i<n ; ++i)
		cout<<a[i]<<" ";
		cout<<endl;
}
