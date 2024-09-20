#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;
//1. generate events 
//2. create master queue 
//3. store events in maser queue 
// Event structure
class Event {
public:
    time_t t; // Time when the event will be executed
    int v;    // Value associated with the event
    //constructor incoming
    Event(int time, int value) : t(time) v(value){}
    //t(time) initializes variabke when object is created :<
    bool operator<(const Event &other) const {
        return t < other.t;
    }
};
    //operator overload needed for comparing the time of events, normal operator will not know whats actually "less than" in an object
void theEventanator(vector<Event>& MEQ,  int eventNum){// generate and inserts events (event+generator)
    for(int i = 0, i < eventNum, i++){
        //random time and integer from 1 to 100
        int randTime = rand() % 100+1; 
        int randInt = rand () % 100+1;

        Event nxtEvent(randTime, randInt);
        MEQ.push_back(nxtEvent);
         
    }
    sort(MEQ.begin(), MEQ.end())//stores based on increasing order using less than operation


}

void print(const vector<Events>& MEQ){
    for(const auto& event : MEQ){
        cout << "time: " << event.t << "; value: "<< event.v <<endl;
    }
    
}


int main(){
    srand(time(0));

    vector<Events> MEQ;

    theEventanator(MEQ, 20);

    print(MEQ);

    return 0;
}