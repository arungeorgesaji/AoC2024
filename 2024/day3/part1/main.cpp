#include <bits/stdc++.h>
using namespace std;

int main() {

    ifstream f("input.txt");

    if (!f.is_open()) {
        cerr << "Error opening the file!";
        return 1;
    }

    string s;
    int sum = 0;

    while (getline(f, s)){
        istringstream iss(s);
        while (iss >> s){
            regex pattern(R"(mul\((\d{1,}),(\d{1,})\))");

            sregex_iterator begin(s.begin(), s.end(), pattern);
            sregex_iterator end;

            for (std::sregex_iterator i = begin; i != end; ++i) {
                std::smatch match = *i;  
                sum += stoi(match[1]) * stoi(match[2]);
            }
        }
    }
    
    std::cout << sum << std::endl;

    f.close();
    return 0;
}
