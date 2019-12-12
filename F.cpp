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

int n;
string A, B;
map<pair<char, char>, int> diff;
map<char, int> match;

int main () {
    cin >> n;
    cin >> A >> B;
    for (int i = 0; i < n; ++i) {
        if (A[i] == B[i]) ++match[A[i]];
        else ++diff[make_pair(A[i], B[i])];
    }

    int curr = 0;
    for (auto& m : match) curr += m.second;

    vector<int> res;
    res.push_back(curr);
    for (auto& d : diff) {
        res.push_back(curr - match[d.first.first] + d.second);
    }
    // for (auto& m : match) cout << m.first << " " << m.second << endl;
    // for (auto& d : diff) cout << d.first.first << " " << d.first.second  << " " << d.second << endl;
    
    cout << *max_element(res.begin(), res.end()) << endl;
}