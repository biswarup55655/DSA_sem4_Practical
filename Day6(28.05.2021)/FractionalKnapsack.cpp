#include <iostream>
using namespace std;
typedef struct {
   float v;
   float w;
} Item;
void input(Item items[],int n) {
   cout << "Enter total "<< n <<" item's values and weight" <<endl;
   for(int i = 0; i < n; i++) {
      cout << "Enter "<< i+1 << " V ";
      cin >> items[i].v;
      cout << "Enter "<< i+1 << " W ";
      cin >> items[i].w;
   }
}
void display(Item items[], int sizeOfItems) {
   int i;
   cout << "values: ";
   for(i = 0; i < sizeOfItems; i++) {
      cout << items[i].v << "\t";
   }
   cout << endl << "weight: ";
   for (i = 0; i < sizeOfItems; i++) {
      cout << items[i].w << "\t";
   }
   cout << endl;
}
void compare(Item item[],int len){
    Item temp;
    double ratio1, ratio2;
    int f;
    for (int i = 0; i < len - 1; i++) {
        f = 0;
        for (int j = 0; j < len - i - 1; j++) {
            ratio1 = (item[j].v) / item[j].w;
            ratio2 = (item[j + 1].v) / item[j + 1].w;
            if (ratio1 < ratio2) {
                f = 1;
                temp = item[j];
                item[j] = item[j + 1];
                item[j + 1] = temp;
            }
        }
        if (!f) return;
    }
}
float knapsack(Item items[], int n, int W) {
   int i, j, pos;
   Item mx, temp;
   float profit = 0,totalWeight = 0;
   for(i=0; i<n; i++) {
      if(totalWeight < W) {
        if((W-totalWeight)>=items[i].w){
            profit += items[i].v ;
            totalWeight += items[i].w;
        }else {
            profit += (W - totalWeight) * ((items[i].v) / items[i].w);
            break;
            }
        }
   }
    cout << "total weight in bag " << totalWeight<<endl;
    return profit;
}
int main() {
   int W,len;
   cout << "Enter length of array: ";
   cin >> len;
   Item items[len];
   input(items, len);
   cout << "Entered data \n";
   display(items,len);
   cout<< "Enter Knapsack weight \n";
   cin >> W;
   compare(items, len);
   float mxVal = knapsack(items, len, W);
   cout << "Max value for "<< W <<" weight is "<< mxVal;
}
