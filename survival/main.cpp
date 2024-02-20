#include <iostream>
#include <sstream>
#include <time.h>

using namespace std;

class Player {
    public:
    Player(int x, int y){
        health = MAX_HEALTH;
        hunger = MAX_HUNGER;
        thirst = MAX_THIRST;
        
        this->x = x;
        this->y = y;
        this->score = 0;
    }
    
    int getScore() const {
        return score;
    }
    
    void takeDamage(int val){
        this->health -= val;
        if(this->health < 0) this->health = 0;
    }
    
    void increaseHealth(int val){
        this->health += val;
        if(this->health > MAX_HEALTH) this->health = MAX_HEALTH;
    }
    
    void takeTurn(){
        this->thirst--;
        this->hunger--;
        
        if(this->thirst <= 0){
            this->health--;
            this->thirst = 0;
        }
        
        if(this->hunger <= 0){
            this->health--;
            this->hunger = 0;
        }
        
        this->score++;
    }
    
    string getStats() const {
        stringstream ss;
        ss  << "============\n"
            << "Health: " << this->health << "\n" 
            << "Hunger: " << this->hunger << "\n" 
            << "Thirst: " << this->thirst << "\n"
            << "============\n";
        return ss.str();
    }
    
    bool isAlive() const {
        return this->health > 0;
    }
    
    void increaseThrist(int val){
        this->thirst += val;
        if(this->thirst > MAX_THIRST) this->thirst = MAX_THIRST;
    }
    
    void increaseHunger(int val){
        this->hunger += val;
        if(this->hunger > MAX_HUNGER) this->hunger = MAX_HUNGER;
    }
    
    int x, y;
    private:
    int health, hunger, thirst, score;
    const int MAX_HEALTH = 3;
    const int MAX_HUNGER = 5;
    const int MAX_THIRST = 3;
};

class Land {
    public:
    virtual string getDescription() = 0;
    virtual string visit(Player& player) = 0;
};

// TODO: Define at least 3 more types of derivded land types
// TODO: Add some unique effect to each new type



class Forest : public Land {
    public:
    string getDescription(){
        return "a densely wooded forest.";
    }
    
    string visit(Player& player){
        int randomNum = rand() % 100;
        
        if(randomNum > 74){
            player.takeDamage(1);
            return "You are attacked by a bear while foraging for berries.";
        } else {
            player.increaseHunger(1);
            return "You forage for berries in the woods and eat a few.";
        }
    }
};

class Lake : public Land {
    public:
    string getDescription(){
        return "a clear sparkling lake.";
    }
    
    string visit(Player& player){
        player.increaseThrist(2);
        return "You visit the lake and drink its clean water";
    }
};

class Laboratory : public Land {
    public:
    string getDescription(){
        return "Dr. Shue's Laboratory. ";
    }
    string visit(Player& player){
        int randomNum = rand() % 10;
        
        if(randomNum < 6){
            player.takeDamage(1);
            return "Dr. Shue uses your body for intense experimental robotics research. ";
        }else{
            player.increaseHunger(1);
            player.increaseHealth(1);
            return "Dr. Shue invites you into the Laboratory for a very enticing conversation with lunch. ";
        }
    }
};

class Farm : public Land {
    public:
    string getDescription(){
        return "Dr.Sass' Apple picking farm. ";
    }
    
    string visit(Player& player){
        int randomNum = rand() % 100;
        if(randomNum == 42){
            player.increaseHunger(2);
            player.increaseThrist(2);
            player.increaseHealth(2);
            return "You picked Dr. Sass' favorite apple. ";
        }else{
        player.takeDamage(1);
        return "You picked a bad, rotten, fruitless apple. ";
        }
    }
};

class City : public Land {
    public:
    string getDescription(){
        return "Great City of New York. ";
    }
    
    string visit(Player& player){
         int randomNum = rand() % 2;
         if(randomNum == 1){
             player.takeDamage(1);
             return "You got pickpocketed. You lose not only your wallet but your dignity (you're lost). ";
         }else{
             player.increaseHealth(1);
             player.increaseThrist(1);
             return "You enjoyed the view (you're exhausted). ";
         }
    }
};

class University : public Land {
    public:
    string getDescription(){
        return "An amazing university .  ";
    }
    
    string visit(Player& player){
         int randomNum = rand() % 2;
         if(randomNum == 1){
             player.takeDamage(1);
             return "You got attacked by a hazing Fraternity ";
         }else{
             player.increaseHunger(1);
             player.increaseHealth(1);
             player.increaseThrist(1);
             return "You stumbled apon a cafeteria with average food. ";
         }
    }
};

class Arcade : public Land {
    public:
    string getDescription(){
        return "An obscure space full of videogames and dance dance revolution. ";
    }
    
    string visit(Player& player){
         int randomNum = rand() % 2;
         if(randomNum == 1){
             player.takeDamage(1);
             return "You are challened to dance dance revolution and lose. (Your ego is hurt) ";
         }else{
             player.increaseHealth(1);
             player.increaseThrist(1);
             return "You surprisingly high scored every game with no breaks.  ";
         }
    }
};

 class Kitchen : public Land {
    public:
    string getDescription(){
        return "A great spacious kitchen with alot of ingredients. ";
    }
    
    string visit(Player& player){
         int randomNum = rand() % 2;
         if(randomNum == 1){
             player.takeDamage(1);
             return "You are careless, you not only cut but also burned yourself ";
         }else{
             player.increaseHealth(2);
             player.increaseThrist(1);
             return "You managed to make an amazing dish along with a thirst quenching beverage. ";
         }
    }
};

class Gym : public Land {
    public:
    string getDescription(){
        return "A mystical gym with an obscure odor. ";
    }
    
    string visit(Player& player){
         int randomNum = rand() % 2;
         if(randomNum == 1){
             player.takeDamage(1);
             player.increaseHealth(1);
             return "You are persuaded to work out with gym bros but can't feel a single muscle. ";
         }else{
             player.increaseHunger(1);
             player.increaseHealth(1);
             return "You trained with the gym trainer who worked you in good form. (you feel empowered)";
         }
    }
};

class Concert : public Land {
    public:
    string getDescription(){
        return "You found a rave with bright lights and loud music. ";
    }
    
    string visit(Player& player){
         int randomNum = rand() % 20;
         if(randomNum == 10){
             player.takeDamage(2);
             return "You staged dived. (Nobody caught you) ";
         }else{
             player.increaseThrist(2);
             player.increaseHealth(1);
             return "You enjoyed concert, stayed well hydrated, ate something called (Sassy Apple). ";
         }
    }
};

const int MAP_SIZE = 10;
Land* map[MAP_SIZE][MAP_SIZE];

void populateMap(){
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            // TODO: Modify this code to add your new land types
            int randomNum = rand() % 9;
            switch(randomNum){
                case 0: // Forest
                    map[i][j] = new Forest;
                    break;
                case 1: // Lake
                    map[i][j] = new Lake;
                    break;
                //case 2: 
                case 2: //Laboratory
                    map[i][j] = new Laboratory;
                    break;
                case 3: //farm
                    map[i][j] = new Farm;
                    break;
                case 4: //city
                    map[i][j] = new City;
                    break;
                case 5: //University
                    map[i][j] = new University;
                    break;
                case 6: //Arcade
                    map[i][j] = new Arcade;
                    break;
                case 7: //Kithcen
                    map[i][j] = new Kitchen;
                    break;
                case 8: //Gym 
                    map[i][j] = new Gym;
                    break;
                case 9: //concert
                    map[i][j] = new Concert;
                    break;
                default:
                    cout << "Invalid land type selected" << endl;
                    break;
            }
        }
    }
}

int main(){
    srand(time(0));
    
    populateMap();
    
    Player player(MAP_SIZE/2, MAP_SIZE/2);
    
    cout << "You wake up and find yourself lost in the middle of a strange wilderness." << endl;
    
    // TODO: Handle boundary conditions (e.g., if index out of bounds north, you index the south-most location)
    player.x = 1;
    player.y = 1;
    while(player.isAlive()){
        if(player.y == 9){ player.y = 1; } //out of bounds for north 
        if(player.x == 0){ player.x = 8; } //out of bounds for south
        if(player.x == 9){ player.x = 1; } //out of bounds for east
        if(player.y == 0){ player.y = 8; } //out of bounds for west 
        
        cout<<player.x<<endl;
        cout<<player.y<<endl;
        
        
        cout << "To the north you see " << map[player.x][player.y - 1]->getDescription() << endl;
        cout << "To the east you see " << map[player.x + 1][player.y]->getDescription() << endl;
        cout << "To the south you see " << map[player.x][player.y + 1]->getDescription() << endl;
        cout << "To the west you see " << map[player.x - 1][player.y]->getDescription() << endl;
        
        cout << "Which way will you go? Enter N, E, S, or W:" << endl;
        char userInput;
        cin >> userInput;
        
        switch(userInput){
            case 'N':
                player.y = player.y - 1;
                break;
            case 'E':
                player.x = player.x + 1;
                break;
            case 'S':
                player.y = player.y + 1;
                break;
            case 'W':
                player.x = player.x - 1;
                break;
            default:
                break;
        }
        
        cout << map[player.x][player.y]->visit(player) << endl;
        
        cout << player.getStats() << endl;
        player.takeTurn();
        
        
    }
    
    cout << "You died." << endl;
    cout << player.getScore() << endl;
    
    return 0;
}