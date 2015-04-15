#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))
using namespace std;
	
class Singing {
public:
	int solve(int N, int low, int high, vector <int> pitch);
};

struct node
{
    int x, next, opp, left;
};

const int maxn = 30000;
const int maxm = 400000;
const int inf = (1 << 29);

node z[maxm];
int h[maxn], u[maxn];
int d[maxn], pre[maxn], q[maxn];
int now[maxn], w[maxn], flag;
int f, r, s, t, tot, v, ans;

void cleargraph(int ss, int tt)
{
    memset(h, 0, sizeof(h));
	s = ss, t = tt;
    tot = 0;
}

void ins(int x, int y, int c)
{
    int t1 = ++ tot, t2 = ++ tot;
    z[t1].x = y; z[t1].left = c; z[t1].next = h[x]; h[x] = t1;
    z[t2].x = x; z[t2].left = 0; z[t2].next = h[y]; h[y] = t2;
    z[t1].opp = t2;
    z[t2].opp = t1;
}

void refresh(int x)
{
    w[d[x]] --;
    if (! w[d[x]])
    {
        flag = 1; return ;
    }
    d[x] = t + 1; now[x] = h[x];
    for (int i = h[x]; i; i = z[i].next)
        if (z[i].left && d[z[i].x] + 1 < d[x])
            d[x] = d[z[i].x] + 1;
    w[d[x]] ++;
}

void augment()
{
    int delta = 1 << 30;
    for (int i = t; i != s; )
    {
        int j = pre[i];
        delta = min(delta, z[j].left);
        i = z[z[j].opp].x;
    }
    ans += delta;
    for (int i = t; i != s; )
    {
        int j = pre[i];
        z[j].left -= delta;
        z[z[j].opp].left += delta;
        i = z[z[j].opp].x;
    }
}

int maxflow()
{
    ans = 0;
    //BFS
    memset(u, 0, sizeof(u)); u[t] = 1;
    for (int i = s; i <= t; i ++) d[i] = t + 1;
    d[t] = 0;
    q[1] = t; f = 0; r = 1; 
    while (f < r)
    {
        int x = q[++ f];
        for (int i = h[x]; i; i = z[i].next)
            if (! u[z[i].x])
            {
                u[z[i].x] = 1;
                d[z[i].x] = d[x] + 1;
                q[++ r] = z[i].x;
            }
    }
    memset(w, 0, sizeof(w));
    for (int i = s; i <= t; i ++)
    {
        now[i] = h[i];
        w[d[i]] ++;
    }
    v = s; flag = 0;
    while (d[s] <= t)
        if (v == t)
        {
            augment(); v = s;
        }
        else
        {
            int j = now[v];
            while (j)
            {
                if (z[j].left && d[v] == d[z[j].x] + 1)
                    break;
                j = z[j].next;
            }
            if (j)
            {
                pre[z[j].x] = j;
                now[v] = j;
                v = z[j].x;
            }
            else
            {
                refresh(v);
                if (flag) break;
                if (v != s) v = z[z[pre[v]].opp].x;
            }
        } 
    return ans;
}

int Singing::solve(int N, int low, int high, vector <int> pitch) 
{
	//make graph
	cleargraph(0, N + 1);
	for (int i = 1; i < low; i ++)
		ins(s, i, inf);
	for (int i = high + 1; i <= N; i ++)
		ins(i, t, inf);
	
	for (int i = 1; i < pitch.size(); i ++)
	{
		int x = pitch[i];
		int y = pitch[i - 1];
		if (x != y)
		{
			ins(x, y, 1);
			ins(y, x, 1);
		}
	}
	return maxflow();
}
