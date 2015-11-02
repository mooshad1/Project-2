// header for linkedList
// @ after code means that it has been tested and works correctly

template <typename T>
class node{
    public:
        node(); //@
        node(T value); //@
        T value;
        node* next;
        void print(); //@
};

template <typename T>
class linkedlist{
    private:
        node<T>* head;
        node<T>* tail;
        
    public:
        linkedlist();
        void append(node<T> &new_node); //@
        void prepend(node<T> &new_node); //@
        void insertAfter(node<T> &curr_node, node<T> &new_node); //@ Add's the new_node after curr_node
        void remove(node<T> &x_node); //@ removes the node after x_node from the linked list
        void remove_head(); //@ // removes the head of the linked list
        int search(T key); //@ Searches if the key is contained by any of the nodes, if found returns index. else -1.
        void print(); //@
        bool is_empty(); //@ // returns true if empty, else returns false
        node<T>& operator[](int x); //@ // returns the node at the given index x
};
