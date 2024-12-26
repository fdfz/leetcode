#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        unordered_set<int> column, diagnal1, diagnal2;
        vector<vector<string>> solution;
        backtrack(n, 0, solution, column, diagnal1, diagnal2);
    }
    void backtrack(int n, int row, vector<vector<string>> &solution,
                   unordered_set<int> &column, unordered_set<int> &diagnal1, unordered_set<int> &diagnal2)
    {
        for(int i=row;i<n;++i){
            
        }
    }
};