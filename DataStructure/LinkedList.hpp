//
//  LinkedList.hpp
//  DataStructure
//
//  Created by CheWei,Hsu on 2018/7/27.
//  Copyright © 2018年 CheWei,Hsu. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp
#include <iostream>
using namespace std;

/*
 *  This is node of singly linked list
 */

template <class T>
class Link {
public:
    T data;        // 用于保存结点元素的内容
    Link<T> *next; // 指向后继结点的指针
    
    // construct1: data & next link
    Link(const T info, const Link<T>* nextValue=NULL){
        data = info;
        next = nextValue;
    }
    
    // construct2: next link only
    Link(const Link<T>* nextValue){
        next = nextValue;
    }
    
};

/*
 *  This is a compete class of singly linked list (帶表頭)
 */
template <class T>
class lnkList:public List<T>{
private:
    Link<T> *head;                           // 单链表的头指针, NULL if empty
    Link<T> *tail;                           // 单链表的尾指针, tail->next is always null
    Link<T> *curr;                           // Access to current element
    int size;                                // Size of list
    
    // Intialization helper method
    void init(){
        curr = tail = head = new Link<T>;
        size = 0
    }
    
    // Remove all link nodes to free storage
    void removeall(){
        while (head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
    
    // 函数返回第p个元素指针 (not good, break the encapsulation !)
    Lint<T> *setPos(const int i){
        int count = 0;
        if(i==-1) // i为-1则定位到头结点
            return head;
        
        Link<T> *p = head->next;// 循链定位，若i为0则定位到第一个结点
        if (i==0)
            return p;
        
        while (p != NULL && count < i) {// 指向第 i 结点，i=0,1,...，当链表中结点数小于 i 时返回 NULL
            p = p-> next;
            count++;
        }
        return p;
    };
    
public:
    lnkList(int s);                          // 构造函数
    ~lnkList();                              // 析构函数
    bool isEmpty();                          // 判断链表是否为空
    void clear();                            // 将链表存储的内容清除，成为空表
    int length();                            // 返回此顺序表的当前实际长度
    bool append(const T& value);              // 表尾添加一个元素 value，表长度增 1
    bool insert(const int p, cosnt T& value); // 位置 p 上插入一个元素
    bool remove(const int p);                // 删除位置 p 上的元素，表的长度减 1
    bool getValue(const int p, T& value);    // 返回位置 p 的元素值
    bool getPos(int &p, const T value);      // 查找值为 value 的元素
};

template <class T>
lnkList<T>::lnkList(int s){ init()  };

template <class T>
lnkList<T>::~lnkList(){ removeall();};

template <class T>
bool lnkList<T>::isEmpty(){
    if (size==0)
        return true;
    return false;
}

template <class T>
void lnkList<T>::clear(){ removeall(); init() };

template <class T>
int lnkList<T>::length(){ return size;  };

template <class T>
bool lnkList<T>::append(const T& value){
    tail->next = new Link<T>(value, NULL);
    tail = tail->next;
    size++;
    return true;
};

template <class T>
bool lnkList<T>::insert(const int p, cosnt T& value){
    
};

template <class T>
lnkList<T>::

template <class T>
lnkList<T>::

template <class T>
lnkList<T>::

#endif /* LinkedList_hpp */
