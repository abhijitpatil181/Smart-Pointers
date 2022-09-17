#include <iostream>
#include <memory>
using namespace std;

struct Son;
struct Daughter;

struct Mother{

    weak_ptr<Son>mySon;
    weak_ptr<Daughter>myDaughter;
    ~Mother(){
        cout<<"m destructed"<<endl;
    }

    void setSon(const shared_ptr<Son>s){
        mySon=s;
    }

    void setDaughter(const shared_ptr<Daughter>d){
        myDaughter=d;
    }
};

struct Son{
    shared_ptr<Mother>myMother;
    Son(shared_ptr<Mother>m):myMother(m){}
    ~Son(){
        cout<<"Son destroyed"<<endl;
    }
};

struct Daughter{
    shared_ptr<Mother>myMother;
    Daughter(shared_ptr<Mother>m):myMother(m){}
    ~Daughter(){
        cout<<"Daughter gone"<<endl;
    }

};

int main(){
    cout<<endl;
    {
        shared_ptr<Mother>mother=shared_ptr<Mother>(new Mother);
        shared_ptr<Son>son=shared_ptr<Son>(new Son(mother));
        shared_ptr<Daughter>daughter=shared_ptr<Daughter>(new Daughter(mother));
        mother->setSon(son);
        mother->setDaughter(daughter);
    }
    cout<<endl;

}