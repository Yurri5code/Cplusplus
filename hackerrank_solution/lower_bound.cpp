#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool isHereElement(const std::vector<int>& arr, const int el, int* index) {
    auto it = std::lower_bound(arr.begin(), arr.end(), el);
    if (it != arr.end() && *it == el) {
        *index = std::distance(arr.begin(), it);
        return true;
    }
    return false;
}

int main() {
    int nbrInt = 0;
    std::cin >> nbrInt;
    std::vector<int> array(nbrInt, 0);

    for (int i = 0; i < nbrInt; i++) {
        std::cin >> array[i];
    }
    std::sort(array.begin(), array.end());

    int queries = 0;
    std::cin >> queries;
    std::vector<int> queriesArray(queries, 0);

    for (int i = 0; i < queries; i++) {
        std::cin >> queriesArray[i];
    }

    int index = 0;
    for (int i = 0; i < queriesArray.size(); i++) {
        if (isHereElement(array, queriesArray[i], &index)) {
            std::cout << "Yes " << index + 1 << std::endl;
        } else {
            auto indexLowerBound = std::lower_bound(array.begin(), array.end(), queriesArray[i]);
            std::cout << "No " << std::distance(array.begin(), indexLowerBound) + 1 << std::endl;
        }
    }
    return 0;
}
