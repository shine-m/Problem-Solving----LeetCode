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
    unordered_map<int, pair<int, int>> mp;
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp[target - nums[i]].first)
            {
                return vector<int>{mp[target - nums[i]].second, i};
            }
            // mp.insert({nums[i], {1, i}});
            mp[nums[i]].first = 1;
            mp[nums[i]].second = i;
        }
        return vector<int>{};
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    Solution ob;
    vector<int> v = {3, 3};
    for (auto &i : ob.twoSum(v, 6))
    {
        cout << i << " ";
    }
    cout << ln;
    ;

    TwoLineVerticalSpace;
    return 0;
}