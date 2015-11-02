#include "linkedList_Set.cpp"
// //@ mean that function has been tested and works

class Mset{
    private:
        Set set;
        linkedlist<unsigned long> counts;
    public:
        Mset(); //@
        ~Mset(); //@
        void insert(string key); //@
        bool is_in(std::string key); //@ // returns true if the key is in the Mset
        unsigned long count(std::string key); //@  // returns the count for the given key
        void removeOne(std::string key); //@ // removes 1 of the counts at the given key, if count hits 0 it's corresponding set is removed
        void removeAll(std::string key); //@ // removes all the counts at the given key
        bool is_empty(); // returns true if empty, else false
        void print(); //@
};
