//
//  main.cpp
//  LeetCode
//
//  Created by Karan Shah on 7/9/21.
//

#include <iostream>
#include "DoubleLinkedList.cpp"
#include "Stack.hpp"
#include "LinkedList.hpp"

int main(int argc, const char * argv[]) {
    Stack s;
    s.Print();
    s.Push(1);
    s.Push(2);
    s.Print();
    int x{s.Top()};
    std::cout << "X IS: " << x << std::endl;
    s.Pop();
    x = s.Top();
    std::cout << "X IS: " << x << std::endl;
    s.Pop();
    x = s.Top();
    std::cout << "X IS: " << x << std::endl;
    s.Push(1);
    s.Print();
    x = s.Top();
    std::cout << "X IS: " << x << std::endl;
    std::cout << "SINGLE START" << std::endl;
    LinkedList myLinkedList;
    myLinkedList.is_listEmpty();
    myLinkedList.addatHead(1);
    myLinkedList.addatTail(3);
    myLinkedList.addatIndex(0, 1);
    myLinkedList.addatIndex(1, 2);
    myLinkedList.Print(myLinkedList.getFirstNode());
    myLinkedList.deleteatIndex(1);
    std::cout << std::endl;
    myLinkedList.Print(myLinkedList.getFirstNode());
    std::cout << "DOUBLE START" << std::endl;
//    DoubleLinkedList lldouble;
//    lldouble.is_listEmpty();
//    lldouble.addatHead(1);
//    lldouble.addatTail(3);
//    lldouble.addatIndex(0, 1);    // linked list becomes 1->1->3
//    lldouble.addatIndex(1, 2);    // linked list becomes 1->2->1->3
//    lldouble.Print(lldouble.getFirstNode());
//    lldouble.deleteatIndex(0);    // now the linked list is 2->1->3
//    std::cout << std::endl;
//    lldouble.Print(lldouble.getFirstNode());
//    lldouble.deleteatIndex(1);    // now the linked list is 2->3
//    std::cout << std::endl;
//    lldouble.Print(lldouble.getFirstNode());
//    lldouble.deleteatIndex(0);    // now the linked list is 3
//    std::cout << std::endl;
//    lldouble.Print(lldouble.getFirstNode());
//    lldouble.getTotalElements();
//    lldouble.deleteatIndex(0);    // now the linked list is
//    std::cout << std::endl;
//    lldouble.Print(lldouble.getFirstNode());
//    lldouble.getTotalElements();
//    lldouble.deleteatIndex(0);    // now the linked list is
//    std::cout << std::endl;
//    lldouble.Print(lldouble.getFirstNode());
//    lldouble.getTotalElements();
//    lldouble.get(1);
//    lldouble.reverse(lldouble.getFirstNode());
//    lldouble.get(1);
//    lldouble.get(0);
//    lldouble.reverse();
//    lldouble.get(1);
//    lldouble.get(0);
//    lldouble.Print(lldouble.getFirstNode());
//    lldouble.ReversePrint(lldouble.getFirstNode());
}
