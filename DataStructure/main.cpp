//
//  main.cpp
//  DataStructure
//
//  Created by CheWei,Hsu on 2018/7/17.
//  Copyright © 2018年 CheWei,Hsu. All rights reserved.
//
// Website: http://dsalgo.openjudge.cn/201409week2/2/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Polynomial{
    int coef_1 = 0;
    int coef_2 = 0;
};

void getValue(vector<Polynomial>& poly, int& MaxPow, int n){
    
    while (1) {
        int coef, pow;
        cin >> coef >> pow;
        
        if (pow<0)
            break;
        
        // pow=10, MaxPow=10, Size=11: Idx=0~10
        // pow=11, MaxPow=10, Size=11: Idx=0~10
        if (pow>MaxPow) {
            MaxPow = pow;
            poly.reserve(MaxPow+1);
            poly.resize(MaxPow+1);
        }
        
        //cout << "Size:" << poly.size() << "; Capability:" << poly.capacity() << endl;
        if (n==1) {
            poly.at(pow).coef_1 += coef;
        } else {
            poly.at(pow).coef_2 += coef;
        }

    }
    
};

void add(vector<Polynomial>& poly, vector<int>& ans){
    ans.resize(poly.size());
    for (int pow=0; pow<poly.size(); ++pow)
        ans.at(pow) = poly.at(pow).coef_1 + poly.at(pow).coef_2;
};

void show_result(vector<int>& vec){
    for (int pow=vec.size()-1 ; pow>=0 ; --pow){
        if (vec.at(pow)==0)
            continue;
        cout << "[ " << vec.at(pow) << " " << pow << " ] ";
    }
    cout << endl;
};


int main(int argc, const char * argv[]) {
    vector<vector<int>> result;
    Polynomial polyX;
    unsigned int n;
    cin >> n;
    
    
    for (int i=0; i<n; ++i) {
        int MaxSize = 20;
        int MaxPow = MaxSize+1;
        vector<Polynomial> poly;
        poly.reserve(MaxPow);
        poly.resize(MaxPow);
        
        getValue(poly, MaxPow, 1);//show_polynomial(tem1);
        getValue(poly, MaxPow, 2);//show_polynomial(tem2);
        
        vector<int> ans;
        add(poly, ans);
        result.push_back(ans);
        
    }
    
    for (int i=0; i<result.size(); ++i)
        show_result(result.at(i));

    return 0;
}
