#include <bits/stdc++.h>
#define BIT(x,i) (((x) >> (i)) & 1)
#define MASK(x) ((1) << (x))
#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second
using namespace std;

const int maxn = 1e5+55;
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

int dd[maxn];
int lim[maxn], cnt[maxn];
int savecnt[maxn], savelim[maxn];

void del(int &a, int &b)
{
    int t = min(a, b);
    a -= t;
    b -= t;
}

bool cmp(int a, int b)
{
    return lim[a] < lim[b];
}

void process()
{
    int n;
    cin >> n;
    for (int i = 0; i < 3; i ++) cin >> lim[i];

    for (int i = 1; i <= n; i ++) dd[i] = 0;

    for (int i = 0; i < 3; i ++)
    {
        int m;
        cin >> m;
        while (m --)
        {
            int x;
            cin >> x;
            dd[x] |= MASK(i);
        }
    }

    for (int mask = 0; mask < 8; mask ++) cnt[mask] = 0;
    for (int i = 1; i <= n; i ++) cnt[dd[i]] ++;

    int tmp = lim[0] + lim[1] + lim[2], res = 0;
    for (int i = 0; i < 3; i ++) del(lim[i], cnt[MASK(i)]);

    if (lim[0] + lim[1] <= cnt[3])
    {
        lim[0] = lim[1] = 0;
        del(lim[2], cnt[5]);
        del(lim[2], cnt[6]);

        int cur = max(0, lim[0] + lim[1] + lim[2] - cnt[7]);
        maximize(res, tmp - cur);
    }
    else
    {
        for (int ca = 0; ca <= cnt[3]; ca ++)
        {
            if (ca > lim[0] || cnt[3] - ca > lim[1]) continue;
            for (int mask = 0; mask < 8; mask ++) savecnt[mask] = cnt[mask];
            for (int i = 0; i < 3; i ++) savelim[i] = lim[i];

            lim[0] -= ca;
            lim[1] -= cnt[3] - ca;

            del(lim[0], cnt[5]);
            del(lim[1], cnt[6]);
            del(lim[2], cnt[5]);
            del(lim[2], cnt[6]);

            int cur = max(0, lim[0] + lim[1] + lim[2] - cnt[7]);
            maximize(res, tmp - cur);

            for (int mask = 0; mask < 8; mask ++) cnt[mask] = savecnt[mask];
            for (int i = 0; i < 3; i ++) lim[i] = savelim[i];
        }
    }

    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #define TASK "bai1"
//    freopen(TASK".inp", "r", stdin);
//    freopen(TASK".out", "w", stdout);

    int ntest = 1; cin >> ntest;
    while (ntest --) process();

    return 0;
}

