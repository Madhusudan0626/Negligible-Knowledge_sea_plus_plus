#include <iostream>

using namespace std;
class Array{
    int *ar;//by default private
    
    public:
        int top=-1;
        int size;
        Array(){}
        Array(int size){this->size=size;ar=new int[size];}
        void insert(int index,int value){
            ar[index] = value;
        }
        void pop(){
            if (top!=-1)
                cout<<ar[top--]<<" poped"<<endl;
            else
                cout<<"stack empty..\n";
        }
        ~Array(){delete []ar;cout<<"Array destroyed\n";}
        void display(){
            int i=size-1;
            cout<<"stack : < -- \n";
            if(i!=-1)
                while(i!=-1){
                    cout<<ar[i]<<" ";
                    i--;
                }
            else
                cout<<"stack empty..\n";
            cout<<"\n";
        }
};

class Stack:protected Array{
    public:
        Stack(int size):Array(size){}
        void push(int value){
            if(top<size-1) {top++;insert(top,value);}
            else cout<<"stack overflowd\n";
            display();
        }
};

int main(){

    Stack s1(6);
    s1.push(63);
    s1.push(13);
    s1.push(23);
    s1.push(33);
}
