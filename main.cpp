#include <iostream>
#include <algorithm> //for std::swap

// Function 
void heapSortDescending(int arr[], int n, long long &comps, long long &swaps);

int main() {
    int n;
    
    std::cout << "Enter the number of integers to sort: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "Invalid input size." << std::endl;
        return 1;
    }

    //Dynamically allocate memory
    int* data = new (std::nothrow) int[n];
    if (!data) {
        std::cerr << "Memory allocation failed for " << n << " items." << std::endl;
        return 1;
    }

    //Accept the unsorted list
    std::cout << "Enter the " << n << " integers (separated by spaces or newlines):" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> data[i];
    }

    long long comps = 0;
    long long swaps = 0;

    //Perform the manual sort
    heapSortDescending(data, n, comps, swaps);

    //Output the result
    std::cout << "\n--- Execution Results ---" << std::endl;
    if (n <= 100) {
        std::cout << "Sorted List: ";
        for (int i = 0; i < n; i++) std::cout << data[i] << " ";
        std::cout << std::endl;
    } else {
        std::cout << "List is too large to display entirely." << std::endl;
        std::cout << "First 10 elements: ";
        for (int i = 0; i < 10; i++) std::cout << data[i] << " ";
        std::cout << "..." << std::endl;
    }

    //Display statistics
    std::cout << "Total Comparisons: " << comps << std::endl;
    std::cout << "Total Swaps: " << swaps << std::endl;

    // 7. Cleanup
    delete[] data;
    return 0;
}

// Manual Heapsort Implementation (Descending order using Min-Heap logic)
void heapSortDescending(int arr[], int n, long long &comps, long long &swaps) {
    
    //Build the Min-Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        int curr = i;
        while (true) {
            int left = 2 * curr + 1;
            int right = 2 * curr + 2;
            int smallest = curr;

            if (left < n) {
                comps++;
                if (arr[left] < arr[smallest]) smallest = left;
            }
            if (right < n) {
                comps++;
                if (arr[right] < arr[smallest]) smallest = right;
            }

            if (smallest != curr) {
                std::swap(arr[curr], arr[smallest]);
                swaps++;
                curr = smallest;
            } else {
                break;
            }
        }
    }

    // Extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        // Swap root (minimum) with the last unsorted element
        std::swap(arr[0], arr[i]);
        swaps++;
        
        // Re-heapify the remaining elements
        int curr = 0;
        while (true) {
            int left = 2 * curr + 1;
            int right = 2 * curr + 2;
            int smallest = curr;

            if (left < i) { // Note: 'i' is the current heap size
                comps++;
                if (arr[left] < arr[smallest]) smallest = left;
            }
            if (right < i) {
                comps++;
                if (arr[right] < arr[smallest]) smallest = right;
            }

            if (smallest != curr) {
                std::swap(arr[curr], arr[smallest]);
                swaps++;
                curr = smallest;
            } else {
                break;
            }
        }
    }
}