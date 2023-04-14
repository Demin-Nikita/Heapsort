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
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]){
        largest = r;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
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