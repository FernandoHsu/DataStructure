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
    int coef;
    int pow;
};

void show_polynomial(vector<Polynomial> &poly){
    for (auto p : poly)
        cout << "[ " << p.coef << " " << p.pow << " ] ";
    cout << endl;
};

void getValue(vector<Polynomial>& poly, int& MAX){
    
    while (1) {
        Polynomial input;
        cin >> input.coef >> input.pow;
        if (input.pow<0)
            break;
        poly.push_back(input);
        if (input.pow > MAX)
            MAX = input.pow;
    }
    
};

void show_result(vector<int>& vec){
    
    for (int pow=vec.size()-1 ; pow>=0 ; --pow){
        if (vec.at(pow)==0)
            continue;
        cout << "[" << vec.at(pow) << " " << pow << " ] ";
    }
    cout << endl;
};

void reconstruct(vector<Polynomial>& tem, vector<int>& poly){
    for (int pow=0; pow<poly.size(); ++pow) {
        for (int j=0; j<tem.size(); ++j) {
            if (pow==tem.at(j).pow)
                poly.at(pow) += tem.at(j).coef;
        }
    }
    
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> result;
    unsigned int n;
    cin >> n;
    
    
    for (int i=0; i<n; ++i) {
        int MAX = -1;
        vector<Polynomial> tem1, tem2;
        
        getValue(tem1, MAX);//show_polynomial(tem1);
        getValue(tem2, MAX);//show_polynomial(tem2);
        MAX += 1;// To record the largest numbers
        
        vector<int>p1, p2, ans;
        p1.resize(MAX);
        p2.resize(MAX);
        ans.resize(MAX);
        
        reconstruct(tem1, p1);tem1.clear();
        reconstruct(tem2, p2);tem2.clear();
        transform(p1.begin(), p1.end(), p2.begin(), ans.begin(), plus<int>());
        result.push_back(ans);
        
    }
    
    for (int i=0; i<result.size(); ++i)
        show_result(result.at(i));

    return 0;
}
