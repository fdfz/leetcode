#include <vector>
#include <algorithm>
#include <ranges>
#include <iostream>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> r(amount + 1, -1);
        r[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            vector<int> cs;
            for (int coin : coins)
            {
                if (i < coin || r[i - coin] == -1)
                    continue;
                cs.push_back(r[i - coin]);
            }
            auto loc = min_element(cs.begin(), cs.end());
            if (loc != cs.end())
                r[i] = *loc + 1;
        }
        return r[amount];
    }
};
int main()
{
    vector<int> v{37, 233, 253, 483};

    cout << Solution().coinChange(v, 7163);
}