//
//  260_Single_Number_III.h
//  leetCode
//
//  Created by PengYan on 16/3/16.
//  Copyright © 2016年 PengYan. All rights reserved.
//
//  Description:
/*  Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
    For example:
    Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 */


#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        
        int len = nums.size();
        for(int i=0; i < len; i++) {
            res = res ^ nums[i];
        }
        vector<int> ret(2, 0);
        int n = res & (~res + 1); //与补码取与，求出a、b最后一个不相同的位（假设为c）
        for (int i = 0; i < len; ++i)
        {
            if ((n & nums[i]) != 0) //c位与a一样的数
            {
                ret[0] ^= nums[i];
            }
            else{
                ret[1] ^= nums[i]; //c位和b一样的数
            }
        }
        return ret;
    }
};

class Test{
private:
    //input
    vector<int> nums{1, 2, 1, 3, 2, 5};
    //correct output
    vector<int> ret = {3, 5};
    //solutions
    vector<int> results;
public:
    //Initialize
    Test(){
        Solution s = Solution();
        results = s.singleNumber(nums);
        
        printf("260_Single_Number_III\n");
        
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
        for(int i=0; i < results.size(); i++) {
            printf("%d", results[i]);
            if(i < results.size()-1) {
                printf(" ");
            }
        }
        printf("}\n");
    }
};