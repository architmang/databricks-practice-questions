// you are given an array of string arrays called requests
// totalSlots - > represents total memory slots; memory is circular
// simulate memory allocation/deallocation based on requests

// ["store", "startIndex", "numberOfSlots"]
// try to allocate numberOfSlots slots starting from or after startIndex
// if successful return starting index, else return -1

// ["free", "startIndex", "numberOfSlots"]
// free numberOfSlots, always succeeds, returns numberOfSlots

#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<vector<string>> &requests, int &totalSlots)
{
    vector<bool> memory(totalSlots, false); // false means free
    vector<int> result;

    for(auto req: requests)
    {
        string cmd = req[0];
        int startInd = stoi(req[1]);
        int numSlots = stoi(req[2]);

        if(cmd == "free")
        {
            for(int i = 0; i < numSlots; i++)
            {
                int ind = (startInd + i)%totalSlots;
                memory[ind] = false;
            }
            result.push_back(numSlots);
        }
        else{
            bool allocated = false;
            // for all indexes, starting from startInd check if allocation can be done
            for(int i=0; i<totalSlots; i++)
            {
                int ind = (startInd + i) % totalSlots;
                bool canAllot = true;
                for(int j=0; j<numSlots; j++)
                {
                    int pos = (ind + j) % totalSlots;
                    if(memory[pos])
                    {
                        canAllot = false;
                        break;
                    }
                }
                if(!canAllot) continue;
                else{
                    result.push_back(ind);
                    for(int j=0; j<numSlots; j++)
                    {
                        int pos = (ind + j) % totalSlots;
                        memory[pos] = true;
                    }
                    allocated = true;
                    break;
                }
            }
            if(!allocated) result.push_back(-1);
        }
    }
    return result;
}

int main()
{
    vector<vector<string>> requests = {
        {"store", "0", "6"},
        {"store", "0", "3"},
        {"free", "0", "3"},
        {"store", "10", "3"},
        {"store", "6", "6"}
    };
    int totalSlots = 15;
    auto vec = solution(requests, totalSlots);
    for(auto v:vec)
        cout << v << " ";
    return 0;
}