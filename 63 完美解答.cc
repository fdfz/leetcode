#include<vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(i==0&&j==0){
                    obstacleGrid[0][0]=!obstacleGrid[0][0];
                }
                else if(i==0){
                    obstacleGrid[0][j]=!obstacleGrid[0][j]&&obstacleGrid[0][j-1];
                }
                else if (j==0)
                {
                    obstacleGrid[i][0]=!obstacleGrid[i][0]&&obstacleGrid[i-1][0];
                }
                else{
                    if(!obstacleGrid[i][j]){
                        obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
                    }
                    else{
                        obstacleGrid[i][j]=0;
                    }
                }
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};