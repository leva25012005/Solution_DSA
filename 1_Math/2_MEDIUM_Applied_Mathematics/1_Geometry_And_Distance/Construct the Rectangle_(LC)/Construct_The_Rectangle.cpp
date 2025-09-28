#include <algorithm> // for min
#include <cmath>
#include <iostream>
#include <numeric> // for accumulate
#include <vector>


using namespace std;

class Solution {
public:
  // 1. Start from sqrt(area) and scan downward
  // Time: O(√area), Space: O(1)
  vector<int> constructRectangle1(int area) {
    int w = (int)sqrt(area);
    while (area % w != 0) {
      w--;
    }
    return {area / w, w};
  }

  // 2. Scan upward from 1..sqrt and record best
  // Time: O(√area), Space: O(1)
  vector<int> constructRectangle2(int area) {
    int L = area, W = 1;
    for (int w = 1; w <= sqrt(area); w++) {
      if (area % w == 0) {
        int l = area / w;
        if (l - w < L - W) {
          L = l;
          W = w;
        }
      }
    }
    return {L, W};
  }

  // 3. Brute-force from 1..area
  // Time: O(area), Space: O(1)
  vector<int> constructRectangle3(int area) {
    int L = area, W = 1;
    for (int w = 1; w <= area; w++) {
      if (area % w == 0) {
        int l = area / w;
        if (l >= w && l - w < L - W) {
          L = l;
          W = w;
        }
      }
    }
    return {L, W};
  }

  // 4. Prime factorization + generate divisors
  // Time: O(√area + d), Space: O(d) (d = number of divisors)
  vector<int> constructRectangle4(int area) {
    vector<int> divisors;
    for (int i = 1; i <= sqrt(area); i++) {
      if (area % i == 0) {
        divisors.push_back(i);
        if (i != area / i)
          divisors.push_back(area / i);
      }
    }
    int L = area, W = 1;
    for (int w : divisors) {
      int l = area / w;
      if (l >= w && l - w < L - W) {
        L = l;
        W = w;
      }
    }
    return {L, W};
  }

  // 5. Greedy (near sqrt and adjust)
  // Time: O(√area), Space: O(1)
  vector<int> constructRectangle5(int area) {
    int w = (int)round(sqrt(area));
    while (w > 0) {
      if (area % w == 0) {
        return {area / w, w};
      }
      w--;
    }
    return {area, 1};
  }

  // 6. Precompute sieve (for multiple queries)
  // Time: O(√area) per query (with precomputation O(N log log N)), Space: O(N)
  // Here we just simulate precomputation by reusing method 1 (since full sieve
  // impl is large)
  vector<int> constructRectangle6(int area) {
    return constructRectangle1(area);
  }
};

int main() {
  Solution sol;
  int area1 = 4, area2 = 37, area3 = 122122;

  auto print = [](vector<int> v) {
    cout << "[" << v[0] << "," << v[1] << "]\n";
  };

  cout << "Area = 4\n";
  print(sol.constructRectangle1(area1));
  print(sol.constructRectangle2(area1));
  print(sol.constructRectangle3(area1));
  print(sol.constructRectangle4(area1));
  print(sol.constructRectangle5(area1));
  print(sol.constructRectangle6(area1));

  cout << "Area = 37\n";
  print(sol.constructRectangle1(area2));
  print(sol.constructRectangle2(area2));
  print(sol.constructRectangle3(area2));
  print(sol.constructRectangle4(area2));
  print(sol.constructRectangle5(area2));
  print(sol.constructRectangle6(area2));

  cout << "Area = 122122\n";
  print(sol.constructRectangle1(area3));
  print(sol.constructRectangle2(area3));
  print(sol.constructRectangle3(area3));
  print(sol.constructRectangle4(area3));
  print(sol.constructRectangle5(area3));
  print(sol.constructRectangle6(area3));

  return 0;
}
