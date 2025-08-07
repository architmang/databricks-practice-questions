// given list of numbers, pattern array: contains only 1, 0 or -1
// each element in pattern describes how adjacent elements in subarray should relate

// 1 increasing numbers[i+1] > numbers[i]
// 0 equal numbers[i+1] = numbers[i]
// -1 decreasing numbers[i+1] < numbers[i]

// count how many subarrays of numbers (of size pattern.size() + 1) match the full pattern

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> numbers = {1, 2, 2, 3, 4, 4, 3, 2, 1, 1};
    // { 5, 6, 6, 7, 8, 8, 7, 6, 5, 5, 6, 6, 7, 8, 8, 7, 6, 5 };
    vector<int> pattern = {1, 0, 1, 1, 0, -1, -1, -1};
    // { 1, 0, 1, 1, 0, -1, -1, -1}; 

    int n = numbers.size();
    int m = pattern.size();

    // final to n-1 = len
    // n - final = m +1
    // final = n - m - 1
    int cnt = 0;
    for(int i=0; i<n-m; i++)
    {
        bool valid = true;
        // sliding window over starting position
        for(int j=0; j<m; j++)
        {
            int curr = numbers[i + j];
            int next = numbers[i + j + 1];

            if(pattern[j] == 0 && curr!=next) valid = false;
            if(pattern[j] == 1 && curr>next) valid = false;
            if(pattern[j] == -1 && curr<next) valid = false;
        }
        if(valid) cnt++;
    }
    cout << cnt;
    return 0;
}