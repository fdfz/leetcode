#include <print>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
    unordered_map<char, int> pattern, current;

  public:
    bool check()
    {
        for (const auto &c : pattern)
            if (current[c.first] < c.second)
                return false;
        return true;
    }
    string minWindow(string s, string t)
    {
        for (const auto &c : t)
            pattern[c]++;
        int l = 0, r = 0;
        current[s[0]] = 1;
        int length = 0;
        int ansl;
        while (r < s.size())
        {
            if (check())
            {
                if (r - l + 1 < length || !length)
                {
                    length = r - l + 1;
                    ansl = l;
                }
                current[s[l]]--;
                l++;
            }
            else
            {
                r++;
                current[s[r]]++;
            }
        }
        return length ? s.substr(ansl, length) : "";
    }
};
int main()
{
    print("{}", Solution().minWindow("", ""));