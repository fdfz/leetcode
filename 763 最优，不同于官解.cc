#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <print>
#include <ranges>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        if (s.size() == 1)
            return {1};
        unordered_map<char, pair<int, int>> m;
        for (int i = 0; i < s.size(); ++i)
        {
            if (!m.contains(s[i]))
            {
                m[s[i]] = make_pair(i, i);
            }
            else
            {
                m[s[i]].second = max(m[s[i]].second, i);
            }
        }
        vector<pair<int, int>> v(views::values(m).begin(), views::values(m).end());
        sort(v.begin(), v.end(), [](auto &p1, auto &p2)
             { return p1.first < p2.first; });
        vector<int> res;
        int begin = v[0].first, end = v[0].second;
        for (int i = 1; i < v.size(); ++i)
        {
            if (v[i].first < end)
            {
                end = max(end, v[i].second);
            }
            else
            {
                res.push_back(end - begin + 1);
                begin = v[i].first;
                end = v[i].second;
            }
        }
        res.push_back(end - begin + 1);
        return res;
    }
};

int main()
{
    vector<int> res = Solution().partitionLabels("ababcbacadefegdehijhklij");
    for (auto &i : res)
    {
        print("{} ", i);
    }
}