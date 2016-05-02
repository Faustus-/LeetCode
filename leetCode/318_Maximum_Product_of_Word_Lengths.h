//
//  318_Maximum_Product_of_Word_Lengths.h
//  leetCode
//
//  Created by PengYan on 16/5/2.
//  Copyright © 2016年 PengYan. All rights reserved.
//
//  Description:
/*
 Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
 
 Example 1:
 Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 Return 16
 The two words can be "abcw", "xtfn".
 
 Example 2:
 Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
 Return 4
 The two words can be "ab", "cd".
 
 Example 3:
 Given ["a", "aa", "aaa", "aaaa"]
 Return 0
 No such pair of words.
*/



#ifndef _18_Maximum_Product_of_Word_Lengths_h
#define _18_Maximum_Product_of_Word_Lengths_h


#endif /* _18_Maximum_Product_of_Word_Lengths_h */


#include <vector>

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int r = words.size();
        int prod = 0;
        vector<int> mask;
        
        if(r < 2) return 0;
        
        // apply an int variable as a mask to represent whether a character appears in the word.
        for(int n = 0; n < r; n++){
            //for(vector<string>::iterator it = words.begin(); it != words.end(); it++) {
            int temp = 0;
            for(int w = 0; w < words[n].size(); w++){
                //for(int w = 0; w < (*it).size(); w++) {
                //temp |= (1 << ((*it)[w] - 'a'));
                temp |= (1 << (words[n][w] - 'a'));
            }
            mask.push_back(temp);
        }
        
        for(int i = 0; i < r - 1; i++){
            for(int j = i + 1; j < r; j++){
                if ((mask[i] & mask[j]) == 0){
                    int p = words[i].size() * words[j].size();
                    //prod = max(prod, static_cast<int>(words[i].size() * words[j].size()));
                    prod = prod > p ? prod:p;
                }
            }
        }
        return prod;
    }
};