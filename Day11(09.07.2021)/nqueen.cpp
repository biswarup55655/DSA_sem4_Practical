#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int mat[10][10];
int cnt=0;
bool place(int x[],int k, int i){
	for(int j=0;j<k;j++){
		if(x[j]==i or abs(k-j)==abs(i-x[j]))
			return false;
	}
	return true;
}
void display(int x[],int n){
    cout<<"\nSolution "<<++cnt<<":\n";
	cout<<"[ ";
	for(int i=1;i<=n;i++)
		cout<<x[i]<<" ";
    cout<<"]";
	cout<<endl<<endl;
    int i,j;
    for(i=1;i<=n;++i)
        cout<<"\t"<<i;
    for(i=1;i<=n;++i){
        cout<<"\n\n"<<i;
            for(j=1;j<=n;++j){ //for nxn board
                if(x[i]==j)
                    cout<<"\tQ"; //queen at i,j position
                else
                    cout<<"\t-";
                }
    }
    cout<<endl<<endl;
}

void NQueen(int x[],int k,int n){
	for(int i=1;i<=n;i++){
		if(place(x,k,i))
		{
			x[k]=i;
			if(k==n)
                display(x,n);
			else
				NQueen(x,k+1,n);
		}

	}
}

int main(){
	int n;
	cout<<"Enter queens number: ";
	cin>>n;
	int x[n];
	//Solution is never possible for 3 or less Queens
	if(n<=3)
	{
		cout<<"\nNo solution possible!!!";
		return 1;
	}
	cout<<"The queens position are: "<<endl<<endl;
	NQueen(x,1,n);
	cout<<"\nThe counts are:"<<cnt<<endl;
	return 0;
}
