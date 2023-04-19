/*
Author(s): Stephen Arel & Professor Neibarger
Class: CSC240
Assignment: Lab 6 - STL
Description: This program utilizes and displays the use of polymorphism, inheritance, and STL. This program uses a vector
    containing Plant objects (and due to polymorphism, Flower objects as well) and performing different operations with
    these objects' values (some of which Flower values are inherited from the Plant class). Simple sorting algorithms are
    also utilized to sort the vector based on the desired order of certain values.
*/

#include <string>
#include <iostream>
using namespace std;

#ifndef PLANT_H;
#define PLANT_H;

class Plant
        {
        private:
            string name;
            double cost;

        public:
            //------constructors------
            Plant(string plantName, double plantCost);

            //------functions------
            string getName();
            double getCost();
            bool operator == (string pName);

            virtual ostream& display(ostream& out);
            friend ostream& operator << (ostream& out, const Plant& p);
};

#endif //UNTITLED_PLANT_H
