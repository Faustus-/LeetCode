//
//  1_Two_Sum.h
//  leetCode
//
//  Created by PengYan on 16/3/16.
//  Copyright © 2016年 PengYan. All rights reserved.
//
//  Description
/*  Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 
 You may assume that each input would have exactly one solution.
 
 Example:
 Given nums = [2, 7, 11, 15], target = 9,
 
 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].
 */

#ifndef __Two_Sum_h
#define __Two_Sum_h


#endif /* __Two_Sum_h */

#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
    //applying merge sort
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted(nums.size(), 0);
        vector<int> sortedIndex(nums.size(), 0);
        vector<int> index(nums.size(), 0);
        
        for(int i=0; i<nums.size(); i++) {
            index[i] = i;
        }
        
        vector<int> ret(2,0);
        mergeSort(nums, sorted, index, sortedIndex, 0, nums.size()-1);
        
        int i = 0;
        int j = nums.size()-1;
        
        while ((nums[i] + nums[j]) != target) {
            if ((nums[i] + nums[j]) < target) {
                i++;
            }
            else {
                j--;
            }
        }
        
        ret[0] = sortedIndex[i] < sortedIndex[j]?sortedIndex[i]:sortedIndex[j];
        ret[1] = sortedIndex[i] > sortedIndex[j]?sortedIndex[i]:sortedIndex[j];
        
        return ret;
    }
    
    void mergeSort(vector<int>& nums, vector<int>& sorted, vector<int>& index, vector<int>& sortedIndex, int a, int b) {
        if (a >= b) {
            return;
        }
        else {
            int mid = (a + b) / 2;
            mergeSort(nums, sorted, index, sortedIndex, a, mid);
            mergeSort(nums, sorted, index, sortedIndex, mid+1, b);
            int i = a;
            int j = mid+1;
            int k = a;
            while (i<mid+1 && j<b+1) {
                if (nums[i] <= nums[j]) {
                    sorted[k] = nums[i];
                    sortedIndex[k] = index[i];
                    i++;
                    k++;
                }
                else {
                    sorted[k] = nums[j];
                    sortedIndex[k] = index[j];
                    j++;
                    k++;
                }
            }
            while (i<mid+1) {
                sorted[k] = nums[i];
                sortedIndex[k] = index[i];
                k++;
                i++;
            }
            while (j<b+1) {
                sorted[k] = nums[j];
                sortedIndex[k] = index[j];
                k++;
                j++;
            }
            for (i=a; i<b+1; i++) {
                nums[i] = sorted[i];
                index[i] = sortedIndex[i];
            }
        }
    }
    
};


class Test{
private:
    //input
    vector<int> nums{150,24,79,50,88, 345, 87};
    //target
    int target = 200;
    
    //correct output
    vector<int> ret = {0, 3};
    //solutions
    vector<int> results;
public:
    //Initialize
    Test(){
        Solution s = Solution();
        results = s.twoSum(nums, target);
        
        printf("1_Two_Sum\n");
        
        printf("nums: {");
        for(int i=0; i < nums.size(); i++) {
            printf("%d", nums[i]);
            if(i < nums.size()-1) {
                printf(" ");
            }
        }
        printf("}\n");
        
        printf("Target:\n");
        printf("%d", target);
        
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