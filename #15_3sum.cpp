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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int prev = INT_MIN;
        for (int i = 0; i < nums.size() && nums[i] <= 0; i++)
        {
            if (nums[i] == prev)
                continue;

            int complement = -1 * nums[i];
            // auto it = lower_bound(nums.begin() + i, nums.end(), nums[nums.size() - 1] - complement);
            int l = i + 1, r = nums.size() - 1;
            int prevl = INT_MIN, prevr = INT_MIN;
            while (l < r)
            {
                if (prevl == nums[l])
                {
                    l++;
                    continue;
                }
                if (prevr == nums[r])
                {
                    r--;
                    continue;
                }
                if (nums[i] + nums[l] + nums[r] == 0)
                {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    prevl = nums[l];
                    prevr = nums[r];
                    r--;
                    l++;
                }
                else if (nums[i] + nums[l] + nums[r] > 0)
                {
                    r--;
                }
                else if (nums[i] + nums[l] + nums[r] < 0)
                {
                    l++;
                }
            }
            prev = nums[i];
        }
        return ans;
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    vector<int> v = {-1, 0, 1, 2, -1, -4};
    for (auto &j : Solution().threeSum(v))
    {
        for (auto &i : j)
        {
            cout << i << " ";
        }
        cout << ln;
    }

    TwoLineVerticalSpace;
    return 0;
}