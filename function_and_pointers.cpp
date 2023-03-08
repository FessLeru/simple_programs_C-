#include <iostream>

using namespace std;

bool Check_array(int *pArr, const int *px){
  for (int i = 0; i < (*px); ++i){
    if (pArr[i] == 0){
      return true;
    } 
  }
  return false;
}

int main() {
  const int SIZE = 5;
  int arr[SIZE]{0, 2, 3, 4, 5};
  bool result = Check_array(arr, &SIZE);
  cout << result;
}
