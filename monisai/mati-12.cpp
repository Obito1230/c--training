#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
double parseField(const string &s, char &concept) {
    concept = s[0];
    size_t eqPos = s.find('=');
    string numPart = s.substr(eqPos + 1);
    
    double value = 0;
    char prefix = 0, unit = 0;
    size_t i = 0;

    while (i < numPart.size() && (isdigit(numPart[i]) || numPart[i] == '.')) {
        i++;
    }
    string numStr = numPart.substr(0, i);
    sscanf(numStr.c_str(), "%lf", &value);
    
  
    if (i < numPart.size()) {
        if (numPart[i] == 'm' || numPart[i] == 'k' || numPart[i] == 'M') {
            prefix = numPart[i];
            i++;
        }
        if (i < numPart.size()) {
            unit = numPart[i];
        }
    }
    
    if (prefix == 'm') value *= 1e-3;
    else if (prefix == 'k') value *= 1e3;
    else if (prefix == 'M') value *= 1e6;
    
    return value;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); 
    
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        string line;
        getline(cin, line);
        
        double P = 0, U = 0, I = 0;
        bool hasP = false, hasU = false, hasI = false;
        
        // 扫描所有 "Concept=..." 字段
        size_t pos = 0;
        while ((pos = line.find('=')) != string::npos) {
         
            size_t start = pos;
            while (start > 0 && line[start-1] != ' ' && line[start-1] != '\t') {
                start--;
            }
            size_t end = pos;
            while (end < line.size() && line[end] != ' ' && line[end] != '\t') {
                end++;
            }
            string field = line.substr(start, end - start);
            
            char concept;
            double val = parseField(field, concept);
            if (concept == 'P') {
                P = val;
                hasP = true;
            } else if (concept == 'U') {
                U = val;
                hasU = true;
            } else if (concept == 'I') {
                I = val;
                hasI = true;
            }
            
            // 跳过已处理部分
            line = line.substr(end);
        }
        
        // 计算未知量
        char unknown = 0;
        double ans = 0;
        if (hasP && hasU) {
            ans = P / U;
            unknown = 'I';
        } else if (hasP && hasI) {
            ans = P / I;
            unknown = 'U';
        } else if (hasU && hasI) {
            ans = U * I;
            unknown = 'P';
        }

        printf("Problem #%d\n", caseNum);
        printf("%c=%.2lf%c\n", unknown, ans, 
               (unknown == 'P' ? 'W' : (unknown == 'U' ? 'V' : 'A')));
        printf("\n");
    }
    return 0;
}