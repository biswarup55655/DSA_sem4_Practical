#include <iostream>
using namespace std;
struct Job
{
	char id;
	int profit;
	int deadline;
};
typedef Job job;
/*void profitSort(job *arr, int len) {
    job temp;
    int f;
    for (int i = 0; i < len - 1; i++){
        f = 0;
        for (int j = 0; j < len - i - 1; j++){
            if (arr[j].profit < arr[j + 1].profit){
                f = 1;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (!f) return;
    }
}*/

void merge(Job a[] , int l , int mid , int r , int n){
    int i=l , j=mid+1 , k=l ,  t=1;
    Job z[r+1];
    while( i<=mid && j<=r){
        if(a[i].profit>=a[j].profit)
            z[k++]=a[i++];
        else
            z[k++]=a[j++];
        }
    while(i<=mid) z[k++]=a[i++];
    while(j<=r) z[k++]=a[j++];

    for(int i=l ; i<=r ; ++i)
        a[i]=z[i];
}
void merge_sort(Job a[] , int l , int r , int n){
    int mid ;
    static int t=1;
    if(l<r){
         mid=(l+r)/2;
        merge_sort(a , l , mid , n);
        merge_sort(a , mid+1 , r , n);
        merge(a , l , mid , r , n);
}
}


void display(char id[], int len) {

    printf("Schedule ids: ");
    for (int i = 0; i < len; i++) cout << id[i] << " ";
    cout << endl;
}

int *Job_Scheduling(job *jobs, unsigned int len){
    int *schedule = new int[len]{0};
    char id[len];
    int deadline;
    for (int i = 0; i < len; i++) {
        deadline = jobs[i].deadline - 1;
        while (deadline >= 0) {
            if (!schedule[deadline]) {
                schedule[deadline] = jobs[i].profit;
                id[deadline] = jobs[i].id;
                break;
            }
            deadline--;
        }
    }
    display(id, len);
    return schedule;
}



int schedule_sum(int *schedule,int len){
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += *(schedule + i);
    return sum;
}

void input(job jobs[], int len){
    char id = 'A';
    for (int i = 0; i < len; i++) {
        jobs[i].id = id;
        cout<<"Enter the profit: ";
        cin>>jobs[i].profit;
        cout<<"Enter the deadlines: ";
        cin>>jobs[i].deadline;
        id++;
    }
}

void display_schedule(int *schedule, int len){
    for (int i = 0; i < len; i++)
        if (schedule[i])
            cout << schedule[i] << " ";
    cout << endl;
}

int main(){
	int n;
	cout << "How many jobs do you want to check ? ";
	cin >> n;
    job jobs[n];
    input(jobs, n);
    merge_sort(jobs,0,n-1,n);
    int *schedule = Job_Scheduling(jobs, n);
    int total_profit = schedule_sum(schedule, n);
    printf("Schedule profits: ");
    display_schedule(schedule, n);
    printf("Total profit: %d\n", total_profit);
    return 0;
}



