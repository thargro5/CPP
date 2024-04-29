#include <iostream>

using namespace std;

int main(){
    int x = 0;
    
    char answer;
    while(x==0){
        cout<<"Stocks are very high do you choose to invest? [y,n]"<<endl;
        cin>>answer;
        if(answer == 'y'){cout<<"good"<<endl; x = 1;}
        
    }
    return 0;
}