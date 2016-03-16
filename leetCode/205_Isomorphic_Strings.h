//
//  205_Isomorphic_Strings.h
//  leetCode
//
//  Created by PengYan on 16/3/16.
//  Copyright © 2016年 PengYan. All rights reserved.
//
//  Description
/*  Given two strings s and t, determine if they are isomorphic.
 
 Two strings are isomorphic if the characters in s can be replaced to get t.
 
 All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 
 For example,
 Given "egg", "add", return true.
 
 Given "foo", "bar", return false.
 
 Given "paper", "title", return true.
 */

#ifndef _05_Isomorphic_Strings_h
#define _05_Isomorphic_Strings_h


#endif /* _05_Isomorphic_Strings_h */


#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m != n)
            return false;
        unordered_map<char, char> m1;   //s --> t
        unordered_map<char, char> m2;   //t --> s
        for(int i = 0; i < m; i ++)
        {
            char schar = s[i];
            char tchar = t[i];
            // the same char in s map to different chars in t
            if(m1.find(schar) != m1.end() && m1[schar] != tchar)
                return false;
            // two different chars in s map tp the same char in t
            if(m2.find(tchar) != m2.end() && m2[tchar] != schar)
                return false;
            m1[schar] = tchar;
            m2[tchar] = schar;
        }
        return true;
    }
};


class Test{
private:
    //input
    string a = "paper";
    //correct output
    string b = "title";
    //solutions
    bool results;
public:
    //Initialize
    Test(){
        Solution s = Solution();
        results = s.isIsomorphic(a, b);
        
        cout<<"205_Isomorphic_Strings"<<endl;
        
        cout<<"a: ";
        
        cout<<a<<endl;
        
        cout<<"b: ";
        
        cout<<b<<endl;
        
        cout<<"solutions: "<<endl;
        
        cout<<results<<endl;
    }
};