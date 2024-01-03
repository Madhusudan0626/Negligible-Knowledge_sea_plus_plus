#include <iostream>
using namespace std;
//when to use private or protected inheritance

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

class Stack:public Array{
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


    s1.insert(5,20);//6th element from the buttom of the stack is placed as 20 whereas 5th element
    //is not in the stack 
    //CONTRADICTION OCCUR
    s1.display();//here index 0 start from RIGHT 
}

/*
stack : < -- 
0 0 0 0 0 63 
stack : < -- 
0 0 0 0 13 63 
stack : < -- 
0 0 0 23 13 63 
stack : < -- 
0 0 33 23 13 63 
stack : < -- 
20 0 33 23 13 63 
Array destroyed
*/
