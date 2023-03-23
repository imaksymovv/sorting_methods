#include <iostream>
#include <algorithm>
#include <vector>

void merge(std::vector<int>& arr) {
  if (arr.size() == 1) {
    return;
  } else if (arr.size() <= 2) {
    auto m = arr.begin();
    if (*m > *(m + 1)) {
      std::swap(*m, *(m + 1));
    }
    return;
  }
  int n = arr.size();
  std::vector<int> left(n % 2 + n / 2);
  std::vector<int> right(n / 2);
  auto i = arr.begin();
  auto j = left.begin();
  auto k = right.begin();
  for (i; j < left.end(); i++) {
    *j = *i;
    j++;
  }
  for (i; i < arr.end(); i++) {
   *k = *i;
    k++;
  }
  merge(left);
  merge(right);
  j = left.begin();
  k = right.begin();
  for (auto i = arr.begin(); i < arr.end(); i++) {
    if (j < left.end() && k < right.end() && *j < *k) {
      *i = *j;
      j++;
    } else if (k < right.end()) {
      *i = *k;
      k++;
    } else if (j < left.end()) {
      *i = *j;
      j++;
    }
  }
}

void sort(std::vector<int>& arr) {
  int n = arr.size();
  if (n < 2) {
    return;
  } else if (n == 2) {
    auto m = arr.begin();
    std::swap(*m, *(m + 1));
    return;
  }
  std::vector<int> left;
  std::vector<int> right;
  int left_size = 0;
  int right_size = 0;
  auto pivot = arr.end() - 1;
  auto i = arr.begin();
  for (i; i < arr.end() - 1; i++) {
    if (*pivot > *i) {
      left_size++;
    } else {
      right_size++;
    }
  }
  left.resize(left_size);
  right.resize(right_size);
  auto j = left.begin();
  auto k = right.begin();
  for (i = arr.begin(); i < arr.end(); i++) {
    if (j < left.end() && k < right.end() && *i < *pivot) {
      *j = *i;
      j++;
    } else if (*i != *pivot) {
      *k = *i;
      k++;
    }
  }
  if (left_size != 0) {
    sort(left);
  }
  if (right_size != 0) {
    sort(right);
  }
  j = left.begin();
  k = right.begin();
  for (i = arr.begin(); j < left.end(); i++) {
    *i = *j;
    j++;
  }
  *i = *pivot;
  for (i = arr.begin() + left.size() + 1; i < arr.end(); i++) {
    *i = *k;
    k++;
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
  auto m = memory.begin();
  auto i = arr.begin();
  for (i; i < arr.end(); i++) {
    std::cin >> *i;
    *m = *i;
    m++;
  }
  std::cout << "\nbubble sort\n";
  do {
    for (i = arr.begin(); i + 1 < arr.end(); i++) {
      if (*i > *(i + 1)) {
        std::swap(*i, *(i + 1));
      }
    }
    counter++;
  } while (counter != iterations);
  counter = 0;
  for (i = arr.begin(); i < arr.end(); i++) {
    std::cout << *i;
  }
  m = memory.begin();
  for (i = arr.begin(); i < arr.end(); i++) {
    *i = *m;
    m++;
  }

  std::cout << "\nshaker sort\n";
  auto left_border = arr.begin();
  auto right_border = arr.end()-1;
  while (left_border < right_border) {
    for (i = left_border; i < right_border; i++) {
      if (*i > *(i + 1)) {
        std::swap(*i, *(i + 1));
      }
    }
    right_border--;

    for (i = right_border; i > left_border; i--) {
      if (*i < *(i - 1)) {
        std::swap(*i, *(i - 1));
      }
    }
    left_border++;
  }

  for (i = arr.begin(); i < arr.end(); i++) {
    std::cout << *i;
  }
  m = memory.begin();
  for (i = arr.begin(); i < arr.end(); i++) {
    *i = *m;
    m++;
  }

  std::cout << "\ncomb sort\n";
  size_t distance = n - 1;
  while (distance >= 1) {
    for (i = arr.begin(); i + distance < arr.end(); i++) {
      if (*i > *(i + distance)) {
        std::swap(*i, *(i + distance));
      }
    }
    distance--;
  }

  for (i = arr.begin(); i < arr.end(); i++) {
    std::cout << *i;
  }
  m = memory.begin();
  for (i = arr.begin(); i < arr.end(); i++) {
    *i = *m;
    m++;
  }
  
  std::cout << "\ninsertion sort\n";
  for (i = arr.begin() + 1; i < arr.end(); i++) {
    int number = *i;
    auto j = i;
    while (j > arr.begin() && *(j - 1) > number) {
      *j = *(j - 1);
      j--;
    }
    *j = number;
  }
  
  for (i = arr.begin(); i < arr.end(); i++) {
    std::cout << *i;
  }
  m = memory.begin();
  for (i = arr.begin(); i < arr.end(); i++) {
    *i = *m;
    m++;
  }

  std::cout << "\n";
  std::cout << "insertion by choice" << std::endl;
  for (auto i = arr.begin(); i < arr.end(); i++) {
    for (auto j = i + 1; j < arr.end(); j++) {
      if (*i > *j) {
        std::swap(*i, *j);
      }
    }
  }

  for (i = arr.begin(); i < arr.end(); i++) {
    std::cout << *i;
  }
  m = memory.begin();
  for (i = arr.begin(); i < arr.end(); i++) {
    *i = *m;
    m++;
  }

  std::cout << "\nmerge sort\n";
  merge(arr);

  for (i = arr.begin(); i < arr.end(); i++) {
    std::cout << *i;
  }
  m = memory.begin();
  for (i = arr.begin(); i < arr.end(); i++) {
    *i = *m;
    m++;
  }

  std::cout << "\nquick sort\n";
  sort(arr);

  for (i = arr.begin(); i < arr.end(); i++) {
    std::cout << *i;
  }
  return 0;
}