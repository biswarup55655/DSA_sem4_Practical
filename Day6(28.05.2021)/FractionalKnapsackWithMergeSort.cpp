#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

struct Item{
    int value;
    int weight;
    int ratio;
};
void display(Item arr[], int n) {
   int i;
   cout << "values: ";
   for(i = 0; i < n; i++) {
      cout << arr[i].value << "\t";
   }
   cout << endl << "weight: ";
   for (i = 0; i < n; i++) {
      cout << arr[i].weight << "\t";
   }
   cout << endl;
}

void merge(Item a[] , int l , int mid , int r , int n){
    int i=l , j=mid+1 , k=l ,  t=1;
    Item z[r+1];
    while( i<=mid && j<=r){
        if(a[i].ratio>=a[j].ratio)
            z[k++]=a[i++];
        else
            z[k++]=a[j++];
        }
    while(i<=mid) z[k++]=a[i++];
    while(j<=r) z[k++]=a[j++];

    for(int i=l ; i<=r ; ++i)
        a[i]=z[i];
}
void merge_sort(Item a[] , int l , int r , int n){
    int mid ;
    static int t=1;
    if(l<r){
         mid=(l+r)/2;
        merge_sort(a , l , mid , n);
        merge_sort(a , mid+1 , r , n);
        merge(a , l , mid , r , n);


}
}

void fractionalKnapSack(int W,Item arr[],int n){
    double x[n];
    int totalweight=0;
    for(int i=0;i<n;i++){
        x[i]=0.0;
        totalweight+=arr[i].weight;
    }
    int u = W;
    int i;
    for(i=0;i<n;i++){
        if(arr[i].weight > u)break;
        x[i]=1.0;
        u = u - arr[i].weight;
    }
    if(i<=n){
        x[i] = u/(double)arr[i].weight;
    }

    double ans=0.0;
    for(int i=0;i<n;i++){
        ans = ans+x[i]*arr[i].value;
    }
        cout << "total weight in bag " << totalweight<<endl;
        cout << "Max value for "<< W <<" weight is "<< ans<<endl;
}

int main(){
    int n;
    int W;
    fstream infile;
	infile.open("fractionalKnapsack.txt" , ios::in);
	if(!infile)
	{
		cout<<"Error on openning file"<<endl;
		return 0;
	}
	infile>>n;
	infile>>W;
    Item arr[n];
    for(int i=0; i<n; i++){
        infile>>arr[i].value;
    }
    for(int i=0;i<n;i++){
        infile>>arr[i].weight;
    }
    cout << "Entered data \n";
    display(arr,n);
    for(int i=0 ; i<n ; ++i)
    {
        arr[i].ratio=arr[i].value/arr[i].weight;

    }
    cout<<endl;

    merge_sort(arr , 0 , n-1 , n);
    cout << "After sorting: \n";
    display(arr,n);
    cout<<endl;
    fractionalKnapSack(W,arr,n);
    cout<<endl;
    return 0;
}
