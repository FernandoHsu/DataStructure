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
 *  This is a compete class of singly linked list (帶空表頭)
 *  ----------------------------------------------------------
 *  – 整个单链表:  head
 *  – 第一个结点:  head != NULL & head->next
 *  – 空表判断:    head->next == NULL
 *  – 当前结点 a1: curr->next
 */
template <typename T>
class LList: public Link<T> {
private:
    Link<T>* head;       // Pointer to list header, NULL if empty
    Link<T>* tail;       // Pointer to last element, tail->next is always null
    Link<T>* curr;       // Access to current element by curr->next
    int size;            // Size of list, not include head node
    
    void init() {        // Intialization helper method
        curr = tail = head = new Link<T>;
        size = 0;
    }
    
    void removeall() {   // Return link nodes to free store
        while(head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
    
public:
    LList() { init(); }                          // Constructor
    ~LList() { removeall(); }                    // Destructor
    void print() const;                          // Print list contents
    void clear() { removeall(); init(); }        // Clear list
    int length() const { return size; }          // Return length
    
    
    // ---------------- Change/Get current position ----------------
    // Place curr at list start
    void moveToStart(){ curr = head; }
    
    // Place curr at list end
    void moveToEnd(){ curr = tail; }
    
    // Move curr one step left; no change if already at front
    void moveToPrev() {
        if (curr == head) return;       // No previous element
        
        Link<T>* temp = head;   // Traversal list until we find the previous element
        while (temp->next!=curr) temp=temp->next;
        curr = temp;
    }
    
    // Move curr one step right; no change if already at end
    void moveToNext(){
        if (curr != tail) curr = curr->next;
    }
    
    // Move down list to "pos" position
    void moveToPos(int pos) {
        Assert ((pos>=0)&&(pos<=size), "Position out of range"); // continue if positoin is neithor negative nor greater than size
        curr = head;
        for(int i=0; i<pos; i++) curr = curr->next;
    }
    
    // Return the position of the current element
    int getCurrPos() const {
        Link<T>* temp = head;
        int i;
        for (i=0; temp != curr; i++) // line serach until find curr
            temp = temp->next;
        return i;
    }
    
    // ---------------- File I/O with "current" postion----------------
    // Insert value at current position
    void insert(const T& value) {
        curr->next = new Link<T>(value, curr->next);
        if (tail == curr)   // if previous node is tail, then it becomes new tail
            tail = curr->next;
        size++;
    }
    
    // Remove and return current element
    T remove() {
        Assert(curr->next != NULL, "No element"); // already in the end of linked list (curr->next=NULL)
        
        Link<T>* list_to_delete = curr->next; // current list
        T value_to_delete = list_to_delete->data;
        
        if (list_to_delete == tail) // Update tail to previous link of list_to_delete
            tail = curr;
        curr->next = list_to_delete->next; // Update current list
        
        delete list_to_delete;
        size--;
        return value_to_delete;
    }
    
    // Return current element
    const T& getValue() const {
        Assert(curr->next != NULL, "No value"); // already in the end of linked list (curr->next=NULL)
        return curr->next->element;
    }
    
    // ---------------- File I/O with "integar" postion i, where -1 <= i < size ----------------
    // Assume size = 3
    // node:  0, 1, 2, 3
    //   i : -1, 0, 1, 2
    //   p :  X  p1 p2 p3 Null
    
    // 函数重新定義index，返回值是找到的结点指针。
    // node:  0, 1, 2, 3
    //      head,1, 2, tail
    // -----------------------------
    //   i : -1, 0, 1, 2, 3, , 4
    //return:hd,p1,p2,p3,Null,Null
    // ------------------------------
    // iter:  X  1, 2, 3, 4,   break
    //   p : p1 p1 p2 p3, Null, Null
    // count: 0, 0, 1, 2, 3   ,  3
    
    Link<T>* getPosPtr(int i) {
        Assert(-1 <= i, "Range of i: -1 <= i < size");
        if(i==-1) // i为-1则定位到头结点
            return head;
        
        Link<T> *p = head->next;// p循链定位，若i为0则p定位到第一个结点
        int count = 0;

        while (p != NULL && count < i) { // 雙條件保持 p & count 一致性;
            p = p-> next;                // p指向第 i 结点，i=0,1,...;
            count++;
        }
        return p; // 当 i >= size(链表中结点数) 返回 NULL
    }
    
    
    // 插入数据内容为value的新结点作为第i个结点
    bool insertPos(const int i, const T& value){
        curr = getPosPtr(i-1);// 第i个節点的指針為第i-1個(curr)
        if ( curr == NULL ) {
            cout << " 非法插入点"<< endl;
            return false;
        }
        
        Link<T> *link_to_insert = new Link<T>(value, curr->next);// 產生要插入的新結節點
        curr->next = link_to_insert; // 插入新值
        size+=1;
        
        if (curr == tail) // 若插入点在链尾，則插入结点成为新的链尾
            tail = link_to_insert;
        return true;
    };
    
    // 删除位置 p 上的元素，表的长度减一
    bool removePos(const int i) {
        curr = getPosPtr(i-1);// 第i个節点的指針為第i-1個(curr)
        if ( curr->next == NULL || curr == tail) {// 待删结点不存在，即给定的i大于当前链中元素个数
            cout << " 非法删除点"<< endl;
            return false;
        }
        
        Link<T> *link_to_delte = curr->next;
        if (link_to_delte == tail) {
            curr->next = NULL;
            tail = curr;
        }else{
            curr->next = link_to_delte->next;
        }
        delete link_to_delte;
        size --;
        return true;
    }
    
    // ---------------- Other File I/O ----------------
    // Append "value" to the end of list
    void append(const T& value) {
        tail->next = new Link<T>(value, NULL); // tail->next is always null
        tail = tail->next;
        size++;
    }
    
};



#endif /* LinkedList_hpp */
