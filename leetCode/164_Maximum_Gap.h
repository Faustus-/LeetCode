//
//  164_Maximum_Gap.h
//  leetCode
//
//  Created by PengYan on 16/5/3.
//  Copyright © 2016年 PengYan. All rights reserved.
//
// Description
/*
 Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 
 Try to solve it in linear time/space.
 
 Return 0 if the array contains less than 2 elements.
 
 You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 
*/


#ifndef _64_Maximum_Gap_h
#define _64_Maximum_Gap_h


#endif /* _64_Maximum_Gap_h */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // sort first. however, it is not O(n)
        /*
        if(nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int maxGap = 0;
        for(int i = 1; i < nums.size(); i++) {
            maxGap = max((nums[i] - nums[i-1]), maxGap);
        }
        return maxGap;
        */
        
        
        /////////Bucket sort//////////////////
        if(nums.size() < 2) return 0;
        int n = nums.size();
        int minAll = *min_element(nums.begin(), nums.end());
        int maxAll = *max_element(nums.begin(), nums.end());
        // type conversion!!!
        double gap = ((double)(maxAll - minAll)) / (n - 1);
        // compute min and max element for each bucket
        // hence the gap between two successive elements is smaller than (maxV[i] - minV[i])
        // and there is an i that maxGap = maxV[i]-minV[i-1];
        vector<int> minV(n-1, INT_MAX);
        vector<int> maxV(n-1, INT_MIN);
        for(int i = 0; i < n; i ++){
            if(nums[i] != maxAll){
                // the bktId of maxAll will fall out of bucket range
                int bktId = (int)((nums[i] - minAll) / gap);
                minV[bktId] = min(minV[bktId], nums[i]);
                maxV[bktId] = max(maxV[bktId], nums[i]);
            }
        }
        int ret = 0;
        int curMax = maxV[0];
        for(int i = 1; i < n-1; i ++){
            if(minV[i] != INT_MAX){
                ret = max(ret, minV[i]-curMax);
                curMax = maxV[i];
            }
        }
        ret = max(ret, maxAll-curMax);
        return ret;
    }
};