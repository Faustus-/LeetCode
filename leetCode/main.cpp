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

void sss(string xxx){
    xxx += "abc";
    cout<<xxx<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string a = "aaa";
    vector<string> temp;
    temp.push_back(a);
    
    a = a+"bbb";
    
    cout<<temp[0]<<endl;
    cout<<a<<endl;
    
    sss(a);
    
    cout<<a<<endl;
    
    a.erase(a.begin());
    cout<<a<<endl;
    
    cout<<a.size()<<endl;
    return 0;
}
