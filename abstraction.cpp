//a class containing at least pure virtual class is called an abstract class
#include <iostream>

using namespace std;

class Person{
    public:
        virtual void fun()=0;//pure virtual function
        void fun1(){
            cout<<"Hello from parent\n";
        }
};
//cann't create the object of the Person class

class Student:public Person{
    public:
        void fun1(){cout<<"hello\n";}
        void fun(){cout<<"Here we go for the fun() from the parent class\n";}//definition of declared function in parent class i.e abstarct function | pure virtual function
};

//to access the function that definites in parent class as a pure virtual function need to create a
//child class of it

int main(){
    //Person p; object of abstract class type "Person" is not alowed
    Person *p;
    Student s;
    p=&s;
    s.fun();
    p->fun1();
}
/*
Output: 
Here we go for the fun() from the parent class
Hello from parent
*/
