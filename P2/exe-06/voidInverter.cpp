#include <iostream>
using namespace std;

void begin(int *array, int n) {
  for (int i = 0; i < n; i++) {
    array[i] = i + 1;
  }
}

void inverter(int *p, int n) {
  for (int i = 0; i < n / 2; i++) {
    int temp = *(p + i); // This is similar to temp = p[i]
    /* This is a technique called Pointer Indexing, that allows acessing
       elements of an array using pointer arithmetic.
    */
    *(p + i) = *(p + n - i - 1);
    *(p + n - i - 1) = temp;
  }
}

void print(int *array, int n) {
  cout << "The array is: ";
  for (int i = 0; i < n; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

int main() {
  int n = 10;
  int array[n];
  begin(array, n);
  print(array, n);
  inverter(array, n);
  print(array, n);
  return 0;
}