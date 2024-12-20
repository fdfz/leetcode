#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size=nums.size();
        vector<int> f(size,1);
        int ma=1;
        for(int i=0;i<size;++i){
            for(int j =0;j<i;++j){
                if(nums[i]>nums[j]){
                    f[i]=max(f[i],f[j]+1);
                }
            }
            ma=max(ma,f[i]);
        }
        return ma;
    }
};
int main()
{
    vector<int> v={1,2,1};
    cout<<Solution().lengthOfLIS(v);
    return 0;
}