#pragma once
template<typename T>
class Vector{
    T* a;
    int cur;
    int n;
    public:
    Vector():cur(0),n(8){
        a=new T[n]();
    }
    Vector(int sz):cur(sz),n(sz>4?2*sz:8){
        a=new T[n]();
    }
    Vector(int sz,const T& value):cur(sz),n(sz>4?2*sz:8){
        a=new T[n];
        for(int i=0;i<cur;i++){
            a[i]=value;
        }
    }
    Vector(const Vector &other):cur(other.cur),n(other.n){
        a=new T[n];
        for(int i=0;i<cur;i++){
            a[i]=other.a[i];
        }
    }
    void mergesort(int l,int r,T* tmp){
        if(l>=r)return;
        int mid=(l+r)/2;
        mergesort(l,mid,tmp);
        mergesort(mid+1,r,tmp);
        int i=l,j=mid+1,k=l;
        while(i<=mid&&j<=r){
            if(a[j]<a[i])tmp[k++]=a[j++];
            else tmp[k++]=a[i++];
        }
        while(i<=mid)tmp[k++]=a[i++];
        while(j<=r)tmp[k++]=a[j++];
        for(int i=l;i<=r;i++){
            a[i]=tmp[i];
        }
    }
    public:
    T &operator[](int i){
        return a[i];
    }
    Vector &operator=(const Vector &other){
        if(this==&other)return *this;
        delete[] a;
        cur=other.cur;
        n=other.n;
        a=new T[n];
        for(int i=0;i<cur;i++){
            a[i]=other.a[i];
        }
        return *this;
    }
    void sort(){
        if(cur<2)return;
        T* tmp=new T[cur];
        mergesort(0,cur-1,tmp);
        delete[] tmp;
    }
    int lower_bound(T value){
        int l=0,r=cur-1;
        int res=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(a[mid]>=value){
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return res;
    }
    int upper_bound(T value){
        int l=0,r=cur-1;
        int res=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(a[mid]>value){
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return res;
    }
    void check(){
        if(cur<n)return;
        T* na=new T[2*n]();
        for(int i=0;i<n;i++){
            na[i]=a[i];
        }
        delete[] a;
        a=na;
        n=2*n;
    }
    void push_back(T value){
        check();
        a[cur++]=value;
    }
    bool empty(){
        return cur==0;
    }
    void pop_back(){
        cur--;
    }
    int size(){
        return cur;
    }
    ~Vector(){
        delete[] a;
    }
};

