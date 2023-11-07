#include <sstream>
#include <string>
#include <vector>

using namespace std;

string solution(string letter) {
    string answer = "";
    stringstream ss(letter);
    vector<string> morse;

    string word;
    // 스트림을 한 줄씩 읽어, 공백 단위로 분리한 뒤, 결과 배열에 저장
    while (getline(ss, word, ' ')) {
        morse.push_back(word);
    }

    for(int i = 0; i < morse.size(); i++) {
        if(morse[i] == ".-") {
            answer += "a";
        }
        else if(morse[i] == "-...") {
            answer += "b";
        }
        else if(morse[i] == "-.-.") {
            answer += "c";
        }
        else if(morse[i] == "-..") {
            answer += "d";
        }
        else if(morse[i] == ".") {
            answer += "e";
        }
        else if(morse[i] == "..-.") {
            answer += "f";
        }
        else if(morse[i] == "--.") {
            answer += "g";
        }
        else if(morse[i] == "....") {
            answer += "h";
        }
        else if(morse[i] == "..") {
            answer += "i";
        }
        else if(morse[i] == ".---") {
            answer += "j";
        }
        else if(morse[i] == "-.-") {
            answer += "k";
        }
        else if(morse[i] == ".-..") {
            answer += "l";
        }
        else if(morse[i] == "--") {
            answer += "m";
        }
        else if(morse[i] == "-.") {
            answer += "n";
        }
        else if(morse[i] == "---") {
            answer += "o";
        }
        else if(morse[i] == ".--.") {
            answer += "p";
        }
        else if(morse[i] == "--.-") {
            answer += "q";
        }
        else if(morse[i] == ".-.") {
            answer += "r";
        }
        else if(morse[i] == "...") {
            answer += "s";
        }
        else if(morse[i] == "-") {
            answer += "t";
        }
        else if(morse[i] == "..-") {
            answer += "u";
        }
        else if(morse[i] == "...-") {
            answer += "v";
        }
        else if(morse[i] == ".--") {
            answer += "w";
        }
        else if(morse[i] == "-..-") {
            answer += "x";
        }
        else if(morse[i] == "-.--") {
            answer += "y";
        }
        else if(morse[i] == "--..") {
            answer += "z";
        }

    }
    return answer;
}