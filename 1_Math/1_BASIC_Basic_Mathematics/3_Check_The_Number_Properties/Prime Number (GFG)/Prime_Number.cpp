#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // 1. Naive (check from 2 to n-1)
  // Time: 0(n), Space: o(1)
  bool Solution1(long long n) {
    if (n <= 1)
      return false;
    for (long long i = 2; i < n; i++) {
      if (n % i == 0)
        return false;
    }
    return true;
  }

  // 2. Check up to sqrt(n)
  // Time: O(√n), Space: o(1)
  bool Solution2(long long n) {
    if (n <= 1)
      return false;
    for (long long i = 2; i * i <= n; i++) {
      if (n % i == 0)
        return false;
    }
    return true;
  }

  // 3. 6k ± 1 optimization
  // Time: O(√n / 3) ~ O(√n), Space: o(1)
  bool Solution3(long long n) {
    if (n <= 1)
      return false;
    if (n <= 3)
      return true;
    if (n % 2 == 0 || n % 3 == 0)
      return false;
    for (long long i = 5; i * i <= n; i += 6) {
      if (n % i == 0 || n % (i + 2) == 0)
        return false;
    }
    return true;
  }

  // 4. Sieve of Eratosthenes (for many queries)
  // Time: O(N log log N), Space: o(N)
  vector<bool> sievePrime(int N) {
    vector<bool> Solution(N + 1, true);
    Solution[0] = Solution[1] = false;
    for (int i = 2; i * i <= N; i++) {
      if (Solution[i]) {
        for (int j = i * i; j <= N; j += i)
          Solution[j] = false;
      }
    }
    return Solution;
  }

  // 5. Segmented Sieve (range [L, R])
  // Time: O((R-L+1) log log R), Space: O(R-L+1)
  vector<bool> segmentedSieve(long long L, long long R) {
    long long limit = sqrt(R) + 1;
    vector<bool> mark(limit + 1, true);
    vector<long long> primes;
    for (long long i = 2; i <= limit; i++) {
      if (mark[i]) {
        primes.push_back(i);
        for (long long j = i * i; j <= limit; j += i)
          mark[j] = false;
      }
    }

    vector<bool> Solution(R - L + 1, true);
    for (long long p : primes) {
      long long start = max(p * p, ((L + p - 1) / p) * p);
      for (long long j = start; j <= R; j += p)
        Solution[j - L] = false;
    }
    if (L == 1)
      Solution[0] = false;
    return Solution;
  }

  // 6. Miller–Rabin Primality Test (probabilistic)
  // Time: O(k log³ n), Space: O(1)
  long long mulmod(long long a, long long b, long long mod) {
    return (__int128)a * b % mod; // use __int128 for safety
  }

  long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
      if (exp & 1)
        result = mulmod(result, base, mod);
      base = mulmod(base, base, mod);
      exp >>= 1;
    }
    return result;
  }

  bool millerTest(long long d, long long n, long long a) {
    long long x = power(a, d, n);
    if (x == 1 || x == n - 1)
      return true;
    while (d != n - 1) {
      x = mulmod(x, x, n);
      d *= 2;
      if (x == 1)
        return false;
      if (x == n - 1)
        return true;
    }
    return false;
  }

  bool Solution6(long long n, int k = 5) {
    if (n <= 1 || n == 4)
      return false;
    if (n <= 3)
      return true;

    long long d = n - 1;
    while (d % 2 == 0)
      d /= 2;

    for (int i = 0; i < k; i++) {
      long long a = 2 + rand() % (n - 4);
      if (!millerTest(d, n, a))
        return false;
    }
    return true;
  }

  // 7. AKS Primality Test (deterministic, polynomial time)
  // (Simplified placeholder version: not efficient for coding platforms)
  // Time: O(log⁶ n), Space: O(log² n)
  bool Solution7(long long n) {
    if (n <= 1)
      return false;
    if (n <= 3)
      return true;
    // The real AKS is complex, but here we simulate by falling back to sqrt
    // method
    return Solution2(n);
  }
};

int main() {
  Solution sol;

  cout << boolalpha;
  cout << "Naive: " << sol.Solution1(7) << "\n"; // true
  cout << "Sqrt: " << sol.Solution2(25) << "\n"; // false
  cout << "6k±1: " << sol.Solution3(29) << "\n"; // true
  auto sieve = sol.sievePrime(30);
  cout << "Sieve (29): " << sieve[29] << "\n"; // true
  auto seg = sol.segmentedSieve(20, 30);
  cout << "Segmented (29): " << seg[9] << "\n";              // true
  cout << "Miller–Rabin: " << sol.Solution6(97) << "\n";     // true
  cout << "AKS (simulated): " << sol.Solution7(101) << "\n"; // true
  return 0;
}
