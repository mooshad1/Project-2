#include <iostream>
#include <stdexcept>
#include "linkedList_Map.h"
using namespace std;

Map::Map(){
    keys = Set();
    values = linkedlist<int>();
}
    
Map::~Map(){
    node<int>* n = &(values[0]);
    while(n != 0){
        node<int>* temp = n;
        n = n->next;
        delete temp;
    }
}

void Map::set(string key, int value){
    keys.insert(key);
    node<int>* n = new node<int>(value);
    values.append(*n);
}

void Map::remove(string key){
    int x = keys.search(key);
    if(x == -1){ // not found
        return;
    }
    else {
        keys.remove(key);
        if(x == 0){
            values.remove_head();
        }
        else values.remove(values[x - 1]); // remember, removes the node AFTER the given index
    }
    
}

int Map::get(string key){
    int x = keys.search(key);
    if(x == -1){ // The key is not in the map.
        throw runtime_error("Invalid key in get().");
    }
    else return values[x].value;
}

int* Map::operator[](string key){
    int x = keys.search(key);
    if(x == -1){
        throw runtime_error("Invalid key in operator[].");
    }
    else return &(values[x].value);
}

bool Map::is_in(string key){
    return keys.is_in(key);
}

int Map::search(string key){
    return keys.search(key);
}

void Map::print(){
    keys.print();
    values.print();
}


// Testing
/*
int main(){
    Map map = Map();
    map.set("flick", 54);
    map.set("candy", 87);
    map.set("horizon", 12);
    map.set("eclipse", 101);
    map.print();
    cout << endl;
    
    map.remove("horizon");
    map.print();
    cout << endl;
    
    cout << "Obtaining candy's value, should equal 87: ";
    try{
        cout << map.get("candy") << endl;
    }
    catch(runtime_error &excpt){
        cout << excpt.what() << endl;
    }
    
    cout << "Searching for milk: ";
    try{
        cout << map.get("milk");
    }
    catch(runtime_error &excpt){
        cout << excpt.what() << endl;
    }
    cout << endl;
    
    
    cout << "Testing operator[]" << endl;
    try{
        cout << "Should return value for flick (54): " << *(map["flick"]) << endl;
    }
    catch(runtime_error &excpt){
        cout << excpt.what() << endl;
    }
    cout << endl;
    
    cout << "Should return error: ";
    try{
        cout << *(map["table"]) << endl;
    }
    catch(runtime_error &excpt){
        cout << excpt.what() << endl;
    }
    cout << endl;
    
    cout << map.is_in("table") << endl;
    cout << map.is_in("candy") << endl;
    cout << endl;
    
    cout << map.search("table") << endl;
    cout << map.search("flick") << endl;
}
*/

// TIMING
/*
int main(){
    Map map = Map();
    int length = 400000;
    for(int i = 0; i < length; i++){
        stringstream convert;
        convert << i;
        string result = convert.str();
        map.set(result, i);
    }
    int x = map.get("200000");
}
*/
