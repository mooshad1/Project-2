#include <iostream>
#include <sstream>
#include "linkedList_Bag.h"
using namespace std;

Mset::Mset(){
    set = Set();
    counts = linkedlist<unsigned long>();
}

Mset::~Mset(){
    node<unsigned long>* n = &(counts[0]);
    while(n != 0){
        node<unsigned long>* temp = n;
        n = n->next;
        delete temp;
    }
}


void Mset::insert(string key){ // Might not be working.
    if(!(set.is_in(key))){ // returns true if the given key isn't in our set yet. 
        set.insert(key);
        node<unsigned long>* n = new node<unsigned long>(1);
        counts.append(*n);
    }
    else {
        int x = set.search(key);
        ++(counts[x].value);
    }
}

bool Mset::is_in(string key){
    return set.is_in(key);
}

unsigned long Mset::count(string key){ // returns the number of time a key appears in our bag
    int x = set.search(key);
    if(x == -1){
        return 0;
    }
    else return counts[x].value;
}

void Mset::removeOne(string key){ // TEST
    int x = set.search(key);
    if(counts[x].value == 1){ // only one left, remove from counts and set from our Mset
        set.remove(key);
        if(x == 0){ // first in counts, remove head
            counts.remove_head();
        }
        else counts.remove(counts[x - 1]); // will remove the node after counts[x - 1].
    }
    else if(x > 0){
        counts[x].value = counts[x].value - 1;
    }
    else return; // not found
}

void Mset::removeAll(string key){
    int x = set.search(key);
    if(x == 0){ // first in counts, remove head of counts and set.
        set.remove(key);
        counts.remove_head();
    }
    else if(x > 0){ // it's in there
        set.remove(key);
        counts.remove(counts[x - 1]);
    }
    else return; // not found
}

bool Mset::is_empty(){
    set.is_empty();
}

void Mset::print(){
    set.print();
    counts.print();
}

// Testing
/*
int main(){
    Mset my_mset = Mset();
    
    
    my_mset.insert("hello"); // Inserting some values
    for(int i = 0; i < 4; ++i){
        my_mset.insert("afternoon");
    }
    my_mset.insert("bye");
    my_mset.insert("fish");
    for(int i = 0; i < 20; ++i){
        my_mset.insert("bye");
    }
    my_mset.insert("flavor");
    my_mset.print();
    cout << endl;
    
    
    if(my_mset.is_in("afternoon")){ // testing is_in
        cout << "afternoon is in the mset." << endl; // afternoon should be found
    }
    if(!(my_mset.is_in("children"))){
        cout << "children is not in the mset." << endl; // children should not be found
    }
    cout << endl;
    
    
    cout << "Count for bye should be 21: ";
    cout << my_mset.count("bye") << endl;
    
    cout << "count for children should be 0: ";
    cout << my_mset.count("children") << endl;
    cout << endl;
    
    my_mset.print();
    cout << "Removing one from bye." << endl;
    my_mset.removeOne("bye");
    my_mset.print();
    cout << endl;
    
    cout << "Removing one from hello." << endl;
    my_mset.removeOne("hello");
    my_mset.print();
    cout << endl;
    
    cout << "Removing all from bye." << endl;
    my_mset.removeAll("bye");
    my_mset.print();
    cout << endl;
    
    cout << "Removing all counts for all values in the set" << endl;
    my_mset.removeAll("afternoon");
    my_mset.removeAll("fish");
    my_mset.removeAll("flavor");
    
    if(my_mset.is_empty()){
        cout << "The mset is empty." << endl;
    }
}
*/

/*
// TIMING BAG
int main(){
    Mset set = Mset();
    int length = 400000;
    for(int i = 0; i < length; i++){
        stringstream convert;
        convert << i;
        string result = convert.str();
        set.insert("result");
        set.insert("result");
    }
    
    // for(int i = length - 1; i > 0; --i){
    //     stringstream convert;
    //     convert << i;
    //     string result = convert.str();
    //     set.removeAll(result);
    // }
}
*/
