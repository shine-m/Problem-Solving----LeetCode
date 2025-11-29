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
    int maximumSum(vector<int> &nums)
    {
        map<int, multiset<int, greater<int>>> mp;
        for (auto &i : nums)
        {

            int sum = 0, temp = i;
            while (i > 0)
            {
                sum += (i % 10);
                i /= 10;
            }
            mp[sum].insert(temp);
        }

        int ans = -1;
        for (auto &[key, value] : mp)
        {
            if (value.size() >= 2)
                ans = max(ans, *value.begin() + *(++value.begin()));
        }
        return ans;
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    vector<int> v = {18, 43};
    Solution obj;
    cout << obj.maximumSum(v);

    TwoLineVerticalSpace;
    return 0;
}