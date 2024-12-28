#include <vector>
using namespace std;
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int r = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '0')
                    matrix[i][j] = 0;
                else
                {
                    matrix[i][j] = 1;
                    r = 1;
                }
            }
        }
        if (r == 0)
            return 0;
        for (;r <= min(m, n); ++r)
        {
            bool found=false;
            for (int i = 0; i < m - r; ++i)
            {
                for (int j = 0; j < n - r; ++j)
                {
                    matrix[i][j] = matrix[i][j] && matrix[i][j+1]&&matrix[i+1][j]&&matrix[i+1][j+1];
                    if(matrix[i][j]==1){
                        found=true;
                    }
                }
            }
            if(!found)
            return r*r;
        }
        return (r-1)*(r-1);
    }
};
int main(){
    vector<vector<char>> v={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    Solution().maximalSquare(v);
}