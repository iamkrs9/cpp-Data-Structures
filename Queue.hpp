//
//  Queue.hpp
//  LeetCode
//
//  Created by Karan Shah on 7/12/21.
//

#ifndef Queue_hpp
#define Queue_hpp

#include "LinkedList.hpp"

#endif /* Queue_hpp */

class Queue : protected LinkedList {
public:
    Queue() : LinkedList() {}
    
    void enqueue();
    
    int dequeue();
};
