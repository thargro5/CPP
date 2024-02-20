#include "menu.h"
#include <vector>

using namespace std;


int main(){
    
    menu sum("",0.0, 0.0, 0.0, 0.0, 0.0);
    vector<menu> food;
    vector<menu> selected;
    //push the food back into selected;
    string choice;
    int choice2;
    
    menu n0("Red Apple", 10.1, 4.5, 11.4, 4.1,0.99);

    menu n1("Green Apple", 18.1, 9.5, 1.4, 6.9, 1.99);

    menu n2("Yellow Apple", 0.1, 0.5, 0.4, 0.1, 0.9);
 
    menu n3("Blue Apple", 100.1, 34.5,  19.4, 44.1, 12.9);

    menu n4("Black Apple", 999, 999, 999, 999, 999);
    
    menu n5("Blue Apple", 156.1, 0.5, 123.4, 66.1, 77.9);
    
    menu n6("Purple Apple", 47.8, 77.5, 5.4, 0.1, 8.49);
    
    menu n7("White Apple", 777, 777, 777, 777, 777);
    
    menu n8("Orange Apple", 34.1, 45.5, 116.4, 43.1, 75.2);
    
    menu n9("Brown Apple", 100.1, 400.5, 110.4, 400.1, 0.99);
    
    food.push_back(n0);
    food.push_back(n1);
    food.push_back(n2);
    food.push_back(n3);
    food.push_back(n4);
    food.push_back(n5);
    food.push_back(n6);
    food.push_back(n7);
    food.push_back(n8);
    food.push_back(n9);
    
    cout<<"I am the almighty nutritionist. I will judge you harshly!"<<endl;
    cout<<"Choose your apple?"<<endl;
    
    for(int i = 0; i < food.size(); i++){
        menu n = food.at(i);
        
        cout <<i+1<<": "<< n.getSnack() << endl;
       
    }
    cout<<11<<": "<<"Finished"<<endl;
    cin >> choice;
    choice2 = atoi(choice.c_str());
    while(choice2!=11){
       switch(choice2){
        case 0:  
       cout<<"select a valid input!!"<<endl;
       cin >> choice;
       choice2 = atoi(choice.c_str());
       break; 
       case 1:
       
       selected.push_back(n0);
       break;
       
       case 2:
       
       selected.push_back(n1);
       break;
       case 3:
       
       selected.push_back(n2);
       break;
       
       case 4:
       
       selected.push_back(n3);
       break;
       case 5:
       
       selected.push_back(n4);
       break;
       case 6:
       
       selected.push_back(n5);
       break;
       case 7:
       
       selected.push_back(n6);
       break;
       case 8:
       
       selected.push_back(n7);
       break;
       case 9:
       
       selected.push_back(n8);
       break;
       case 10:
       
       selected.push_back(n9);
       }
       
       //iterates throught the options again
       for(int i = 0; i < food.size(); i++){
        menu n = food.at(i);
        cout <<i+1<<": "<< n.getSnack() << endl;
    }
    cout<<11<<": "<<"Finished"<<endl;
    cin >> choice;
    choice2 = atoi(choice.c_str());
   }
    //use choice2 for input 
    for(int i = 0; i < selected.size(); i++){
        sum = sum + selected.at(i);
    }
    
    cout <<"Calories:"<<sum.getCalories()<<endl;
    cout <<"Fat(g)"<<sum.getFat()<<endl;
    cout <<"Sugars(g)"<<sum.getSugar()<<endl;
    cout <<"Protein(g)"<<sum.getProtein()<<endl;
    cout <<"Sodium(mg)"<<sum.getSodium()<<endl;

    return 0;
}