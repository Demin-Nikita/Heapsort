#include <iostream>
#include <time.h>

bool is_sorted(int arr[], int n);
void print_tts(int arr[], int n);
void printArray(int arr[], int n);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

int main() {
    const size_t arr_size = 100000;
    int arr[arr_size] = {};

    std::cout << "/-----------------------ascending-----------------------/" << '\n';
    int k = 0;
    for (int i = 0; i < arr_size*10; i++) {
        if (rand() % 9 == 7) {
            arr[k] = i;
            k++;
            if (k == arr_size) { break; }
        }
    }

    std::cout << "Part of array before sorting: ";
    for (int i = 0; i < 10; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';

    std::cout << "Is sorted? >> " << is_sorted(arr, arr_size) << '\n';
    print_tts(arr, arr_size);
    std::cout << "Is sorted? >> " << is_sorted(arr, arr_size) << '\n';

    std::cout << "/-----------------------descending----------------------/" << '\n';
    k = 0;
    for (int i = arr_size*10; i > 0; i--) {
        if (rand() % 9 == 4) {
            arr[k] = i;
            k++;
            if (k == arr_size) { break; }
        }
    }

    std::cout << "Part of array before sorting: ";
    for (int i = 0; i < 10; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';

    std::cout << "Is sorted? >> " << is_sorted(arr, arr_size) << '\n';
    print_tts(arr, arr_size);
    std::cout << "Is sorted? >> " << is_sorted(arr, arr_size) << '\n';


    std::cout << "/------------------------average------------------------/" << '\n';
    for (int i = 0; i < arr_size; i++)
        arr[i] = rand() % 80000;

    std::cout << "Part of array before sorting: ";
    for (int i = 0; i < 10; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';

    std::cout << "Is sorted? >> " << is_sorted(arr, arr_size) << '\n';
    print_tts(arr, arr_size);
    std::cout << "Is sorted? >> " << is_sorted(arr, arr_size) << '\n';
    
    return 0;
}

void heapify(int arr[], int n, int i) {
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[max]) {
        max = left;
    }

    if (right < n && arr[right] > arr[max]){
        max = right;
    }

    if (max != i) {
        std::swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

bool is_sorted(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void print_tts(int arr[], int n) {
    clock_t start = clock();
    heapSort(arr, n);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << seconds;
    std::cout << '\n';
}