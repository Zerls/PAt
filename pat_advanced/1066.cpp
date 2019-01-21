//
// 1066.cpp 
// pat 
// 
// Created by zerl on 2019/1/2. 
// Github: https://github.com/zerls
// Copyright © 2019年 zerl. All rights reserved. 
//

#include <iostream>
using namespace std;
struct node_0 {
    int val;
    struct node_0 *left, *right;
};
node_0 *rotateLeft(node_0 *root) {
    node_0 *t = root->right;
    root->right = t->left;
    t->left = root;
    return t; }
node_0 *rotateRight(node_0 *root) {
    node_0 *t = root->left;
    root->left = t->right;
    t->right = root;
    return t; }
node_0 *rotateLeftRight(node_0 *root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}
node_0 *rotateRightLeft(node_0 *root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}
int getHeight(node_0 *root) {
    if(root == NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}
node_0 *insert(node_0 *root, int val) {
    if(root == NULL) {
        root = new node_0();
        root->val = val;
        root->left = root->right = NULL;
    } else if(val < root->val) {
        root->left = insert(root->left, val);
        if(getHeight(root->left) - getHeight(root->right) == 2)
            root = val < root->left->val ? rotateRight(root) :
            rotateLeftRight(root);
    } else {
        root->right = insert(root->right, val);
        if(getHeight(root->left) - getHeight(root->right) == -2)
            root = val > root->right->val ? rotateLeft(root) :
            rotateRightLeft(root);
    }
    return root;
}
int i1066() {
    int n, val;
    scanf("%d", &n);
    node_0 *root = NULL;
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("%d", root->val);
    return 0;
    
}
