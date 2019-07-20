# Useful C++ Stuff
## Websties
- [general](http://eel.is/c++draft/)
- [cppreference](https://en.cppreference.com/w/)
- [cplusplus](http://www.cplusplus.com)




## Vector
``` c++
#include <vector>
```
``` c++
// 1D Vector
vector<int> vec {1,2,5,-3};
// 2D Vector
vector<vector<int>> vec2d {{1,2}, {4,3}};
```
``` c++
// access/modify elements
vec[3]; // -3
vec2d[1][1] = -20; // 3 --> -20
vec.front(); // returns value of first element
vec.back(); // returns value of last element
```
``` c++
vec.push_back(value); // append to end

vec.insert(position, value); // insert

vec.erase(position); // erase at index

vec.pop_back(); // erase last element

vec.resize(10) // will add 0s to initialize extra elements
vec.resize(2) // will truncate vector and discard for reduced num elements

vec.size(); // get length/size

vec.empty(); // check if vector is empty

vec.clear(); // clear vector
```


## Strings
```c++
str.substring(position, n_elements_from_position)
str.find("find")
reverse(str.begin(), str.end())
```


## [Map vs Unordered Map](https://www.geeksforgeeks.org/map-vs-unordered_map-c/)
category | map | unordered_map
--- | --- | ---
Ordering | increasing  order (by default) | no ordering
Implementation | Self balancing BST (like Red-Black Tree) | Hash Table
Search Time | log(n) | O(1) -> Average <br/> O(n) -> Worst Case
Insertion time | log(n) + Rebalance | Same as search      
Deletion time | log(n) + Rebalance | Same as search

``` c++
#include <unordered_map>

int main() 
{ 
    // initializing
    unordered_map<string, int> umap = {{"Hey", 1}, {"listen!", -24}}; 

    // appending
    umap["Apple"] = 10; 
    umap["Pie"] = 20; 
    umap["is great!"] = 30; 

    // accessing through .first, .second
    for (auto x : umap) 
      cout << x.first << " " << x.second << endl; 

    // accessing through key
    umap["Apple"];
    umap["listen!"];
}
```



## Sorting
``` c++
#include <algorithm>
#include <vector>

int main() 
{
    vector<int> a = {5,1,2,5,6,1,9,-1};
    sort(a.begin(), a.end());
}
```

## Searching
``` c++
find(vec.begin(), vec.end(), value_to_find); // returns index of first occurence, returns last if not found
binary_search(vec.begin(), vec.end(), value_to_find) // returns True if found, False if not
```
