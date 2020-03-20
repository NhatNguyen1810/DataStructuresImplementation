#include <iostream>

using namespace std;

#include <cassert>
#include "StaticArray.h"
#include "StaticArray.h" //ifndef test


int main()
{

      cout << "Programmer Name: Nhat Nguyen" << endl;
      cout << "Programer's ID: 1793410" << endl;
      cout << "Assignment 3: Static Array Template TestDriver" << endl;
      cout << endl << endl;
      cout << "===========Test with Int type===========" << endl;
      StaticArray<int, 100> a;

    // Array::capacity
      cout << "\nTesting Array::capacity\n";
      cout << "EXPECTED: 100\n";
      cout << "ACTUAL: " << a.capacity( ) << endl;
      assert(100 == a.capacity( ));
      cout << "Pass!" << endl;



      // Array::Array
      cout << "\nTesting Array::Array\n";
      for (int i = 0; i < a.capacity( ); i++)
        assert(a[i] == 0);
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
      cout << endl;




      assert(12356 == a[6]);
      assert(7654321 == a[7]);
      assert(123123 == a[-6]); // any out-of-range uses dummy
      assert(123123 == a[100]); // checks upper end of range
      assert(123123 != a[99]); // checks upper end of range
      assert(123123 != a[0]); // checks lower end of range
      cout << "Pass!" << endl;

        // Array::operator[ ] getter
      cout << "\nTesting the Array::operator[ ] getter\n";
      const StaticArray<int, 100> b = a;
      for (int i = 0; i < a.capacity(); i++)
        assert(a[i] == b[i]);
      cout << "Pass!" << endl;

      cout << "\nConst object test\n";
      const StaticArray<int, 100> c; // if this compiles, Array::Array main constructor exists
      assert(c.capacity( ) == 100); // if this compiles, Array::capacity is a getter
      assert(c[0] == c[0]); // if this compiles, there is an Array::operator[ ] getter
      assert(c[-1] == c[-1]); // tests the getter's range checking
      cout << "Pass!" << endl;



      //testing with double array
      cout << endl << endl;
      cout << "===========Test with Double type===========" << endl;
      StaticArray<double, 100> d;
      // Array::capacity
      cout << "\nTesting Array::capacity\n";
      cout << "EXPECTED: 100\n";
      cout << "ACTUAL: " << d.capacity( ) << endl;
      assert(100 == d.capacity( ));
      cout << "Pass!" << endl;

      // Array::Array
      cout << "\nTesting Array::Array\n";
      for (int i = 0; i < d.capacity( ); i++)
        assert(d[i] == 0.0);
      cout << "Pass!" << endl;


      cout << "\nTesting the Array::operator[ ] setter\n";
      d[6] = 12.34;
      d[7] = 45.56;
      cout << "\nTesting Array::operator[ ] setter\n";
      cout << "EXPECTED: 12.34 for d[6]\n";
      cout << "ACTUAL: " << d[6] << endl;
      assert(12.34 == d[6]);
      cout << "Pass!" << endl;
      cout << endl;


      cout << "EXPECTED: 45.56 for d[7]\n";
      cout << "ACTUAL: " << d[7] << endl;
      assert(45.56 == d[7]);
      cout << "Pass!" << endl;
      cout << endl;


      d[-1000] = 12.2345;//dummy will assgined this value, any out-of-range retrive later on will return this value
      cout << "EXPECTED: 12.2345 for d[-1000] (dummy) \n";
      cout << "ACTUAL: " << d[-1000] << endl;
      assert(12.2345 == d[-1000]);
      cout << endl;


      assert(12.34 == d[6]);
      assert(45.56 == d[7]);
      assert(12.2345 == d[-6]); // any out-of-range uses dummy
      assert(12.2345 == d[100]); // checks upper end of range
      assert(12.2345 != d[99]); // checks upper end of range
      assert(12.2345 != d[0]); // checks lower end of range
      cout << "Pass!" << endl;


      // Array::operator[ ] getter
      cout << "\nTesting the Array::operator[ ] getter\n";
      const StaticArray<double, 100> dB = d;
      for (int i = 0; i < d.capacity(); i++)
        assert(dB[i] == d[i]);
      cout << "Pass!" << endl;


      cout << "\nConst object test\n";
      const StaticArray<double, 100> dC; // if this compiles, Array::Array main constructor exists
      assert(dC.capacity( ) == 100); // if this compiles, Array::capacity is a getter
      assert(dC[0] == dC[0]); // if this compiles, there is an Array::operator[ ] getter
      assert(dC[-1] == dC[-1]); // tests the getter's range checking
      cout << "Pass!" << endl;










      //testing with double array
      cout << endl << endl;
      cout << "===========Test with Character Data type===========" << endl;
      StaticArray<char, 100> testChar;


      // Array::capacity
      cout << "\nTesting Array::capacity\n";
      cout << "EXPECTED: 100\n";
      cout << "ACTUAL: " << testChar.capacity( ) << endl;
      assert(100 == testChar.capacity( ));
      cout << "Pass!" << endl;

      // Array::Array
      cout << "\nTesting Array::Array\n";
      for (int i = 0; i < testChar.capacity( ); i++)
        assert(testChar[i] == '\0');
      cout << "Pass!" << endl;

      cout << "\nTesting the Array::operator[ ] setter\n";
      testChar[6] = 'c';
      testChar[7] = 'd';
      cout << "\nTesting Array::operator[ ] setter\n";
      cout << "EXPECTED: \'c\' for testChar[6]\n";
      cout << "ACTUAL: " << testChar[6] << endl;
      assert(testChar[6] == 'c');
      cout << "Pass!" << endl;
      cout << endl;


      cout << "EXPECTED: \'d\' for testChar[7]\n";
      cout << "ACTUAL: " << testChar[7] << endl;
      assert('d' == testChar[7]);
      cout << "Pass!" << endl;



      testChar[-1000] = 'e';//dummy will assgined this value, any out-of-range retrive later on will return this value
      cout << "EXPECTED: \'e\' for testChar[-1000] (dummy)\n";
      cout << "ACTUAL: " << testChar[-1000] << endl;
      assert('e' == testChar[-1000]);



      assert('c' == testChar[6]);
      assert('d' == testChar[7]);
      assert('e' == testChar[-6]); // any out-of-range uses dummy
      assert('e' == testChar[100]); // checks upper end of range
      assert('e' != d[99]); // checks upper end of range
      assert('e' != d[0]); // checks lower end of range
      cout << "Pass!" << endl;

      // Array::operator[ ] getter
      cout << "\nTesting the Array::operator[ ] getter\n";
      const StaticArray<char, 100> testCharB = testChar;
      for (int i = 0; i < testChar.capacity(); i++)
        assert(testCharB[i] == testChar[i]);
      cout << "Pass!" << endl;


      cout << "\nConst object test\n";
      const StaticArray<char, 100> testCharC; // if this compiles, Array::Array main constructor exists
      assert(testCharC.capacity( ) == 100); // if this compiles, Array::capacity is a getter
      assert(testCharC[0] == testCharC[0]); // if this compiles, there is an Array::operator[ ] getter
      assert(testCharC[-1] == testCharC[-1]); // tests the getter's range checking
      cout << "Pass!" << endl;










      //testing with string array
      cout << endl << endl;
      cout << "===========Test with Character String type===========" << endl;
      StaticArray<string, 100> testString;


      // Array::capacity
      cout << "\nTesting Array::capacity\n";
      cout << "EXPECTED: 100\n";
      cout << "ACTUAL: " << testString.capacity( ) << endl;
      assert(100 == testString.capacity( ));
      cout << "Pass!" << endl;

      // Array::Array
      cout << "\nTesting Array::Array\n";
      for (int i = 0; i < testString.capacity( ); i++)
        assert(testString[i] == "\0");
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
      assert("datastructure" == testString[-6]); // any out-of-range uses dummy
      assert("datastructure" == testString[100]); // checks upper end of range
      assert("datastructure" != testString[99]); // checks upper end of range
      assert("datastructure" != testString[0]); // checks lower end of range
      cout << "Pass!" << endl;

      // Array::operator[ ] getter
      cout << "\nTesting the Array::operator[ ] getter\n";
      const StaticArray<string, 100> testStringB = testString;
      for (int i = 0; i < testString.capacity(); i++)
        assert(testStringB[i] == testString[i]);
      cout << "Pass!" << endl;


      cout << "\nConst object test\n";
      const StaticArray<string, 100> testStringC; // if this compiles, Array::Array main constructor exists
      assert(testCharC.capacity( ) == 100); // if this compiles, Array::capacity is a getter
      assert(testStringC[0] == testStringC[0]); // if this compiles, there is an Array::operator[ ] getter
      assert(testStringC[-1] == testStringC[-1]); // tests the getter's range checking
      cout << "Pass!" << endl;



      return 0;
}
