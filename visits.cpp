// q: visits array given, find the first day i when sum of total number
// of visits so far exceed target

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> visits{300, 200, 100, 200, 500};
    int target = 700;
    vector<int> sum_arr = visits;
    for(int i=1; i<visits.size(); i++)
    {
        sum_arr[i] += sum_arr[i-1];
    }
    // binary search
    int low = 0;
    int high = 5;
    int mid;
    while(low<=high)
    {
        mid = midpoint(low, high);
        if(sum_arr[mid] >= target)
            break;
        else if(sum_arr[mid] > target)
        {
            high = mid + 1;
        }
        else{
            low = mid - 1;
        }
    }
    cout << mid << endl;
    return 0;
}