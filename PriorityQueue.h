#pragma once
#include <type_traits>
#include "Vector.h"
template<typename T>
class PriorityQueue{
    static_assert(std::is_integral<T>::value,"PriorityQueue only supports integer types");
    struct Node{
        int left,right,cnt;
        Node():left(-1),right(-1),cnt(0){
        }
    };
    Vector<Node>tree;
    T lo,hi;
    void insert(int node,T l,T r,T value){
        tree[node].cnt++;
        if(l==r)return;
        T mid=l+(r-l)/2;
        if(value<=mid){
            if(tree[node].left==-1){
                tree[node].left=tree.size();
                tree.push_back(Node());
            }
            insert(tree[node].left,l,mid,value);
        }else{
            if(tree[node].right==-1){
                tree[node].right=tree.size();
                tree.push_back(Node());
            }
            insert(tree[node].right,mid+1,r,value);
        }
    }
    void erase(int node,T l,T r,T value){
        tree[node].cnt--;
        if(l==r)return;
        T mid=l+(r-l)/2;
        if(value<=mid){
            erase(tree[node].left,l,mid,value);
        }else{
            erase(tree[node].right,mid+1,r,value);
        }
    }
    T maximum(int node,T l,T r){
        if(l==r)return l;
        T mid=l+(r-l)/2;
        if(tree[node].right!=-1&&tree[tree[node].right].cnt)return maximum(tree[node].right,mid+1,r);
        else return maximum(tree[node].left,l,mid);
    }
    public:
    PriorityQueue(T lo,T hi):lo(lo),hi(hi){
        tree.push_back(Node());
    }
    void push(T value){
        insert(0,lo,hi,value);
    }
    T top(){
        return maximum(0,lo,hi);
    }
    void pop(){
        erase(0,lo,hi,top());
    }
    bool empty(){
        return tree[0].cnt==0;
    }
    int size(){
        return tree[0].cnt;
    }
};
