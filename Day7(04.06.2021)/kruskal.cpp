#include<iostream>
#include<fstream>
using namespace std;
class Edge {
    public:
        int src;
        int wgt;
        int dst;
};
/*void sort_Weight(Edge *arr, int E){
    Edge temp;
    bool flag;
    for (int i = 0; i < E - 1; i++){
        flag = false;
        for (int j = 0; j < E - i - 1; j++){
            if (arr[j].wgt > arr[j + 1].wgt){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true;
            }
        }
        if (!flag) return;
    }
}*/

void merge(Edge a[] , int l , int mid , int r , int n){
	int i=l , j=mid+1 , k=l   , t=1;
	Edge z[r+1];
	while(i<=mid && j<=r){
		if(a[i].wgt<=a[j].wgt)
			z[k++]=a[i++];
		else
			z[k++]=a[j++];
		}
	while(i<=mid) z[k++]=a[i++];
	while(j<=r) z[k++]=a[j++];

	for(int i=l ; i<=r ; ++i)
		a[i]=z[i];
}
void merge_sort(Edge a[] , int l , int r , int n){
	int mid ;

	if(l<r){
		 mid=(l+r)/2;
		merge_sort(a , l , mid , n);
		merge_sort(a , mid+1 , r , n);
		merge(a , l , mid , r , n);

	}

}

int find_parent(int v, int *parent) {
    if (v == parent[v])
        return v;
    return find_parent(parent[v], parent);
}

Edge *get_MinSpanTree_Kruskal(Edge *arr, int V, int E){
    merge_sort(arr,0,E-1, E);
    Edge *result = new Edge[V - 1];
    int *parent = new int[V];
    for (int i = 0; i < V; i++) parent[i] = i;
    int count = 0;
    for (int i = 0; count != V - 1; i++) {
        Edge currEdge = arr[i];
        int srcParent = find_parent(currEdge.src, parent);
        int dstParent = find_parent(currEdge.dst, parent);
        if (srcParent != dstParent) {
            result[count] = currEdge;
            count++;
            parent[srcParent] = dstParent;
        }
    }
    return result;
}

void input(Edge *arr, int E){
    fstream infile;
    infile.open("kruskal.txt", ios::in);
    if (!infile){
        printf("\nError to open the file\n");
        exit (1);
    }
    int i,j;
    for (int i = 0; i < E; i++){
        infile>> arr[i].src >> arr[i].dst >> arr[i].wgt;
    }
    cout << endl;
}

void output(Edge *arr, int E){
    cout << "Edges on Minimum Spanning Tree :-\n";
    cout << "Source    Destination    Weight\n";
    int sum = 0;
    for (int i = 0; i < E; i++){
        printf("%d            %d             %d\n", arr[i].src, arr[i].dst, arr[i].wgt);
        sum += arr[i].wgt;
    }
    printf("\nTotal weight of minimum spanning tree: %d\n", sum);
}

int main(){
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    Edge *arr = new Edge[E];
    input(arr, E);
    Edge *result = get_MinSpanTree_Kruskal(arr, V, E);
    output(result, V - 1);
    return 0;
}
