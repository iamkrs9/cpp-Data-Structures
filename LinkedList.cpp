//
//  LinkedList.cpp
//  LeetCode
//
//  Created by Karan Shah on 7/9/21.
//

#include <iostream>

class LinkedList {
    
    struct node{
        int val;
        node *next;
        node(int x) : val(x), next(NULL) {}     // constructor with val for node
        node() : next(NULL) {}                  // constructor without val for node
    };
    node *head;
    int last_index{NULL};
    
public:
    
    LinkedList() {
        /*
         Constructor
         */
        
        node *head_init = new node;
        head = head_init;
    }
    
    bool is_listEmpty() {
        /*
         Checks if  the list is empty
         */
        
        if(head->next == NULL) {
            return 1;
        }
        else {
            return 0;
        }
    }
    
    node *getFirstNode() {
        /*
         Returns the address to first node
         */
        
        return head->next;
    }
    
    int get(int index) {
        /*
         Gets the index-th element in the list
         The list is 0 indexed
         */
        
        if(is_listEmpty() || index>=last_index) {
            std::cout << "CANNOT GET BECAUSE EMPTY" << std::endl;
            return -1;
        }
        else {
            node *ptr = head->next;
            for(int i{0}; i<last_index; i++) {
                if(i == index) {
                    std::cout << ptr->val << std::endl;
                }
                else {
                    ptr = ptr->next;
                }
            }
        }
        return 0;
    }
    
    void addatHead(int val) {
        /*
         Add a node as the first node
         */
        
        node *temp = new node(val);
        temp->next = head->next;
        head->next = temp;
        last_index += 1;
    }
    
    void addatTail(int val) {
        /*
         Add a node at the end
         */
        
        node *ptr = head->next;
        for(int i{0}; i<last_index; i++) {
            if(i == last_index-1) {
                node *temp = new node(val);
                temp->next = NULL;
                ptr->next = temp;
            }
            else {
                ptr = ptr->next;
            }
        }
        last_index += 1;
    }
    
    void addatIndex(int index, int val) {
        /*
         Add a node at the index-th position
         The list is 0 indexed
         */
        
        if(index == last_index+1) {
            addatTail(val);
        }
        else if(index > last_index) {
            std::cout << "NOT ADDED" << std::endl;
        }
        else if(index==0) {
            addatHead(val);
        }
        else {
            node *ptr = head->next;
            for(int i{0}; i<index; i++) {
                if(i == index-1) {
                    node *temp = new node(val);
                    temp->next = ptr->next;
                    ptr->next = temp;
                }
                else {
                    ptr = ptr->next;
                }
            }
        }
        last_index += 1;
    }
    
    void deleteatIndex(int index) {
        /*
         Delete the index-th node
         The list is 0 indexed
         */
        
        if(index >= last_index) {
            std::cout << "NOTHING TO DELETE" << std::endl;
        }
        else {
            node *ptr = head->next;
            node *preptr = ptr;
            for(int i{0}; i<=index; i++) {
                //std::cout << "THE VALUE IS: " << ptr->val << std::endl;
                if(i==index) {
                    preptr->next = ptr->next;
                    delete ptr;
                }
                else {
                    preptr = ptr;
                    ptr = ptr->next;
                }
            }
            last_index -= 1;
        }
    }
    
    void reverse() {
        /*
         Iterative reversal of the list
         */
        
        node *curr = head->next;
        node *prev = NULL;
        node *next;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = prev;
    }
    
    void reverse(node *curr) {
        /*
         Recursive reversal of the list
         */
        
        if(curr->next == NULL) {
            head->next = curr;
            return;
        }
        reverse(curr->next);
        node *q = curr->next;
        q->next = curr;
        curr->next = NULL;
    }
    
    void Print(node *ptr) {
        /*
         Forward print the list
         */
        
        if(ptr == NULL) {
            return;
        }
        std::cout << ptr->val << std::endl;
        Print(ptr->next);
    }
    
    void ReversePrint(node *ptr) {
        /*
         Reverse print the list
         */
        
        if(ptr == NULL) {
            return;
        }
        ReversePrint(ptr->next);
        std::cout << ptr->val << std::endl;
    }
};
