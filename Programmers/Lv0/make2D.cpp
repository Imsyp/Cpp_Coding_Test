#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;

    for(int i = 0; i < num_list.size(); i += n) {
        vector<int> tmp;
        for(int j = 0; j < n; j++) {
            int tmpNum = num_list[i+j];    
            tmp.push_back(tmpNum);
        }
        answer.push_back(tmp);
    }
    return answer;
}