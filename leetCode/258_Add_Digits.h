//
//  258_Add_Digits.h
//  leetCode
//
//  Created by PengYan on 16/3/16.
//  Copyright © 2016年 PengYan. All rights reserved.
//
//  Description
/*  Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
    
    For example:
    
    Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 
    Follow up:
    Could you do it without any loop/recursion in O(1) runtime?
 
    Hint:
 
    A naive implementation of the above process is trivial. Could you come up with other methods?
    What are all the possible results?
    How do they occur, periodically or randomly?
    You may find this Wikipedia article useful.
*/




#include <stdio.h>
class Solution {
    /*
     0~9: 0~9
     10: 1
     11: 2
     12: 3
     ...
     18: 9
     19: 10->1
     20: 2
     ...
     27: 9
     28: 10->1
     ...
     98: 17->8
     99: 18->9
     100: 1
     101: 2
     ...
     108: 9
     109: 10->1
     ...
     
     0 : 0
     mod 9 == 0: 9
     mod 9 != 0: mod9
     */
    
    
public:
    int addDigits(int num) {
        return 1 + (num -1) % 9;
    }
};


class Test{
private:
    //input
    int nums = 99;
    //correct output
    int ret = 9;
    //solutions
    int results;
public:
    //Initialize
    Test(){
        Solution s = Solution();
        results = s.addDigits(nums);
        
        printf("258_Add_Digits\n");
        
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