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
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))
using namespace std;
	
struct node
{
    int x, next, opp, left;
};

const int maxn = 30000;
const int maxm = 500000;

node z[maxm];
int h[maxn], u[maxn];
int d[maxn], pre[maxn], q[maxn];
int now[maxn], w[maxn], flag;
int f, r, s, t, tot, v, ans;


int id[300][300], n;
int D[4][2] = {{0, 3}, {0, -3}, {3, 0}, {-3, 0}};

void cleargraph(int _s, int _t)
{
    memset(h, 0, sizeof(h));
    tot = 0;
	s = _s, t = _t;
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

class BlockTheBlockPuzzle {
public:
	int minimumHoles(vector <string> board);
};

int BlockTheBlockPuzzle::minimumHoles(vector <string> board) 
{
	n = board.size();
	int gx = -1, gy = -1;
	
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			if (board[i][j] == '$')
				gx = i, gy = j;
	
	int total = 0;
	int s = 0, t = 0;
	
	memset(id, 0, sizeof(id));
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			if (i % 3 == gx % 3 && j % 3 == gy % 3)
				id[i][j] = ++ total, total ++;
	
	t = total + 1;
	
	cleargraph(s, t);
	
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			if (id[i][j] > 0 && board[i][j] == 'b')
				ins(s, id[i][j], 10000000);
	
	ins(id[gx][gy] + 1, t, 10000000);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			if (id[i][j] > 0)
				for (int dir = 0; dir < 4; dir ++)
				{
					int x = i + D[dir][0];
					int y = j + D[dir][1];
					if (x >= 0 && x < n && y >= 0 && y < n)
					{
						int curCost = 0;
						int dx = D[dir][0];
						int dy = D[dir][1];
						dx /= 3, dy /= 3;
						if (board[i + dx][j + dy] == '.')
							curCost ++;
						else if (board[i + dx][j + dy] != 'H')
							curCost += 10000000;						
						dx *= 2, dy *= 2;
						if (board[i + dx][j + dy] == '.')
							curCost ++;
						else if (board[i + dx][j + dy] != 'H')
							curCost += 10000000;						
	
						ins(id[i][j] + 1, id[x][y], curCost);
					}
				}
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			if (id[i][j] > 0)
			{
				if (board[i][j] == '.')
					ins(id[i][j], id[i][j] + 1, 1);
				else if (board[i][j] != 'H')
					ins(id[i][j], id[i][j] + 1, 10000000);
			}
	int ans = maxflow();
	if (ans > n * n)
		ans = -1;
	return ans;
}
