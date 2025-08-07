#include<bits/stdc++.h>
using namespace std;

string solution(string &s)
{
    int n= s.size();
    string news = "";
    for(int i=0; i<n/2; i++)
    {
        news+= s[i];
        news+= s[n-i-1];
    }
    if(n%2) news += s[n/2];
    return news;
}

int main()
{
    string s1 = "abcde";
    string s2 = "xyzwe";
    cout << solution(s1) << endl;
    cout << solution(s2) << endl;
    return 0;
}