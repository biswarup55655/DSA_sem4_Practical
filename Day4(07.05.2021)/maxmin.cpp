#include<iostream>
using namespace std;

void MaxAndMin(int arr[],int low,int high,int &max,int &min){

	int max1=INT_MIN;
	int min1=INT_MAX;
	if(low==high){
		max=arr[low];
		min=arr[low];
	}
	else if(low==high-1){
		if(arr[low]>=arr[high]){
			max=arr[low];
			min=arr[high];
		}
		else{
			max=arr[high];
			min=arr[low];
		}
	}
	else{
		int mid = (low+high)/2;
		MaxAndMin(arr,low,mid,max,min);
		MaxAndMin(arr,mid+1,high,max1,min1);
		if(max<=max1){
			max=max1;
		}
		if(min>=min1){
			min=min1;
		}
	}
}

int main(){
	int n;
	cout<<"Enter the limit of the array: "<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the Array Elements: "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int max=arr[0];
	int min=arr[0];
	MaxAndMin(arr,0,n-1,max,min);

	cout<<"The maximum element of the array is: "<<max<<endl;
	cout<<"The minimum element of the array is: "<<min<<endl;
	return 0;
}
