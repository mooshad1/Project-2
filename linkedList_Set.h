#include "linkedList.cpp"

class Set{
    private:
        linkedlist<std::string> keys;
    public:
        Set();
        ~Set();
        void insert(std::string key);
        bool is_in(std::string key);
        void remove(std::string key);
        bool is_empty();
        void print();
        int search(std::string key); // returns the index of the key if it is in keys, otherwise returns -1
        linkedlist<std::string> return_keys();
        Set Union(Set &other_set); // Uses &other_set instead of other_set
        Set Intersection(Set &other_set); // Uses &other_set instead of other set
};
