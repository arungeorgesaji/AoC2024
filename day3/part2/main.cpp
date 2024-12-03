#include <bits/stdc++.h>
using namespace std;

bool is_safe(vector<int> v) {
    bool inc = true;
    bool dec = true;
    for(int i=1;i<v.size();i++) {
        if(abs(v[i] - v[i-1]) < 1 || abs(v[i] - v[i-1]) > 3) return false;
        if(v[i] < v[i-1]) inc = false;
        if(v[i] > v[i-1]) dec = false;
    }

    return inc || dec;
}

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
        vector<int> v;
        int x;
        while (iss >> x) v.push_back(x);

        if(is_safe(v)) {
            safe++;
            continue;
        }

        for(int i=0;i<v.size();i++) {
            vector<int> temp = v;
            temp.erase(temp.begin() + i);
            if (is_safe(temp)) {
                safe++;
                break;
            }
        }
    }
    
    cout << safe << endl;

    f.close();
    return 0;
}
