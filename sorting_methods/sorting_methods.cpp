#include <iostream>
#include <algorithm>

int main() {
  int arr[100];
  int memory[100];
  size_t n = 0;
  int iterations = 0;
  int counter = 0;
  std::cout << "input array size(max size 100): ";
  std::cin >> n;
  iterations = (n * (n + 1)) / 2;
  std::cout << "\n";
  std::cout << "now input array characters: ";
  for (size_t i = 0; i < n; i++) {
    std::cin >> arr[i];
    memory[i] = arr[i];
  }
  std::cout << "bubble sort" << std::endl;
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

  std::cout << "\n";
  std::cout << "shaker sort" << std::endl;
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

  std::cout << "\n";
  std::cout << "comb sort" << std::endl;
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

  std::cout << "\n";
  std::cout << "insertion sort" << std::endl;
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

  return 0;
}