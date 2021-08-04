#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;
int V;
int graph[100][100];


int extractMin(int dist[],bool stdSet[]){

	int min = INT_MAX, temp;

    for (int i = 0; i < V; i++)
        if (stdSet[i] == false && dist[i] <= min)
            min = dist[i], temp = i;
    return temp;
}

void print(int dist[]){
	cout<<"Vertex \t\t Distance from Source"<<endl;
    for (int i = 0; i < V; i++)
        cout<<char(i+65)<<"\t\t"<<dist[i]<<endl;
}

void dijkstra(int src){
	int dist[V];
  	int pred[V];
    bool sptSet[V];


    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;
  	pred[0] = -1;

    for (int count = 0; count < V - 1; count++) {

        int u = extractMin(dist, sptSet);
        cout<<u<<"\n";
        sptSet[u] = true;


        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
            	dist[v] = dist[u] + graph[u][v];
            	pred[v]=u;
			}

    }

    print(dist);
}

int main(){
	fstream infile;
	infile.open("dijkstra.txt" , ios::in);
	if(!infile)
	{
		cout<<"Error on openning file"<<endl;
		return 0;
	}

	infile>>V;
	for(int i=0 ; i<V ; ++i)
	{
		for(int j=0 ; j<V ; ++j)
		{
			infile>>graph[i][j];
		}
	}
	cout<<"The Input Graph is: "<<endl;
	for(int i=0 ; i<V ; ++i)
	{
		for(int j=0 ; j<V ; ++j)
		{
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	dijkstra(0);
	return 0;
}
