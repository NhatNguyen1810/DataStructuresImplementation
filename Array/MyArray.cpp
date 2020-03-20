#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

#include <cstdlib>


class Array{
    int values[100];
    int dummy;

public:

    Array();
    int capacity() const;
    int operator[](int ) const;
    int& operator[](int ) ;

};

Array::Array(){
    for(int i = 0 ; i < 100; i++){
        values[i] = 0;
    }
    int dummy = 0;

} // constructor

int Array::capacity() const{
    return 100;
}//capacity of the array

int Array::operator[](int index) const{
    if(index < 0 || index >= 100){
        return 0;
    }

    return values[index];
} //getter version


int& Array::operator[](int index) {

    if(index < 0 || index >= 100){
        return dummy;
    }
    return values[index];

} // setter version



int main()
{
    int total = 0; //count how many lines have been added so far
    int duplicatedVals = 0; // count if there is an already input number

    Array ind; // for index
    Array val; // for value
    string input; // to read input



    do{


        cout << "Input an index and a value [Q to quit]: ";
        cin >> input; // read for index

        int index, value;

        if(input[0] == 'q' || input[0] == 'Q'){
            break;
        } // in case to quit as the input starts with the character q or Q





        index = atoi(input.c_str());//convert to c string then to number for index





        cin >> input; // read for value


        if(input[0] == 'q' || input[0] == 'Q'){
            break;
        } // in case to quit as the input starts with the character q or Q




        value = atoi(input.c_str()); // convert to c string then to number for index


        if(index < 0 || index >= 100){
            continue;
        } // out-of-range, since out-of-range index won't be taken into consideration, just continue


        bool flag = false;// to check if that index is already entered a value

            if(ind[index] == 1){ // in  case that index is already used before
                flag = true;
                duplicatedVals++;// increase the number of duplicated values

            }



            ind[index] = 1; // set that index to 1 to remember that at that index there is a value to output
            val[index] = value; // set value to the index
            total++; // how many lines have been added so far



    } while(input[0] != 'q' || input[0] != 'Q'); // end of index-value input

    cout << endl << endl;
    cout << "You have input " << total - duplicatedVals << " values" << endl; // list out how many different values are added
    cout << "The index-value pairs are: " << endl << endl;

    for(int i = 0 ; i < 100; i++){
        if(ind[i] != 0){ // check to see the index has a value
            cout << i << " => " << val[i] << endl;
        }

    }

    cout << endl << endl;


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

