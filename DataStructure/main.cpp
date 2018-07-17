//
//  main.cpp
//  DataStructure
//
//  Created by CheWei,Hsu on 2018/7/17.
//  Copyright © 2018年 CheWei,Hsu. All rights reserved.
//
// Problem Source: http://dsalgo.openjudge.cn/201409week2/1/

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    unsigned int m, n;
    cout << "Input n & m" << endl;
    cin >> n >> m;
    if (m>300) {
        cerr << "Error!\n";
        exit(1);
    }
    
    vector<int> monkey;
    for (int i=0; i<n; ++i) {
        monkey.push_back(1);
    }
    
    unsigned int count;
    n = monkey.size();
    while (n!=1) {
        count = 0;
        for (int i=0; i<n; ++i) {
            count += 1;
            if(count == m){
                cout << "Remove monkey:" << m << endl;
                monkey.erase(monkey.begin()+m-1);
                n = monkey.size();
                cout << "Size of monkey:" << n << endl;
                break;
            }
        }
    }
    
    cout << "Final monkey:" << monkey.at(0);
    
    
    return 0;
}

