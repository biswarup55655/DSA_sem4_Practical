#include<iostream>
#include<fstream>
#include<string>
#include "stacklink.cpp"
using namespace std;

int v;
int mat[10][10];
int vis[100]={0};

void dfs(int n)
{
    stack st;
    st.push(n);
    vis[n]=1;
    while(!st.isempty())
    {
        int u=st.pop();
        cout<<u<<" ";
        for(int w=0 ; w<v ; ++w)
        {
            if(mat[u][w]==1)
            {
                if(vis[w]!=1)
                {
                    vis[w]=1;
                    st.push(w);
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

	int e=1;
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			if(mat[i][j]){
				e++;
			}
		}
	}
	cout<<"The number of edges: "<<e/2<<endl;
	cout<<"The number of degree: "<<e<<endl;

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

	cout<<"DFS is: "<<endl;
    dfs(0);
	return 0;
}
