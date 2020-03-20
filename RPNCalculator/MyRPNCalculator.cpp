#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include <stdlib.h>
#include <cstring>
#include "Stack.h"


int main()
{


    cout << endl << "Student's Name: Nhat Nguyen" << endl;
    cout << "Student's ID: 1793410" << endl;
    cout << "Asignment 7: MyRPNCalculator" << endl;

    Stack<double> a;

    string input; // to read input



    do{


        Stack<double> b = a;// copy a into b


        Stack<double> c;// this stack is used to output in a reverse order, make the output looks better

        while(b.empty() == false){ // copy b to c in a reverse order

            cout << setprecision(3) << b.peek() << " ";
            b.pop();
        }



        cout << endl;

        cout << "Input a value [Q to quit]: ";
        getline(cin, input);





        if(input[0] == 'q' || input[0] == 'Q'){
            break;
        } // in case to quit as the input starts with the character q or Q





        int found = -1;
        for(int i = 0 ; i < input.size() ; i++){// check if the input string contains various numbers and operators

            if(isspace(input[i])){

                found = 1;
                break;
            }
        }


        if(found != -1){// if there is a space in the input, meaning there are more than one entry.

            int counter = 0;
            string tmpString = "";
            while(counter < input.length()){
                if(input[counter] != ' '){// if not a space, add to a temp string to see if will eventually be a number of a operator
                    tmpString += input[counter];
                }
                else{// if a space occur, check if tmpString is a number of a operator
                    if(tmpString != "+" && tmpString != "-" && tmpString != "*" && tmpString != "/"){ // none operator applies, meaning a number
                        double index = atof(tmpString.c_str());//convert to c string then to number for index
                        a.push(index);
                    }
                    else{// is an operator, check what that operator is
                        if(a.size() <= 1){
                            cout << "Invalid, there are not enough elements in the stack" << endl;
                            continue;
                        }
                        double index1 = a.peek();
                        a.pop();
                        double index2 = a.peek();
                        a.pop();
                        if(tmpString[0] == '+'){
                            a.push(index1+index2);
                        }
                        else if(input[0] == '-'){
                            a.push(index2-index1);
                        }
                        else if(input[0] == '*'){
                            a.push(index1*index2);
                        }
                        else if(input[0] == '/'){
                            a.push(index2/index1);
                        }
                    }
                    tmpString = "";
                }


                if( (counter == input.length() - 1) && tmpString.compare("") != 0){// check for the last entry as there is no space after the last entry

                        if(tmpString != "+" && tmpString != "-" && tmpString != "*" && tmpString != "/"){
                            double index = atof(tmpString.c_str());//convert to c string then to number for index
                            a.push(index);
                        }
                        else{
                            if(a.size() <= 1){
                                cout << "Invalid, there are not enough elements in the stack" << endl;
                                continue;
                            }
                            double index1 = a.peek();
                            a.pop();
                            double index2 = a.peek();
                            a.pop();
                            if(tmpString == "+"){
                                a.push(index1+index2);
                            }
                            else if(tmpString == "-"){
                                a.push(index2-index1);
                            }
                            else if(tmpString == "*"){
                                a.push(index1*index2);
                            }
                            else if(tmpString == "/"){
                                a.push(index2/index1);
                            }
                        }

                }
                counter++;

            }
        }

        else{// incase there is only either a number or a oprator.


            bool flag = false;


            if(input[0] == '+' || input[0] == '*' || input[0] == '/' || input[0] == '-'){
                if(a.size() <= 1){
                    cout << "Invalid, there are not enough elements in the stack" << endl;
                    continue;
                }
                double index1 = a.peek();
                a.pop();
                double index2 = a.peek();
                a.pop();
                if(input[0] == '+'){
                    a.push(index1+index2);
                }
                else if(input[0] == '-'){
                    a.push(index2-index1);
                }
                else if(input[0] == '*'){
                    a.push(index1*index2);
                }
                else if(input[0] == '/'){
                    a.push(index2/index1);
                }

                flag = true;
            }

            if(flag == false){
                double index = atof(input.c_str());//convert to c string then to number for index
                a.push(index);
            }

        }




    } while(input[0] != 'q' || input[0] != 'Q'); // end of index-value input

    return 0;
}
