//
//  328_Odd_Even_Linked_List.h
//  leetCode
//
//  Created by PengYan on 16/5/3.
//  Copyright © 2016年 PengYan. All rights reserved.
//
// Description:
/* Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
 
 You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
 
 Example:
 Given 1->2->3->4->5->NULL,
 return 1->3->5->2->4->NULL.
 
 Note:
 The relative order inside both the even and odd groups should remain as it was in the input.
 The first node is considered odd, the second node even and so on ...
 */


#ifndef _28_Odd_Even_Linked_List_h
#define _28_Odd_Even_Linked_List_h


#endif /* _28_Odd_Even_Linked_List_h */


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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* oddTail = head;
        ListNode* evenTail = head->next;
        ListNode* current = evenTail->next;
        while(current != NULL) {
            evenTail->next = current->next;
            current->next = oddTail->next;
            oddTail->next = current;
            oddTail = current;
            evenTail = evenTail->next;
            if(evenTail != NULL) {
                current = evenTail->next;
            }
            else {
                return head;
            }
        }
        return head;
    }
};