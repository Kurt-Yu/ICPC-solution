#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric> 
using namespace std; 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1e9 + 5;
typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////


int main () {
    int s, r;
    cin >> s >> r;

    map<string, int> items;
    int num;
    string name;
    for (int i = 0; i < s; ++i) {
        cin >> num >> name;
        if (num > 1) name = name.substr(0, name.length() - 1);
        items[name] += num;
    }

    for (int i = 0; i < r; ++i) {
        cin >> num >> name;
        if (num > 1) name = name.substr(0, name.length() - 1);
        items[name] -= num;
        if (items[name] < 0) {
            cout << "error" << endl;
            return 0;
        }
    }

    vector<pair<string, int>> temp;
    for (auto& it : items) {
        if (it.second != 0) temp.push_back({it.first, it.second});
    }

    if (temp.size() == 0) {
        cout << "null" << endl;
    } else if (temp.size() == 1) {
        if (temp[0].second == 1) cout << "item" << endl;
        else cout << "items" << endl;
    } else {
        cout << "items" << endl;
    }

}