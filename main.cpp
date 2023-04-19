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
#include "Flower.h"

#include <stdio.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

vector<Plant*> garden;
vector<Plant*>::iterator gardenPtr;

//------compare functions (sort)------
//sort by name
bool nameSorter(Plant* first, Plant* second)
{
    string firstName = first->getName();
    string secondName = second->getName();

    //make both names the same case so they are compared evenly
    transform(firstName.begin(), firstName.end(), firstName.begin(), ::toupper);
    transform(secondName.begin(), secondName.end(), secondName.begin(), ::toupper);

    //compare by ASCII values
    return firstName < secondName;
}

//sort by cost
bool costSorter(Plant* first, Plant* second)
{
    if (first->getCost() < second->getCost())
        return true;
    else
        return false;
}


//------prototype functions------
void addPlant(char objType, string objName, double objCost, string objColor, bool annual);
void removePlant(Plant* p);
ostream& display(ostream& out);
double totalCost();
void sortName();
void sortCost();

//------variables------
//menu variables
char again = 'Y';
int option;
bool tempBool = false;
double total;

//entered object parameters as variables
char objType;
string objName;
double objCost;
string objColor;
char annual;
bool annualBool = false;


int main()
{
    do{
        cout << "*===================================*\n";
        cout << "***MY GARDEN MENU***\n\t"
                     "1. Add a new plant\n\t"
                     "2. Remove a plant\n\t"
                     "3. Display plants\n\t"
                     "4. Total cost\n\t"
                     "5. Sort by plant name\n\t"
                     "6. Sort by plant cost\n\t"
                     "7. Quit"
                     "\n\nEnter your selection: ";

        //input for menu option
        cin >> option;

        switch (option) {
            case 1:
                //get parameters for plant
                cout << "Enter plant type ('P' - plant, 'F' - flower): ";
                cin >> objType;

                cout << "\nEnter plant name: ";
                cin >> objName;

                cout << "\nEnter plant cost: $";
                cin >> objCost;

                if (objType == 'F' || objType == 'f') //if adding a flower, get flower parameters
                {
                    cout << "\nEnter flower color: ";
                    cin >> objColor;

                    cout << "\nEnter if flower is an annual (Y/N)? ";
                    cin >> annual;

                    if (annual == 'Y' || annual == 'y')
                        annualBool = true;

                }

                //add plant with given parameter values
                addPlant(objType, objName, objCost, objColor, annualBool);

                break;

            case 2:
                cout << "Enter plant name to remove: ";
                cin >> objName;

                //iterate through garden to make sure this name exists
                for(gardenPtr = garden.begin(); gardenPtr != garden.end(); gardenPtr++)
                {
                    if((**gardenPtr).getName() == objName)
                    {
                        tempBool = true; //it is true that this name exists in the garden
                        break;
                    }

                }

                if (tempBool == true) //if the plant name exists,  remove it
                {
                    removePlant(*gardenPtr);
                    cout << objName << " was removed from the garden.\n";
                }
                else
                    cout << "ERROR - " << objName << " is not in the garden.\n";

                break;

            case 3:
                display(cout);
                break;

            case 4:
                total = totalCost();
                cout << "The total cost of all plants and flowers is $" << total << ".\n";
                break;

            case 5:
                sortName();
                display(cout);
                break;

            case 6:
                sortCost();
                display(cout);
                break;

            case 7:
                again = 'n';
                exit(0);

            default:
                cout << "ERROR - Invalid selection.\n";
                break;
        } //end switch

    }while (again == 'Y' || again == 'y');

    return 0;
}

//------functions------
void addPlant(char objType, string objName, double objCost, string objColor, bool annual)
{
    if (objType == 'F' || objType == 'f') //if the added plant is a flower
    {
        Flower* newFlower = new Flower(objName, objCost, objColor, annual);
        garden.push_back(newFlower);
    }
    else
    {
        Plant* newPlant = new Plant(objName, objCost);
        garden.push_back(newPlant);
    }
}

void removePlant(Plant* p)
{
    string namey = p->getName();

    for(gardenPtr = garden.begin(); gardenPtr != garden.end(); gardenPtr++) //find the desired plant
    {
        if ((**gardenPtr).getName() == namey) {
            break;
        }
    }
    garden.erase(gardenPtr); //remove the plant from the garden vector

}

ostream& display(ostream& out)
{
    int count = 1;
    for(gardenPtr = garden.begin(); gardenPtr != garden.end(); gardenPtr++)
    {
        cout << "\nPlant " << count << ": ";
        (**gardenPtr).display(out);
        count++;
    }
    cout << "\n";
    return out;
}

double totalCost()
{
    double total = 0;
    for(gardenPtr = garden.begin(); gardenPtr != garden.end(); gardenPtr++)
    {
        total += (*gardenPtr)->getCost();
    }

    return total;
}

void sortName()
{
    sort(garden.begin(), garden.end(), nameSorter);
}

void sortCost()
{
    sort(garden.begin(), garden.end(), costSorter);
}
