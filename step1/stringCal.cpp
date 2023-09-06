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

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
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

    for(i=0; i<formula.size(); i++) //���ڴ� numStr��, �����ڴ� operStr�� ����
    {
        if(isdigit(formula[i]) !=0)
            numStr.push_back(formula[i]-'0');
        else
            operStr.push_back(formula[i]);
    }

    for (i = 0; i < operStr.size(); i++) // ������ +, - �� ���� ����
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