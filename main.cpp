//
//  main.cpp
//  LeetCode
//
//  Created by Karan Shah on 7/9/21.
//

#include <iostream>
#include "LinkedList.cpp"
#include "DoubleLinkedList.cpp"

int main(int argc, const char * argv[]) {
//    LinkedList myLinkedList;
//    myLinkedList.is_listEmpty();
//    myLinkedList.addatHead(1);
//    myLinkedList.addatTail(3);
//    myLinkedList.addatIndex(0, 1);
//    myLinkedList.addatIndex(1, 2);
//    myLinkedList.get(0);
//    myLinkedList.get(1);
//    myLinkedList.get(2);
    DoubleLinkedList lldouble;
    lldouble.is_listEmpty();
    lldouble.addatHead(1);
    lldouble.addatTail(3);
    lldouble.addatIndex(1, 2);    // linked list becomes 1->2->3
    lldouble.get(0);
    lldouble.get(1);
    lldouble.get(2);
    lldouble.deleteatIndex(1);    // now the linked list is 1->3
    lldouble.get(1);
    lldouble.reverse(lldouble.getFirstNode());
    lldouble.get(1);
    lldouble.get(0);
    lldouble.reverse();
    lldouble.get(1);
    lldouble.get(0);
    lldouble.Print(lldouble.getFirstNode());
    lldouble.ReversePrint(lldouble.getFirstNode());
}
