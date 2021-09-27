//
//  BST.cpp
//  LeetCode
//
//  Created by Karan Shah on 7/16/21.
//

#include "BST.hpp"

BST::BSTNode* BST::newNode(int data) {
    BSTNode* newNode = new BSTNode;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BST::BSTNode* BST::insert(BSTNode* root, int data) {
    if(root == NULL) {
        root = newNode(data);
    }
    else if(data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

bool BST::search(BSTNode *root, int data) {
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return search(root->left, data);
    else return search(root->right, data);
}

int BST::findMin(BSTNode *root) {
    if(root == NULL) {
        std::cout << "Empty Tree" << std::endl;
    }
    else if(root->left == NULL) {
        return root->data;
    }
    return findMin(root->left);
}

int BST::findMax(BSTNode *root) {
    if(root == NULL) {
        std::cout << "Empty Tree" << std::endl;
    }
    else if(root->right == NULL) {
        return root->data;
    }
    return findMax(root->right);
}

int BST::findHeight(BSTNode* root) {
    if(root == NULL) {
        return -1;
    }
    return std::max(findHeight(root->left), findHeight(root->right)) + 1;
}

void BST::levelOrder(BSTNode* root) {
    if(root == NULL) return;
    std::queue<BST::BSTNode*> Q;
    Q.push(root);
    
    while(!Q.empty()) {
        BST::BSTNode* current = Q.front();
        std::cout << current->data << '\n';
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop();
    }
}

void BST::preOrder(BSTNode* root) {
    if(root == NULL) return;
    std::cout << root->data << '\n';
    preOrder(root->left);
    preOrder(root->right);
}

void BST::inOrder(BSTNode* root) {
    if(root == NULL) return;
    inOrder(root->left);
    std::cout << root->data << '\n';
    inOrder(root->right);
}

void BST::postOrder(BSTNode* root) {
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->data << '\n';
}
