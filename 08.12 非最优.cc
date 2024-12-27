#include <vector>
#include <string>
#include <unordered_set>
#include <ranges>
using namespace std;
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        unordered_set<int> column, diagnal1, diagnal2;
        vector<vector<string>> solution;
        vector<int> queens;
        backtrack(n, 0, queens, solution, column, diagnal1, diagnal2);
        return solution;
    }
    void backtrack(int n, int row, vector<int> &queens, vector<vector<string>> &solution,
                   unordered_set<int> &column, unordered_set<int> &diagnal1, unordered_set<int> &diagnal2)
    {
        if (row == n)
        {
            solution.push_back(queentostring(queens, n));
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (column.contains(i) || diagnal1.contains(i - row) || diagnal2.contains(i + row))
            {
                continue;
            }
            column.insert(i);
            diagnal1.insert(i - row);
            diagnal2.insert(i + row);
            queens.push_back(i);
            backtrack(n, row + 1, queens, solution, column, diagnal1, diagnal2);
            queens.pop_back();
            column.erase(i);
            diagnal1.erase(i - row);
            diagnal2.erase(i + row);
        }
    }
    vector<string> queentostring(vector<int> &queens, int n)
    {
        vector<string> res;
        for (auto i : queens)
        {
            string a;
            for (auto j : views::iota(0,n))
            {
                if (i == j)
                {
                    a.push_back('Q');
                }
                else
                {
                    a.push_back('.');
                }
            }
            res.push_back(a);
        }
        return res;
    }
};
int main(){
    Solution().solveNQueens(4);
}