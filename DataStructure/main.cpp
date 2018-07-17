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

// sort descending by power
bool sortPow_Desc(vector<int> x,vector<int> y){
    return x[1] > y[1];
}

// compare by power
bool comp(vector<int> x,vector<int> y){
    return x[1] == y[1];
}

class poly{
public:
    vector<int> coef_pow;
    vector<vector<int>> x;
    
    poly(){
        //coef_pow.assign(2, 0); // init 2 columns (0, 0) for (coef, pow)
        //x.assign(1, coef_pow); // init n rows
    };
    ~poly(){};
    
    // copy constructor
    poly(const poly& p){
        for (int i=0; i<p.getSize(); ++i) {
            this->setVal(p.getCoef(i), p.getPow(i));
        }
        
    };
    
    // assignment operator
    const poly& operator=(const poly& rhs){
        if (&rhs==this) {
            return *this;
        }
        if (this->getSize()!=rhs.getSize()) {
            this->clear();
        }
        for (int i=0; i<rhs.getSize(); ++i) {
            this->setVal(rhs.getCoef(i), rhs.getPow(i));
        }
        return *this;
    };
    
    // operator overload +
    friend poly operator+(const poly &p1, const poly &p2){
        poly ans;
        int i,j;
        set_difference(p1.x.begin(), p1.x.end(), p2.x.begin(), p2.x.end(), inserter(ans.x, ans.x.begin()), comp);
        
        for (i=0; i<p1.getSize(); ++i) {
            for (j=0; j<p2.getSize(); ++j) {
                if (p1.getPow(i) == p2.getPow(j)) {
                    //cout << p1.getPow(i) << "," << p2.getPow(j) << "," << p1.getCoef(i)+p2.getCoef(j) << endl;
                    ans.setVal(p1.getCoef(i)+p2.getCoef(j), p1.getPow(i));
                    break;
                }
            }
        }


        return ans;
    };
    
    // operator <<
    friend ostream& operator<<(ostream&out, poly& p){
        p.sortPoly();
        for (int i=0; i<p.getSize(); ++i) {
            if (p.getCoef(i)==0)    continue;
            out << " [ " << p.getCoef(i) << " " << p.getPow(i) << " ]";
        }
        out << endl;
        return out;
    };
    
    void setVal(int c, int p){
        vector<int> newX;
        newX.push_back(c);
        newX.push_back(p);
        x.push_back(newX);
    };
    
    int getCoef(int n) const{
        if (n>x.size()) {
            cerr << "Error\n";
            exit(1);
        }
        return x[n][0];
    }
    
    int getPow(int n) const{
        if (n>x.size()) {
            cerr << "Error\n";
            exit(1);
        }
        return x[n][1];
    }
    
    int getSize() const{
        return x.size();
    }
    
    void clear(){
        x.clear();
    }
    
    void sortPoly(){
        sort(x.begin(), x.end(), sortPow_Desc);
    }
    
};


int main(int argc, const char * argv[]) {
    //unsigned int n;
    //cin >> n;
    // for i=1~n:
    
    poly p1, p2;
    int coef, pow;
    while (1) {
        cin >> coef >> pow;
        if (pow<0) {
            break;
        }
        p1.setVal(coef, pow);
    }
    cout << p1;
    while (1) {
        cin >> coef >> pow;
        if (pow<0) {
            break;
        }
        p2.setVal(coef, pow);
    }
    cout << p2;
    poly ans = p1 + p2;
    cout << "ans:\n" << ans;
    
    
    return 0;
}
