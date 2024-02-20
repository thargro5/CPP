#include <iostream>
#include <vector> 


using namespace std;

class employee {
    private:
    string empNames;
    double wages;
    
    public:
    double pay;
    string empTitles;
    
    void addWage(double wage){
        wages = wage;
    }
   
    
    void names(string n){
        empNames = n;
    }
    
    string getName() const{
        return empNames;
    }
    
  
    double getWages() const{
        return wages;
    }
    
    void title(string t){
        empTitles = t;
    }
    
    string getTitles() const{
        return empTitles;
    }
    
};

int main(){
    string choice;
    int choice2;
   vector<employee> database;
   
   employee e0;
   e0.names("Ethan Hunt");
   e0.title("Head Custodial Assistant");
   e0.addWage(11.79);
   
   employee e1;
   e1.names("James Bond");
   e1.title("Precision Eye Docotr");
   e1.addWage(63.11);
   
   employee e2;
   e2.names("Jason Bourne");
   e2.title("Reclusie History Professor");
   e2.addWage(18.86);
   
   employee e3;
   e3.names("Logan Davis");
   e3.title("Executive Hall Monitor");
   e3.addWage(69.69);
   
   employee e4;
   e4.names("Sam Shue");
   e4.title("Chief Untenured Professor");
   e4.addWage(98.14);
   
   employee e5;
   e5.names("Steve Jobs");
   e5.title("Personal Antagonist");
   e5.addWage(54);
  
   database.push_back(e0);
   database.push_back(e1);
   database.push_back(e2);
   database.push_back(e3);
   database.push_back(e4);
   database.push_back(e5);
   
   cout <<"I am the almighty employee database please select your operation"<<endl;
   cout <<"1) print list of employees"<<endl;
   cout <<"2) Calculate total wages"<<endl;
   cout <<"3) exit the application"<<endl;
   
   cin >> choice;
   choice2 = atoi(choice.c_str());
   while(choice2 == 0|| choice2>3){
       
       cout<<"select a valid input!!"<<endl;
       cin >> choice;
       choice2 = atoi(choice.c_str());
   }
   switch(choice2){
       case 1:
   for(int i = 0; i < database.size(); i++){
        employee e = database.at(i);
        cout << e.getName() << endl;
        cout << e.getTitles() << endl;
        cout << e.getWages() << endl;
        cout << endl;
    }
    break;
   case 2:
   int hours;
   int multi;
   int total;
   
   for(int i = 0; i <database.size(); i++){
       employee e = database.at(i);
       cout << e.getName() << endl;
       cout<<"how many hours for the week"<<endl;
       cin>>hours;
       multi = hours*e.getWages();
       cout<<multi<<" total"<<endl;
       
   } 
   
   case 3:
       break;
   }
   
    
    return 0;
}
