#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

//Ʈ���� num1�� num2 node�� �θ� ���� ����
//�� �� �ϳ��� �θ��尡 ������ true ��ȯ
//�� �� �θ��尡 ������ false ��ȯ
//���� �����ϸ� false ��ȯ
bool setTree(map<int, int> &myMap, int num1, int num2) {
    //base case
    if (myMap[num1] != 0 && myMap[num2] != 0) {
        return false;
    }

    if (myMap[num1] != 0 && myMap[num2] == 0) {
        myMap[num2] = num1; 
        return true;
    } 
    else {
        myMap[num1] = num2;
        return true; 
    } 
}

int main(void) {
    int N;
    cin >> N;

    map<int, int> myMap;
    vector<stack<int>> inputs;

    //1~N������ tree�� input ����, 0�κ��� ����
    for(int i = 0; i <= N; i++) {
        myMap.insert({i, 0});

        stack<int> input;
        inputs.push_back(input);
    }

    //��Ʈ ��� ó��
    myMap[1] = 100;

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
        while(!inputs[key].empty()) {
            //case1: �� �� �ϳ��� �θ� ��尡 ���� ��� -> next key�� �̵�
            //case2: �� �� �θ� ��尡 �ִ� ��� -> ���� key�� ���� ��ҷ� ����
            //���� key�� �迭�� ���� ��� -> ���� key�� ȸ��
            if (setTree(myMap, key, inputs[key].top())) {
                kStack.push(inputs[key].top());
                inputs[key].pop();
                break; 
            }   

            inputs[key].pop();

            if (inputs[key].empty()) {
                kStack.pop();  
            }
        }
        if(inputs[1].empty() && kStack.top() == 1) {
            break;
        }
    }

    for(int i = 2; i <= N; i++) {
        cout << myMap[i] <<endl;
    }

    return 0;
}