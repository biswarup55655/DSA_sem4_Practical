#include<iostream>
#include<fstream>
using namespace std;
int main (){
    fstream infile;
    infile.open("graph.txt", ios::in);
    if (!infile){
        printf("\nError to open the file\n");
        exit (1);
        }
    int n;
    infile>>n;
    int graph[n][n];
    int degree = 0;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            infile>>graph[i][j];
            degree+=graph[i][j];
        }
    }
    int edges= degree/2;
    cout<<"\nNumber of edges in the graphs: "<<edges;
    cout<<"\nTotal degree of the graphs: "<<degree;
    cout<<"\nEnter the vertex to get its adjacent vertex : ";
    int adj;
    cin>>adj;
    cout<<"\nAdjacent vertex of the given vertex are:";
    for(int i=0;i<n;i++){
        if(graph[adj][i]){
            cout<<i<<" ";
        }
    }
    cout<<"\n-The garph-\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<graph[i][j];
            }
        cout << endl;
    }
    infile.close ();
 return 0;
 }
