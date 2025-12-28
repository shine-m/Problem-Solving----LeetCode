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
    int minDifference(vector<int> &nums)
    {
        if (nums.size() <= 4)
            return 0;

        multiset<int> bigger;
        multiset<int, greater<int>> smaller;
        for (int i = 0; i < 4; i++)
        {
            smaller.insert(nums[i]);
            bigger.insert(nums[i]);
        }
        for (int i = 4; i < nums.size(); i++)
        {

            bigger.insert(nums[i]);
            smaller.insert(nums[i]);

            smaller.erase(smaller.begin());
            bigger.erase(bigger.begin());
        }

        int ans = INT_MAX;
        for (int i = 0; i < 4; i++)
        {

            ans = min(*(--bigger.end()) - *(smaller.begin()), ans);
            bigger.erase(--bigger.end());
            smaller.erase(smaller.begin());
        }

        return ans;
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;
    vector<int> v = {75, 19, 78, 9, 70, 5, 63, 90};
    cout << Solution().minDifference(v);

    TwoLineVerticalSpace;
    return 0;
}