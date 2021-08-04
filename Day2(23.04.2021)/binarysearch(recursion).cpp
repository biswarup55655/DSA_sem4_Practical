#include<iostream>
using namespace std;
void in(int a[],int n){
	for(int i=0;i<n;i++)
		cin>>a[i];
}
void print(int a[],int n){
	for(int i=0;i<n;i++)
		cout<<a[i];
}
int binary(int a[],int l,int  r,int k){
	if(l>r)
		return -1;
	int m=(l+r)/2;
	if(a[m]==k)
		return m;
	if(a[m]<k)
		return binary(a,m+1,r,k);
	else
		return binary(a,l,m-1,k);
}
int main(void){
	int n;
	cout<<"Size of the array-";
	cin>>n;
	int a[n];
	cout<<"Enter the elements-";
	in(a,n);
	int k;
	cout<<"Enter the element to search-";
	cin>>k;
	int i=binary(a,0,n-1,k);
	if(i==-1)
		cout<<"Not present";
	else
		cout<<"ITs Index "<<i<<endl;
}
