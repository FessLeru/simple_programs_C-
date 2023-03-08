/*Complete the solution so that it returns true if the first argument(string) passed in ends with the 2nd argument (also a string).

Examples:

solution('abc', 'bc') // returns true
solution('abc', 'd') // returns false*/

#include <iostream>
#include <string>


using namespace std;

bool solution(std::string const &str, std::string const &ending) {
    int count = ending.length() - 1;
    for (int i = str.length()- 1; i >= 0; --i){
      if (count == -1){
        return true;
      }
      if (str[i] != ending[count]){
        return false;
      }
      --count;
    }
    return true;
}

int main() {
  string a = "abcde";
  string b = "abc";
  cout << solution(a, b);
}
  
