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
	
class MaliciousPath {
public:
	long long minPath(int N, int K, vector <int> from, vector <int> to, vector <int> cost);
};

const int MAXN = 1010;
const int Base = 1048576;
const LL inf = 1LL << 61LL;

vector<pair<int, int> > adj[MAXN], adj1[MAXN];
LL Bound[MAXN], opt[2][MAXN]; 
int q[Base], f, r, u[MAXN];;

long long MaliciousPath::minPath(int N, int K, vector <int> from, vector <int> to, vector <int> cost) 
{
	for (int i = 0; i < N; i ++)
		adj[i].clear(), adj1[i].clear();
	for (int i = 0; i < cost.size(); i ++)
	{
		int x = from[i];
		int y = to[i];
		adj[x].push_back(make_pair(y, cost[i]));
		adj1[y].push_back(make_pair(x, cost[i]));
	}

	for (int k = 0; k <= K; k ++)
	{
		int cur = k % 2;
		if (k == 0)
			memset(Bound, 0, sizeof(Bound));
		else
			for (int i = 0; i < N; i ++)
			{
				Bound[i] = 0;
				for (int j = 0; j < adj[i].size(); j ++)
				{
					int next = adj[i][j].first;
					int cost = adj[i][j].second;
					Bound[i] = max(Bound[i], opt[cur ^ 1][next] + (LL) cost);
				}
			}
		Bound[N - 1] = 0;
		//spfa
		memset(u, 0, sizeof(u));
		f = 0, r = 1;
		q[1] = N - 1;
		for (int i = 0; i < N; i ++)
			opt[cur][i] = inf;
		opt[cur][N - 1] = Bound[N - 1];

		while (f != r)
		{
			f = (f + 1) % Base;
			int x = q[f];
			u[x] = 0;
			for (int i = 0; i < adj1[x].size(); i ++)
			{
				int next = adj1[x][i].first;
				int cost = adj1[x][i].second;
				
				LL v = max(opt[cur][x] + (LL) cost, Bound[next]);
				if (v < opt[cur][next])
				{
					opt[cur][next] = v;
					if (! u[next])
					{
						u[next] = 1;
						r = (r + 1) % Base;
						q[r] = next;
					}
				}
			}
		}
	}
	
	return (opt[K % 2][0] == inf ? -1 : opt[K % 2][0]);
}
