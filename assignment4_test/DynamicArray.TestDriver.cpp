#include <iostream>

using namespace std;

#include <cassert>
#include "DynamicArray.h"
#include "DynamicArray.h"//ifndef test

int main()
{

    cout << "Programmer Name: Nhat Nguyen" << endl;
    cout << "Programer's ID: 1793410" << endl;
    cout << "Assignment 4: Dynamic Array Template" << endl;
    cout << endl << endl;
    cout << "===========Test with Int type===========" << endl;
    DynamicArray<int> a;
// Array::capacity
    cout << "\nTesting Array::capacity\n";
    cout << "EXPECTED: 2\n";
    cout << "ACTUAL: " << a.capacity() << endl;
    assert(2 == a.capacity( ));
    cout << "Pass!" << endl;



      // Array::Array
    cout << "\nTesting Array::Array\n";
    for (int i = 0; i < a.capacity( ); i++)
        assert(a[i] == 0);
    cout << "Pass!" << endl;


    cout << "\nTesting Array capacity setter\n" ;
    a.capacity(100);
    cout << "EXPECTED: 100\n";
    cout << "ACTUAL: " << a.capacity() << endl;
    assert(100 == a.capacity());
    cout << "Pass!" << endl;

      // Array::operator[ ] setter

     cout << "\nTesting the Array::operator[ ] setter\n";
     a[6] = 12356;
     a[7] = 7654321;
     cout << "\nTesting Array::operator[ ] setter\n";
     cout << "EXPECTED: 12356 for a[6]\n";
     cout << "ACTUAL: " << a[6] << endl;
     assert(12356 == a[6]);
     cout << "Pass!" << endl;
     cout << endl;



     cout << "EXPECTED: 7654321 for a[7]\n";
     cout << "ACTUAL: " << a[7] << endl;
     assert(7654321 == a[7]);
     cout << "Pass!" << endl;
     cout << endl;



     a[-1000] = 123123;//dummy will assgined this value, any out-of-range retrive later on will return this value
     cout << "EXPECTED: 123123 for a[-1000] (dummy) \n";
     cout << "ACTUAL: " << a[-1000] << endl;
     assert(123123 == a[-1000]);







     assert(12356 == a[6]);
     assert(7654321 == a[7]);
     assert(0 == a[100]);//auto-adjusting
     assert(123123 == a[-6]); // any out-of-range uses dummy
     assert(123123 != a[99]); // checks upper end of range
     assert(123123 != a[0]); // checks lower end of range
     cout << "Pass!" << endl << endl;



     cout << "The expected new capacity will be 100*2"<< endl;
     cout << "ACTUAL:" << a.capacity() << endl;
     assert(a.capacity() == 200);
     cout << "Pass!" << endl;

        // Array::operator[ ] getter
      cout << "\nTesting the Array::operator[ ] getter\n";
      const DynamicArray<int> b = a;
      for (int i = 0; i < a.capacity(); i++)
        assert(a[i] == b[i]);
      cout << "Pass!" << endl;

      cout << "\nConst object test\n";
      const DynamicArray<int> c; // if this compiles, Array::Array main constructor exists
      assert(c.capacity( ) == 2); // if this compiles, Array::capacity is a getter
      assert(c[0] == c[0]); // if this compiles, there is an Array::operator[ ] getter
      assert(c[-1] == c[-1]); // tests the getter's range checking
      cout << "Pass!" << endl;


      cout << "\nObject Assignment Test\n" ;
      DynamicArray<int> e;
      e = a;
      assert(a.capacity() == e.capacity());
      for(int i = 0 ; i < a.capacity() ; i++){
        assert(a[i] == e[i]);
      }
      for(int i = 0 ; i < a.capacity() ; i++){
        a[i]++;
        assert(a[i] != e[i]);
      }
      cout << "Pass!" << endl;

      cout << "\nObject Copy Test\n" ;
      DynamicArray<int> d = a;
      assert(d.capacity() == a.capacity());
      for(int i = 0 ; i < d.capacity(); i++){
        assert(d[i] == a[i]);
      }
      for(int i = 0 ; i < a.capacity() ; i++){
        a[i]++;
        assert(a[i] != d[i]);
      }
      cout << "Pass!" << endl;



      //testing with string array
      cout << endl << endl;
      cout << "===========Test with String type===========" << endl;
      DynamicArray<string> testString;


      // Array::capacity
      cout << "\nTesting Array::capacity\n";
      cout << "EXPECTED: 2\n";
      cout << "ACTUAL: " << testString.capacity( ) << endl;
      assert(2 == testString.capacity( ));
      cout << "Pass!" << endl;


      // Array::Array
      cout << "\nTesting Array::Array\n";
      for (int i = 0; i < testString.capacity( ); i++)
        assert(testString[i] == string());
      cout << "Pass!" << endl;


      cout << "\nTesting Array capacity setter\n" ;
      testString.capacity(100);
      assert(100 == testString.capacity());
      cout << "EXPECTED: 100\n";
      cout << "ACTUAL: " << testString.capacity() << endl;
      cout << "Pass!" << endl;


      cout << "\nTesting the Array::operator[ ] setter\n";
      testString[6] = "nhat";
      testString[7] = "nguyen";
      cout << "\nTesting Array::operator[ ] setter\n";
      cout << "EXPECTED: \'nhat\' for testString[6]\n";
      cout << "ACTUAL: " << testString[6] << endl;
      assert(testString[6] == "nhat");
      cout << "Pass!" << endl;
      cout << endl;


      cout << "EXPECTED: \'nguyen\' for testString[7]\n";
      cout << "ACTUAL: " << testString[7] << endl;
      assert("nguyen" == testString[7]);
      cout << "Pass!" << endl;
      cout << endl;


      testString[-1000] = "datastructure";//dummy will assgined this value, any out-of-range retrive later on will return this value
      cout << "EXPECTED: \'datastructure\' for testString[-1000] (dummy)\n";
      cout << "ACTUAL: " << testString[-1000] << endl;
      assert("datastructure" == testString[-1000]);



      assert("nhat" == testString[6]);
      assert("nguyen" == testString[7]);
      assert(string() == testString[100]);//auto-adjusting
      assert("datastructure" == testString[-6]); // any out-of-range uses dummy
      assert("datastructure" != testString[99]); // checks upper end of range
      assert("datastructure" != testString[0]); // checks lower end of range
      cout << "Pass!" << endl << endl;


      cout << "The expected new capacity will be 100*2"<< endl;
      cout << "ACTUAL:" << testString.capacity() << endl;
      assert(testString.capacity() == 200);
      cout << "Pass!" << endl;

      // Array::operator[ ] getter
      cout << "\nTesting the Array::operator[ ] getter\n";
      const DynamicArray<string> testStringB = testString;
      for (int i = 0; i < testString.capacity(); i++)
        assert(testStringB[i] == testString[i]);
      cout << "Pass!" << endl;


      cout << "\nConst object test\n";
      const DynamicArray<string> testStringC; // if this compiles, Array::Array main constructor exists
      assert(testStringC.capacity( ) == 2); // if this compiles, Array::capacity is a getter
      assert(testStringC[0] == testStringC[0]); // if this compiles, there is an Array::operator[ ] getter
      assert(testStringC[-1] == testStringC[-1]); // tests the getter's range checking
      cout << "Pass!" << endl;



      cout << "\nObject Assignment Test\n";
      DynamicArray<string> testStringD;
      testStringD = testString;
      assert(testString.capacity() == testStringD.capacity());
      for(int i = 0 ; i < testString.capacity() ; i++){
        assert(testStringD[i] == testString[i]);
      }
      for(int i = 0 ; i < testString.capacity() ; i++){
        testString[i] = testString[i] + "n";
        assert(testStringD[i] != testString[i]);
      }
      cout << "Pass!" << endl;

      cout << "\nObject Copy Test\n";
      DynamicArray<string> testStringE = testString;
      assert(testStringE.capacity() == testString.capacity());
      for(int i = 0 ; i < testString.capacity(); i++){
        assert(testStringE[i] == testString[i]);
      }
      for(int i = 0 ; i < testString.capacity() ; i++){
        testString[i] = testString[i] + "n";
        assert(testString[i] != testStringE[i]);
      }
      cout << "Pass!" << endl;



    return 0;
}
