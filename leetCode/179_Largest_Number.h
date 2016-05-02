//
//  179_ Largest_Number.h
//  leetCode
//
//  Created by PengYan on 16/3/24.
//  Copyright © 2016年 PengYan. All rights reserved.
//
// Description:
/*
 Given a list of non negative integers, arrange them such that they form the largest number.
 
 For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 
 Note: The result may be very large, so you need to return a string instead of an integer.
 */


#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    static bool cmp(const string &a,const string &b){
        string ab = a + b;
        string ba = b + a;
        return ab > ba;
    }
    string largestNumber(vector<int> &num) {
        int count = num.size();
        vector<string> vec;
        if(count == 0){
            return NULL;
        }
        int zeroCount = 0;
        for(int i = 0;i < count;++i){
            if(num[i] == 0){
                zeroCount ++;
            }
            char str[20];
            sprintf(str,"%d",num[i]);
            vec.push_back(str);
        }
        if(zeroCount == count){
            return "0";
        }
        if(count == 1){
            return vec[0];
        }
        sort(vec.begin(),vec.end(),cmp);
        string result;
        for(int i = 0;i < count;++i){
            result += vec[i];
        }
        return result;
    }
    /*
     void quickSort(vector<int>& nums, int left, int right){
     int p = nums[(left + right)/2];
     int i = left;
     int j = right;
     int temp = 0;
     
     do{
     while(ge(nums[i], p) && i < right) i++;
     while(ge(p, nums[j]) && left < j) j--;
     if(i <= j) {
     temp = nums[i];
     nums[i] = nums[j];
     nums[j] = temp;
     i++;
     j--;
     }
     }while (i<=j);
     if(left < j) quickSort(nums, left, j);
     if(i < right) quickSort(nums, i, right);
     }
     */
};