//
//  main.cpp
//  leetCode
//
//  Created by PengYan on 16/3/16.
//  Copyright © 2016年 PengYan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> a;
    a.push_back("abc");
    a.push_back("edf");
    
    cout<<a.size()<<endl;
    cout<<a[0].size()<<endl;
    cout<<a[0][0]<<endl;
    
    string b = "abcdfef";
    //cout<<b[3]<<endl;
    //cout<<*b.begin();
    sort(b.begin(), b.end());
    
    for(int i =0;i<b.size();i++) cout<<b[i]<<(1<<(b[i]-'a'))<<endl;
    
    int x = 1;
    int y = 5;
    if((x&&y) == 1)
        cout<<true<<endl;
    else
        cout<<false<<endl;
    
    return 0;
}
