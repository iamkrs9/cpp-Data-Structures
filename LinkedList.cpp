//
//  LinkedList.cpp
//  LeetCode
//
//  Created by Karan Shah on 7/9/21.
//

#include "LinkedList.hpp"

bool LinkedList::is_listEmpty() {
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
    
void LinkedList::getTotalElements() {
        std::cout << "Number of elements in list is: " << last_index << std::endl;
    }
    
LinkedList::node *LinkedList::getFirstNode() {
        /*
         Returns the address to first node
         */

        return head->next;
    }
    
int LinkedList::get(int index) {
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
        node *ptr = head->next;
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
    
void LinkedList::addatHead(int val) {
        /*
         Add a node as the first node
         */
        
        node *temp = new node(val);
        temp->next = head->next;
        head->next = temp;
        last_index += 1;
    }
    
void LinkedList::addatTail(int val) {
        /*
         Add a node at the end
         */
    
//    if(rear == NULL) {
//        addatHead(val);
//        return;
//    }
//    node *temp = new node(val);
//    rear->next = temp;
//    rear = temp;
        
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
    
void LinkedList::addatIndex(int index, int val) {
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
    
void LinkedList::deleteatIndex(int index) {
        /*
         Delete the index-th node
         The list is 0 indexed
         */
        
        if(index >= last_index) {
            std::cout << "NOTHING TO DELETE" << std::endl;
        }
        else if(index == 0) {
            node*ptr = head;
            head->next = ptr->next->next;
            delete ptr->next;
            last_index -= 1;
        }
        else {
            node *ptr = head->next;
            node *preptr = ptr;
            for(int i{0}; i<=index; i++) {
                if(i==index) {
                    preptr->next = ptr->next;
                    delete ptr;
                    last_index -= 1;
                }
                else {
                    preptr = ptr;
                    ptr = ptr->next;
                }
            }
        }
    }
    
void LinkedList::reverse() {
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
    
void LinkedList::reverse(LinkedList::node *curr) {
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
    
void LinkedList::Print(LinkedList::node *ptr) {
        /*
         Forward print the list
         */
        
        if(ptr == NULL) {
            return;
        }
        std::cout << ptr->val << std::endl;
        Print(ptr->next);
    }
    
void LinkedList::ReversePrint(LinkedList::node *ptr) {
        /*
         Reverse print the list
         */
        
        if(ptr == NULL) {
            return;
        }
        ReversePrint(ptr->next);
        std::cout << ptr->val << std::endl;
    }

