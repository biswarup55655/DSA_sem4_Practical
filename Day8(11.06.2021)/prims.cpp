#include<iostream>
#include<fstream>
using namespace std;

int V;
int graph[100][100];


int minKey(int key[], bool mstSet[]){
    int min= INT_MAX, min_index;
    for (int i = 0; i < V; i++)
        if (mstSet[i] == false && key[i] < min)
            min = key[i], min_index = i;

    return min_index;
}

void print(int parent[]){
    for(int i=1;i<V;i++){
        cout<<char(parent[i]+65)<<" - "<<char(i+65)<<" \t"<<graph[i][parent[i]]<<endl;
    }
}

void primsAlgo(){
    int parent[V];
    int key[V];
    bool mstSet[V];
    for(int i=0;i<V;i++){
        key[i]=INT_MAX;
        mstSet[i]=false;
    }
    parent[0]=-1;
    key[0]=0;
    for(int i=0;i<V-1;i++){
        int u=minKey(key,mstSet);
        mstSet[u]=true;
        for(int j=0;j<V;j++){
            if(graph[u][j] && mstSet[j]==false && graph[u][j]<key[j]){
                parent[j]=u;
                key[j]=graph[u][j];
            }
        }

    }
    print(parent);
}

int main(){
    fstream infile;
	infile.open("prims.txt" , ios::in);
	if(!infile)
	{
		cout<<"Error on openning file"<<endl;
		return 0;
	}
	infile>>V;
	for(int i=0 ; i<V ; i++)
	{
		for(int j=0 ; j<V ; j++)
		{
			infile>>graph[i][j];
		}
	}
	cout<<endl;
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
	primsAlgo();
	return 0;


}
