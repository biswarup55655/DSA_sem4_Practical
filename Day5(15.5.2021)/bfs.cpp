#include<iostream>
#include<fstream>
#include<string>
#include "queuelink.cpp"
using namespace std;

int v;
int mat[10][10];
int vis[100]={0};

void bfs(int n){
	queue q;
	vis[n]=1;
	q.enqueue(n);
	while(!q.isempty()){
		int u=q.dequeue();
		cout<<u<<" ";
		for(int w=0;w<v;w++){
			if(mat[u][w]==1)
            {
                if(vis[w]!=1)
                {
                    vis[w]=1;
        	        q.enqueue(w);
                }
            }
		}
	}
}

int main(){
	fstream infile;
	infile.open("graphbfs_dfs.txt",ios::in);

	if(!infile){
		cout<<"\nError to open the file\n"<<endl;
		exit(1);
	}

	infile>>v;

	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			infile>>mat[i][j];
		}
	}

	cout<<endl;
	cout<<"The graph is: "<<endl;

	for(int i=0;i<v;i++){
		cout<<i<<"-->";
		for(int j=0;j<v;j++){
			if(mat[i][j])
				cout<<j<<"-->";
		}
		cout<<endl;
	}

	cout<<"BFS is: "<<endl;
    bfs(0);
	return 0;
}
