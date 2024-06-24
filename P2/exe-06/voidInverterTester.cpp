#include <iostream>
using namespace std;

void begin(double *array, int n) {
  cout << "Starting array:\n";
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }
}

void inverter(double *p, int n) {
  for (int i = 0; i < n / 2; i++) {
    int temp = *(p + i); // This is similar to temp = p[i]
    /* This is a technique called Pointer Indexing, that allows acessing
       elements of an array using pointer arithmetic.
    */
    *(p + i) = *(p + n - i - 1);
    *(p + n - i - 1) = temp;
  }
  cout << "The array was inverted\n";
}

void print(double *array, int n) {
  cout << "The array is: ";
  for (int i = 0; i < n; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cout << "Enter the size of the array: ";
  cin >> n;
  double array[n];
  begin(array, n);
  print(array, n);
  inverter(array, n);
  print(array, n);
  return 0;
}