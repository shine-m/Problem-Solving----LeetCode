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
    int minMirrorPairDistance(vector<int> &nums)
    {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {

            int temp = nums[i];
            int reverse = 0;
            while (temp > 0)
            {
                reverse = reverse * 10 + temp % 10;
                temp /= 10;
            }
            if (!mp[reverse].empty())
            {
                auto it = upper_bound(mp[reverse].begin(), mp[reverse].end(), i);
                if (it != mp[reverse].end())
                    ans = min(ans, abs(i - *it));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;
    vector<int> v = {12, 21, 45, 33, 54};
    cout << Solution().minMirrorPairDistance(v);

    TwoLineVerticalSpace;
    return 0;
}