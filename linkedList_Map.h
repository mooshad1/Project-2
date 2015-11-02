#include "linkedList_Bag.cpp"

// This is my favorite ADT. A map is the typical key/value pair storage device 
// (I've given you a sample associative array in the notes). In this case we 
// will save values under a key, then retrieve a value by referencing the key.

// For your sanity you can make all keys strings and all values ints.

class Map{
    private:
        Set keys;
        linkedlist<int> values;
    public:
        Map();
        ~Map();
        void set(std::string key, int value);
        void remove(std::string key);
        int get(std::string key); // returns the value assigned to the given key
        int* operator[](std::string key);
        bool is_in(string key);
        int search(string key);
        void print();
};
