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


/* Inspired by this proble: 
    https://leetcode.com/problems/image-overlap/
*/
const int N = 50;
int m, row, col, val;
char dir;
set<pair<int, int>> coord;
map<pair<int, int>, int> values;
int no_use;

int main(){
    no_use = scanf("%d", &m);
    getchar();
    int r = 0, c = 0;
    coord.insert({r, c});
    for (int i = 0; i < m; ++i) {
        no_use = scanf("%c", &dir);
        if (dir == 'l') c--;
        else if (dir == 'r') c++;
        else if (dir == 'u') r--;
        else r++;
        coord.insert({r, c});
    }

    no_use = scanf("%d%d", &row, &col);
    int matrix[row][col];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            no_use = scanf("%d", &val);
            values[{i, j}] = val;
        }
    }

    map<pair<int, int>, int> res;
    for (auto& c : coord) {
        for (auto& v : values) {
            res[{c.first - v.first.first, c.second - v.first.second}] += v.second;
        }
    }

    int max_sum = 0;
    for (auto& r : res) max_sum = max(max_sum, r.second);
    printf("%d\n", max_sum);
}