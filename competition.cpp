// wins =  3pts, lose = 0 pts, tie = 1 pt
// team that accumulates the most points wins
// if tie, team with highest goal difference among the tied teams wins

// wins, draws, cored, conceded
// ith element reprsents metric for ith team

// determine indices of winning team and team in second place


#include<bits/stdc++.h>
using namespace std;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b)
{
    if(get<0>(a) > get<0>(b)) return true;
    else if(get<1>(a) > get<1>(b)) return true;
    return false;
}

vector<int> getTopTwoTeams(vector<int> &wins, vector<int> &draws, vector<int> &scored, vector<int> &conceded)
{
    int n = wins.size();
    vector<tuple<int, int, int>> t;
    for(int i=0; i<n; i++)
    {
        int points = wins[i]*3 + draws[i];
        int gd = scored[i] - conceded[i];
        t.push_back({points, gd, i});
    }
    sort(t.begin(), t.end(), cmp);
    
    int i1 = get<2>(t[0]);
    int i2 = get<2>(t[1]);
    
    return {i1, i2};
}


int main()
{
    vector<int> wins     = {3, 1, 2, 2};
    vector<int> draws    = {1, 5, 4, 4};
    vector<int> scored   = {30, 10, 20, 40};
    vector<int> conceded = {32, 13, 18, 37};

    vector<int> result = getTopTwoTeams(wins, draws, scored, conceded);
    cout << "Top two teams " << result[0] << "," << result[1] << endl;
    return 0;
}