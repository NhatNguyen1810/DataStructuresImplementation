#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED


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

}

int Array::operator[](int index) const{
    if(index < 0 || index >= 100){
        return 0;
    }

    return values[index];
}


int& Array::operator[](int index) {

    if(index < 0 || index >= 100){
        return dummy;
    }
    return values[index];

}







#endif // ARRAY_H_INCLUDED
