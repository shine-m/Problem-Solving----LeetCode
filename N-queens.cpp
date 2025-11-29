
#include <bits/stdc++.h>
using namespace std;
#define swap(a, b) a = a + b - (b = a);
#define ln "\n"
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)

class Solution
{
public:
    int n;
    vector<vector<string>> ans;
    vector<string> board;

    bool safetyCheck(int row, int col)
    {
        // hoorisontal and vertical at the same time
        for (int i = 0; i < n; i++)
        {
            if (board[row][i] == 'Q' || board[i][col] == 'Q')
                return false;
        }
        // left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        // right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void Nqueen(int row, int col)
    {
        if (row >= n)
        {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (safetyCheck(row, i))
            {
                board[row][i] = 'Q';
                Nqueen(row + 1, 0);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        // vector<vector<string>> ans(2, vector<string>(4, string(4, '.')));
        this->n = n;
        board = vector<string>(n, string(n, '.'));

        Nqueen(0, 0);

        return ans;
    }
};

int main()
{
    system("cls");
    cout << ln << ln;

    Solution ob;
    for (auto j : ob.solveNQueens((5)))
    {
        for (auto i : j)
        {
            cout << i << ln;
        }
        cout << ln;
    }

    cout << ln << ln << ln;
    return 0;
}