#include<iostream>
#include<fstream>
using namespace std;
int dp[100][100];
void _01knapsack(int p[] , int w[] , int wt , int n)
{
	for(int i=0 ; i<=wt ; ++i)
		dp[0][i]=0;
	for(int i=0 ; i<=n ; ++i)
		dp[i][0]=0;
	for(int i=1 ; i<=n ; ++i)
	{
		for(int j=1 ; j<=wt ; ++j)
		{
			if(w[i]>j)
				dp[i][j]=dp[i-1][j];
			else
			{
				dp[i][j]=max(p[i]+dp[i-1][j-w[i]] , dp[i-1][j]);
			}
		}


	}
	cout<<"Final matix is - "<<endl;
	for(int i=0 ; i<=n ; ++i)
	{
		for(int j=0 ; j<=wt ; ++j)
		{
			cout<<dp[i][j]<<"\t";
		}
		cout<<endl;


	}
	int total_profit=dp[n][wt];
	int wait=wt;
	cout<<"The selected items are"<<endl;
	for(int i=n ; i>0 ; --i)
	{
		if(total_profit==dp[i-1][wait])
			continue;
		cout<<i<<" ";
		wait=wait-w[i];
		total_profit=total_profit-p[i];
		if(total_profit==0) break;

	}
	cout<<endl;
	cout<<"The total profit is"<<endl;
	cout<<dp[n][wt]<<endl;


}
int main()
{

	int n , wt;
	fstream infile;
	infile.open("01_knapsack.txt" , ios::in);
	if(!infile)
	{
		cout<<"Error on openning file"<<endl;
		return 0;
	}
	infile>>n>>wt;
	int w[n+1] , p[n+1];
	for(int i=1 ; i<=n ; ++i)
		infile>>p[i];
	for(int i=1 ; i<=n ; ++i)
		infile>>w[i];

	_01knapsack(p , w , wt , n);

}
