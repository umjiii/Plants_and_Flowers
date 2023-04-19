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
#include <string>
#include <iostream>

#ifndef UNTITLED_FLOWER_H
#define UNTITLED_FLOWER_H


class Flower : public Plant
        {
        private :
            string color;
            string annualStat; //used for perennial/annual

        public:
            //------constructors------
            Flower(string plantName, double plantCost, string flowerColor, bool flowerType);

            //------functions------
            virtual ostream& display(ostream& out);
            friend ostream& operator << (ostream& out, const Flower& f);
};


#endif //UNTITLED_FLOWER_H
