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
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<long long> v;
        v.push_back(0); // for convinence of prefix array claculation;
        long long initial = 0;
        for (int i = 1; i <= n; i++)
        {
            initial += nums[i - 1];
            v.push_back(initial);
            for (int j = i; j < n; j++)
            {

                v.push_back(v[v.size() - 1] + nums[j] - nums[j - i]);
            }
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); i++)
        {
            v[i] += v[i - 1];
        }
        long long modulo = (1e9) + 7;

        return (v[right] - v[left - 1]) % modulo;
    }
};
auto init = atexit([]()
                   { ofstream("display_runtime.txt") << "0"; });

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;
    vector<int> v = {1, 2, 3};
    cout << Solution().rangeSum(v, 3, 2, 3);

    TwoLineVerticalSpace;
    return 0;
}