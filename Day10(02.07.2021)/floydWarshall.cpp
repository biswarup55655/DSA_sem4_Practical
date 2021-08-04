#include<bits/stdc++.h>
#include<fstream>
using namespace std;

int graph[1000][1000];
int V;
int dist[1000][1000];
int pred[1000][1000];

void shortest_path(int i , int j)
{
	if(i==j)
	{
		cout<<i<<"->";
		return;
	}
	if(pred[i][j]==-1)
	{
		cout<<"No shortest path is found"<<endl;
		return;
	}
	else
	{

		shortest_path(i , pred[i][j]);
        cout<<j<<"->";

	}


}

void floyd_warshall()
{
	for(int i=0;i<V;++i)
		for(int j=0;j<V;++j){
			dist[i][j] = graph[i][j];
			if(graph[i][j]==0 or graph[i][j]==INT_MAX)
				pred[i][j]=-1;
			else pred[i][j]=i;
		}

	for(int k=0;k<V;++k){
        for(int i=0;i<V;++i){
            for(int j=0;j<V;++j){
                if(dist[i][j]>dist[i][k]+dist[k][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
					pred[i][j]=pred[k][j];

				}
            }
            if (dist[i][i] < 0)
			{
				cout << "Negative-weight cycle found!!\n";
				return;
			}

        }

	}

}



int main()
{
	fstream infile;
	infile.open("floydWarshall.txt" , ios::in);
	if(!infile)
	{
		cout<<"Error on openning file"<<endl;
		return 0;
	}

	infile>>V;



	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			infile>>graph[i][j];
		}
	}


	cout<<"The input graph is"<<endl;
	for(int i=0 ; i<V ; ++i)
	{
		for(int j=0 ; j<V ; ++j)
		{

			if(graph[i][j]==999)
     			cout<<"INF"<<"\t";
     		else cout<<graph[i][j]<<"\t";
		}
		cout<<endl;
	}
	int E=0;

	floyd_warshall();
	cout<<"The shortest distances between every pair of vertices: "<<endl;
	for(int i=0 ; i<V ; ++i)
      	{
     			for(int j=0 ; j<V ; ++j)
     			{
     				if(dist[i][j]==999)
     					cout<<"INF"<<"\t";
     				else cout<<dist[i][j]<<"\t";
     			}
     			cout<<endl;
      	}
      	int i , j;
        cout<<"Enter two vertices"<<endl;
        cin>>i>>j;
      	cout<<"shortest path between "<<char(i+'A')<<"and "<<char(j+'A')<<" is"<<endl;
     	shortest_path(i,j);
     	cout<<"\ndistance: " <<dist[i][j];
	return 0;
}
