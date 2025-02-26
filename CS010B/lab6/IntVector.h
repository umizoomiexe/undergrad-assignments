// IntVector.h

/*Encapsulated (Private) Data Fields
(the number of elements currently being used to store the user's values).*/


//store the size of the array (therefore must always be >= to _size).

class IntVector {
    private: 
        int *_data; //a pointer that stores the address of the dynamically-allocated array of integers
        unsigned _size; //stores the size of the IntVector
        unsigned _capacity; // store the size of the array (therefore must always be >= to _size).
        
        void expand(unsigned amount);
    public: 
    void expand(); 
        IntVector(unsigned capacity = 0, int value = 0);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned index) const;
        const int & front() const;
        const int & back() const;
        int & at(unsigned index);
        void insert(unsigned index, int value);
        void erase(unsigned index);
        int & front();
        int & back();
        void assign(unsigned n, int value);
        void push_back(int value);
        void pop_back();
        void clear();
        void resize(unsigned size, int value = 0);
        void reserve(unsigned n);
        

};