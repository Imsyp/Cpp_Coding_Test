#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(string my_string)
{
    int answer = 0;
    int i;
    
    vector<string> formulaStr;

    vector<int> numStr;
    vector<char> operStr;

    formulaStr = split(my_string, ' ');
    vector<char> formula;


    for(i=0; i<formulaStr.size(); i++)
        formula[i] = string(formulaStr[i]);

    for(i=0; i<formula.size(); i++) //숫자는 numStr에, 연산자는 operStr에 정렬
    {
        if(isdigit(formula[i]) !=0)
            numStr.push_back(formula[i]-'0');
        else
            operStr.push_back(formula[i]);
    }

    for (i = 0; i < operStr.size(); i++) // 연산자 +, - 에 따라 연산
    {
        switch (operStr[i])
        {
        case '+':
            {
                int op1 = numStr.back();
                numStr.pop_back();
                int op2 = numStr.back();
                numStr.pop_back();

                numStr.push_back(op1 + op2);
                break;
            }

        case '-':
            {
                int op1 = numStr.back();
                numStr.pop_back();
                int op2 = numStr.back();
                numStr.pop_back();

                numStr.push_back(op2 - op1);
                break;
            }
        }
    }

    answer = numStr.back();

    return answer;
}