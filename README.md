<img src="assets/icon.svg" width="64" height="64" alt="">

# cpp-containers-from-scratch

C++ standard library containers implemented from scratch, using raw memory and no STL containers. `Set` and `PriorityQueue` are built on a dynamic segment tree instead of the usual red-black tree and binary heap.

## Containers

| Container | File | Built on | Operations |
|---|---|---|---|
| `Vector<T>` | `Vector.h` | array that doubles when full | `push_back`, `pop_back`, `[]`, `size`, `empty`, `sort`, `lower_bound`, `upper_bound` |
| `Deque<T>` | `Deque.h` | array filled from the middle | `push_back`, `push_front`, `pop_back`, `pop_front`, `front`, `back`, `[]`, `size`, `empty` |
| `Set<T>` | `Set.h` | dynamic segment tree | `insert`, `erase`, `count`, `kth`, `minimum`, `maximum`, `size`, `empty` |
| `PriorityQueue<T>` | `PriorityQueue.h` | dynamic segment tree | `push`, `pop`, `top`, `size`, `empty` |
| `UnorderedSet<T>` | `UnorderedSet.h` | hash table of `Vector` buckets | `insert`, `erase`, `count`, `size`, `empty` |

## Complexity

`U` is the size of the value range, `hi - lo + 1`.

| Container | Operation | Time |
|---|---|---|
| `Vector` | `push_back` | O(1) amortized |
| `Vector` | `sort` | O(n log n) |
| `Vector` | `lower_bound`, `upper_bound` | O(log n) |
| `Deque` | `push_back`, `push_front` | O(1) amortized |
| `Set` | all except `size`, `empty` | O(log U) |
| `PriorityQueue` | `push`, `pop`, `top` | O(log U) |
| `UnorderedSet` | `insert`, `erase`, `count` | O(1) on average, O(n) worst case |

## Usage

The containers are header-only and need C++11 or newer. Copy the headers into your project and include the ones you need. `Set`, `PriorityQueue` and `UnorderedSet` also need `Vector.h`.

```cpp
#include "Vector.h"
#include "Deque.h"
#include "Set.h"
#include "PriorityQueue.h"
#include "UnorderedSet.h"
#include <iostream>
#include <string>

int main(){
    Vector<int> v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(3);
    v.sort();
    std::cout<<v.lower_bound(3)<<"\n";   // 1

    Deque<int> d;
    d.push_back(2);
    d.push_front(1);
    std::cout<<d.front()<<"\n";          // 1

    Set<int> s(-1000000000,1000000000);  // the range of allowed values
    s.insert(7);
    s.insert(-3);
    std::cout<<s.minimum()<<"\n";        // -3
    std::cout<<s.kth(2)<<"\n";           // 7

    PriorityQueue<int> pq(0,100);
    pq.push(5);
    pq.push(9);
    std::cout<<pq.top()<<"\n";           // 9

    UnorderedSet<std::string> names;
    names.insert("apple");
    std::cout<<names.count("apple")<<"\n"; // 1
}
```
