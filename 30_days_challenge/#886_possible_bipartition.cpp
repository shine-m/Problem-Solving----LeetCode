#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define PRECISION cout << setprecision(12);
#ifdef _WIN32
#define CLEAR_SCREEN system("cls");
#endif
#define TwoLineVerticalSpace cout << ln << ln;
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)
using ll = long long;

class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        unordered_map<int, vector<int>> adjacency_list;

        for (auto &i : dislikes)
        {
            adjacency_list[i[0]].push_back(i[1]);
            adjacency_list[i[1]].push_back(i[0]);
        }

        vector<int> notation(n + 1, -1), isvisited(n + 1, 0);

        queue<int> q;

        for (auto &[key, value] : adjacency_list)
        {

            if (isvisited[key])
                continue;

            isvisited[key] = 1;
            q.push(key);

            while (!q.empty())
            {

                short curr_notation = notation[q.front()] = notation[q.front()] == -1 ? 0 : notation[q.front()];
                short set_notation = !curr_notation;

                               isvisited[q.front()] = 1;

                for (auto &i : adjacency_list[q.front()])
                {

                    if (notation[i] == curr_notation)
                    {
                        return false;
                    }
                    if (notation[i] == -1)
                    {
                        notation[i] = set_notation;
                        if (!isvisited[i])
                            q.push(i);
                    }
                }

                q.pop();
            }
        }
        return true;
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;
    int n = 4;
    vector<vector<int>> v = {{1, 2}, {1, 3}, {2, 4}, {3, 4}};
    cout << Solution().possibleBipartition(n, v) << ln;
    TwoLineVerticalSpace;
    return 0;
}