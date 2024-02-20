#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;
const int radius = 3958.8;
const int jet = 575;

    //vectors 
   //vector of names for the cords 
   vector <string>names(
         {"South San Francsico, CA, USA ", "Delray Beach, FL, USA ", "New Castle, DE, USA ", "Roswell, NM, USA ", "West Haven, CT, USA ", 
            "Belle Glade, FL, USA ", "Atlantic City, NJ, USA ", "Albany, GA, USA ", "Idaho City, ID, USA ", "Walsenburg, CO, USA "});
    //vector of latitude cords
    vector <double> latitude(
        {37.662937, 26.459763, 39.668564, 33.400322, 41.275898, 26.687412, 39.370121, 31.594915, 43.828850, 37.630322});
    //vector of longitude cords 
    vector <double> longitude(
        {-122.433014, -80.105545, -75.586189, -104.534897, -72.975739, -80.681831, -74.438942, -84.224236, -115.837860, -104.790543});
   
   
    
    double getFlightTime(double lat1, double long1, double lat2, double long2);
    
    double haversine(double lat1, double long1, double lat2, double long2, double radius);
    
   int main(){
       int k;
       string start;
       int inputStart;
       //intro 
       cout << "I can transcend the planet calculating distances and flight time! " <<endl;
       for (k=1; k < 11; ++k){
           cout<< k << ") "<<names.at(k-1)<<latitude.at(k-1)<< " " <<longitude.at(k-1)<<endl;
       }
       cout << "Please Choose a departure to start 1-10?" << endl;
       
       cin >> start; 
       inputStart = atoi(start.c_str());
       while(inputStart == 0|| inputStart>10){
           
           cout<< "Select a valid input?! (1-10) " << endl;
           cin>>start;
           inputStart = atoi(start.c_str());
    }
        cout << "You has chosen "<< names.at(inputStart-1) << endl;
       
       string inputEnd;
       int end;
       int e;
       int c;
       c=1;
       
       for (e=1; e < 11; ++e){
           
           if(e == inputStart){
               
           }else{
                cout << c << ") "<<names.at(e-1)<<latitude.at(e-1)<< " " <<longitude.at(e-1)<<endl;
                c++;
           }
      }
       cout << "Where is your destination?"<<endl;
       cin >> inputEnd;
       end = atoi(inputEnd.c_str());
       while(end == 0|| end>9){
           cout<< "Choose between 1-9! "<<endl;
           cin>>inputEnd;
           end = atoi(inputEnd.c_str());
       }
      
       cout<<"The desitination is "<<names.at(end-1)<<endl;
       
       haversine(latitude.at(inputStart-1), longitude.at(inputStart-1), latitude.at(end-1), longitude.at(end-1), radius);
       //flight time calculator 
       getFlightTime(latitude.at(inputStart-1), longitude.at(inputStart-1), latitude.at(end-1), longitude.at(end-1));
       
      return 0;
   }
   
   
    double haversine(double lat1, double long1, double lat2, double long2, double radius){
        double dist;
    //dist is the distance
    dist = 2*radius*asin(sqrt(pow(sin((lat2-lat1)/2),2) + (cos(lat1) * cos(lat2) * pow(sin((long2-long1)/2),2))));

    return dist;
    }
    
  double getFlightTime(double lat1, double long1, double lat2, double long2){
      double speed;
      double dist;
    dist = haversine(lat1, long1, lat2, long2, radius);
      //jet moving at 575 mph 
      speed = dist/jet;
      cout <<"Traveling distance is approx " <<endl;
      cout<< dist<<" ~miles~"<<endl;
      cout <<"Traveling time is approx"<<endl;
      cout<<speed<<" ~hours~"<<endl;
      return speed;
  }
   
   
    
    
