//
//  283_Move_Zeroes.h
//  leetCode
//
//  Created by PengYan on 16/3/16.
//  Copyright © 2016年 PengYan. All rights reserved.
//
//  Description
/*  Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 
 For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 
 Note:
 You must do this in-place without making a copy of the array.
 Minimize the total number of operations.
*/

#ifndef _83_Move_Zeroes_h
#define _83_Move_Zeroes_h


#endif /* _83_Move_Zeroes_h */

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int nZero = 0;  // count the number of zeros we have met
        for(int i=0; i < len; i++) {
            if(nums[i] == 0) {
                nZero++; // current 'last' element is zero.
            }
            else {
                for(int j=i-1; j>= i-nZero; j--){ // pop up current 'last' element if it is not a zero.
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }
    }
};


class Test{
private:
    //input
    vector<int> nums{0, 1, 0, 3, 12};
    //correct output
    vector<int> ret = {1, 3, 12, 0, 0};
    //solutions
    vector<int> results;
public:
    //Initialize
    Test(){
        printf("260_Single_Number_III\n");
        
        printf("nums: {");
        for(int i=0; i < nums.size(); i++) {
            printf("%d", nums[i]);
            if(i < nums.size()-1) {
                printf(" ");
            }
        }
        
        
        Solution s = Solution();
        s.moveZeroes(nums);
    
        results = nums;
        
        printf("}\n");
        
        printf("ret: {");
        for(int i=0; i < ret.size(); i++) {
            printf("%d", ret[i]);
            if(i < ret.size()-1) {
                printf(" ");
            }
        }
        printf("}\n");
        
        printf("solutions: {");
        for(int i=0; i < results.size(); i++) {
            printf("%d", results[i]);
            if(i < results.size()-1) {
                printf(" ");
            }
        }
        printf("}\n");
    }
};