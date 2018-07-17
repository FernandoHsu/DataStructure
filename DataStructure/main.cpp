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


class poly{
private:
    vector<int> coef_pow;
    vector<vector<int>> x;
    
public:
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
    
        // Record if the index of p2 is differnt from p1 or not
        vector<bool> idx_diff;
        for (int i=0; i<p2.getSize(); ++i) idx_diff.push_back(true);
        
        // Find the inner loops elements same with outer loops
        poly ans = p1;
        for (int i=0; i<ans.getSize(); ++i) {
            for (int j=0; j<p2.getSize(); ++j) {
                if (ans.getPow(i) == p2.getPow(j)) {
                    ans.chgCoef(ans.getCoef(i)+p2.getCoef(j), ans.getPow(i));
                    idx_diff[j] = false;
                    break;
                }
            }
        }
        
        // Find the inner loops elements different with outer loops
        for (int i=0; i<p2.getSize(); ++i) {
            if (idx_diff[i]) {
                ans.setVal(p2.getCoef(i), p2.getPow(i));
            }
        }

        return ans;
    };
    
    // operator <<
    friend ostream& operator<<(ostream&out, poly& p){
        p.sortPoly();
        for (int i=0; i<p.getSize(); ++i) {
            if (p.getCoef(i)==0)    continue;
            out << "[ " << p.getCoef(i) << " " << p.getPow(i) << " ] ";
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
    
    void chgCoef(int c, int p){
        for (int i=0; i<x.size(); ++i) {
            if (x[i][1]==p) {
                x[i][0]=c;
                return;
            }
        }
        return;
    };
    
    void removeX(int pos){
        x.erase(x.begin()+pos);
        return;
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
//-------------------------------------------------------------------------------------------

struct x{
    int coef;
    int pow;
};

void getValue(vector<x>& v){
    while (1) {
        x input;
        cin >> input.coef >> input.pow;
        if (input.pow<0) {
            break;
        }
        v.push_back(input);
    }
};

void combine_duplicate(vector<x>& v){
    
    
};

void add(vector<x>& p1, vector<x>& p2, vector<x>& ans){
    
    
};

void show_result(vector<x>& v){
    
    
};

int main(int argc, const char * argv[]) {
    
    unsigned int n;
    cin >> n;
    vector<x> p1, p2, ans;
    vector<vector<x>> result;
    
    for (int i=0; i<n; ++i) {
        getValue(p1);combine_duplicate(p1);
        getValue(p2);combine_duplicate(p2);
        add(p1, p2, ans);
        result.push_back(ans);
    }
    
    for (int i=0; i<n; ++i) show_result(result);

    return 0;
}
