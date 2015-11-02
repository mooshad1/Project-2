// linkedlist
// Jake Papineau
#include <iostream>
#include "linkedList.h"
using namespace std;

template <typename T>
node<T>::node(){
    next = 0;
}

template <typename T>
node<T>::node(T value){
    this->value = value;
    next = 0;
}

template <typename T>
void node<T>::print(){
    cout << this->value;
}

template <typename T>
linkedlist<T>::linkedlist(){
    head = 0;
    tail = 0;
}

template <typename T>
void linkedlist<T>::append(node<T> &new_node){ //good
    if(this->head == 0){
        head = &new_node;
        tail = &new_node;
    }
    else{
        tail->next = &new_node;
        tail = &new_node;
    }
}

template <typename T>
void linkedlist<T>::prepend(node<T> &new_node){ // check
    if(head == 0){
        head = &new_node;
        tail = &new_node;
    }
    else{
        new_node.next = head;
        head = &new_node;
    }
}

template <typename T>
void linkedlist<T>::insertAfter(node<T> &curr_node, node<T> &new_node){
    if(head == 0){
        head = &new_node;
        tail = &new_node;
    }
    else if(&curr_node == tail){
        tail->next = &new_node;
        tail = &new_node;
    }
    else{
        new_node.next = curr_node.next;
        curr_node.next = &new_node;
    }
}

template <typename T>
void linkedlist<T>::remove(node<T> &x_node){  // Removes the node AFTER x_node
    if(&x_node == 0 && head->next != 0){ // removes head
        node<T>* temp_node = head->next;
        head = &x_node;
        
        if(temp_node == 0){
            tail = 0;
        }
    }
    else if(x_node.next != 0){ // check if the removed's next is 0
        node<T>* temp_node = x_node.next->next;
        x_node.next = temp_node;
        
        if(temp_node == 0){
            tail = &x_node;
        }
    }
}

template <typename T>
void linkedlist<T>::remove_head(){
    if(head == 0){
        return;
    }
    else{
        node<T>* temp_node = head->next;
        head = temp_node;
    }
}

template <typename T>
int linkedlist<T>::search(T key){  // Returns int at index
    int counter = 0;
    node<T>* temp_node = head;
    while(temp_node != 0){
        if(temp_node->value == key){
            return counter;
        }
        temp_node = temp_node->next;
        ++counter;
    }
    return -1;
}

template <typename T>
void linkedlist<T>::print(){ // Good?
    node<T>* temp_node = head;
    while(temp_node != 0){
        temp_node->print();
        cout << " ";
        temp_node = temp_node->next;
    }
    cout << endl;
}

template <typename T>
bool linkedlist<T>::is_empty(){
    return (head == 0);
}

template <typename T>
node<T>& linkedlist<T>::operator[](int x){ // returns node
    node<T>* temp_node = head;
    for(int i = 0; i < x; ++i){
        temp_node = temp_node->next;
    }
    return *temp_node;
}

/*
// Testing
int main(){
    linkedlist<int> list = linkedlist<int>(); // linkedlist constructor works
    cout << "is empty?: " << list.is_empty() << endl << endl;
    list.remove_head(); // should do nothing
    cout << "linked list constructor operational" << endl;
    node<int> x = node<int>(10); // node constructor works
    cout << "node constructor operational" << endl << endl;
    //list.append(n); // append works
    //list.append(x);
    //list.print();
    
    int start_length = 10;
    node<int> arr_n[start_length];
    
    for(int i = 0; i < start_length; ++i){ // fill array with nodes
        arr_n[i] = node<int>(i);
    }
    
    for(int i = 0; i < start_length; ++i){ // extend linkedlist with array
        list.append(arr_n[i]);
    }
    list.print(); // print works
    cout << "append operational" << endl << endl;
    cout << "is empty? " << list.is_empty() << endl;
    cout << "is_empty operational" << endl << endl;
    
    node<int> n = node<int>(15);
    list.prepend(n); // prepend works
    list.print();
    cout << "prepend operational" << endl << endl;
    
    cout << list[0].value << endl; // [] operator works
    //cout << list[9].value << endl;
    cout << "[] operator operational" << endl << endl;
    
    list.remove(list[0]); // works, remember removes value AFTER given node
    list.remove(list[8]); // works
    list.remove(list[6]); // works
    list.print();
    cout << "remove operational" << endl << endl;
    
    node<int> node1 = node<int>(1);
    node<int> node2 = node<int>(9);
    node<int> node3 = node<int>(7);
    list.insertAfter(list[0], node1); // works
    list.insertAfter(list[8], node2); // works
    list.insertAfter(list[6], node3); // works
    list.print();
    cout << "insertAfter operational" << endl << endl;
    
    cout << "testing search" << endl;
    cout << "Expecting 6: " << list.search(5) << endl; // works
    cout << "Expecting 10: " << list.search(9) << endl; // works
    cout << "Expecting -1: " << list.search(10) << endl;
    cout << "search operational" << endl << endl;
    
    list.print();
    list.remove_head();
    list.print();
    cout << "remove_head opertational" << endl;
}
