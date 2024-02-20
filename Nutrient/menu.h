#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
using namespace std;

class menu {
    private:
    string snack;
    double calories;
    double fat;
    double sugar;
    double protein;
    double sodium; 
    
    public:
    
void snackName(string s){
    snack = s;
}
void setCalories(double e){
    calories = e;
}
void setFat(double f){
    fat = f;
}
void setSugar(double su){
    sugar = su;
}
void setProtein(double p){
    protein = p;
}
void setSodium(double sod){
    sodium = sod;
}
double getCalories() const{
    return calories;
}
double getFat() const{
    return fat;
}
double getSugar() const{
    return sugar;
}
double getProtein() const{
    return protein;
}
double getSodium() const{
    return sodium;
}
string getSnack(){
    return snack;
}
    
    menu operator+(const menu&) const;

   menu(string snack, double calories, double fat, double sugar, double protein, double sodium){
    this->snack = snack;
    this->calories = calories;
    this->fat = fat;
    this->sugar = sugar;
    this->protein = protein;
    this->sodium = sodium; 
}
   menu operator+(const menu& v){
    menu sum("",0.0, 0.0, 0.0, 0.0, 0.0);

    sum.calories = calories + v.calories;
    sum.fat = fat + v.fat;
    sum.sugar = sugar + v.sugar;
    sum.protein = protein + v.protein;
    sum.sodium = sodium + v.sodium;
    return sum;
} 
};

#endif