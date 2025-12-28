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
    int longestValidParentheses(string s)
    {

        int maxlen = 0;

        stack<pair<char, int>> stk;
        vector<int> v(s.length(), -1);

        for (int i = 0; i < s.size(); i++)
        {

            if (!stk.empty() && stk.top().first == '(' && s[i] == ')')
            {

                stk.pop();
                if (stk.empty())
                    maxlen = i + 1;
                else
                    maxlen = max(maxlen, i - stk.top().second);
            }
            else
            {
                stk.push({s[i], i});
            }
        }

        return maxlen;
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;
    cout << Solution().longestValidParentheses(")()())");
    TwoLineVerticalSpace;
    return 0;
}