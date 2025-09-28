#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // 1. Naive: compute factorial then count trailing zeros
  // Time: O(n) for factorial + O(log(n!)) for counting zeros (≈ O(n)), Space:
  // O(1)
  int trailingZeroesNaive(int n) {
    if (n == 0)
      return 0;
    long double fact = 1; // factorial grows fast, so use long double (still
                          // overflow for large n)
    for (int i = 1; i <= n; i++)
      fact *= i;

    int count = 0;
    while (fmod(fact, 10.0) == 0.0) {
      count++;
      fact /= 10.0;
    }
    return count; // Works only for small n
  }

  // 2. Count factors of 5 (best solution)
  // Time: O(log n), Space: O(1)
  int trailingZeroesIterative(int n) {
    int count = 0;
    while (n > 0) {
      n /= 5;
      count += n;
    }
    return count;
  }

  // 3. Recursive version (based on counting 5s)
  // Time: O(log n), Space: O(log n) due to recursion stack
  int trailingZeroesRecursive(int n) {
    if (n == 0)
      return 0;
    return n / 5 + trailingZeroesRecursive(n / 5);
  }

  // 4. Prime factorization (count 2s and 5s separately)
  // Time: O(n log n), Space: O(1)
  int trailingZeroesPrimeFactorization(int n) {
    int count2 = 0, count5 = 0;
    for (int i = 2; i <= n; i++) {
      int x = i;
      while (x % 2 == 0) {
        count2++;
        x /= 2;
      }
      x = i;
      while (x % 5 == 0) {
        count5++;
        x /= 5;
      }
    }
    return min(count2, count5);
  }
};

int main() {
  Solution sol;
  int n = 25;

  cout << "Naive: " << sol.trailingZeroesNaive(10)
       << "\n"; // only safe for small n
  cout << "Iterative (best): " << sol.trailingZeroesIterative(n) << "\n";
  cout << "Recursive: " << sol.trailingZeroesRecursive(n) << "\n";
  cout << "Prime Factorization: " << sol.trailingZeroesPrimeFactorization(25)
       << "\n";

  return 0;
}
