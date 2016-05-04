//
//  17_Letter_Combinations_of_a_Phone_Number.h
//  leetCode
//
//  Created by PengYan on 16/5/4.
//  Copyright © 2016年 PengYan. All rights reserved.
//

#ifndef _7_Letter_Combinations_of_a_Phone_Number_h
#define _7_Letter_Combinations_of_a_Phone_Number_h


#endif /* _7_Letter_Combinations_of_a_Phone_Number_h */


class Solution {
private:
    map<char, string> dict;
    vector<string> ret;
    
    void initMap() {
        dict['2'] = "abc";
        dict['3'] = "def";
        dict['4'] = "ghi";
        dict['5'] = "jkl";
        dict['6'] = "mno";
        dict['7'] = "pqrs";
        dict['8'] = "tuv";
        dict['9'] = "wxyz";
    }
    
    void DFS(string& c, string d, vector<string>& r, map<char, string>& m){
        if(d == "") {
            r.push_back(c);
            return;
        }
        else{
            char current = d[0];
            d.erase(d.begin());
            for(int i = 0; i < m[current].size(); i++) {
                c = c + m[current][i];
                DFS(c, d, r, m);
                c.erase(c.end()-1);
            }
            return;
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") {
            return ret;
        }
        else {
            initMap();
            string word = "";
            DFS(word, digits, ret, dict);
            return ret;
        }
    }
};