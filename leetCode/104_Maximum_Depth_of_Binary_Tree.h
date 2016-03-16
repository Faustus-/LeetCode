//
//  104_Maximum_Depth_of_Binary_Tree.h
//  leetCode
//
//  Created by PengYan on 16/3/16.
//  Copyright © 2016年 PengYan. All rights reserved.
//
//  Description
/*  Given a binary tree, find its maximum depth.
 
    The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/


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
    // DFS or BFS
    
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        else {
            int left = maxDepth((*root).left);
            int right = maxDepth((*root).right);
            return (1 + (left > right ? left : right));
        }
    }
};