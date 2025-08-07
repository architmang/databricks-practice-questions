// A, B two cities woth travel time 100 minutes
// Flights from A to B depart at times specifies by array a2b
// Flights from B to A depart at times specifies by array b2a

// you want to take trips round trips, find the time when you will take the last round trip

// two pointer approach

#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> &a2b, vector<int> &b2a, int &trips)
{
    int current_time = 0;
    int i=0; int j=0;
    for(int t=0; t<trips; t++)
    {
        while(i<a2b.size() && a2b[i] < current_time) i++;
        current_time = a2b[i] + 100;

        while(j<b2a.size() && b2a[j] < current_time) j++;
        current_time = b2a[j] + 100;
    }
    return current_time;
}

int main()
{
    vector<int> a2b = {0, 200, 500};
    vector<int> b2a = {99, 210, 450, 610};
    int trips = 2;
    cout << solution(a2b, b2a, trips) << endl;
    return 0;
}