#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> r(nums.size());
        r[0]=nums[0];
        r[1]=nums[1];
        r[2]=nums[0]+nums[2];
        for(int i=3;i<nums.size();++i){
            r[i]=max(r[i-3],r[i-2])+nums[0];
        }
        return r[nums.size()-1];
    }
};