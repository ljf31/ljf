#include <iostream>
using namespace std;

class Target{
public:
    virtual void request(){
        cout << "this is client require request" << endl;
    }
};

class Adaptee{
public:
    void specialRequest(){
        cout << "this is what i have, need to adapte" << endl;
    }
};

class Adapter:public Target
{
public:
    Adapter(){
        adaptee = new Adaptee();
    }
    ~Adapter(){
        delete adaptee;
    }
    void request(){
        //do something to adapte
        adaptee->specialRequest();
    }
private:
    Adaptee* adaptee;

};

int main()
{
    Target* target = new Adapter();
    target->request();
    delete target;

    return 0;
}
