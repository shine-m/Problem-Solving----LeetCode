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
    string removeDuplicateLetters(string s)
    {
        vector<char> v;

        vector<int> freq(26);
        for (auto &i : s)
        {
            freq[i - 'a']++;
        }

        int signature = 0;
        for (int i = 0; i < s.length(); i++)
        {

            if (!(signature & (1 << (s[i] - 'a'))))
                while (!v.empty() && v[v.size() - 1] >= s[i] && freq[v[v.size() - 1] - 'a'])
                {
                    signature &= (~(1 << (v[v.size() - 1] - 'a')));
                    v.pop_back();
                }
            if (!(signature & (1 << (s[i] - 'a'))))
            {

                v.push_back(s[i]);
                signature |= (1 << (s[i] - 'a'));
            }

            freq[s[i] - 'a']--;
        }
        return string(v.begin(), v.end());
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    cout << Solution().removeDuplicateLetters("aaabcdabcd");
    TwoLineVerticalSpace;
    return 0;
}