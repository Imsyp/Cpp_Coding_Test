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

    //처음 꺼낼때
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

        //'('면 basket에 push, ')'면 basket의 top이 '('인지 확인하고 둘 다 pop
        if(strStack.top() == '(') {
            basket.push(strStack.top());
            strStack.pop();
        }
        else if(strStack.top() == ')') {
            //')'일 때, basket이 비어있으면 false, basket의 top이 '('이면 둘 다 pop, ')'이면 false
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