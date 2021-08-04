#include <iostream>
using namespace std;
struct Job
{
	char id;
	int profit;
	int deadline;
};
typedef Job job;
void profitSort(job *arr, int len) {
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
    profitSort(jobs, n);
    int *schedule = Job_Scheduling(jobs, n);
    int total_profit = schedule_sum(schedule, n);
    printf("Schedule profits: ");
    display_schedule(schedule, n);
    printf("Total profit: %d\n", total_profit);
    return 0;
}



