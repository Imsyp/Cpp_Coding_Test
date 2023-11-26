#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited(100, false);

void dfs(vector<vector<int>> &relations, int pos) {
    for(int i = 0; i < relations[pos].size(); i++) {
        if(!visited[relations[pos][i]]) {
            visited[relations[pos][i]] = true;
            dfs(relations, relations[pos][i]);
        }
    }
    return ;
}


int main(void) {
    int N;
    cin >> N;

    vector<int> relation;
    vector<vector<int>> relations(N, relation);

    int M;
    cin >> M;

    while(M--) {
        int com1, com2;
        cin >> com1 >> com2;

        com1--;
        com2--;

        relations[com1].push_back(com2);
        relations[com2].push_back(com1);
    }

    visited[0] = true;
    dfs(relations, 0);

    int answer = 0;
    for(int i = 1; i < N; i++) {
        if(visited[i] == true) {
            answer++;
        }
    }

    cout << answer << endl;
    
    return 0;
}