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
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> aux;
        for (auto &i : nums)
        {

            auto it = lower_bound(aux.begin(), aux.end(), i);
            if (it != aux.end())
                *it = i;
            else
                aux.push_back(i);
        }
        return aux.size();
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    vector<int> v = {1, 2, 3, 2, 1, 4, 5, 2};
    cout << Solution().lengthOfLIS(v);

    TwoLineVerticalSpace;
    return 0;
}