// IntVector.cpp

#include "IntVector.h"
#include <iostream>

using namespace std;

IntVector::IntVector(unsigned capacity, int value){

    _size = capacity; // he number of elements currently being used to store the user's values
    _capacity = capacity; 

    if (_capacity == 0){
        _data = nullptr; // or nullptr? its causing error
        cout << "No vector created"  << endl; 
    }

    else { 
        _data = new int[capacity];
        for(unsigned int i =0; i < capacity; ++i){
            _data[i] = value; 
        }
    }

}

IntVector::~IntVector(){

   delete[] _data; 
   _data = nullptr;

}

unsigned IntVector::size() const{

    return _size;

}
unsigned IntVector::capacity() const{
    return _capacity;
}

bool IntVector::empty() const{

    if(_size ==0){
        return true;
    }
    return false;

}
const int& IntVector::at(unsigned index) const{
    if (index >= _size){
        throw out_of_range("IntVector::at_range_check");
        }

    return _data[index];

}
const int & IntVector::front() const{
    return _data[0]; 

}
const int &IntVector::back() const{
    return _data[_size-1]; 

}

void IntVector::insert(unsigned index, int value){
    if (index > _size) {
        throw std::out_of_range("IntVector::insert_range_check");
    }

    if (_size + 1 > _capacity) {
        expand();
    }

    for (unsigned i = _size; i > index; --i) {
        _data[i] = _data[i - 1];
    }

        
    _data[index] = value;

    _size++;

}

void IntVector::erase(unsigned index){
    if (index >= _size) {
        throw out_of_range("IntVector::erase_range_check");
    }

    for (unsigned i = index; i < _size - 1; ++i) {
        _data[i] = _data[i + 1];
    }

    _size--;
}

int & IntVector::front(){
     return _data[0]; 
}
int & IntVector::back(){
    return _data[_size-1]; 
}

void IntVector::assign(unsigned n, int value){
    clear();
    //_size = n;

    if (_size >= n)
    {
        for (unsigned i = 0; i < n; ++i) {
        _data[i] = value;
        }

        for (unsigned i = size(); i >= n; --i) {
            pop_back();
        }

        return;
    }

    _size = n;
    if((n - _capacity) > (_capacity * 2)){
        //expand(n - _capacity);
    }
    else{
        //expand();
        int* temp = _data;
        _data = new int[_capacity];
        //cout << _size << "--" << _capacity << endl;
        for (unsigned i = 0; i < _size; ++i) {
            _data[i] = temp[i];
        }
    }

    // _data = new int[_capacity];
    for (unsigned i = 0; i < n; ++i) {
        _data[i] = value;
    }

    /*
    vect = 0 1 2 3 -- 1 1 1 1
    size = ? (current size of vector)
    loop through the vector and assign all values to value from paraemeter
    check with n (from parameter) ... and expand with value from parameter
    ----- the assumption above is expand creates new memory locations as well
    this results in vector of size n with all values same as value 
    */
}

void IntVector::push_back(int value){
    if (_size + 1 > _capacity) {
        expand();
    }
    _data[_size] = value;
    _size++;

}
void IntVector::clear(){
    _size = 0;
}
void IntVector::resize(unsigned size, int value){
    if(size < _size){
        _size = size;
    }
    else if (size > _size) {
if(size > _capacity){
    unsigned newcap;
    if(size > 2*_capacity) {
        newcap = size;
    }
    else {
        newcap = 2* _capacity;
    }
    if (newcap > _capacity){
        expand (newcap - _capacity);
    }
    else{
        expand();
    }
    for (unsigned int i = _size; i < size; ++i){
        push_back(value);
    }
    _size = size;
}
}

}
void IntVector::reserve(unsigned n){
    if (n > _capacity) {
        _capacity = n;
    }

}

void IntVector::pop_back(){
    if (_size > 0) {
        _size--;
    }
}

void IntVector::expand(){
    //cout << _size << "--" << _capacity << endl;
    if (_capacity == 0) {
            _capacity = 1;
           // cout << _size << "--" << _capacity << endl;
    } 
    else {
        _capacity *= 2;
        //cout << _size << "--" << _capacity << endl;
    }

    int* temp = _data;
    _data = new int[_capacity];
    //cout << _size << "--" << _capacity << endl;
    for (unsigned i = 0; i < _size; ++i) {
         _data[i] = temp[i];
    }

    // for (unsigned i = _size; i < _capacity; ++i) {
    //     new_data[i] = 0;
    // }

    //_data = new_data;
    delete[] temp;
}

int & IntVector::at(unsigned index){
     if (index >= _size){
        throw out_of_range("IntVector::at_range_check");
        }

    return _data[index];


}
void IntVector::expand(unsigned amount){
    
    _capacity = _capacity + amount;
    int* temp = _data;
    _data = new int[_capacity];

    for (unsigned i = 0; i < _size; ++i) {
         _data[i] = temp[i];
     }

    delete[] temp;

    

}