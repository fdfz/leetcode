#include <vector>
using namespace std;

/**
 * 复杂度已经是最优了，但是还有更好的写法
class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int cnt = 0, m = f.size();
        for (int i = 0; i < m; ++i) {
            if ((i == 0 || f[i - 1] == 0) && f[i] == 0 && (i == m - 1 || f[i + 1] == 0)) {
                cnt += 1;
                f[i] = 1;
            }
        }
        return cnt >= n;
    }
};

 */
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n == 0)
            return true;
        int m = 0, size = flowerbed.size();
        if (size >= 2 && !flowerbed[0] && !flowerbed[1])
        {
            flowerbed[0] = 1;
            ++m;
        }

        for (int i = 1; i < size - 1; ++i)
        {
            if (flowerbed[i - 1] || flowerbed[i] || flowerbed[i + 1])
                continue;
            flowerbed[i] = 1;
            ++m;
            if (m == n)
                return true;
        }
        if (size - 2 >= 0 && !flowerbed[size - 2] && !flowerbed[size - 1])
        {
            ++m;
        }
        if (m == n)
            return true;
        else
            false;
    }
};