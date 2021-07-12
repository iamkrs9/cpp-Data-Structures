//
//  Stack.cpp
//  LeetCode
//
//  Created by Karan Shah on 7/12/21.
//

#include "Stack.hpp"

void Stack::Print() {
    LinkedList::Print(getFirstNode());
}

void Stack::Push(int val) {
    addatHead(val);
}

void Stack::Pop() {
    deleteatIndex(0);
}

int Stack::Top() {
    if(LinkedList::is_listEmpty()) {
        std::cout << "Stack is Empty" << std::endl;
        return NULL;
    }
    return get(0);
}
