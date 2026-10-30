#pragma once
#include <functional>
#include "Vector.h"
template<typename T>
class UnorderedSet{
    Vector<Vector<T>>buckets;
    int m;
    int cnt;
    size_t hash(const T& value){
        size_t h=std::hash<T>()(value);
        h^=h>>16;
        h*=0x45d9f3b;
        h^=h>>16;
        return h;
    }
    void rehash(){
        int nm=2*m;
        Vector<Vector<T>>nb(nm);
        for(int i=0;i<m;i++){
            for(int j=0;j<buckets[i].size();j++){
                nb[hash(buckets[i][j])%nm].push_back(buckets[i][j]);
            }
        }
        buckets=nb;
        m=nm;
    }
    public:
    UnorderedSet():buckets(8),m(8),cnt(0){
    }
    bool count(T value){
        Vector<T>&b=buckets[hash(value)%m];
        for(int i=0;i<b.size();i++){
            if(b[i]==value)return true;
        }
        return false;
    }
    void insert(T value){
        if(count(value))return;
        if(cnt+1>m)rehash();
        buckets[hash(value)%m].push_back(value);
        cnt++;
    }
    void erase(T value){
        Vector<T>&b=buckets[hash(value)%m];
        for(int i=0;i<b.size();i++){
            if(b[i]==value){
                b[i]=b[b.size()-1];
                b.pop_back();
                cnt--;
                return;
            }
        }
    }
    bool empty(){
        return cnt==0;
    }
    int size(){
        return cnt;
    }
};
