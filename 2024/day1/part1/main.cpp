#include <bits/stdc++.h>
using namespace std;

int main() {

    ifstream f("input.txt");
    multiset<int> nums1;
    multiset<int> nums2;

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
    auto it2 = nums2.begin();

    int sum = 0;

    while (it1 != nums1.end() && it2 != nums2.end()){
        sum += abs(*it1 - *it2); 
        it1++;
        it2++;
    }

    cout << sum << endl;

    f.close();
    return 0;
}
