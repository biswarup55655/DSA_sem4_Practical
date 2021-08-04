#include<iostream>
using namespace std;
class Stack{
private:
    int stk[100];
    int size;
    int top;

public:
    Stack();
    Stack(int);
    void push(int);
    int pop();
    int peek();
    int isFull();
    int isEmpty();
    void print();
};

Stack::Stack(){
    size=5;
    top=-1;
}
Stack::Stack(int size){
    this->size=size;
    top=-1;
}
void Stack::push(int val){
    if(top+1==size){
        cout<<"\n Stack Overflow";
    }else{
        stk[++top]=val;
        cout<<"\n The is pushed in the stack"<<endl;
    }
}

int Stack::pop(){
    if(top==-1){
        cout<<"\n Empty stack";
        return 0;
    }else{
        int val=stk[top--];
        return val;
    }
}

int Stack::peek(){
    if(top==-1){
        cout<<"\n Empty stack";
        return 0;
    }else{
        int val=stk[top];
        return val;
    }
}

int Stack::isFull(){
    if(top+1==size){
        return 1;
    }else{
        return 0;
    }
}

int Stack::isEmpty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}

void Stack::print(){
    if(top==-1){
        cout<<"The Stack is Empty";
    }else{
        cout<<"\n Values in the stack are:";
        for(int i=top;i>=0;i--){
            cout<<stk[i]<<endl;
        }
    }
}



int main(void){
    int size,choice,val;
    cout<<"\n Enter the size of the stack:";
    cin>>size;
    Stack obj(size);

    while(1){
        cout<<"\n 1.Push \n 2.Pop \n 3.Peek \n 4.isFull \n 5.isEmpty \n 6.Print \n 7.Exit \n Enter your choice:";
        cin>>choice;
        if(choice==1){
            cout<<"\n Enter the value to push: ";
            cin>>val;
            obj.push(val);
        } else if(choice==2){
            val=obj.pop();
            if(val!=0){
                cout<<"\n value popped: "<<val<<endl;
            }
        }else if(choice==3){
            val=obj.peek();
            if(val!=0){
                cout<< "\n Top value of the stack is :"<<val<<endl;
            }
        }else if(choice==4){
            if(obj.isFull()){
                cout<<"\n The Stack is full";
            }else{
                cout<<"\n The stack is not full";
            }
        }else if(choice==5){
            if(obj.isEmpty()){
                cout<<"\n The Stack is Empty";
            }else{
                cout<<"\n The stack is not Empty";
            }
        }else if(choice==6){
            obj.print();
        }else if(choice==7){
            cout<<"\n Thank-you User";
            break;
        }else{
            cout<<"\n Invalid choice";
        }
    }
}
