#include <iostream>
using namespace std;

void begin(double *array, int n) {
  cout << "Starting array:\n";
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }
}

void print(double *array, int n) {
  cout << "The array is: ";
  for (int i = 0; i < n; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

int removeOccurrences(double *p, int n, double x){
  int v = 0;
  for(int i = 0; i < n;){ //Here, we check if the value of the array is equal to x.
    if(*(p+i) == x){
      v ++;
      for(int j = i; j < n - 1; j++){ //Here, we will change all the values of the array that are equal to x.
        *(p+j) = *(p+j+1);
      }
      n --;
    }
    else{
      i ++;
    }
  }
  return v;
}


int main() {
  int n;
  float x;
  cout << "Enter the size of the array: ";
  cin >> n;
  double array[n];
  begin(array, n);
  print(array, n);
  cout << "Enter the element you want to remove: ";
  cin >> x;
  n = n - removeOccurrences(array, n, x);
  print(array, n);
  return 0;
}