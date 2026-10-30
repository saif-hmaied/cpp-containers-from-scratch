#pragma once
template<typename T>
class Deque{
    T* a;
    int head;   
    int tail;   
    int n;      
    public:
    Deque():head(4),tail(4),n(8){
        a=new T[n]();
    }
    Deque(int sz):n(sz>4?2*sz:8){
        head=(n-sz)/2;
        tail=head+sz;
        a=new T[n]();
    }
    Deque(int sz,const T& value):n(sz>4?2*sz:8){
        head=(n-sz)/2;
        tail=head+sz;
        a=new T[n];
        for(int i=head;i<tail;i++){
            a[i]=value;
        }
    }
    Deque(const Deque &other):head(other.head),tail(other.tail),n(other.n){
        a=new T[n];
        for(int i=head;i<tail;i++){
            a[i]=other.a[i];
        }
    }
    Deque &operator=(const Deque &other){
        if(this==&other)return *this;
        delete[] a;
        head=other.head;
        tail=other.tail;
        n=other.n;
        a=new T[n];
        for(int i=head;i<tail;i++){
            a[i]=other.a[i];
        }
        return *this;
    }
    T &operator[](int i){
        return a[head+i];
    }
    void check(){
        if(head>0&&tail<n)return;
        int sz=tail-head;
        int nn=(2*sz>=n?2*n:n);   
        T* na=new T[nn]();
        int nh=(nn-sz)/2;
        for(int i=0;i<sz;i++){
            na[nh+i]=a[head+i];
        }
        delete[] a;
        a=na;
        n=nn;
        head=nh;
        tail=nh+sz;
    }
    void push_back(T value){
        check();
        a[tail++]=value;
    }
    void push_front(T value){
        check();
        a[--head]=value;
    }
    void pop_back(){
        tail--;
    }
    void pop_front(){
        head++;
    }
    T &front(){
        return a[head];
    }
    T &back(){
        return a[tail-1];
    }
    bool empty(){
        return head==tail;
    }
    int size(){
        return tail-head;
    }
    ~Deque(){
        delete[] a;
    }
};
