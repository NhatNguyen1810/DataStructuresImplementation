#ifndef DYNAMICARRAY_H_INCLUDED
#define DYNAMICARRAY_H_INCLUDED


//Student's Name: Nhat Nguyen
//Student's ID: 1793410
//Assignment 4: Dynamic Array

template<typename V>
class DynamicArray{
    V* values;
    int cap;
    V dummy = V();
public:
    DynamicArray(int = 2);
    DynamicArray(const DynamicArray<V>&);
    ~DynamicArray(){delete[] values;}
    DynamicArray& operator=(const DynamicArray<V>&);
    int capacity() const;
    void capacity(int); //setter
    V operator[](int) const; // getter
    V& operator[](int); //setter
};



template<typename V>
DynamicArray<V>::DynamicArray(int cap){
    values = new V[cap];
    this->cap = cap;
    for(int i = 0 ; i < cap; i++){
        values[i] = V();
    }

}

template<typename V>
DynamicArray<V>::DynamicArray(const DynamicArray<V>& original){
    cap = original.cap;
    values = new V[cap];
    for(int i = 0 ; i < cap ; i++){

        values[i] = original.values[i];
    }

    dummy = original.dummy;
}


template<typename V>
DynamicArray<V>& DynamicArray<V>::operator=(const DynamicArray<V>& original){
    if(this != &original){
        delete[] values;
        cap = original.cap;
        values = new V[cap];
        for(int i = 0 ; i < cap ; i++){

            values[i] = original.values[i];
        }

        dummy = original.dummy;
    }
    return *this;
}

template<typename V>
int DynamicArray<V>::capacity() const{
    return cap;
}

template<typename V>
void DynamicArray<V>::capacity(int cap){
    V* temp = new V[cap];

    int limit = (cap < this->cap) ? cap: this->cap;

    for(int i = 0 ; i < limit ; i++){

        temp[i] = values[i];
    }

    for(int i = limit; i < cap; i++){
        temp[i] = V();
    }

    delete [] values;

    values = temp;

    this->cap = cap;

}

template<typename V>
V DynamicArray<V>::operator[](int index) const{
    if(index < 0 || index >= cap){
        return dummy;
    }
    return values[index];
}

template<typename V>
V& DynamicArray<V>::operator[](int index){
    if(index < 0){
        return dummy;
    }
    if(index >= cap){
        capacity(2*index);
    }


    return values[index];
}








#endif // DYNAMICARRAY_H_INCLUDED
