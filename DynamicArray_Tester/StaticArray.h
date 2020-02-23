#ifndef STATICARRAY_H_INCLUDED
#define STATICARRAY_H_INCLUDED


//Student's Name: Nhat Nguyen
//Student's ID: 1793410
//Assignment 3: My Static Array

template <typename T, int CAP>
class StaticArray{
    T value[CAP];
    T dummy;
public:
    StaticArray();
    int capacity() const;
    T operator[](int) const;
    T& operator[](int);
};


template <typename T, int CAP>
StaticArray<T, CAP>::StaticArray(){
    for(int i = 0 ; i < CAP; i++){
        value[i] = T();

    }

    dummy = T();
}

template <typename T, int CAP>
int StaticArray<T, CAP>::capacity() const{
    return CAP;

}


template <typename T, int CAP>
T StaticArray<T, CAP>::operator[](int index) const{
    if(index < 0 || index >= CAP){
        dummy;
    }
    return value[index];
}


template <typename T, int CAP>
T& StaticArray<T, CAP>::operator[](int index){
    if(index < 0 || index >= CAP){
        return dummy;
    }
    return value[index];
}


#endif // STATICARRAY_H_INCLUDED
