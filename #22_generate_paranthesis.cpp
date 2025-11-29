#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define PRECISION cout << setprecision(12);
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)

class Solution
{
    vector<string> ans;
    int n;
    unordered_map<string, bool> s, t1, t2, final_filter;

public:
    vector<string> generateParenthesis(int n)
    {
        this->n = n;
        recurse(0, 0, "");
        return ans;
    }
    void recurse(int, int, string);
};
void Solution::recurse(int l, int r, string s)
{
    if (l == n && l == r)
    {

        ans.push_back(s);
        return;
    }

    if (l < n)
        recurse(l + 1, r, s + "(");
    if (r < l)
        recurse(l, r + 1, s + ")");
}
int main()
{
    FAST_IO PRECISION;
    Solution ob;
    for (auto &i : ob.generateParenthesis(3))
    {
        cout << i << " ";
    }
    cout << ln;
    return 0;
}