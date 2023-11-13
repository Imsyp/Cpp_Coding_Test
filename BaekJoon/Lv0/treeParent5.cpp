#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//Ʈ���� num1�� num2 node�� �θ� ���� ����
//�� �� �ϳ��� �θ��尡 ������ true ��ȯ
//�� �� �θ��尡 ������ false ��ȯ
//���� �����ϸ� false ��ȯ
bool setTree(vector<int> &parent, int num1, int num2) {
    //base case
    if (parent[num1] != 0 && parent[num2] != 0) {
        return false;
    }

    if (parent[num1] != 0 && parent[num2] == 0) {
        parent[num2] = num1; 
        return true;
    } 
    else {
        parent[num1] = num2;
        return true; 
    } 
}  

int main(void) {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> parent;
    vector<stack<int>> inputs;

    //1~N������ tree�� input ����, 0�κ��� ����
    for(int i = 0; i <= N; i++) {
        parent.push_back(0);

        stack<int> input;
        inputs.push_back(input);
    }

    //��Ʈ ��� ó��
    parent[1] = 100;

    int Re = N-1;
    while(Re--) {
        int num1, num2;
        cin >> num1 >> num2;

        inputs[num1].push(num2);
        inputs[num2].push(num1);
    } 

    stack<int> kStack;
    int key;  
    kStack.push(1); 
    while(!kStack.empty()) {  
        key = kStack.top(); 
        if (inputs[key].empty()) { 
            kStack.pop();   
        }
        while(!inputs[key].empty()) { 
            //�̹� Ž���� ���� ��Ҵ� ����
            //case1: �� �� �ϳ��� �θ� ��尡 ���� ��� -> next key�� �̵�
            //case2: �� �� �θ� ��尡 �ִ� ��� -> ���� key ��ġ stack�� top ���
            //���� key�� �迭�� ���� ��� -> ���� key�� ȸ��
            if (setTree(parent, key, inputs[key].top())) {
                kStack.push(inputs[key].top());
                inputs[key].pop();
                break; 
            }   

            inputs[key].pop();

            /*
            if (inputs[key].empty()) {
                kStack.pop();  
            }
            */
        }
        if(inputs[1].empty() && kStack.top() == 1) {
            break;
        }
    }

    for(int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }

    return 0; 
} 