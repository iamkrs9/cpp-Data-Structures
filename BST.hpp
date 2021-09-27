//
//  BST.hpp
//  LeetCode
//
//  Created by Karan Shah on 7/16/21.
//

#ifndef BST_hpp
#define BST_hpp

#include <iostream>
#include <queue>

class BST {
    struct BSTNode {
        int data;
        BSTNode* left;
        BSTNode* right;
    };

public:
    BSTNode *root = NULL;
    
    BSTNode *newNode(int data);
    
    BSTNode* insert(BSTNode* root, int data);
    
    bool search(BSTNode* root, int data);
    
    int findMin(BSTNode* root);
    
    int findMax(BSTNode* root);
    
    int findHeight(BSTNode* root);
    
    void levelOrder(BSTNode* root);
    
    void preOrder(BSTNode* root);
    
    void inOrder(BSTNode* root);
    
    void postOrder(BSTNode* root);
};

#endif /* BST_hpp */
