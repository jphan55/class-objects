/**********************
* Name: Judy Phan
Assignment: 7 Classes and Objects
Purpose of the file: This file contains the declaration of the MyList class, including basic class functionality such as constructors, destructors
accessors, and mutators
**********************/

#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>     /* cout, endl */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


#define RMIN 1
#define RMAX 10

class MyList {
    /************************************** 
        This class defines a MyList. It must be passed
        an initial size which defaults to 1 if an invalid
        value is passed (negative number or zero).

        @attrib (int) length : the size of the list
        @attrib (int) array : the array of the list
    ***************************************/

public:
    
    /**********************
    Constructors/Destructor
    ***********************/
    MyList(int);
    ~MyList();


    /**********************
    Getters/Accessors
    ***********************/
    int getLength();
    int getElement(int);
    bool getElement(int, int*);
    bool getSorted();

    /**********************
    Setters/Mutators
    ***********************/
    void setArray(int);
    void setRandom(int, int);
    bool setElement(int,int);
    bool resizeArray(int*);
    void sort();
    void swap(int*,int*);

   
   /**********************
    Display Method
    ***********************/
    void printArray();
    

     
private:
    int length;
    int *array;
    bool sorted;

};

#endif //MYLIST_H
