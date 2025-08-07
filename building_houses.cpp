// you are given a number line and you are building houses at a certain position one by one
// initially no houses present, each position can have a house or be empty
//  queries array gives the order of the building

// return length of longest contigous segment of houses

#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> &queries)
{
    unordered_map<int, int> left, right; 
    // hash maps
    // left[pos] = length of segment that ends at pos
    // right[pos] = length of segment that starts at pos

    vector<int> result;
    int maxLen = 0;
    set<int> built;
    for(int q: queries)
    {
        if(built.count(q))
        {
            result.push_back(maxLen);
            continue;
        }
        built.insert(q);
        int l = q;
        int r = q;

        // expand left
        if(built.count(q-1))
            l -= left[q-1];

        // expand right
        if(built.count(q+1))
            r += right[q+1];

        int len = r-l+1;
        left[r] = len;
        right[l] = len;

        maxLen = max(maxLen, len);

        result.push_back(maxLen);
    }
    return result;
}

int main()
{
    vector<int> queries = {1, 3, 5, 2, 4};
    vector<int> result = solution(queries);
    for(int x: result) cout << x << " ";
    return 0;
}