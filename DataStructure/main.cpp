//
//  main.cpp
//  DataStructure
//
//  Created by CheWei,Hsu on 2018/7/17.
//  Copyright © 2018年 CheWei,Hsu. All rights reserved.
//
// Website: http://dsalgo.openjudge.cn/201409week2/2/

#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin>>n;
    while(n--){
        int coef,pow,count=0;
        map<int,int> m;  // (key, value) = (pow, coef)
        
        while(count!=2&&cin>>coef>>pow){
            if(pow>=0){// Input not ended
                if(m.count(pow)==-1)// if inputed not existing, then insert
                    m.insert(make_pair(pow, coef));
                else{
                    m[pow]+=coef;// if inputed is existing, then add the coeficient
                    if(!m[pow])// if coeficient is zere, then remove it.
                        m.erase(pow);
                }
            }
            else // end inputed
                count++;
        }
        if(count==2){
            for(auto i=m.rbegin();i!=m.rend();++i){
                if (i!=m.rbegin())
                    cout<<' ';
                cout<<"[ "<<i->second<<' '<<i->first<<" ]";
            }
            cout<<endl;
        }
    }
}
