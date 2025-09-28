#include <cmath>    // for sqrt in prime factorization
#include <iostream> // for input/output
#include <numeric>  // for std::gcd
#include <vector>   // for vector (prime factorization, multiples)

using namespace std;

class Solution {
public:
  // 1. Using GCD formula
  // Time: O(log(min(a, b))), Space: O(1)
  int lcmUsingGcd(int a, int b) { return (a / gcd(a, b)) * b; }

  // 2. Brute force search from max(a, b) to a*b
  // Time: O(a*b / max(a,b)) ≈ O(min(a,b)), Space: O(1)
  int lcmBruteForce(int a, int b) {
    int lcm = max(a, b);
    while (true) {
      if (lcm % a == 0 && lcm % b == 0)
        return lcm;
      lcm++;
    }
  }

  // 3. Prime factorization method
  // Time: O(sqrt(max(a,b))), Space: O(sqrt(max(a,b)))
  int lcmPrimeFactorization(int a, int b) {
    int n1 = a, n2 = b;
    int result = 1;

    for (int i = 2; i <= max(n1, n2); i++) {
      bool divided = false;
      while (n1 % i == 0 || n2 % i == 0) {
        if (n1 % i == 0)
          n1 /= i;
        if (n2 % i == 0)
          n2 /= i;
        result *= i;
        divided = true;
      }
      if (n1 == 1 && n2 == 1)
        break;
    }
    return result;
  }

  // 4. Multiples enumeration method
  // Time: O(min(a, b)), Space: O(min(a, b))
  int lcmByMultiples(int a, int b) {
    vector<int> multiples;
    for (int i = 1; i <= b; i++) {
      multiples.push_back(a * i);
    }
    for (int i = 1; i <= a; i++) {
      int val = b * i;
      if (find(multiples.begin(), multiples.end(), val) != multiples.end()) {
        return val;
      }
    }
    return a * b; // fallback
  }
};

int main() {
  Solution sol;
  int a = 12, b = 18;

  cout << "LCM using GCD: " << sol.lcmUsingGcd(a, b) << "\n";
  cout << "LCM brute force: " << sol.lcmBruteForce(a, b) << "\n";
  cout << "LCM prime factorization: " << sol.lcmPrimeFactorization(a, b)
       << "\n";
  cout << "LCM by multiples: " << sol.lcmByMultiples(a, b) << "\n";

  return 0;
}
