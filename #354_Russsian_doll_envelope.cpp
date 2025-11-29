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

class Solution
{
public:
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int ans = 1;
        sort(envelopes.begin(), envelopes.end(), Solution());

        vector<int> aux;
        for (auto &i : envelopes)
        {

            auto it = lower_bound(aux.begin(), aux.end(), i[1]);

            if (it == aux.end())
                aux.push_back(i[1]);
            else
                *it = i[1];
        }

        return aux.size();
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;
    vector<vector<int>> v = {{1, -2}, {1, 3}, {2, 2}, {5, 0}, {6, 1}, {7, 3}};
    cout << Solution().maxEnvelopes(v);
    TwoLineVerticalSpace;
    return 0;
}