#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>


namespace search {
namespace favorite_search {
uint64_t func(std::vector<uint64_t> arr, uint64_t val) {
    uint64_t low = 0;
    uint64_t high = arr.size() - 1;

    while (low <= high) {
        uint64_t m = low + (high - low) / 2;

        if (val == arr[m]) {
            return m;
        }
        else if (val < arr[m]) {
            high = m - 1;
        } else {
            low = m + 1;
        }
    }
    return -1;
}
}  // namespace favorite_search
}  // namespace search

void test() {    
    std::cout << "Initiatinig Predefined Tests..." << std::endl;
    std::cout << "Initiating Test 1..." << std::endl;

    std::vector<uint64_t> arr = {{1, 3, 5, 7, 9, 8, 6, 4, 2}};
    std::sort(arr.begin(), arr.end());

    assert(search::favorite_search::func(arr, 4) == 3);
    std::cout << "Test 1 Passed..." << std::endl;

    std::cout << "Initiating Test 2..." << std::endl;

    arr = {{1, 23, 25, 4, 2}};
    std::sort(arr.begin(), arr.end());

    assert(search::favorite_search::func(arr, 25) == 4);
    std::cout << "Test 2 Passed..." << std::endl;

    std::cout << "Initiating Test 3..." << std::endl;

    arr = {{1, 31, 231, 12, 2, 5, 51, 21, 23, 12, 3}};
    std::sort(arr.begin(), arr.end());

    assert(search::favorite_search::func(arr, 31) == 8);
    std::cout << "Test 3 Passed..." << std::endl;
    std::cout << "All Test Passed..." << std::endl;
}

int main() {
    test();

    return 0;
}
