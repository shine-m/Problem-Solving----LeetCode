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
    string evaluate(string s, vector<vector<string>> &knowledge)
    {

        unordered_map<string, string> mp;

        for (auto &i : knowledge)
        {
            mp[i[0]] = i[1];
        }

        string temp;
        int r;
        for (int i = s.length() - 1; i >= 0; i--)
        {

            if (s[i] == ')')
                r = i;

            if (s[i] == '(')
            {
                temp = s.substr(i + 1, r - i - 1);
                cout << temp << ln;
                s.replace(i, r - i + 1, mp[temp] == "" ? "?" : mp[temp]);
            }
        }
        return s;
    }
};
int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    vector<vector<string>> v = {{"name", "bob"}, {"age", "two"}};
    cout << Solution().evaluate("(name)is(age)yearsold", v);

    TwoLineVerticalSpace;
    return 0;
}