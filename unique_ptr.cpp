#include <iostream>
#include <memory>
using namespace std;

class Foo{
private:
    int x;
public:
    Foo(int x):x(x){}
    ~Foo(){
        cout<<"Destructor called"<<endl;
    }

    int get(){
        return x;
    }
};

int main(){
    Foo* f1=new Foo(10);
    cout<<f1->get()<<endl;

    unique_ptr<Foo>f2(new Foo(100));
    unique_ptr<Foo>f3=make_unique<Foo>(20);
    cout<<f2->get()<<endl;
    cout<<f3->get()<<(*f3).get()<<endl;

}