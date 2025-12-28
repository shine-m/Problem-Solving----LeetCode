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
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> ansv(queries.size());

        //                              < trimOnIndex < queryIndex,  posKth>>
        unordered_map<int, vector<pair<int, int>>> queries_entry;
        int indx = 0;

        for (auto &i : queries)
        {

            queries_entry[i[1]].push_back({i[0], indx++});
        }
        indx = 0;
        vector<pair<string, int>> nums_with_index;
        for (auto &i : nums)
        {
            nums_with_index.push_back({i, indx++});
        }

        for (int i = nums[0].size() - 1; i >= 0; i--)
        {
            vector<int> freq(10);
            vector<pair<string, int>> temp(nums.size());

            for (auto &s : nums)
            {
                freq[s[i] - '0']++;
            }

            for (int j = 1; j < 10; j++)
            {
                freq[j] += freq[j - 1];
            }

            for (int j = nums.size() - 1; j >= 0; j--)
            {
                temp[--freq[nums_with_index[j].first[i] - '0']] = nums_with_index[j];
            }

            for (auto &x : queries_entry[nums[0].size() - i])
            {

                ansv[x.second] = temp[x.first - 1].second;
            }

            nums_with_index.swap(temp);
        }

        return ansv;
    }
};

int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;
    vector<string> nums = {"111", "111", "111", "111"};
    // vector<string> nums = {"102", "473", "251", "814"};
    // vector<vector<int>> queries = {{1, 1},
    //                                {2, 3},
    //                                {4, 2},
    //                                {1, 2}};
    vector<vector<int>> queries = {
        {1, 1},
        {2, 2},
        {3, 3},
    };

    for (auto &i : Solution().smallestTrimmedNumbers(nums, queries))
    {
        cout << i << " ";
    }
    cout << ln;

    TwoLineVerticalSpace;
    return 0;
}