//
//  292_Nim_Game.h
//  leetCode
//
//  Created by PengYan on 16/3/16.
//  Copyright © 2016年 PengYan. All rights reserved.
//
//  Description:
/*  You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.
 
    Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the
    game given the number of stones in the heap.
 
    For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the
    last stone will always be removed by your friend.
 
    Hint:
    If there are 5 stones in the heap, could you figure out a way to remove the stones such that you will always be the winner?
 */

#include <stdio.h>
class Solution {
    // Induction
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};

class Test{
private:
    //input
    int nums = 10;
    //correct output
    bool ret = true;
    //solutions
    bool results;
public:
    //Initialize
    Test(){
        Solution s = Solution();
        results = s.canWinNim(nums);
        
        printf("292_Nim_Game\n");
        
        printf("nums: ");
        printf("%d", nums);
        printf("\n");
        
        printf("ret: ");
        printf("%d", ret);
        printf("\n");
        
        printf("solutions: ");
        printf("%d", results);
        printf("\n");
    }
};