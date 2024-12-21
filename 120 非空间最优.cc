#include <vector>
using namespace std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int size = triangle.size();
        vector<int> r(triangle[size - 1]);
        for (int i = size - 2; i >= 0; --i)
        {
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                r[j] = min(r[j], r[j + 1]) + triangle[i][j];
            }
        }
        return r[0];
    }
};