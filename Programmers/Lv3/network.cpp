#include <string>
#include <vector>

using namespace std;

vector<bool> visited(200, false);

void dfs(int node, vector<vector<int>> newComputers) {
    for(int i = 0; i < newComputers[node].size(); i++) {
        if(visited[newComputers[node][i]] == false) {
            visited[newComputers[node][i]] = true;
            dfs(newComputers[node][i], newComputers);
        }
    }
    return ;
}

//network 하나에 대해서 dfs 돌면서 지나온 요소는 모두 visited를 true로 변경 -> 다 돌고 answer++
//node의 visited가 true면 skip 
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<int> computer;
    vector<vector<int>> newComputers(n, computer);
    vector<int> network(n, 0);
    for(int i = 0; i < n - 1; i++) {
        for(int j = 1; j < n; j++) {
            if(computers[i][j] == 1) {
                newComputers[i].push_back(j);
                newComputers[j].push_back(i);               
            }
        }
    }
    for(int i = 0; i < newComputers.size(); i++) {
        if(visited[i] == false) {
            answer++;
            visited[i] = true;
            dfs(i, newComputers);
        }
    }
    return answer;
}