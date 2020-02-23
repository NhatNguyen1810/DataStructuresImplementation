#include <iostream>
#include <string>

using namespace std;

#include <cstdlib>
#include "StaticArray.h"


//programmar name: Nhat Nguyen
//programmer ID: 1793410
//Assignment 3: Static Array


int main()
{
    cout << "Student's name: Nhat Nguyen" << endl;
    cout << "Student's ID: 1793410" << endl;
    cout << "Assignment3 : My Static Array" << endl;
    bool b = new bool();
    cout << b << endl;
    StaticArray<double, 100> val;// for value storage
    StaticArray<bool, 100> ind;// for index storage, which index
    string input;// for indexn-value input
    int total = 0;// this variable is to check how many lines have been added so far
    int duplicatedVals = 0;// this variable is to keep track how many times already-existed values are added
    do{

        cout << "Input an index and a value [Q to quit] ";
        double value;// for value
        int index;// for index
        cin >> input;// the first time of input is for index
        if(input[0] == 'q' || input[0] == 'Q'){
            break;
        }// check to quit
        index = atoi(input.c_str());//



        cin >> input;
        if(input[0] == 'q' || input[0] == 'Q'){
            break;
        }// this one is to check if the user wants to quit the index-value input loop

        value = atof(input.c_str());// value input

        if(index < 0 || index >= 100){
            continue;
        } // out-of-range, since out-of-range index won't be taken into consideration, just continue


        bool flag = false;// to check if that index is already entered a value

        if(ind[index] == 1){ // in  case that index is already used before
            flag = true;
            duplicatedVals++;// increase the number of duplicated values

        }



        ind[index] = true; // set that index to 1 to remember that at that index there is a value to output
        val[index] = value; // set value to the index
        total++; // how many lines have been added so far


    } while(input[0] != 'q' || input[0] != 'Q');


    cout << endl << endl;
    cout << "You have input " << total - duplicatedVals << " values" << endl; // list out how many different values are added
    cout << "The index-value pairs are: " << endl << endl;

    for(int i = 0 ; i < val.capacity(); i++){
        if(ind[i] != false){ // check to see the index has a value
            cout << i << " => " << val[i] << endl;
        }

    }

    string inputTwo; // readfor index checking


    do{


        cout << "Input an index for me to look it up [Q to quit]: " ;
        cin >> inputTwo; // input the index

        if(inputTwo[0] == 'q' || inputTwo[0] == 'Q'){
            break;
        } // in case to quit as the input starts with the character q or Q


        int checkIndex = atoi(inputTwo.c_str()); // convert to c string then convert to number


        if(checkIndex < 0 || checkIndex >= 100){
            cout << "I didn't find it" << endl;
            continue;
        }// in case out-of-range index, there is no value to return, so just continue



        if(ind[checkIndex] == 1){ // if that index has a value
            cout << "Found it -- the value stored at " << checkIndex << " is " << val[checkIndex] << endl;
        }
        else{
            cout << "I didn't find it" << endl;
        }




    } while(inputTwo[0] != 'q' || inputTwo[0] != 'Q'); // end of index checking


    return 0;
}
