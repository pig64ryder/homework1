//第一題
#include <iostream>
using namespace std;

int a(int m, int n) {
    if (m == 0) return n + 1;
    if (n == 0) return a(m - 1, 1);
    return a(m - 1, a(m, n - 1));
}

int a_no_rec(int m, int n) {
    while (m > 0 || n > 0) {
        if (m == 0) return n + 1;
        if (n == 0) { m--; n = 1; continue; }
        n--; int temp = a(m, n); m--; n = temp;
    }
    return n + 1;
}

int main() {
    cout << "A(1, 2) = " << a(1, 2) << endl;
    cout << "A(1, 2) 非遞迴 = " << a_no_rec(1, 2) << endl;
    return 0;
}
//第二題
#include <iostream>
#include <vector>
using namespace std;

void powerset(vector<char>& s, int i, vector<char>& curr, vector<vector<char>>& res) {
    if (i == s.size()) {
        res.push_back(curr);
        return;
    }
    powerset(s, i + 1, curr, res);
    curr.push_back(s[i]);
    powerset(s, i + 1, curr, res);
    curr.pop_back();
}

void print_set(vector<vector<char>>& res) {
    cout << "{ ";
    for (auto& subset : res) {
        cout << "{";
        for (char c : subset) cout << c;
        cout << "} ";
    }
    cout << "}" << endl;
}

int main() {
    vector<char> s = {'a', 'b', 'c'}, curr;
    vector<vector<char>> res;
    powerset(s, 0, curr, res);
    print_set(res);
}

