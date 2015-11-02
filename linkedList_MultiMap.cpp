#include <iostream>
#include <stdexcept>
#include "linkedList_MultiMap.h"
using namespace std;

Multimap::Multimap(){
    map = Map();
    counts = linkedlist<linkedlist<int> >();
}

Multimap::~Multimap(){
    node<linkedlist<int> >* n = &(counts[0]);
    while(n != 0){ // iterates through the linkedlist of linkedlists of ints
        linkedlist<int> list = (n[0].value);
        node<int>* n2 = &(list[0]); // sets a second pointer to the first node in the inner linked list
        while(n2 != 0){ // iterates through one of the linkedlist of ints and deletes everything
            node<int>* temp2 = n2;
            n2 = n2->next;
            delete temp2;
        }
        node<linkedlist<int> >* temp = n;
        n = n->next;
        delete temp;
    }
}

void Multimap::set(string key, int value){
   if(!(map.is_in(key))){ // returns true if the given key isn't in our map yet. 
        map.set(key, value);
        node<int>* x = new node<int>(value);
        node<linkedlist<int> >* n = new node<linkedlist<int> >();
        n->value.append(*x);
        counts.append(*n);
    }
    else {
        int index = map.search(key);
        node<int>* x = new node<int>(value);
        (counts[index].value).append(*x);
    }
}

void Multimap::removeAll(string key){
    int x = map.search(key);
    map.remove(key);
    if(x == 0){
        counts.remove_head();
    }
    else if(x > 0){
        counts.remove(counts[x - 1]);
    }
    else {
        throw runtime_error("Invalid key in removeAll().");
    }
}

int Multimap::count(string key){
    int index = map.search(key);
    linkedlist<int>* list = &(counts[index].value);
    node<int>* n = &((*list)[0]);
    int count = 0;
    while(n != 0){
        n = n->next;
        ++count;
    }
    return count;
}

linkedlist<int>& Multimap::getAll(string key){
    int index = map.search(key);
    if (index == -1) {
        throw runtime_error("Invalid key in getAll().");
    }
    linkedlist<int>* list = &(counts[index].value);
    return *list;
}

void Multimap::removeOne(string key, int value){
    int index = map.search(key); // Get index of key
    if (index == -1) { // key not found
        throw runtime_error("Invalid key in removeOne().");
    }
    
    linkedlist<int>* list = &(counts[index].value); // Get linked list of given index
    
    int count = list->search(value); // searches the linked list for the value.
    
    if(count == 0){ // removes the value if it is the head
        list->remove_head();
    }
    else if(count > 0){ // removes the value if it is anywhere else
        list->remove((*list)[count - 1]);
    }
    else if(count == -1){ // value not found.
        return;
    }
}


// Testing
int main(){
    Multimap map = Multimap();
    map.set("hello", 5);
    map.set("hello", 22);
    map.set("hello", 52);
    map.set("bye", 100);
    
    cout << map.count("hello") << endl;
    map.getAll("hello").print();
    
    try{
        map.removeAll("hello");
    }
    catch(runtime_error &excpt){
        cout << excpt.what() << endl;
    }
    /* Testing exception, will stop main
    try{
        map.getAll("b").print();
    }
    catch(runtime_error &excpt){
        cout << excpt.what() << endl;
    }
    */
    
    // Testing removeOne()
    
    Multimap map2 = Multimap();
    map2.set("phone", 5);
    map2.set("phone", 10);
    map2.set("book", 15);
    
    cout<< "phone has values: ";
    map2.getAll("phone").print(); // Phones has values
    
    map2.removeOne("phone", 5);
    
    cout << "Removed 5. Now phone has values: ";
    map2.getAll("phone").print();
    
    cout << "book has values: ";
    map2.getAll("book").print();
    map2.removeOne("book", 15);
    
    cout << "Removed 15, now book has no values.";
    map2.getAll("book").print();
    
    
}



// TIMING MULTIMAP
/*
int main(){
    Multimap multimap = Multimap();
    int length = 20000;
    for(int i = 0; i < length; ++i){
        stringstream convert;
        convert << i;
        string result = convert.str();
        multimap.set(result, i);
        multimap.set(result, i);
    }
    for(int i = 0; i < length / 100; ++i){
        stringstream convert;
        convert << i * 5;
        string result = convert.str();
        multimap.set(result, i * i);
    }
    for(int i = 0; i < length; ++i){
        stringstream convert;
        convert << i;
        string result = convert.str();
        linkedlist<int> y = multimap.getAll(result);
    }
}
*/
