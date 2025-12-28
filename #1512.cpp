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
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto &i : nums)
        {
            mp[i]++;
        }
        int ans = 0;
        for (auto &[key, value] : mp)
        {
            ans += (value * (value - 1) / 2);
        }
        return ans;
    }
};
int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    TwoLineVerticalSpace;
    return 0;
}