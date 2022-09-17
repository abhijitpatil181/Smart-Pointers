#include <iostream>
using namespace std;

class Myint{
private: 
    int* Data;
public:
    explicit Myint(int* p=nullptr):Data(p){}

    ~Myint(){
        delete Data;
    }

    int& operator * (){
        return *Data;
    }

};

int main(){
    int* p=new int(10);
    Myint myint=Myint(p);
    cout<<*myint<<endl;
}

/*
-> Smart pointer is class which wraps a raw pointer,to manage a life time of pointer.
-> The most fundamental job of smart pointer is to remove chance of memory leak.
-> It makes sure object is deleted if it is not refernce any more.

Types:-
1) unique_ptr -> allows only one owner of the underlying pointer.

2) shared_ptr -> allows multiple owener of the same pointer(refernce is counted)

3) weak_ptr -> It is special type of shared pointer which doesn't count refernce.
*/