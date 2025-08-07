// q: maintain N plants along a hiking trail
// plants numbereed 0 to N-1, i th plant located at x = i
// water source at x = -1
// you can't refill can before it is empty or it cannot water the next plant

// number of steps you need to take to water all plants along the hiking trail successfully?
// one step = one unit on x axis

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6;
    int C = 10;
    vector<int> plants {2, 4, 5, 1, 2, 6};
    // {50, 25, 30, 22, 75, 7, 55, 27, 11, 42};
    int steps = 0;
    int left = C;
    for(int i=0; i<n; i++)
    {
        if(plants[i] <= left)
        {
            // check this everytime
            // move from i-1 to i
            steps++;
            left -= plants[i];
        }
        else{
            // plants[i] > left
            // requirement is more
            // go back and refill
            left = C - plants[i];
            // move from i-1 to -1 and then to i
            steps += i + (i + 1) ;
            // flower this and move to next
        }
    }
    cout << steps << endl;
    return 0;
}
