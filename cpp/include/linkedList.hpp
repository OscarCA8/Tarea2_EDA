#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include "node.hpp"

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    void insertLast(int val);
    void insertFirst(int val);
    void removeFirst();
    void remove(int val);
    void removeAll();
    Node* find(int val);
    Node* getHead() const { return head; }
    void print();
    virtual ~LinkedList();
};

#endif /* LINKEDLIST_HPP_ */
