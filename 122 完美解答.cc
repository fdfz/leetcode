#include <vector>
using namespace std;
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int cnt = 0;
        for (int i = 1; i <= prices.size(); ++i)
            cnt += max(prices[i] - prices[i - 1], 0);
        return cnt;
    }
};