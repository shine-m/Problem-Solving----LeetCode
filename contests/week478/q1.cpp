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
    int countElements(vector<int> &nums, int k)
    {

        sort(nums.begin(), nums.end());
        int i = nums.size() - 1;
        unordered_map<int, int> mp;
        int taken = 0, gross = 0;
        for (; i >= 0; i--)
        {
            gross++;
            if (!(mp[nums[i]]))
            {

                if (gross > k)
                {
                    return i + 1;
                }
                taken++;
            }

            if (taken > k)
                break;
            mp[nums[i]] = 1;
        }
        return taken > k ? i + 1 : 0;
    }
};
int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    vector<int> v = {0, 3, 1, 5, 4, 3};
    cout << Solution().countElements(v, 5);

    TwoLineVerticalSpace;
    return 0;
}