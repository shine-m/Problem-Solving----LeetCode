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
    vector<int> signature;

    int n;
    int total_iteration = 0;
    int inline stringToInt(const string &s)
    {
        int val = 0;
        for (char c : s)
        {
            val = (val << 1) | (c - '0');
        }
        return val;
    }

    void backTrack(int i, string &s)
    {
        if (i > n / 2)
        {
            if (n & 1) // if n is odd then we need to tweak the middle element manually for 0 , 1
            {
                s[n / 2] = '0';
                signature[stringToInt(s)] = 1;
                s[n / 2] = '1';
                signature[stringToInt(s)] = 1;
            }
            else
            {

                signature[stringToInt(s)] = 1;
            }
            return;
        }

        s[i] = s[n - 1 - i] = '1';
        backTrack(i + 1, s);
        if (i != 0) // to avoid leading zero
        {

            s[i] = s[n - 1 - i] = '0';
            backTrack(i + 1, s);
        }
    }

    template <typename t>
    inline string integer_to_binary_string(t x)
    {
        string s = "";
        while (x > 0)
        {
            s += (x % 2) + '0';
            x /= 2;
        }
        string ret = "";
        for (int i = s.length() - 1; i >= 0; i--)
        {
            ret += s[i];
        }
        return ret;
    }
    vector<int> minOperations(vector<int> &nums)
    {

        // int maxel = *max_element(nums.begin(), nums.end());
        signature = vector<int>(1 << (int)ceil(log2(5000)) + 2, 0);
        vector<int> palindromes;

        for (int i = 2; i <= ceil(log2(5000)); i++)
        {
            n = i;
            string s = string(i, ' ');
            backTrack(0, s);
        }
        signature[0] = 0, signature[1] = 1;
        vector<int> ans;

        for (int i = 1; i < signature.size(); i++)
        {
            if (signature[i])
                palindromes.push_back(i);
        }

        for (auto &i : nums)
        {
            auto it = lower_bound(palindromes.begin(), palindromes.end(), i);
            if (*it == i)
                ans.push_back(0);
            else
                ans.push_back(min(i - *(it - 1), *(it)-i));
        }

        return ans;
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;
    vector<int> v = {1, 224};
    for (auto &i : Solution().minOperations(v))
    {
        cout << i << ln;
    }

    TwoLineVerticalSpace;
    return 0;
}