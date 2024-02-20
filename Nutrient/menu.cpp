
#include "menu.h"

using namespace std;

menu::menu(string snack, double calories, double fat, double sugar, double protein, double sodium){
    this->calories = calories;
    this->fat = fat;
    this->sugar = sugar;
    this->protein = protein;
    this->sodium = sodium; 
}

void menu::snackName(string s){
    snack = s;
}
void menu::setCalories(double e){
    calories = e;
}
void menu::setFat(double f){
    fat = f;
}
void menu::setSugar(double su){
    sugar = su;
}
void menu::setProtein(double p){
    protein = p;
}
void menu::setSodium(double sod){
    sodium = sod;
}
double menu::getCalories() const{
    return calories;
}
double menu::getFat() const{
    return fat;
}
double menu::getSugar() const{
    return sugar;
}
double menu::getProtein() const{
    return protein;
}
double menu::getSodium() const{
    return sodium;
}
string menu::getSnack(){
    return snack;
}

menu menu::operator+(const menu& v){
    menu sum("",0.0, 0.0, 0.0, 0.0, 0.0);
    //menu sum.snack("");
    //menu sum.calories(0.0);
    //menu sum.fat(0.0); 
    //menu sum.protein(0.0);
    //menu sum.sugar(0.0);
    //menu sum.sodium(0.0);

    sum.calories = calories + v.calories;
    sum.fat = fat + v.fat;
    sum.sugar = sugar + v.sugar;
    sum.protein = protein + v.protein;
    sum.sodium = sodium + v.sodium;
    return sum;
}