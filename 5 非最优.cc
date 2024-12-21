#include <string>
#include <cmath>
#include <iostream>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string max = s.substr(0, 1);
        for (int i = 1; i < s.size()-1; ++i)
        {
            for (int step=1; i - step >= 0 && i + step < s.size(); ++step)
            {
                if (s[i - step] != s[i + step])
                    break;
                else if(2*step+1>max.size())
                    max = s.substr(i - step, 2 * step + 1);
            }
        }
        for (int i = 1; i < s.size(); ++i)
        {
            for (int step=1; i - step >= 0 && i + step-1 < s.size(); ++step)
            {
                if (s[i - step] != s[i + step-1])
                break;
                else if(2*step>max.size())
                    max = s.substr(i - step, 2 * step);
            }
        }
        return max;
    }
};

int main()
{
    string a = "aaaaa";
    cout << Solution().longestPalindrome(a);
}