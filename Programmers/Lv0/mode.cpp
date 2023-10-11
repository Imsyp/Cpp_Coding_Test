#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(vector<int> array) 
{
    int answer = 0;
    vector<int> oarr = array;

    sort(array.begin(), array.end());
    array.erase(unique(array.begin(), array.end()), array.end());

    unordered_map<int, int> um;

    for(int i=0; i<array.size(); i++)
    {
        um.insert(make_pair(array[i], 0));
    }

    for(int i=0; i<oarr.size(); i++)
    {
        um[oarr[i]] += 1;
    }

    int max = 0;

    for(int i=0; i<array.size(); i++)
    {
        if(um[array[i]]>um[max])
        {
            max = array[i];
        }
    }

    int count = 0;

    for(int i=0; i<array.size(); i++)
    {
        if(um[array[i]] == um[max])
        {
            count +=1;
        }
    }

    if(count ==1)
        return max;
    else
        return -1;
}

int main(void)
{
    cout<<solution({1, 1, 4, 4, 5, 5, 5, 3, 3, 2})<<endl;
    return 0;
}