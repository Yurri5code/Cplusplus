#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    std::vector<int> array;
    size_t size (0);
    std::cin >>size;
    for(int i = 0;i < size;i++) {
        int x(0);
        std::cin>>x;
        array.push_back(x);
    }
    std::sort(array.begin(),array.end());
    for(int i = 0; i < size;i++) {
        std::cout << array[i]<<" ";
    }
    return 0;
}

//code avec std::ranges
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> array;
    size_t size (0);
    std::cin >>size;
    for(int i = 0;i < size;i++) {
        int x(0);
        std::cin>>x;
        array.push_back(x);
    }
    std::ranges::sort(array);
    for(int i = 0; i < size;i++) {
        std::cout << array[i]<<" ";
    }
    return 0;
}
