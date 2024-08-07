#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Hàm xây d?ng m?ng LPS cho xâu t
vector<int> computeLPSArray(const string &t) {
    int m = t.length();
    vector<int> lps(m, 0);
    int length = 0;
    int i = 1;

    while (i < m) {
        if (t[i] == t[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// Hàm tìm ki?m KMP
int KMPSearch(const string &s, const string &t) {
    int n = s.length();
    int m = t.length();
    vector<int> lps = computeLPSArray(t);

    int i = 0; // index for s
    int j = 0; // index for t

    while (i < n) {
        if (t[j] == s[i]) {
            i++;
            j++;
        }

        if (j == m) {
            return i - j; // tìm th?y t t?i v? trí (i - j)
        } else if (i < n && t[j] != s[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return -1; // Không tìm th?y t trong s
}

// Hàm xóa xâu t trong s cho d?n khi t không còn xu?t hi?n trong s
string removeSubstringKMP(string s, const string &t) {
    int pos;
    while ((pos = KMPSearch(s, t)) != -1) {
        s.erase(pos, t.length());
    }
    return s.empty() ? "Xâu s là xâu r?ng." : s;
}

int main() {
    string s, t;
    cout << "Nh?p xâu s: ";
    cin >> s;
    cout << "Nh?p xâu t: ";
    cin >> t;

    string result = removeSubstringKMP(s, t);
    cout << result << endl;

    return 0;
}

