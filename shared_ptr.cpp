#include <iostream>
#include <memory>
#include <thread>
using namespace std;

class foo{
public:
    int x;
public:
    foo(int x):x(x){}

    int get(){
        return x;
    }

    ~foo(){
        cout<<"destructor called";
    }
};

void fun(shared_ptr<foo>sp){
    cout<<"fun:"<<sp.use_count()<<endl;
}

int main(){
    // foo* sp=new foo(10);
    // cout<<sp->get();
    shared_ptr<foo>sp(new foo(100));
    // cout<<sp->get()<<endl;
    // cout<<sp.use_count()<<endl;

    // shared_ptr<foo>sp1=sp;
    // cout<<sp1->get()<<endl;
    // cout<<sp1.use_count()<<endl;

    // shared_ptr<foo>sp2=sp;
    // cout<<sp2->get()<<endl;
    // cout<<sp2.use_count()<<endl;

    thread t1(fun,sp),t2(fun,sp),t3(fun,sp);
    cout<<"main "<<sp.use_count()<<endl;
    t1.join();
    t2.join();
    t3.join();

    return 0;
    
}