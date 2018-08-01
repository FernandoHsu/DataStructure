//
//  List.hpp
//  DataStructure
//
//  Created by CheWei,Hsu on 2018/7/27.
//  Copyright © 2018年 CheWei,Hsu. All rights reserved.
//

#ifndef List_hpp
#define List_hpp
#include <iostream>
using namespace std;


template <class T>
class List{
private:
    
    T* aList;    // 存储顺序表的实例
    int maxSize; // 顺序表实例的最大长度
    int curLen;  // 顺序表实例的当前长度
    int position;// 当前处理位置
    
public:
    List(const int size);
    ~List();
    void clear(); // 置空线性表
    bool isEmpty(); // 线性表为空时，返回 true
    bool append(const T value); // 在表尾添加一个元素 value，表的长度增 1
    bool insert(const int p, const T value); // 在位置 p 上插入一个元素 value，表的长度增 1
    bool Delete(const int p); // 删除位置 p 上的元素，表的长度减 1
    bool getPos(int& p, const T value); // 查找值为 value 的元素并返回其位置
    bool getValue(const int p, T& value); // 把位置 p 元素值返回到变量 value
    bool setValue(const int p, const T value); // 用 value 修改位置 p 的元素值
};

template <class T>
List<T>::List(const int size){
    maxSize = size;
    aList = new  T[maxSize];
    curLen = position = 0;
};

template<class T>
List<T>::~List(){
    delete [] aList;
};

template<class T>
void List<T>::clear(){
    delete [] aList;
    aList = new T[maxSize];
    curLen = positoin = 0;
};

template<class T>
bool List<T>::isEmpty(){
    if (curLen==0)
        return true;
    return false;
};

template<class T>
bool List<T>::append(const T value){
    if (curLen>=maxSize) {
        cerr << "Reach maxSize\n";
        return false;
    }
    
    position = curLen-1;
    aList[position] = value;
    curLen += 1;
    return true;
};

template<class T>
bool List<T>::insert(const int p, const T value){
    if (curLen>=maxSize) {
        cerr << "Reach maxSize" << endl;
        return false;
    }
    if ( p<0 || p>curLen) {
        cerr << "Insertion point is out of current length." << endl;
        return false;
    }
    // 从表尾(curLen -1)起往右移动直到p
    for (int i=curLen; i>p; i--)
        aList[i] = aList[i-1];
    aList[p] = value;
    curLen += 1;
    return true;
};

template<class T>
bool List<T>::Delete(const int p){
    if (curLen<=0) {
        cerr << "No element to delete." << endl;
        return false;
    }
    if ( p<0 || p>curLen) {
        cerr << "Delete point is out of current length." << endl;
        return false;
    }
    // 从p+1起往左移动直到表尾(curLen -1)
    for (int i=p; i<curLen-1; i++)
        aList[i] = aList[i+1];
    curLen -= 1;
    return true;
};

template<class T>
bool List<T>::getPos(int& p, const T value){
    for (position=0;position<curLen;position++) {
        if (aList[position]==value) {
            p = position;
            return true;
        }
    }
    return false;
};

template<class T>
bool List<T>::getValue(const int p, T& value){
    if (curLen<=0) {
        cerr << "No element to in list." << endl;
        return false;
    }
    if ( p<0 || p>curLen) {
        cerr << "Position is out of current length." << endl;
        return false;
    }
    value = aList[p]
    return true;
};

template<class T>
bool List<T>::setValue(const int p, const T value){
    if (curLen<=0) {
        cerr << "No element to in list." << endl;
        return false;
    }
    if ( p<0 || p>curLen) {
        cerr << "Position is out of current length." << endl;
        return false;
    }
    aList[p] = value;
    return true;
};

#endif /* List_hpp */
