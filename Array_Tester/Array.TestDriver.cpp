#include <iostream>

using namespace std;

#include <cassert>

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

}// Array constructor


int Array::capacity() const{
    return 100;
}// capacity of the Array

int Array::operator[](int index) const{
    if(index < 0 || index >= 100){
        return 0;
    }

    return values[index];
} // getter version


int& Array::operator[](int index) {

    if(index < 0 || index >= 100){
        return dummy;
    }
    return values[index];

} //setter version





int main()
{
      Array a;// Array declaration


      // Array::capacity
      cout << "\nTesting Array::capacity\n";
      cout << "EXPECTED: 100\n";
      cout << "ACTUAL: " << a.capacity( ) << endl;
      assert(100 == a.capacity( ));



      // Array::Array
      cout << "\nTesting Array::Array\n";
      for (int i = 0; i < a.capacity( ); i++)
        assert(a[i] == 0);

      // Array::operator[ ] setter





      cout << "\nTesting the Array::operator[ ] setter\n";
      a[6] = 12356;
      a[7] = 7654321;
      cout << "\nTesting Array::operator[ ] setter\n";
      cout << "EXPECTED: 12356 for a[6]\n";
      cout << "ACTUAL: " << a[6] << endl;
      assert(12356 == a[6]);
      cout << endl;



      cout << "EXPECTED: 7654321 for a[7]\n";
      cout << "ACTUAL: " << a[7] << endl;
      assert(7654321 == a[7]);
      cout << endl;




      a[-1000] = 123123;//dummy will assgined this value, any out-of-range retrive later on will return this value
      cout << "EXPECTED: 123123 for a[-1000]\n";
      cout << "ACTUAL: " << a[-1000] << endl;
      cout << endl;




      assert(12356 == a[6]);
      assert(7654321 == a[7]);
      assert(123123 == a[-6]); // any out-of-range uses dummy
      assert(123123 == a[100]); // checks upper end of range
      assert(123123 != a[99]); // checks upper end of range
      assert(123123 != a[0]); // checks lower end of range

        // Array::operator[ ] getter
      cout << "\nTesting the Array::operator[ ] getter\n";
      const Array b = a;
      for (int i = 0; i < 10; i++)
      assert(a[i] == b[i]);


      cout << "\nConst object test\n";
      const Array c; // if this compiles, Array::Array main constructor exists
      assert(c.capacity( ) == 100); // if this compiles, Array::capacity is a getter
      assert(c[0] == c[0]); // if this compiles, there is an Array::operator[ ] getter
      assert(c[-1] == c[-1]); // tests the getter's range checking
      return 0;

}

