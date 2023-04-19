/*
Author(s): Stephen Arel & Professor Neibarger
Class: CSC240
Assignment: Lab 6 - STL
Description: This program utilizes and displays the use of polymorphism, inheritance, and STL. This program uses a vector
    containing Plant objects (and due to polymorphism, Flower objects as well) and performing different operations with
    these objects' values (some of which Flower values are inherited from the Plant class). Simple sorting algorithms are
    also utilized to sort the vector based on the desired order of certain values.
*/

#include "Plant.h"
#include <iomanip>

using namespace std;

//------constructors------
//default constructor
Plant::Plant(string plantName, double plantCost)
{
    name = plantName;
    cost = plantCost;
}

//------functions------
string Plant::getName()
{
    return name;
}

double Plant::getCost()
{
    return cost;
}

bool Plant::operator == (const string pName)
{
    return name == pName;
}

ostream& Plant::display(ostream& out)
{
    out << (*this);
    return out;
}

ostream& operator << (ostream& out, const Plant& p)
{
    out << left << setw(20) << p.name << "   $" << right << setw(6) << fixed << setprecision(2) << p.cost;
    return out;
}