#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
int binary_search_rec(const T& array, int value, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (array[mid] == value)
        return mid;
    if (value < array[mid])
        return binary_search_rec(array, value, low, mid - 1);
    return binary_search_rec(array, value, mid + 1, high);
}

using namespace std;

int main() {
    std::vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(10);
    arr.push_back(40);

    int x = 2;
    int result = binary_search_rec(arr, x,0,arr.size()-1);
    if(result == -1) cout << "Element is not present in array";
    else cout << "Element is present at index " << result;
    return 0;
}