#include <iostream>
#include <memory>
using namespace std;

int main(){
    shared_ptr<int>sp=make_shared<int>(100);
    weak_ptr<int>wp(sp);

    cout<<"shared_ptr count:"<<sp.use_count()<<endl;
    cout<<"weak_ptr count:"<<wp.use_count()<<endl;
    cout<<"weak_ptr expired:"<<wp.expired()<<endl;

    if(shared_ptr<int>sp1=wp.lock()){
        cout<<"shared_ptr:"<<*sp1<<endl;
        cout<<"shard_ptr count:"<<sp1.use_count()<<endl;
    }
    else{
        cout<<"Don't get resources"<<endl;
    }

    wp.reset();
    if(shared_ptr<int>sp1=wp.lock()){
        cout<<"shared_ptr:"<<*sp1<<endl;
        cout<<"shard_ptr count:"<<sp1.use_count()<<endl;
    }
    else{
        cout<<"Don't get resources"<<endl;
    }

    return 0;
}