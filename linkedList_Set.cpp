#include <iostream>
#include <sstream>
#include "linkedList_Set.h"
using namespace std;

/*
The abstract data type (ADT) Set is the CS equivalent of a mathematical set.

It allows you to add keys (but not values), test for inclusion of a key, remove 
a key, and test for an empty set.

For the sake of your sanity I'll let you limit your keys to strings (as opposed
to generic templates).
*/

Set::Set(){
    keys = linkedlist<string>();
}

Set::~Set(){
    node<string>* n = &(keys[0]);
    while(n != 0){
        node<string>* temp = n;
        n = n->next;
        delete temp;
    }
}


void Set::insert(string key){
    node<std::string>* n = new node<std::string>(key);
    keys.append(*n);
}

bool Set::is_in(string key){
    int x = keys.search(key);
    return (x != -1);
}

// Correct?
void Set::remove(string key){
    int index = keys.search(key);
    if(key == keys[0].value){
        keys.remove_head();
    }
    else if(index > 0){ // checks if there is a node in keys that has value key
        keys.remove(keys[index - 1]); // remove() removes the node after the designated index, so
    }                                 // we must use index - 1 to remove keys[index]
    else return; // not found
}

bool Set::is_empty(){
    return keys.is_empty();
}

void Set::print(){
    keys.print();
}

linkedlist<std::string> Set::return_keys(){
    return keys;
}

int Set::search(string key){
    return keys.search(key);
}

Set Set::Union(Set &other_set){
    Set new_set = Set();
    node<string>* n = &(keys[0]);
    while(n != 0){
        new_set.insert((n->value));
        n = n->next;
    }
    n = &(other_set.return_keys()[0]); // Sets n to the head in other_set's keys
    node<string>* temp = n;
    while(n != 0){
        if(this->is_in(n->value)){ // value is already in our new set
            n = n->next;
        }
        else { // value isn't in new set an needs to be added
            new_set.insert((n->value));
            n = n->next;
        }
    }
    n = temp;
    return new_set;
}

Set Set::Intersection(Set &other_set){
    Set new_set = Set();
    node<string>* n = &(keys[0]);
    while(n != 0){
        if(other_set.is_in(n->value)){
            new_set.insert(n->value);
            n = n->next;
        }
        else n = n->next;
    }
    return new_set;
}

/*
int main(){
    Set set = Set();
    
    cout << "Expected 1: " << "Actual: " << set.is_empty() << endl;
    
    cout << "Inserting hello!" << endl;
    set.insert("hello!");
    
    cout << "Inserting doggy" << endl;
    set.insert("doggy");
    
    cout << "Inserting kitty" << endl;
    set.insert("kitty");
    
    cout << "Expected 0: " << "Actual: " << set.is_empty() << endl;
    
    cout << "Searching for hello! (is_in: ";
    if(set.is_in("hello!")){
        cout << "hello! was found." << endl;
    }
    else cout << "hello! was not found." << endl;
    
    cout << "Removing hello!" << endl;
    set.remove("hello!");
    
    cout << "Searching for hello!: ";
    if(set.is_in("hello!")){
        cout << "hello! was found." << endl;
    }
    else cout << "hello! was not found." << endl;
    
    cout << "Removing then searching for kitty: ";
    set.remove("kitty");
    if(set.is_in("kitty")){
        cout << "kitty was found." << endl;
    }
    else cout << "kitty was not found." << endl;
    
    cout << endl;
    set.insert("mint");
    set.insert("fresh");
    set.insert("frog");
    set.print();
    
    cout << "searching for mint: Index ";
    cout << set.search("mint") << endl;
    
    cout << "Creating new set containing frog, fresh, jello, octopus" << endl;
    Set set2 = Set();
    set2.insert("frog");
    set2.insert("fresh");
    set2.insert("jello");
    set2.insert("octopus");
    
    cout << endl;
    cout << "Set 1: ";
    set.print();
    cout << "Set 2: ";
    set2.print();
    cout << endl;
    
    cout << "Union of set 1 and set 2: ";
    (set.Union(set2)).print(); // Expected is doggy, mint, fresh, frog, jello, octopus
    cout << endl;
    
    cout << "Set 1: ";
    set.print(); // Should be unchanged
    cout << "Set 2: ";
    set2.print(); // Should be unchanged
    cout << "Intersection of set 1 and set 2: ";
    (set.Intersection(set2)).print(); // should be fresh frog
    cout << endl;
}
*/

// g++ ll-Jake/linkedList.cpp ll-Jake/linkedList_Set.cpp ll-Jake/linkedList.h ll-Jake/linkedList_Set.h -lstdc++
// That compile code is unnecessary, compile normally with g++ ll-Jake/linkedList_Set.cpp

/*
// TIMING SET
int main(){
    Set set = Set();
    int length = 1000000;
    for(int i = 0; i < length; ++i){
        string result;
        stringstream convert;
        convert << i;
        result = convert.str();
        set.insert(result);
    }
    // for (int i = length - 1; i >= 0; --i){
    //     string result;
    //     stringstream convert;
    //     convert << i;
    //     result = convert.str();
    //     set.remove(result);
    // }
    set.is_in("1000000");
}
*/
