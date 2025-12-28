for (auto &x : queries_entry[nums.size() - i])
            {
                ansv[x.first] = initial_index[temp[x.second - 1 /*as convering to o based index*/ ]];
            }