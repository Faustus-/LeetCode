//
//  100_Same_Tree.h
//  leetCode
//
//  Created by PengYan on 16/3/16.
//  Copyright © 2016年 PengYan. All rights reserved.
//
//  Description
/*  Given two binary trees, write a function to check if they are equal or not.
 
    Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */

#ifndef _00_Same_Tree_h
#define _00_Same_Tree_h


#endif /* _00_Same_Tree_h */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
            return false;
        }
        if(p != NULL && q != NULL) {
            if((*p).val != (*q).val) {
                return false;
            }
            else {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
        }
        return true;
    }
};