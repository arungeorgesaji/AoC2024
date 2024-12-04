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
    bool current_do = true;

    regex pattern(R"(mul\((\d{1,}),(\d{1,})\))");
    regex do_pattern(R"(do\(\))");
    regex dont_pattern(R"(don't\(\))");

    while (getline(f, s)){
        sregex_iterator it(s.begin(), s.end(), pattern);
        sregex_iterator do_it(s.begin(), s.end(), do_pattern);
        sregex_iterator dont_it(s.begin(), s.end(), dont_pattern);
        sregex_iterator end;

        vector<pair<int, string>> events;

        for (; it != end; ++it) {
            events.emplace_back(it->position(0), (*it).str());
        }

        for (; do_it != end; ++do_it) {
            events.emplace_back(do_it->position(0), "do");
        }

        for (; dont_it != end; ++dont_it) {
            events.emplace_back(dont_it->position(0), "dont");
        }
          
        sort(events.begin(), events.end());;

        for (auto const[pos, event] : events) {
            if (event == "do") {
                current_do = true;
            } else if (event == "dont") {
                current_do = false;
            } else {
                if (current_do) {
                    smatch match;
                    regex_match(event, match, pattern);
                    sum += stoi(match[1]) * stoi(match[2]);
                }
            }
        }



    }
    
    std::cout << sum << std::endl;

    f.close();
    return 0;
}
