#include <iostream>
#include <vector>
using namespace std;

class fraction{
    private:
    double numerator;
    double denominator; 
    
    public:
    void setNumer(int a){
        numerator = a;
    }
    
    void setDenom(int b){
        if(b!=0){
            denominator = b;
        }
    }
    double getNumer()const{
        return numerator;
    }
    double getDenom()const{
        return denominator;
    }
    double getDecimal()const{
        double total;
        total = numerator / denominator ;
        return total;
    }
};

int main(){
    vector<fraction> number;
    
    fraction n0;
   n0.setNumer(3);
   n0.setDenom(5);

    number.push_back(n0);
    fraction n = number.at(0);
   cout<<n.getDecimal()<<endl;
    int x = 2;
    int* p = &x;
    cout<<*p<<endl;
    *p = 11;
    cout<<x<<endl;
    //return 0;

//int listarray[];
int listarray[4] = {22, 45, 77};
int usernum;
int a;
cin >> a;
while(a>20){
    for(int index = 0; index<3; index++){
        usernum = listarray[index];
    //cout<<usernum<<endl;
    
        if(a==usernum){
            cout<<index+1<<endl;
            cin >> a;
        }
        
    }
}
return 0;
}