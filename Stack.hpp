//
//  Stack.hpp
//  LeetCode
//
//  Created by Karan Shah on 7/12/21.
//

#ifndef Stack_hpp
#define Stack_hpp

#include "LinkedList.hpp"
#endif /* Stack_hpp */

class Stack : protected LinkedList {
public:
    Stack() : LinkedList() {}
    
    void Print();
    
    void Push(int val);
    
    void Pop();
    
    int Top();
};
