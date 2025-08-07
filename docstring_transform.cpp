#include<bits/stdc++.h>
using namespace std;

bool IsupperString(string word)
{
    bool isUpper = true;
    for(auto ch: word)
    {
        if(ch != '_' && !isupper(ch))
        {
            isUpper = false;
        }
    }
    return isUpper;
}

string convertCamel(string word)
{
    stringstream ss(word);
    string token, result;
    bool first = true;
    while(getline(ss, token, '_'))
    {
        if(first)
        {
            result += token;
            first = false;
        }
        else{
            token[0] = toupper(token[0]);
            result += token;
        }
    }
    return result;
}

string solution(string docstring)
{
    string result;
    int n = docstring.size();
    for(int i=0; i<n; i++)
    {
        if(docstring[i] == '`')
        {
            result += '`';
            i++;
            string temp;
            while(i<docstring.size() && docstring[i]!='`')
                temp += docstring[i++];
            stringstream ss(temp);
            string word, newTemp;
            
            while(ss >> word) 
            // space seperated components in temp
            {
                if(IsupperString(word))
                    newTemp += word + " ";
                else
                    newTemp += convertCamel(word) + " ";
            }
            
            // remove trailiing " " from newTemp
            if(!newTemp.empty() && newTemp.back() == ' ')
                newTemp.pop_back();
            
            result += newTemp;
            result += '`';
        }
        else{
            result += docstring[i];
        }
    }
    return result;
}

int main()
{
    string docstring = "Function `some_function` has `short_arg very_long_argument` and `CONSTANT_VALUE`.";
    cout << solution(docstring) << endl;
}