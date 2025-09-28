#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
  // Solution 1: Direct if-else chain
  // Time: O(1), Space: O(1)
  string categorizeBox1(int length, int width, int height, int mass) {
    long long volume = 1LL * length * width * height;
    if ((length >= 10000 || width >= 10000 || height >= 10000 ||
         volume >= 1000000000LL) &&
        mass >= 100) {
      return "Both";
    } else if (length >= 10000 || width >= 10000 || height >= 10000 ||
               volume >= 1000000000LL) {
      return "Bulky";
    } else if (mass >= 100) {
      return "Heavy";
    } else {
      return "Neither";
    }
  }

  // Solution 2: Using bool variables
  // Time: O(1), Space: O(1)
  string categorizeBox2(int length, int width, int height, int mass) {
    long long volume = 1LL * length * width * height;
    bool bulky = (length >= 10000 || width >= 10000 || height >= 10000 ||
                  volume >= 1000000000LL);
    bool heavy = (mass >= 100);

    if (bulky && heavy)
      return "Both";
    if (bulky)
      return "Bulky";
    if (heavy)
      return "Heavy";
    return "Neither";
  }

  // Solution 3: Bitmask / Encoding
  // Time: O(1), Space: O(1)
  string categorizeBox3(int length, int width, int height, int mass) {
    long long volume = 1LL * length * width * height;
    int bulky = (length >= 10000 || width >= 10000 || height >= 10000 ||
                 volume >= 1000000000LL)
                    ? 1
                    : 0;
    int heavy = (mass >= 100) ? 2 : 0;
    int status = bulky + heavy;

    if (status == 3)
      return "Both";
    if (status == 1)
      return "Bulky";
    if (status == 2)
      return "Heavy";
    return "Neither";
  }

  // Solution 4: Map / Dictionary lookup
  // Time: O(1), Space: O(1)
  string categorizeBox4(int length, int width, int height, int mass) {
    long long volume = 1LL * length * width * height;
    bool bulky = (length >= 10000 || width >= 10000 || height >= 10000 ||
                  volume >= 1000000000LL);
    bool heavy = (mass >= 100);

    map<pair<bool, bool>, string> category = {{{false, false}, "Neither"},
                                              {{true, false}, "Bulky"},
                                              {{false, true}, "Heavy"},
                                              {{true, true}, "Both"}};

    return category[{bulky, heavy}];
  }

  // Solution 5: Switch-case with encoding
  // Time: O(1), Space: O(1)
  string categorizeBox5(int length, int width, int height, int mass) {
    long long volume = 1LL * length * width * height;
    int bulky = (length >= 10000 || width >= 10000 || height >= 10000 ||
                 volume >= 1000000000LL)
                    ? 1
                    : 0;
    int heavy = (mass >= 100) ? 2 : 0;
    int status = bulky + heavy;

    switch (status) {
    case 3:
      return "Both";
    case 1:
      return "Bulky";
    case 2:
      return "Heavy";
    default:
      return "Neither";
    }
  }

  // Solution 6: Ternary operator (compact one-liner)
  // Time: O(1), Space: O(1)
  string categorizeBox6(int length, int width, int height, int mass) {
    long long volume = 1LL * length * width * height;
    bool bulky = (length >= 10000 || width >= 10000 || height >= 10000 ||
                  volume >= 1000000000LL);
    bool heavy = (mass >= 100);

    return bulky && heavy ? "Both"
           : bulky        ? "Bulky"
           : heavy        ? "Heavy"
                          : "Neither";
  }
};

int main() {
  Solution sol;
  cout << sol.categorizeBox1(1000, 35, 700, 300) << "\n";       // Heavy
  cout << sol.categorizeBox2(200, 50, 800, 50) << "\n";         // Neither
  cout << sol.categorizeBox3(10000, 10, 10, 10) << "\n";        // Bulky
  cout << sol.categorizeBox4(10, 10, 10, 150) << "\n";          // Heavy
  cout << sol.categorizeBox5(10000, 10000, 10000, 200) << "\n"; // Both
  cout << sol.categorizeBox6(5, 5, 5, 5) << "\n";               // Neither
  return 0;
}
