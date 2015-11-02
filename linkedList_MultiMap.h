#include "linkedList_Map.cpp"

// The MultiMap acts just like the Map but allows inserting many values for each
// key. So you can have many values saved under the same key.

class Multimap{
    private:
        Map map;
        linkedlist<linkedlist<int> > counts;
    public:
        Multimap();
        ~Multimap();
        void set(string key, int value);
        void removeAll(string key);
        int count(string key);
        linkedlist<int>& getAll(string key);
        void removeOne(string key, int value); // EXTRA CREDIT
};
