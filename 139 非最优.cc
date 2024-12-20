#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> set(wordDict.cbegin(), wordDict.cend());
    int size = s.size();
    vector<int> v(size + 1);
    // v[i]表示不包括在内的i之前的在wordDict中
    v[0] = 1;
    for (int i = 0; i <= size; ++i) {
      for (int j = i; j >= 0; j--) {
        if (v[j] == 1 && ranges::contains(wordDict, s.substr(j, i))) {
          v[i] = 1;
          break;
        }
      }
    }
    return v[size];
  }
};
int main() {
  auto v = vector{string{"apple"}, string{"pen"}};
  cout << Solution().wordBreak("applepenapple", v);
}