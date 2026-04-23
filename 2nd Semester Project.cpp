#include <iostream>
#include <windows.h>
using namespace std;

class Package {
protected:
    double weight;
	double distance;
    string sender;
	string receiver;
public:
    Package(double w, double d, string s, string r):weight(w),distance(d),sender(s),receiver(r){}
    
    virtual double cost()=0;
    virtual double time()=0;
    
    void display(){
        cout<<"\n--- Package Details ---\n";
        cout<<"Sender: "<<sender<<endl;
        cout<<"Receiver: "<<receiver<<endl;
        cout<<"Weight: "<<weight<<" kg\n";
        cout<<"Distance: "<<distance<<" km\n";
        cout<<"Delivery Cost: Rs. "<<cost()<<endl;
        cout<<"Estimated Time: "<<time()<<" hours\n";
    }
};

class Standard:public Package{
public:
    using Package::Package;
    
    double cost()override{
		return weight*distance*0.5;
	}
    double time()override{
		return distance/40.0;
	}
};

class Express:public Package{
public:
    using Package::Package;
    
    double cost()override{
		return weight*distance+50;
	}
    double time()override{
		return distance/60.0;
	}
};

int main(){
    double weight;
	double distance;
    string sender;
	string receiver;
	
    int choice;

    cout<<"Enter Sender Name: ";
    getline(cin,sender);

    cout<<"Enter Receiver Name: ";
    getline(cin,receiver);

    cout<<"Enter Package Weight (kg): ";
    cin>>weight;

    cout<<"Enter Distance (km): ";
    cin>>distance;

    cout<<"\nSelect Delivery Type:\n";
    cout<<"1. Standard Delivery (Cheaper, Slower)\n";
    cout<<"2. Express Delivery (Faster, Costlier)\n";
    cout<<"Choice: ";
    cin>>choice;

    Package* pkg;

    if(choice==1){
        pkg=new Standard(weight,distance,sender,receiver);
        cout<<"\n[Standard Delivery Selected]";
    }else{
        pkg=new Express(weight,distance,sender,receiver);
        cout<<"\n[Express Delivery Selected]";
    }

    pkg->display();
    delete pkg;
    return 0;
}