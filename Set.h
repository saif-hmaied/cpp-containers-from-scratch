#pragma once
#include <type_traits>
#include "Vector.h"
template<typename T>
class Set{
    static_assert(std::is_integral<T>::value,"Set only supports integer types");
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
    T kth(int node,T l,T r,int k){
        if(l==r)return l;
        T mid=l+(r-l)/2;
        if(tree[node].left!=-1&&tree[tree[node].left].cnt>=k)return kth(tree[node].left,l,mid,k);
        else return kth(tree[node].right,mid+1,r,k-(tree[node].left!=-1?tree[tree[node].left].cnt:0));
    }
    bool count(int node,T l,T r,T value){
        if(l==r)return tree[node].cnt==1;
        T mid=l+(r-l)/2;
        if(value<=mid){
            return (tree[node].left==-1?false:count(tree[node].left,l,mid,value));
        }else return (tree[node].right==-1?false:count(tree[node].right,mid+1,r,value));
    }
    T minimum(int node,T l,T r){
        if(l==r)return l;
        T mid=l+(r-l)/2;
        if(tree[node].left!=-1&&tree[tree[node].left].cnt)return minimum(tree[node].left,l,mid);
        else return minimum(tree[node].right,mid+1,r);
    }
    T maximum(int node,T l,T r){
        if(l==r)return l;
        T mid=l+(r-l)/2;
        if(tree[node].right!=-1&&tree[tree[node].right].cnt)return maximum(tree[node].right,mid+1,r);
        else return maximum(tree[node].left,l,mid);
    }
    public:
    Set(T lo,T hi):lo(lo),hi(hi){
        tree.push_back(Node());
    }
    bool count(T value){
        return count(0,lo,hi,value);
    }
    void insert(T value){
        if(count(value))return;
        insert(0,lo,hi,value);
    }
    T kth(int k){
        return kth(0,lo,hi,k);
    }
    void erase(T value){
        if(!count(value))return;
        erase(0,lo,hi,value);
    }
    bool empty(){
        return tree[0].cnt==0;
    }
    int size(){
        return tree[0].cnt;
    }
    T minimum(){
        return minimum(0,lo,hi);
    }
    T maximum(){
        return maximum(0,lo,hi);
    }
};
