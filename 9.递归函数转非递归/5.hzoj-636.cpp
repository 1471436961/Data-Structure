/*************************************************************************
	> File Name: 5.hzoj-636.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 13 Jan 2024 11:39:08 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 100000
int indeg[MAX_N + 5] = {0};
int ans[MAX_N + 5] = {0};
vector<vector<int>> g(MAX_N + 5);

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, x, y; i < m; i++) {
        scanf("%d%d", &x, &y);
        indeg[y] += 1;
        g[x].push_back(y);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i]) continue;
        q.push(i);
        ans[i] = 1;
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0, I = g[now].size(); i < I; i++) {
            int t = g[now][i];
            indeg[t] -= 1;
            if (indeg[t] == 0) q.push(t);
            ans[t] = max(ans[now] + 1, ans[t]);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
