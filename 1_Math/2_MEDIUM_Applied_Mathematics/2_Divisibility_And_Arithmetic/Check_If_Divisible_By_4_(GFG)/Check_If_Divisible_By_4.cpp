#include <cmath>
#include <iostream>
#include <numeric> // in case we use accumulate
#include <string>


using namespace std;

class Solution {
public:
  // Time: O(1), Space: O(1)
  int divisibleBy4_modulo(const string &N) {
    int num = stoi(N);
    return (num % 4 == 0) ? 1 : 0;
  }

  // Time: O(1), Space: O(1)
  int divisibleBy4_lastTwoDigits(const string &N) {
    int len = N.size();
    int lastTwo = (len == 1) ? (N[len - 1] - '0') : stoi(N.substr(len - 2));
    return (lastTwo % 4 == 0) ? 1 : 0;
  }

  // Time: O(1), Space: O(1)
  int divisibleBy4_bitwise(const string &N) {
    int num = stoi(N);
    return ((num & 3) == 0) ? 1 : 0;
  }

  // Time: O(1), Space: O(1)
  int divisibleBy4_fmod(const string &N) {
    double num = stod(N);
    return (fmod(num, 4) == 0) ? 1 : 0;
  }

  // Time: O(1), Space: O(1)
  int divisibleBy4_bigIntSafe(const string &N) {
    int len = N.size();
    int lastTwo = (len == 1) ? (N[len - 1] - '0')
                             : ((N[len - 2] - '0') * 10 + (N[len - 1] - '0'));
    return (lastTwo % 4 == 0) ? 1 : 0;
  }
};

int main() {
  Solution sol;
  cout << sol.divisibleBy4_modulo("1124") << "\n";        // 1
  cout << sol.divisibleBy4_lastTwoDigits("1124") << "\n"; // 1
  cout << sol.divisibleBy4_bitwise("1124") << "\n";       // 1
  cout << sol.divisibleBy4_fmod("1124") << "\n";          // 1
  cout << sol.divisibleBy4_bigIntSafe("1124") << "\n";    // 1

  cout << sol.divisibleBy4_modulo("7") << "\n";        // 0
  cout << sol.divisibleBy4_lastTwoDigits("7") << "\n"; // 0
  cout << sol.divisibleBy4_bitwise("7") << "\n";       // 0
  cout << sol.divisibleBy4_fmod("7") << "\n";          // 0
  cout << sol.divisibleBy4_bigIntSafe("7") << "\n";    // 0
  return 0;
}
