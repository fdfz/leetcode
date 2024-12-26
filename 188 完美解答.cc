#include <vector>
#include<algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> buy(k,-prices[0]), sell(k,0);
        for(int i=1;i<prices.size();++i){
            for(int j=0;j<k;++j){
                buy[j]=j-1>=0?max(buy[j],sell[j-1]-prices[i]):max(buy[j],-prices[i]);
                sell[j]=max(sell[j],buy[j]+prices[i]);
            }
        }
        return sell[k-1];
    }
};
int main(){
    vector<int> prices={3,2,6,5,0,3};
    cout<<Solution().maxProfit(2,prices);
}