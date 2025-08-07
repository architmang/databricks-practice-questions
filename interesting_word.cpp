// a word is interesting if it contains a substring that satisfies 

// a letter alpha is repeated exactly n times in a row
// if there is a letter before the substring, it must not be equal to alpha
// if there is a letter after the substring, it must not be equal to alpha

// you are given a list of words & n. return which words are interesting
#include<bits/stdc++.h>
using namespace std;
int solution(vector<string> &words, int &n)
{
    int cnt = 0;
    for(auto word: words)
    {
        bool valid = false; //assume every word is invalid
        int len = word.size();
        // sliding window over starting letter of substring
        // len -1 - final + 1  = n
        // final = len - n
        for(int i=0; i<=len - n; i++)
        {
            // assume every substring is interesting
            bool isInteresting = true;
            char ch = word[i];
            
            for(int j =i; j< i+n; j++)
            {
                if(word[j]!=ch) isInteresting = false;
            }
            if( i!=0 && ch==word[i-1]) isInteresting = false;
            if( i!=len - n && ch==word[i+n]) isInteresting = false;
            
            if(isInteresting) valid = true;
        }
        if(valid) cnt++;
    }
    return cnt;
}
int main()
{
    vector<string> words1 = {"abc", "abaaaccct", "abaaaa", "aaaaba"};
    int n1 = 3;
    cout << "Output: " << solution(words1, n1) << endl; 
    // Output should be 1

    vector<string> words2 = {"all", "cook", "llama"};
    int n2 = 2;
    cout << "Output: " << solution(words2, n2) << endl; 
    // Output should be 3
    return 0;
}