#include <iostream>
#include <algorithm>

void heapSortDescending(int arr[], int n, long long &comps, long long &swaps);

int main() {
    int n;
    std::cout << "Enter the number of integers to sort: ";
    if (!(std::cin >> n) || n <= 0) return 1;

    int* data = new (std::nothrow) int[n];
    if (!data) return 1;

    for (int i = 0; i < n; i++) std::cin >> data[i];

    long long comps = 0, swaps = 0;
    heapSortDescending(data, n, comps, swaps);

    std::cout << "Comparisons: " << comps << "\nSwaps: " << swaps << std::endl;
    delete[] data;
    return 0;
}

void heapSortDescending(int arr[], int n, long long &comps, long long &swaps) {
    // Sorting logic to be implemented
}