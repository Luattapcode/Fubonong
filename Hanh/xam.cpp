#include <iostream>
#include <vector>
#include <string>

using namespace std;

// H�m x�y d?ng m?ng LPS cho x�u t
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

// H�m t�m ki?m KMP
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
            return i - j; // t�m th?y t t?i v? tr� (i - j)
        } else if (i < n && t[j] != s[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return -1; // Kh�ng t�m th?y t trong s
}

// H�m x�a x�u t trong s cho d?n khi t kh�ng c�n xu?t hi?n trong s
string removeSubstringKMP(string s, const string &t) {
    int pos;
    while ((pos = KMPSearch(s, t)) != -1) {
        s.erase(pos, t.length());
    }
    return s.empty() ? "X�u s l� x�u r?ng." : s;
}

int main() {
    string s, t;
    cout << "Nh?p x�u s: ";
    cin >> s;
    cout << "Nh?p x�u t: ";
    cin >> t;

    string result = removeSubstringKMP(s, t);
    cout << result << endl;

    return 0;
}

