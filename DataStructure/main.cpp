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

struct node{
    int existence;
    node* next;
};


class monkey{
public:
    node* first;
    node* cur;
    int length=0;
    
    monkey(int n){
        for (int i=1; i<=n; ++i) {
            node* tem = new node;
            tem->existence = i;
            cur->next = tem;
            tem->next = cur;
            length++;
            if (length==1) {
                first = tem;
            }
        }
    };
    ~monkey(){
        while (length>0) {
            node* tem = cur->next->next;
            cout << "Delete:" << cur->next->existence << endl;
            delete  cur->next;
            cur->next = tem;
            length--;
            cout << "length is: " << length << "\n";
        }
    };
    
    bool pop(node* Node){
        node* node_to_delete = Node->next;
        Node->next = node_to_delete->next;
        delete node_to_delete;
    };
};

int main(int argc, const char * argv[]) {
    int m, n;
    cout << "Input n & m" << endl;
    cin >> n >> m;
    if (m>300) {
        cerr << "Error!\n";
        exit(1);
    }
    
    monkey M(n);
    node* now = M.first;
    int count=1;
    while (M.length>1) {
        now = now->next;
        count += 1;

        if (count++ == m) {
            M.pop(now);
            count = 0;
        } 
    }
    
    
    
    
    return 0;
}

