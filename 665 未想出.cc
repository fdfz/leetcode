#include <limits>
#include <vector>
using namespace std;
class Solution
{
  public:
    // 02 -1 34
    // 01  5 24
    bool checkPossibility(vector<int> &nums)
    {
        int hit = false;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] > nums[i + 1])
            {
                if (hit)
                    return false;
                hit = true;
                if (i + 2 < nums.size() && nums[i] > nums[i + 2])
                    return false;
            }
        }
        return true;
    }
};