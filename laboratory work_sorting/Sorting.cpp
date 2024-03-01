#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
void quick_sort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

template <typename T>
void quick_sort_random(std::vector<T>& arr) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(arr.begin(), arr.end(), g);
    quick_sort(arr, 0, arr.size() - 1);
}

template <typename T>
void bubble_sort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
void merge(std::vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<T> L(arr.begin() + left, arr.begin() + left + n1);
    std::vector<T> R(arr.begin() + mid + 1, arr.begin() + mid + 1 + n2);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

template <typename T>
void merge_sort(std::vector<T>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // Quick Sort with random pivot
    std::vector<int> arr_quick = arr;
    quick_sort_random(arr_quick);
    std::cout << "Quick Sort with random pivot: ";
    for (auto num : arr_quick) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Bubble Sort
    std::vector<int> arr_bubble = arr;
    bubble_sort(arr_bubble);
    std::cout << "Bubble Sort: ";
    for (auto num : arr_bubble) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Merge Sort
    std::vector<int> arr_merge = arr;
    merge_sort(arr_merge, 0, arr_merge.size() - 1);
    std::cout << "Merge Sort: ";
    for (auto num : arr_merge) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}


