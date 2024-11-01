#include <bits/stdc++.h>
#define BIT(x,i) (((x) >> (i)) & 1)
#define MASK(x) ((1) << (x))
#define ALL(v) (v).begin(), (v).end()
#define fi first
#define se second
#define int long long
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

int dp[111][maxn][2];
int n, W, H;
int w[maxn], c[maxn];

void process()
{
    cin >> n >> W >> H;
    for (int i = 1; i <= n; i ++) cin >> w[i] >> c[i];

    int maxsum = 0;
    for (int i = 1; i <= n; i ++) maxsum += c[i];

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;

    for (int i = 1; i <= n; i ++)
    {
        for (int s = 0; s <= maxsum; s ++)
        {
            for (int ok = 0; ok < 2; ok ++)
            {
                minimize(dp[i][s][ok], dp[i-1][s][ok]);
                if (s + c[i] <= maxsum) minimize(dp[i][s + c[i]][ok], dp[i-1][s][ok] + w[i]);
                if (!ok && w[i] <= H) minimize(dp[i][s + c[i]][1], dp[i-1][s][ok]);
            }
        }
    }

    int res = 0;
    for (int s = 0; s <= maxsum; s ++)
    {
        if (dp[n][s][1] <= W || dp[n][s][0] <= W) res = s;
    }
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

