#include <iostream>

using namespace std;

#include <cassert>
#include "Stack.h"
#include "Stack.h" //ifndef test

int main()
{
    cout << endl << "Student's Name: Nhat Nguyen" << endl;
    cout << "Student's ID: 1793410" << endl;
    cout << "Asignment 7: MyRPNCalculator" << endl;
    Stack<double> a;
    cout << "Stack test: double" << endl;
    cout << "==================" << endl;
    cout << "Testing Stack:size" << endl;
    cout << "Expected: 0" << endl;
    cout << "Acutal: " << a.size() << endl ;
    assert(a.size() == 0);
    cout << "Pass!" << endl << endl;

    cout << "Testing stack::peek and stack::push" << endl;
    a.push(1.1);
    cout << "Expected: 1.1" << endl;
    cout << "Actual: " << a.peek() << endl;
    assert(a.peek() == 1.1);
    cout << "Pass!" << endl << endl;

    a.push(2.2);
    cout << "Testing stack::pop" << endl;
    cout << "Before pop: 1.1 2.2" << endl;
    assert(a.peek() == 2.2);
    a.pop();
    cout << "After pop: " << a.peek() << endl  ;
    assert(a.peek() == 1.1);
    a.push(2);
    a.push(3);
    a.push(4);
    cout << "Pass!" << endl << endl;


    cout << "Tesing copy constructor" << endl;
    Stack<double> c = a;
    while(c.empty() == false){
        assert(a.peek() == c.peek());
        a.pop();
        c.pop();
    }
    cout << "Pass!" << endl << endl;



    a.push(2);
    a.push(3);
    a.push(4);
    Stack<double> b ; b = a;
    cout << "Tesing assignment operator" << endl;


    while(a.size() > 0){

        assert(a.peek() == b.peek());
        a.pop();
        b.pop();
    }
    cout << "Pass!" << endl << endl;


    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    cout << "Testing stack::size" << endl;
    cout << "After pushing 5 elements, now size is 5" << endl;
    cout << "Actual: " << a.size() << endl;
    assert(a.size() == 5);
    cout << "Pass!" << endl << endl;


    a.clear();
    cout << "Testing clear and empty"  << endl;
    assert(a.size() == 0);
    assert(a.empty() == true);
    cout << "Pass!" << endl << endl;

    a.push(1.1);
    a.push(2.2);
    a.push(3.3);
    a.push(4.4);
    a.push(5.5);


    cout << "Constant object test" << endl << endl;

    const Stack<double> d(a);
    assert(d.size() == a.size());
    assert(d.size() == 5);
    cout << "size: 5" << endl;
    assert(d.size() > 0);
    cout << "Its NOT empty" << endl;



    cout << endl << endl << endl << endl;






    Stack<string> stringa;
    cout << "Stack test: string" << endl;
    cout << "==================" << endl;
    cout << "Testing Stack:size" << endl;
    cout << "Expected: 0" << endl;
    cout << "Acutal: " << stringa.size() << endl;
    assert(stringa.size() == 0);
    cout << "Pass!"<< endl << endl;

    cout << "Testing stack::peek and stack::push" << endl;
    stringa.push("ONE");
    cout << "Expected: ONE" << endl;
    cout << "Reality: " << stringa.peek() << endl;
    assert(stringa.peek() == "ONE");
    cout << "Pass!" << endl<< endl;

    stringa.push("TWO");
    cout << "Testing stack::pop" << endl;
    cout << "Before pop: ONE TWO" << endl;
    stringa.pop();
    cout << "After pop: " << stringa.peek() << endl ;
    assert(stringa.peek() == "ONE");
    cout << "Pass!" << endl << endl;

    stringa.push("2");
    stringa.push("3");
    stringa.push("4");


    cout << "Tesing copy constructor" << endl;
    Stack<string> stringc = stringa;
    while(stringc.empty() == false){
        assert(stringa.peek() + "ab" != stringc.peek());
        stringc.pop();
        stringa.pop();
    }
    cout << "Pass!"<< endl << endl;


    stringa.push("2");
    stringa.push("3");
    stringa.push("4");
    Stack<string> stringb ; stringb = stringa;
    cout << "Tesing assignment operator" << endl;


    while(stringa.size() > 0){

        assert(stringa.peek() + "anbc" != stringb.peek());
        stringa.pop();
        stringb.pop();
    }
    cout << "Pass!" << endl << endl;


    stringa.push("1");
    stringa.push("2");
    stringa.push("3");
    stringa.push("4");
    stringa.push("5");
    cout << "Testing stack::size" << endl;
    cout << "After pushing 5 elements, now size is 5" << endl;
    cout << "Actual: " << stringa.size() << endl;
    assert(stringa.size() == 5);
    cout << "Pass!" << endl << endl;


    stringa.clear();
    cout << "Testing clear and empty"  << endl;
    assert(stringa.size() == 0);
    assert(stringa.empty() == true);
    cout << "Pass!" << endl << endl;



    stringa.push("1.1");
    stringa.push("2.2");
    stringa.push("3.3");
    stringa.push("4.4");
    stringa.push("5.5");
    cout << "Constant object test" << endl;

    const Stack<string> stringd(stringa);
    assert(stringd.size() == a.size());
    cout << "size: 5" << endl;
    assert(stringd.size() > 0);
    cout<< "Its NOT empty" << endl;



    return 0;


}
