/**********************
* Name: Judy Phan
Assignment: 7 Classes and Objects
Purpose of the file: This file consists of the MyList class, including basic class functionality such as constructors, destructors
accessors, and mutators. Also includes the header file function.h.
**********************/

#include "mylist.h"

MyList::MyList(int length) {
    /* **************************
     * Constructor accepts an index length
     * and sets the length of the index.
     *
     * @param int length
     * @exception none
     * @return void
     ****************************/

    if (length>0){
        this-> length =length;
    }
    else{
        this-> length = RMIN;
    }

    array = new int[this->length];

    this-> setArray(0);

    }

MyList::~MyList() {
   /* **************************
     * Destructor (empty)
     * @param none
     * @exception none
     * @return void
     ****************************/

    delete[] array;
}


void MyList::printArray(){
/* **********************************
 * This function displays the array.
*  @param: na
 * @return (void) : This function does not return a value  
 * @exception na : na
 * @note na
 * **********************************/

    std::cout<<"[";
    for(int i = 0; i < length; i++) {
        std:: cout << array[i];
        if(i< length-1){
            std::cout<<" ";
        }
    }
    std::cout<<"]"<< std:: endl;
 }


int MyList::getLength(){
    /* *************************************************
    Returns the length 
    @param na : na
    @return (int) : length of the array
    @exception na : na
    @note na
    * ************************************************* */
    return length;
}


void MyList::setArray(int num){
    /* *************************************************
    Sets all values of an array to a specific inputted value. 

    @param (int) num : the value to set all the arrays to
    @return na : na
    @exception na : na
    @note na
    * ************************************************* */
    sorted = true;

    for(int i = 0; i < length; i++) {
        array[i] = num;
        }
}

void MyList::setRandom(int min, int max){
    /* *************************************************
   Passes in a min and max value for a random range and 
   set the elements in the array to random numbers from 
   min to max.

    @param (int) min : The minimum range
    @param (int) max : The maximum range
    @return na : na
    @exception na : na
    @note na
    * ************************************************* */
    sorted = false;

    if (max < min){
        int temp =min;
        min=max;
        max=temp;
    }
    else if (max == min || max <0 || min<0) {
        max =RMAX;
        min= RMIN;
    }

    for(int i = 0; i < length; i++) {
        array[i] = rand() % (max - min + 1) + min;
        }

    }

bool MyList:: setElement(int value, int index){
/* **********************************
 Determines if the index is in range. If it is, then it will set the value at that index. 
 * @param (int) value: Value to be set at index
 * @param (int) index: Index of array
 * @return (bool) :  Returns true if the index is within range, or false (and does nothing) if condition is not met. 
 * @exception na : na
 * @note na
 * **********************************/

    if(!getSorted()){
        sorted = false;
    }

    bool valid_nchar = false;  

        if(index != length && index >= 0){
            for(int i = 0; i < length; i++) {
                array[index] = value;
                }
                valid_nchar=true;
            }

    
    return valid_nchar;
}

int MyList:: getElement(int index){
     /* *************************************************
    Passes an index to the method, and returns the integer 
    at that element. If index is out of range, then throws 0
    @param (int) index : Index of array
    @return (int) : Returns element at index if in range, but will throw 0 if out of range
    @exception na : na
    @note na
    * ************************************************* */
    if( index < 0 || index >= length ){
         throw 0;
    }

    return array[index];
}


bool MyList::getElement(int index, int *iptr){
/* **********************************
 Checks to see if provided index is within the range of the array
 * @param (int) index: Index of array
 * @param (int) iptr: A pointer to an integer where the retrieved element will be stored.
 * @return (bool) :  Returns true if the index is within range and false if it is not. 
 * @exception na : na
 * @note na
 * **********************************/
    bool check_num = false;

    if(index >=0 && index < length ){
        *iptr = array[index];
        check_num = true;
    }
    else{
        *iptr=0;
    }
    return check_num;
}

bool MyList:: resizeArray(int *index){
/* **********************************
 Determines if the index is in range. If it is, then it will set the value at that index. 
 * @param (int) index: Index of array
 * @return (bool) :  Returns true if the index is smaller or larger than current size and false if the size is less than 1 or is the same as current. 
 * @exception na : na
 * @note na
 * **********************************/
if(*index > length){
    sorted = false;
}
else{
    sorted=true;
}

bool check = true;
if(*index <= 0 || *index ==length){
    check =false;
}
else{
int* newArray = new int[*index];

    for (int i = 0; i < length; ++i) {
        newArray[i] = array[i];
    }

    if(*index>length){
        for(int i= length; i < *index; i++){
            newArray[i] = 0;
        }
    }

    delete[] array;
    array= newArray;
    length = *index;
}


return check;
} 

void MyList:: swap(int *n1,int *n2){
/* **********************************
 Accepts two integer pointers and swaps the values at those addresses
 * @param (int) n1: A pointer to an integer with a value
 * @param (int) n2: A pointer to an integer with a value
 * @return @return (void) : This function does not return a value 
 * @exception na : na
 * @note na
 * **********************************/
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void MyList:: sort(){
/* **********************************
 Sorts the array ascending from smallest to largest values in array once called upon
 * @param : na
 * @return : na 
 * @exception na : na
 * @note na
 * **********************************/
bool swapped = true;

for(int i=0; i < length -1 && swapped ; i++){
    swapped=false;
    for (int j=0; j<length-i-1;j++){
        if (array[j]>array[j+1]){
            swap(&array[j],&array[j+1]);
            swapped = true;
        }
    }
}
}

bool MyList:: getSorted(){
/* **********************************
 Returns sorted attribute
 * @param : na
 * @return (bool) :  Returns true if array is sorted and false if array is not sorted
 * @exception na : na
 * @note na
 * **********************************/

return sorted;
}


