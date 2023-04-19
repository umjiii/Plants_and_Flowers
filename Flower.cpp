/*
Author(s): Stephen Arel & Professor Neibarger
Class: CSC240
Assignment: Lab 6 - STL
Description: This program utilizes and displays the use of polymorphism, inheritance, and STL. This program uses a vector
    containing Plant objects (and due to polymorphism, Flower objects as well) and performing different operations with
    these objects' values (some of which Flower values are inherited from the Plant class). Simple sorting algorithms are
    also utilized to sort the vector based on the desired order of certain values.
*/

#include "Flower.h"
#include <string>
#include <iostream>
#include <iomanip>

//constructor
Flower::Flower(string plantName, double plantCost, string flowerColor, bool flowerType) : Plant(plantName, plantCost)
{
    color = flowerColor;
    if (flowerType == true)
        annualStat = "annual";
    else
        annualStat = "perennial";

}

//------functions------
ostream& Flower::display(ostream& out)
{
    out << (*this);
    return out;
}

ostream& operator << (ostream& out, const Flower& f)
{
    out << left << (Plant)f << left << "   " << f.color << "   " << f.annualStat;
}