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
        void display(){
            int i=top;
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
        ~Array(){delete []ar;cout<<"Array destroyed\n";}
};

class Stack:public Array{//if we don't do a protected inheritance all public member of parent class gets accessed
    public:
        Stack(int size):Array(size){}
        void push(int value){
            if(top<size-1) {top++;insert(top,value);}
            else cout<<"stack overflowd\n";
        }
};

int main(){
    Stack s1(6);
    s1.push(63);
    s1.push(13);
    s1.push(23);
    s1.push(33);
    s1.push(43);
    s1.push(53);
    s1.push(73);
    s1.push(83);

    s1.display();

    s1.pop();
    s1.display();

    s1.insert(1,20);//2nd element from the buutom of the stack is replaced by 20 
    //contradiction
    s1.display();//here index 0 start from buttom 
    // to overcome with this issue do as a protected or private inheritance of parent / base class to
    //prevent the access of all public member function by the object of child class

    //class B:protected A{};
}

/*
stack overflowd
stack overflowd
stack : < -- 
53 43 33 23 13 63 
53 poped
stack : < -- 
43 33 23 13 63 
stack : < -- 
43 33 23 20 63 
Array destroyed
*/
