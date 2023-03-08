#include <iostream>

int main() {
  std::cout << "Hello World!\n";
  int a = 5;
  int *px = &a;
  std :: cout << px << std :: endl;
  std :: cout << *px + 1 << std :: endl;
}
