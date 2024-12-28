#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](auto point1, auto point2)
             { return point1[1] < point2[1]; });
        int cnt = 1;
        int pos = 0;
        for (int i = 1; i < points.size(); ++i)
        {
            if (points[i][0] <= points[pos][1])
                continue;
            else
            {
                pos = i;
                ++cnt;
            }
        }
        return cnt;
    }
};