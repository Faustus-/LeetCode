//
//  136_Single_Number.h
//  leetCode
//
//  Created by PengYan on 16/3/16.
//  Copyright © 2016年 PengYan. All rights reserved.
//
//  Description
/*  Given an array of integers, every element appears twice except for one. Find that single one.
 *  Note:
 *  Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int result = 0;
        for(int i=0; i < len; i++) {
            result = nums[i] ^ result; // according to a^a = 0, we can eliminate elements appearing twice.
        }
        return result;
    }
};


class Test{
private:
    //input
    vector<int> nums{1, 2, 1, 2, 5};
    //correct output
    vector<int> ret = {5};
    //solutions
    int results;
public:
    //Initialize
    Test(){
        Solution s = Solution();
        results = s.singleNumber(nums);
        
        printf("136_Single_Number\n");
        
        printf("nums: {");
        for(int i=0; i < nums.size(); i++) {
            printf("%d", nums[i]);
            if(i < nums.size()-1) {
                printf(" ");
            }
        }
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
        printf("%d", results);
        printf("}\n");
    }
};