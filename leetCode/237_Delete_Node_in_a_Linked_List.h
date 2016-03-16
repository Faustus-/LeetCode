//
//  237_Delete_Node_in_a_Linked_List.h
//  leetCode
//
//  Created by PengYan on 16/3/16.
//  Copyright © 2016年 PengYan. All rights reserved.
//
//  Description
/*  Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 
    Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
 */

#ifndef _37_Delete_Node_in_a_Linked_List_h
#define _37_Delete_Node_in_a_Linked_List_h


#endif /* _37_Delete_Node_in_a_Linked_List_h */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        (*node).val = (*(*node).next).val;
        (*node).next = (*(*node).next).next;
    }
};