#include <iostream>
#include <algorithm>
#include <vector>

void merge(std::vector<int>& arr, int low, int mid, int high) {
  std::vector<int> temp(high - low + 1);
  int i = low;
  int j = mid + 1;
  int k = 0;

  while (i <= mid && j <= high) {
    if (arr[i] < arr[j]) {
      temp[k] = arr[i];
      i++;
    } else {
      temp[k] = arr[j];
      j++;
    }
    k++;
  }

  while (i <= mid) {
    temp[k] = arr[i];
    k++;
    i++;
  }

  while (j <= high) {
    temp[k] = arr[j];
    k++;
    j++;
  }

  for (size_t i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }
}

void mergeSort(std::vector<int>& arr, int low, int high) {
  if (low >= high) {
    return;
  }
  int mid = low + (high - low) / 2;

  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);

  merge(arr, low, mid, high);
}

int separation(std::vector<int>& arr, int low, int high) {
  int pivot = arr[high];
  int j = low - 1;
  for (size_t i = low; i < high; i++) {
    if (arr[i] < pivot) {
      j++;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[j + 1], arr[high]);
  return j + 1;
}

void QuickSort(std::vector<int>& arr, int low, int high) {
  if (low < high) {
    int pivot_index = separation(arr, low, high);
    QuickSort(arr, low, pivot_index - 1);
    QuickSort(arr, pivot_index + 1, high);
  }
}

int main() {
  std::vector<int> arr;
  std::vector<int> memory;
  size_t n = 0;
  int iterations = 0;
  int counter = 0;
  std::cout << "input array size(max size 100): ";
  std::cin >> n;
  arr.resize(n);
  memory.resize(n);
  iterations = (n * (n + 1)) / 2;
  std::cout << "\nnow input array characters: ";
  for (size_t i = 0; i < n; i++) {
    std::cin >> arr[i];
    memory[i] = arr[i];
  }
  std::cout << "\nbubble sort\n";
  do {
    for (size_t i = 0; i + 1 < n; i++) {
      if (arr[i] > arr[i + 1]) {
        std::swap(arr[i], arr[i + 1]);
      }
    }
    counter++;
  } while (counter != iterations);
  counter = 0;
  for (size_t i = 0; i < n; i++) {
    std::cout << arr[i];
  }
  for (size_t i = 0; i < n; i++) {
    arr[i] = memory[i];
  }

  std::cout << "\nshaker sort\n";
  size_t left_border = 0;
  size_t right_border = n-1;
  while (left_border < right_border) {
    for (size_t i = left_border; i < right_border; i++) {
      if (arr[i] > arr[i + 1]) {
        std::swap(arr[i], arr[i + 1]);
      }
    }
    right_border--;

    for (size_t i = right_border; i > left_border; i--) {
      if (arr[i] < arr[i - 1]) {
        std::swap(arr[i], arr[i - 1]);
      }
    }
    left_border++;
  }

  for (size_t i = 0; i < n; i++) {
    std::cout << arr[i];
  }
  for (size_t i = 0; i < n; i++) {
    arr[i] = memory[i];
  }

  std::cout << "\ncomb sort\n";
  size_t distance = n - 1;
  while (distance >= 1) {
    for (int i = 0; i + distance < n; i++) {
      if (arr[i] > arr[i + distance]) {
        std::swap(arr[i], arr[i + distance]);
      }
    }
    distance--;
  }

  for (size_t i = 0; i < n; i++) {
    std::cout << arr[i];
  }
  for (size_t i = 0; i < n; i++) {
    arr[i] = memory[i];
  }
  
  std::cout << "\ninsertion sort\n";
  for (size_t i = 1; i < n; i++) {
    int number = arr[i];
    size_t j = i;
    while (j > 0 && arr[j-1] > number) {
      arr[j] = arr[j-1];
      j--;
    }
    arr[j] = number;
  }
  
  for (size_t i = 0; i < n; i++) {
    std::cout << arr[i];
  }
  for (size_t i = 0; i < n; i++) {
    arr[i] = memory[i];
  }

  std::cout << "\n";
  std::cout << "insertion by choice" << std::endl;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        std::swap(arr[i], arr[j]);
      }
    }
  }

  for (size_t i = 0; i < n; i++) {
    std::cout << arr[i];
  }
  for (size_t i = 0; i < n; i++) {
    arr[i] = memory[i];
  }

  std::cout << "\nmerge sort\n";
  mergeSort(arr, 0, n - 1);

  for (size_t i = 0; i < n; i++) {
    std::cout << arr[i];
  }
  for (size_t i = 0; i < n; i++) {
    arr[i] = memory[i];
  }

  std::cout << "\nquick sort\n";
  QuickSort(arr, 0, n - 1);

  for (size_t i = 0; i < n; i++) {
    std::cout << arr[i];
  }
  return 0;
}