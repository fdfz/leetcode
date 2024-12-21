#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size(),column=grid[0].size();
        for(int i=row-1;i>=0;--i){
            for(int j=column-1;j>=0;--j){
                if(i==row-1&&j==column-1)
                continue;
                else if(i==row-1)
                grid[i][j]=grid[i][j+1]+grid[i][j];
                else if(j==column-1)
                grid[i][j]=grid[i+1][j]+grid[i][j];
                else
                grid[i][j]=min(grid[i+1][j],grid[i][j+1])+grid[i][j];
            }
        }
        return grid[0][0];
    }
};