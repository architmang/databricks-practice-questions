// binary string consists of 0s and 1s
// array of strings requests containing requests of two types

// "count:<index>" : find number of 0s in the binary string befor and including the specified 0 based index
// "flip" : flip all elements of binary string

// return an array answers where answers[i] contains the answer for the respective count request

#include<bits/stdc++.h>
using namespace std;

vector<int> solution(string &binaryString, vector<string> &requests)
{
    bool flipped = false;
    vector<int> result;
    for(auto req: requests)
    {
        int cnt = 0;
        if(req == "flip")
            flipped = !flipped;
        else{
            int index = stoi(req.substr(6));
            for(int i=0; i<=index; i++)
            {
                if(!flipped && binaryString[i] == '0') cnt++;
                if(flipped && binaryString[i] == '1') cnt++;
            }
            result.push_back(cnt);
        }
    }
    return result;
}

int main()
{
    string b1 = "1111010";
    vector<string> r1 = {"count:4", "count:6", "flip", "count:4", "flip", "count:2"};
    auto ss = solution(b1, r1);
    for(auto s:ss)
    {
        cout << s << " ";
    }
    cout << endl;
}
