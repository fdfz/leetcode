#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        vector<vector<int>> v(s1.size()+1,vector<int>(s2.size()+1,0));
        v[0][0]=1;
        for(int i=0;i<=s1.size();++i){
            for(int j=0;j<=s2.size();++j){
                v[i][j]=v[i-1][j]&&s1[i-1]==s3[i+j-2]||v[i][j-1]&&s2[j-1]==s3[i+j-2];
            }
        }
        return v[s1.size()][s2.size()];
    }
};
int main(){
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    Solution().isInterleave(s1,s2,s3);
}
