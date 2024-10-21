/**********************
* Name: Judy Phan
Assignment: 7 Classes and Objects
Purpose of the file:  Execution of code begins at this file. This file includes main.h. 
**********************/

#include "main.h"

int main() {
/* **********************************
 * This function is the application driver. It uses opens files and calls for the class 'MyList' 

 * @param na:
 * @return (int) : application exit code
 * @exception na : na
 * @note: na
 * **********************************/

    srand(time(NULL));  

    /*Creates a list of size LISTSIZE and initialize all to zero*/
    cout << "create and initialize mylist" << endl;
    MyList mylist(LISTSIZE);
    mylist.printArray();
    cout << "The length of the array is: " << mylist.getLength() << endl;
    cout << endl;

    /* This will set the list to all 50 */
    cout << "set mylist to all 50" << endl;
    mylist.setArray(50);
    mylist.printArray();

    //Determines whether array is sorted or not and sorts if it is not
    cout<<"Is the array sorted in order of ascending?"<< endl;
    if(!mylist.getSorted()){
        cout<<"No it is not sorted." << endl;
        cout<< "Sorting Now..."<< endl;;
        mylist.sort();
        mylist.printArray();
    }
    else{
        cout<< "Yes, it is correctly sorted!"<< endl;
    }
    
    cout<<endl;
    /* This will fail and set the array to the
     * default random 1-10 values */
    cout << "attempt to set to random numbers -2 to 4" << endl;
    mylist.setRandom(-2,4);
    mylist.printArray();

    //Determines whether array is sorted or not and sorts if it is not
    cout<<"Is the array sorted in order of ascending?"<< endl;
    if(!mylist.getSorted()){
        cout<<"No it is not sorted." << endl;
        cout<< "Sorting Now..."<< endl;;
        mylist.sort();
        mylist.printArray();
    }
    else{
        cout<< "Yes, it is correctly sorted!"<< endl;
    }

    /* This will fail and set the array to the
     * default random 1-10 values */
    cout << endl;
    cout << "attempt to set to random numbers 4 to 4" << endl;
    mylist.setRandom(4,4);
    mylist.printArray();

    //Determines whether array is sorted or not and sorts if it is not
    cout<<"Is the array sorted in order of ascending?"<< endl;
    if(!mylist.getSorted()){
        cout<<"No it is not sorted." << endl;
        cout<< "Sorting Now..."<< endl;;
        mylist.sort();
        mylist.printArray();
    }
    else{
        cout<< "Yes, it is correctly sorted!"<< endl;
    }

    /* This will succeed and set the array to the
     * random 1-100 values */
    cout << endl;
    cout << "attempt to set to random numbers 1 to 100" << endl;
    mylist.setRandom(1,100);
    mylist.printArray();

   //Determines whether array is sorted or not and sorts if it is not
    cout<<"Is the array sorted in order of ascending?"<< endl;
    if(!mylist.getSorted()){
        cout<<"No it is not sorted." << endl;
        cout<< "Sorting Now..."<< endl;;
        mylist.sort();
        mylist.printArray();
    }
    else{
        cout<< "Yes, it is correctly sorted!"<< endl;
    }

    /* This will succeed and set the array to the
     * random 500-1000 values */
    cout << endl;
    cout << "attempt to set to random numbers 500 to 1000" << endl;
    mylist.setRandom(1000,500);
    mylist.printArray();

    //Determines whether array is sorted or not and sorts if it is not
    cout<<"Is the array sorted in order of ascending?"<< endl;
    if(!mylist.getSorted()){
        cout<<"No it is not sorted." << endl;
        cout<< "Sorting Now..."<< endl;;
        mylist.sort();
        mylist.printArray();
    }
    else{
        cout<< "Yes, it is correctly sorted!"<< endl;
    }

    /* These next two sets will succeed and set the 1st and last
     * elements to 1000 and 2000 respectively */
    cout << endl;
    if(mylist.setElement(1000, 0)){
        cout << "Element Set" << endl;
    } else {
        cout << "Element NOT Set" << endl;
    }
    if(mylist.setElement(2000, mylist.getLength()-1)){
        cout << "Element Set" << endl;
    } else {
        cout << "Element NOT Set" << endl;
    }
    mylist.printArray();
    cout << endl;

    /* These next two sets will fail and leave the array unmodified */
    if(mylist.setElement(9999, -1)){
        cout << "Element Set" << endl;
    } else {
        cout << "Element NOT Set" << endl;
    }
    if(mylist.setElement(9999, mylist.getLength())){
        cout << "Element Set" << endl;
    } else {
        cout << "Element NOT Set" << endl;
    }
    mylist.printArray();
    cout << endl;

    //Determines whether array is sorted or not and sorts if it is not
    cout<<"Did setElement make the array go out of order?"<< endl;
    if(!mylist.getSorted()){
        cout<<"Yes the array is now out of order." << endl;
    }
    else{
        cout<< "No, the array is correctly sorted still."<< endl;
    }

    /* Start of new code for assignment 7 */
    cout << endl;
    cout << "Testing new and/or modified code..." << endl;
    cout << endl;

    /* print out the array using getElement() */
    cout << "printing the array element by element using: int getElement(int);" << endl;
    cout<< "(going one too far to test out of range)" <<endl;
            int len = mylist.getLength();
            for(int i=0; i<len; i++){
                cout << mylist.getElement(i) << endl;
           }


    /* Solution 1: Will pass a value out of range and if index is out of range, will display error*/
    try{
    int element = mylist.getElement(30); 
    cout << element <<endl; 
    }
    catch(int e){
    cout << "error, out of range" << endl;
    }

    try{
    cout << endl;
    cout << "attempting to get element [length * 1.5] using: int getElement(int); " << endl;
    int element = mylist.getElement(LISTSIZE*1.5); 
    }
    catch(int e){
    cout << "error, out of range" << endl;
    }
    cout << endl;
    
    
    /* Solution 2: Will pass a value out of range and if index is out of range, will display error*/
    cout << "printing the array element by element using: bool getElement(int, int*);" << endl;
    cout<< "(going one too far to test out of range)" <<endl;
    len = mylist.getLength();

    int element;
    for(int i =0; i<= len; i++){
        if(mylist.getElement(i, &element)){
        cout << element << endl;
        } else{
        cout << "error, out of range" << endl;
        }
    }

    cout << endl;
    cout << "attempting to get element [length * 1.5] using: bool getElement(int, int*); " << endl;
    if(mylist.getElement(len*1.5, &element)){
        cout << element << endl;
        } else{
        cout << "error, out of range" << endl;
        }
    
    //Resizes the array to the same length
    cout << endl;
    cout << "resizing array to the same length" << endl;
    int resize= mylist.getLength();
    if(!mylist.resizeArray(&resize)){
        std::cout <<"failed to resize " << std::endl;
    }

    //Adds 5 to array length
    cout << endl;
    cout<<"resizing array to length+5" << endl; 
    cout<<"resized..." << endl;
    int resize2= resize +5;
    if(mylist.resizeArray(&resize2)){
        mylist.printArray();
    }
    cout<<"Is the array sorted in order of ascending?"<< endl;
    if(!mylist.getSorted()){
        cout<<"No it is not sorted." << endl;
        cout<< "Sorting Now..."<< endl;;
        mylist.sort();
        mylist.printArray();
    }
    else{
        cout<< "Yes, it is correctly sorted!"<< endl;
    }
    
    //Subtracts 5 from array length
    cout << endl;
    cout<<"resizing array to length-5" <<endl;
    cout<<"resized..." << endl;
    int resize3 =resize -5;
    if(mylist.resizeArray(&resize3)){
        mylist.printArray();
    }
    cout<<"Is the array sorted in order of ascending?"<< endl;
    if(!mylist.getSorted()){
        cout<<"No it is not sorted." << endl;
        cout<< "Sorting Now..."<< endl;;
        mylist.sort();
        mylist.printArray();
    }
    else{
        cout<< "Yes, it is correctly sorted!"<< endl;
    }
   
    //Resizes array length to 0
    cout << endl;
    cout <<"resizing array to 0"<<endl;
    int resize4=0;
     if(!mylist.resizeArray(&resize4)){
        std::cout <<"failed to resize " << std::endl;
    }

    return 0;
}
