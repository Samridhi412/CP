#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF = INT_MAX;
const int MAX = 1000;
const ll MOD = 1e9 + 7;

int DX[] = {1, 1, -1, -1};
int DY[] = {1, -1, 1, -1};

string pre(string &s) {
    int n = s.size();
    if (n == 0) return "^$";
    string ret = "";
    for (int i = 0; i < n; i++) {
        ret.push_back('#');
        ret.push_back(s[i]);
    }
    ret.push_back('#');
    return ret;
}

ii manacher(string &s) {
    s = pre(s);
    int n = s.size(), c = 0, r = 0, mx = 0;
    vector<int> len(n);
    for (int i = 1; i < n-1; i++) {
        len[i] = (r > i) ? min(r-i, len[2*c-i]) : 0;

        while (s[i+1+len[i]] == s[i-1-len[i]])
            len[i]++;

        if (i + len[i] > r) {
            c = i;
            r = i + len[i];
        }

        mx = max(mx, len[i]);
    }

    int cnt = 0;
    for(int i = 1; i < n-1; i++)
        cnt += mx == len[i];

  return ii(mx, cnt);
}

int main( ) {
    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        ii ans = manacher(s);
        cout << ans.first << " " << ans.second << "\n";
    }

}