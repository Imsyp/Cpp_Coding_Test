#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> strStack;
    stack<char> basket;

    for(int i = s.size()-1; i >= 0; i--) {
        strStack.push(s[i]);
    }

    //ó�� ������
    if(strStack.top() == '(') {
        basket.push(strStack.top()); //basket 
        strStack.pop();
    }
    else {
        return false;
    }

    while(answer) {
        if(strStack.empty()) {
            if(basket.empty()) {
                break;
            }
            else {
                return false;
            }
        }

        //'('�� basket�� push, ')'�� basket�� top�� '('���� Ȯ���ϰ� �� �� pop
        if(strStack.top() == '(') {
            basket.push(strStack.top());
            strStack.pop();
        }
        else if(strStack.top() == ')') {
            //')'�� ��, basket�� ��������� false, basket�� top�� '('�̸� �� �� pop, ')'�̸� false
            if(basket.empty()) {
                return false;
            }
            else if(basket.top() == '(') {
                strStack.pop();
                basket.pop();
            }
            else if(basket.top() == ')') {
                return false;
            }
        }
    }
    
    return answer;
}