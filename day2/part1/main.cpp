#include <bits/stdc++.h>
using namespace std;

int main() {

    ifstream f("input.txt");

    if (!f.is_open()) {
        cerr << "Error opening the file!";
        return 1;
    }

    string s;
    int safe = 0;

    while (getline(f, s)){
        istringstream iss(s);
        int it = 1;
        int prev;
        bool inc = false;
        bool cur_safe = true;
        while (iss >> s){  
            if (it == 1) {
                prev = stoi(s);
                it++;
                continue;
            }

            if (abs(prev - stoi(s)) < 1 || abs(prev - stoi(s)) > 3) {
                cur_safe = false;
                break; 
            }

            if (it == 2) {
                if (stoi(s) > prev) {
                    inc = true;
                }
                prev = stoi(s);
                it++;
                continue;
            } else {
                if (inc && stoi(s) < prev) {
                    cur_safe = false;
                    break;
                }else if (!inc && stoi(s) > prev) {
                    cur_safe = false;
                    break;
                }
                prev = stoi(s); 
            }
        }
        if (cur_safe) {
            safe++;
        }
    }
    
    cout << safe << endl;

    f.close();
    return 0;
}
