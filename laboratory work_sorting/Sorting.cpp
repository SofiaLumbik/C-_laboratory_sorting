#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

// Функция partition для разделения массива
template <typename T> // Шаблонная функция
int partition(std::vector<T>& arr, int low, int high) { // Функция для разделения массива на части
    T pivot = arr[high]; // Выбор опорного элемента
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]); // Обмен элементов
        }
    }
    std::swap(arr[i + 1], arr[high]); // Обмен элементов
    return i + 1;
}

// Функция quick_sort для быстрой сортировки
template <typename T>
void quick_sort(std::vector<T>& arr, int low, int high) { // Функция быстрой сортировки
    if (low < high) {
        int pi = partition(arr, low, high); // Вызов функции 
        quick_sort(arr, low, pi - 1); // Рекурсивный вызов для левой части
        quick_sort(arr, pi + 1, high); // Рекурсивный вызов для правой части
    }
}

// Функция quick_sort_random для быстрой сортировки с рандомным выбором опорного элемента
template <typename T>
void quick_sort_random(std::vector<T>& arr) {
    std::random_device rd; // Создание объекта для генерации случайных чисел
    std::mt19937 g(rd()); // Генератор случайных чисел
    std::shuffle(arr.begin(), arr.end(), g); // Перемешивание массива
    quick_sort(arr, 0, arr.size() - 1); // Вызов функции 
}

// Функция bubble_sort для сортировки пузырьком
template <typename T>
void bubble_sort(std::vector<T>& arr) { // Функция сортировки пузырьком
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]); // Обмен элементов
            }
        }
    }
}

// Функция merge для слияния двух подмассивов
template <typename T>
void merge(std::vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<T> L(arr.begin() + left, arr.begin() + left + n1); // Подмассив L
    std::vector<T> R(arr.begin() + mid + 1, arr.begin() + mid + 1 + n2); // Подмассив R

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++]; // Заполнение массива
        }
        else {
            arr[k++] = R[j++]; // Заполнение массива
        }
    }

    while (i < n1) {
        arr[k++] = L[i++]; // Заполнение массива
    }

    while (j < n2) {
        arr[k++] = R[j++]; // Заполнение массива
    }
}

// Функция merge_sort для сортировки слиянием
template <typename T>
void merge_sort(std::vector<T>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Определение середины
        merge_sort(arr, left, mid); // Рекурсивный вызов для левой части
        merge_sort(arr, mid + 1, right); // Рекурсивный вызов для правой части
        merge(arr, left, mid, right); // Вызов функции merge
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n); // Создание вектора
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];  // Ввод элементов массива
    }

    // Quick Sort with random pivot
    std::vector<int> arr_quick = arr;
    quick_sort_random(arr_quick);  // Вызов функции quick_sort_random
    std::cout << "Quick Sort with random pivot: ";
    for (auto num : arr_quick) {
        std::cout << num << " "; // Вывод отсортированного массива
    }
    std::cout << std::endl;

    // Bubble Sort
    std::vector<int> arr_bubble = arr;
    bubble_sort(arr_bubble); // Вызов функции bubble_sort
    std::cout << "Bubble Sort: ";
    for (auto num : arr_bubble) {
        std::cout << num << " "; // Вывод отсортированного массива
    }
    std::cout << std::endl;

    // Merge Sort
    std::vector<int> arr_merge = arr;
    merge_sort(arr_merge, 0, arr_merge.size() - 1); // Вызов функции merge_sort
    std::cout << "Merge Sort: ";
    for (auto num : arr_merge) {
        std::cout << num << " "; // Вывод отсортированного массива
    }
    std::cout << std::endl;

    return 0;
}
