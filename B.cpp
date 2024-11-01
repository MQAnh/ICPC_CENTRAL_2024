#include <bits/stdc++.h>
#define BIT(x,i) (((x) >> (i)) & 1)
#define MASK(x) ((1) << (x))
#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second
using namespace std;

const int maxn = 5e6+55;
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

int a[maxn];
int dd[maxn];

void process()
{
    int n, maxk;
    cin >> n >> maxk;
    for (int i = 1; i <= n; i ++) cin >> a[i];

    for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) dd[a[i] & a[j]] ++;

    int maxMask = MASK(21) - 1;
    for (int i = 0; i < 21; i ++)
    {
        for (int mask = 0; mask < MASK(21); mask ++) if (BIT(mask, i))
            dd[mask] += dd[mask ^ MASK(i)];
    }

    for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++)
    {
        int tmp = a[i] & a[j];
        int cur = dd[maxMask ^ tmp];

        if (cur < maxk)
        {
            maxk -= cur;
        }
        else
        {
            for (int u = 1; u <= n; u ++) for (int v = 1; v <= n; v ++) if (!(a[i] & a[j] & a[u] & a[v]))
            {
                maxk --;
                if (!maxk)
                {
                    cout << i << " " << j << " " << u << " " << v << endl;
                    return;
                }
            }
        }
    }
    cout << -1;
    return;
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

