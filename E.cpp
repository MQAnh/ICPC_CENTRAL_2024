#include <bits/stdc++.h>
#define BIT(x,i) (((x) >> (i)) & 1)
#define MASK(x) ((1) << (x))
#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second
#define int long long
using namespace std;

const int maxn = 1111;
const int MOD = 1e9+7;

typedef long long ll;
typedef pair <int,int> pii;

void add(int &a, const int &b)
{
    a += b;
    if (a >= MOD) a -= MOD;
}

void maximize(int &a, const int &b)
{
    if (a < b) a = b;
}

void minimize(int &a, const int &b)
{
    if (a > b) a = b;
}

char a[maxn][maxn];
int n, m, maxk;
int dist[maxn][maxn], d[maxn][maxn];
int dp[MASK(15)][16];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool inside(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

void bfs(int u, int v)
{
    memset(d, 0x3f, sizeof(d));
    d[u][v] = 0;
    queue <pii> q;
    q.push(pii(u, v));
    while (!q.empty())
    {
        int u = q.front().fi, v = q.front().se;
        q.pop();

        for (int k = 0; k < 4; k ++)
        {
            int x = u + dx[k];
            int y = v + dy[k];

            if (inside(x, y) && (a[x][y] != '#') && d[x][y] > d[u][v] + 1)
            {
                d[x][y] = d[u][v] + 1;
                q.push(pii(x, y));
            }
        }
    }
}

void process()
{
    cin >> n >> m >> maxk;
    vector <pii> rem;
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++)
    {
        cin >> a[i][j];
        if (a[i][j] == 'S') rem.push_back(pii(i, j));
    }

    for (int i = 0; i < rem.size(); i ++)
    {
        pii x = rem[i];
        bfs(x.fi, x.se);

        for (int j = 0; j < rem.size(); j ++) dist[i][j] = d[rem[j].fi][rem[j].se];
    }

    bfs(1, 1);
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < maxk; i ++) dp[MASK(i)][i] = d[rem[i].fi][rem[i].se];

    for (int mask = 0; mask < MASK(maxk); mask ++)
    {
        for (int i = 0; i < maxk; i ++) if (BIT(mask, i))
            for (int j = 0; j < maxk; j ++) if (!BIT(mask, j))
                minimize(dp[mask + MASK(j)][j], dp[mask][i] + dist[i][j]);
    }

    int res = 1e18;
    for (int i = 0; i < maxk; i ++) minimize(res, dp[MASK(maxk) - 1][i]);

    if (res == 1e18) res = -1;
    cout << res;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #define TASK "bai1"
//    freopen(TASK".inp", "r", stdin);
//    freopen(TASK".out", "w", stdout);

    int ntest = 1;
    while (ntest --) process();

    return 0;
}

