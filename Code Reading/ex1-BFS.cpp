#include <bits/stdc++.h>
using namespace std;
int s[300];
bool vis[300];
int n, m;
int d[2] = {1, -1};
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    q.push(0);
    vis[x] = 1;
    
    while (!q.empty()) {
        x = q.front();
        q.pop();
        int w = q.front();
        q.pop();
        if (x == n) {
            printf("%d\n", w);
            return;
        }
        if (s[x] != 0) {
            int a = s[x];
            if (!vis[a]) {
                vis[a] = 1;
                q.push(a);
                q.push(w + 1);
            }
        }
        for (int i = 0; i < 2; i++) {
            int xx = x + d[i];
            if (xx < 0 || vis[xx])
                continue;
            vis[xx] = 1;
            q.push(xx);
            q.push(w + 1);
        }
    }
}
int main()
{

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        s[a] = b;
    }
    bfs(0);
    return 0;
}