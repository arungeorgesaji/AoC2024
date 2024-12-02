#include <bits/stdc++.h>
using namespace std;

int main() {

    ifstream f("input.txt");
    unordered_multiset<int> nums1;
    unordered_multiset<int> nums2;

    if (!f.is_open()) {
        cerr << "Error opening the file!";
        return 1;
    }

    string s;

    while (getline(f, s)){
        istringstream iss(s);
        bool first = true;
        while (iss >> s){
            if (first){
                nums1.insert(stoi(s));
                first = false;
            }else {
                nums2.insert(stoi(s));
                first = true;
            }
        }
    }
    
    auto it1 = nums1.begin();

    int score = 0;

    while (it1 != nums1.end()){
        score += *it1 * nums2.count(*it1); 
        it1++;
    }

    cout << score << endl;

    f.close();
    return 0;
}
