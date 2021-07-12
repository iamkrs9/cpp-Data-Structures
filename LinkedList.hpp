//
//  a.hpp
//  LeetCode
//
//  Created by Karan Shah on 7/12/21.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>

class LinkedList {
protected:
    int last_index{NULL};
    struct node{
        int val;
        node *next;
        node(int x) : val(x), next(NULL) {}     // constructor with val for node
        node() : next(NULL) {}                  // constructor without val for node
    };
    node *head;
    
public:
    
    LinkedList() {
        /*
         Constructor
         */
        
        node *head_init = new node;
        head = head_init;
    }
    
    bool is_listEmpty();
    
    void getTotalElements();
    
    node *getFirstNode();
    
    int get(int index);
    
    void addatHead(int val);
    
    void addatTail(int val);
    
    void addatIndex(int index, int val);
    
    void deleteatIndex(int index);
    
    void reverse();
    
    void reverse(node *curr);
    
    void Print(node *ptr);
    
    void ReversePrint(node *ptr);
    
};

#endif /* a_hpp */
