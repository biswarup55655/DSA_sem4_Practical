#include<iostream>
using namespace std;
    int q[100];
    int size;
    int front=-1;
    int rear=-1;
void display_main_menu();
class queue{
private:
    int q[10];
    int size;
    int front,rear;
public:
    queue();
    queue(int);
    void insert(int);
    int delete1();
    int isFull();
    int isEmpty();
    void display();
    int peek();
};
queue::queue(){
    size=5;
    front=-1;
    rear=-1;
}
queue::queue(int s){
    this->size=s;
    front=-1;
    rear=-1;
}

void queue :: insert(int val){
    if(rear+1==size){
        cout<<"Queue overflow"<<endl;
    }
    else{
        q[++rear]=val;
        if(front==-1)
        {
            front=0;
        }
        cout<<"\nThe value is inserted successfully"<<endl;
    }
}

int queue::delete1(){
    if(rear==-1 && front== -1){
        cout<<"Queue underflow"<<endl;
        return -9999;
    }else{
        int val=q[front];
        for(int i=front;i<rear;i++)
        {
            q[i]=q[i+1];
        }
        rear--;
        if(rear<front)
        {
            front=rear=-1;
        }
        return val;
    }
}
void queue::display(){
    if(front==-1){
        cout<<"\nThe queue is empty"<<endl;
    }else{
        cout<<"\nvalue in the queue are : "<<endl;
        for(int i=front;i<=rear;i++){
            cout<<q[i]<<endl;
        }
    }
}
int queue::isEmpty(){
    if(rear==-1 && front==-1){
        return 1;
    }else{
        return 0;
    }
}

int queue::isFull(){
    if(rear==size){
        return 1;
    }else{
        return 0;
    }
}

int queue::peek(){
    if (front==-1)
    {
        cout<<"Queue is empty!";
        return -1;
    }
    else
        return q[front];
}



int main(){
    int size,val,choice;
    cout<<"\nEnter the size of the queue:";
    cin>>size;
    queue obj(size);
    while(1){
        display_main_menu();
        cout<<"\nEnter your choice:";
        cin>> choice;
        if(choice==1){
            cout<<"Enter the value to insert:";
            int val;
            cin>>val;
            obj.insert(val);
        }else if(choice==2){
            val=obj.delete1();
            if(val!=-9999){
                cout<<"Value deleted successfully"<<val<<endl;
            }
        }else if(choice==3){
            obj.display();
        }else if(choice==4){
            if(obj.isEmpty()){
                cout<<"queue is empty";
            }else{
                cout<<"queue is not empty.";
            }
        }else if(choice==5){
            if(obj.isFull()){
                cout<<"\n The queue is full";
            }else{
                cout<<"\n The queue is not full";
            }
        }else if(choice==6){
            val=obj.peek();
            if(val!=-1){
                cout<<"\n The rear value is"<<val;
            }
        }else if(choice==7){
            cout<<"Thank you user";
            break;
        }else{
            cout<<"Invalid choice...";
        }
    }
    return 0;
}
void display_main_menu()
{
    cout<<"\n1 to insert";
    cout<<"\n2 to pop";
    cout<<"\n3 to Print";
    cout<<"\n4 to isEmpty";
    cout<<"\n5 to isFull";
    cout<<"\n6 to peek";
    cout<<"\n7 to exit";
}
