//
//  DoubleLinkedList.cpp
//  LeetCode
//
//  Created by Karan Shah on 7/11/21.
//

#include <iostream>

class DoubleLinkedList {
    struct Dnode{
        int val;
        Dnode *next;
        Dnode *prev;
        Dnode() : next(NULL), prev(NULL) {}                     // constructor without val for Dnode
        Dnode(int x) : val(x), next(NULL), prev(NULL) {}        // constructor with val for Dnode
    };
    Dnode *head;
    int last_index{NULL};
    
public:
    
    DoubleLinkedList() {
        /*
         Constructor
         */
        
        Dnode *head_init = new Dnode;
        head = head_init;
    }
    
    bool is_listEmpty() {
        if(head->next == NULL) {
            return 1;
        }
        else {
            return 0;
        }
    }
    
    int getTotalElements() {
        std::cout << "Number of elements in list is: " << last_index << std::endl;
        return last_index;
    }
    
    Dnode *getFirstNode() {
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
        
        int g;
        
        if(is_listEmpty() || index>=last_index) {
            std::cout << "CANNOT GET BECAUSE EMPTY" << std::endl;
            return -1;
        }
        else {
            Dnode *ptr = head->next;
            for(int i{0}; i<last_index; i++) {
                if(i == index) {
                    g = ptr->val;
                }
                else {
                    ptr = ptr->next;
                }
            }
        }
        return g;
    }
    
    void addatHead(int val) {
        /*
         Add a node as the first node
         */
        
        last_index += 1;
        Dnode *new_node = new Dnode(val);
        new_node->next = head->next;
        new_node->prev = NULL;
        if(head->next != NULL) {
            Dnode *old_first = head->next;
            old_first->prev = new_node;
        }
        head->next = new_node;
    }
    
    void addatTail(int val) {
        /*
         Add a node at the end
         */
        
        Dnode *ptr = head->next;
        for(int i{0}; i<last_index; i++) {
            if(i == last_index-1) {
                Dnode *temp = new Dnode(val);
                temp->next = NULL;
                temp->prev = ptr;
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
            return;
        }
        else if(index > last_index) {
            std::cout << "NOT ADDED" << std::endl;
        }
        else if(index==0) {
            addatHead(val);
            return;
        }
        else {
            Dnode *ptr = head->next;
            for(int i{0}; i<index; i++) {
                if(i == index-1) {
                    Dnode *temp = new Dnode(val);
                    temp->next = ptr->next;
                    temp->prev = ptr;
                    ptr->next->prev = temp;
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
        else if(index == 0) {
            Dnode *start = head->next;
            if(start->next == NULL) {
                head->next = NULL;
                delete start;
                last_index = NULL;
            }
            else {
                Dnode *del_node = start;
                head->next = start->next;
                head->next->prev = NULL;
                delete del_node;
                last_index -= 1;
            }
        }
        else {
            Dnode *ptr = head->next;
            for(int i{0}; i<=index; i++) {
                if(i==index) {
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                    delete ptr;
                }
                else {
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
        
        if(getTotalElements() == 0) {
            std::cout << "No elements in list to reverse" << std::endl;
            return;
        }
        
        Dnode *curr = head->next;
        Dnode *prev = NULL;
        Dnode *next;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = prev;
    }
    
    void reverse(Dnode *curr) {
        /*
         Recursive reversal of the list
         */
        
        if(getTotalElements() == 0) {
            std::cout << "No elements in list to reverse" << std::endl;
            return;
        }
        
        if(curr->next == NULL) {
            head->next = curr;
            return;
        }
        reverse(curr->next);
        Dnode *q = curr->next;
        q->next = curr;
        curr->next = NULL;
    }
    
    void Print(Dnode *ptr) {
        /*
         Forward print the list
         */
        
        if(ptr == NULL) {
            return;
        }
        std::cout << ptr->val << std::endl;
        Print(ptr->next);
    }
    
    void ReversePrint(Dnode *ptr) {
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
