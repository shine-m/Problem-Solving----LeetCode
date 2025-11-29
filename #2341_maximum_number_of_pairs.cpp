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
    vector<int> numberOfPairs(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto &i : nums)
        {
            mp[i]++;
        }

        int pairs = 0, free = 0;
        for (auto &[key, value] : mp)
        {
            pairs += value / 2;
            free += value % 2;
        }
        return vector<int>{pairs, free};
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    TwoLineVerticalSpace;
    return 0;
}