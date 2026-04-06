#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    string s;
    cin >> s;
    
    ll base = 0;
    vector<ll> delta(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            base += p[i];
            delta[i] = -p[i];
        } else {
            delta[i] = p[i];
        }
    }
    
    // 计算最大前缀和
    ll pre_max = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += delta[i];
        pre_max = max(pre_max, cur);
    }
    
    // 计算最大后缀和
    ll suf_max = 0;
    cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        cur += delta[i];
        suf_max = max(suf_max, cur);
    }
    
    ll max_gain = max(pre_max, suf_max);
    cout << base + max_gain << endl;
    
    return 0;
}
/*Alice and Bob are playing a game. The game involves splitting up game pieces into two teams. There are n pieces, and the i-th piece has a strength pi.

The way to split up game pieces is split into several steps:

First, Alice will split the pieces into two different groups A and B. This can be seen as writing the assignment of teams of a piece in an n character string, where each character is A or B.
Bob will then choose an arbitrary prefix or suffix of the string, and flip each character in that suffix (i.e. change A to B and B to A). He can do this step at most once.
Alice will get all the pieces marked A and Bob will get all the pieces marked B.
The strength of a player is then the sum of strengths of the pieces in the group.

Given Alice's initial split into two teams, help Bob determine an optimal strategy. Return the maximum strength he can achieve.

Input
The first line contains integer n (1 ≤ n ≤ 5·105) — the number of game pieces.

The second line contains n integers pi (1 ≤ pi ≤ 109) — the strength of the i-th piece.

The third line contains n characters A or B — the assignment of teams after the first step (after Alice's step).

Output
Print the only integer a — the maximum strength Bob can achieve.*/