# Project-2

Project 2: DIY STL

For this task you will be making 12 different implementations of the classic "associative" containers. (An invitation to explore good software engineering and project management.)

Specifically I want you to implement the following 4 abstract data types in 3 ways each:

    Set
    Multiset (Bag)
    Map (Dictionary)
    Multimap

You should implement the ADT/API of those 4, 3 separate times with a different data structure under the hood each time:

    Dynamic Array (Roll your own, no vectors please)
    Linked List (Roll your own)
    Hash Map (Roll your own)

Do some timing on your code and report on which data structure performed the best for each ADT.

Just to be extremely clear, you will implement:

    The Set API using a dynamic array
    The Set API using a linked list
    The Set API using an hash map
    The MultiSet API using a dynamic array
    The MultiSet API using a linked list
    The MultiSet API using an hash map
    The Map API using a dynamic array
    The Map API using a linked list
    The Map API using an hash map
    The MultiMap API using a dynamic array
    The MultiMap API using a linked list
    The MultipMap API using an hash map

Details of the APIs

For this project we will allow unordered keys. In no case will we require an ordering of the keys.
Set

The abstract data type (ADT) Set is the CS equivalent of a mathematical set.

It allows you to add keys (but not values), test for inclusion of a key, remove a key, and test for an empty set.

For the sake of your sanity I'll let you limit your keys to strings (as opposed to generic templates).

To summarize you need to provide the following methods:

    void Set::insert(string key)
    bool Set::is_in(string key)
    void Set::remove(string key)
    bool Set::is_empty()

Extra Credit/Honors: Write a Set Set::Union(Set other_set) function and a Set Set::Intersection(Set other_set) function.
MultiSet (Bag)

A multiset is just like a set, but you can add the same key many times. In this case we add one feature count(key) to return the number of times key appears in our "Bag".

To summarize you need to provide the following methods:

    void MSet::insert(string key)
    bool MSet::is_in(string key)
    unsigned long MSet::count(string key)
    void MSet::removeOne(string key)
    void MSet::removeAll(string key)
    bool MSet::is_empty()

Extra Credit: implement a string MSet::draw_random(), so you can Monte Carlo simulate those math problems about bags with red and blue marbles.
Map (Dictionary)

This is my favorite ADT. A map is the typical key/value pair storage device (I've given you a sample associative array in the notes). In this case we will save values under a key, then retrieve a value by referencing the key.

For your sanity you can make all keys strings and all values ints.

The functions you should implement:

    void Map::set(string key, int value)
    void Map::remove(string key)
    int Map::get(string key)
    int& Map::operator[](string key)

MultiMap

The MultiMap acts just like the Map but allows inserting many values for each key. So you can have many values saved under the same key.

The functions you should implement:

    void Map::set(string key, int value)
    void Map::removeAll(string key)
    int Map::count(string key)
    int* Map::getAll(string key)

Extra Credit: A feature which I want but is too subtle is removing a single key/value pair. To do this you would need some sort of iterator and the ability to delete the key/value pair at a location. (See the STL erase example.)
Freedom

You have the freedom to implement more than I've asked for. For instance overriding << or creating any other features you would like. In your presentation state the additional features you are most proud of so we know and appreciate your work.
Extra Resources

https://en.wikipedia.org/wiki/Unordered_associative_containers_(C%2B%2B)

http://cs.smu.ca/~porter/csc/common_341_342/notes/ADTSet.html

http://cs.smu.ca/~porter/csc/common_341_342/notes/ADTMap.html 
