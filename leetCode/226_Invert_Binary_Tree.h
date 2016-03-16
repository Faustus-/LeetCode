//
//  226_Invert_Binary_Tree.h
//  leetCode
//
//  Created by PengYan on 16/3/16.
//  Copyright © 2016年 PengYan. All rights reserved.
//
//  Description
/*  Invert a binary tree.
      4
    /   \
   2     7
  / \   / \
 1   3 6   9
    to
      4
    /   \
   7     2
  / \   / \
 9   6 3   1
*/

#ifndef _26_Invert_Binary_Tree_h
#define _26_Invert_Binary_Tree_h


#endif /* _26_Invert_Binary_Tree_h */


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
    // visit
    
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }
        if((*root).left != NULL) {
            invertTree((*root).left);
        }
        if((*root).right != NULL) {
            invertTree((*root).right);
        }
        TreeNode * temp = (*root).left;
        (*root).left = (*root).right;
        (*root).right = temp;
    }
};