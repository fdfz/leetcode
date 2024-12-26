#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        vector<int> point(n + 1, -1);
        for (int i = 0; i < ranges.size(); ++i)
        {
            if (!ranges[i])
                continue;
            int left = max(i - ranges[i], 0), right = min(i + ranges[i], n);
            point[left] = max(point[left], right);
        }
        int right = 0, next_right = 0;
        int num = 0;
        for (int i = 0; i < n; ++i)
        {
            next_right = max(next_right, point[i]);
            if (i == next_right)
                return -1;
            if (i == right)
            {
                right = next_right;
                ++num;
            }
        }
        return num;
    }
};

int main()
{
    vector<int> v = {1, 2, 1, 0, 2, 1, 0, 1};
    cout << Solution().minTaps(7, v);
}
