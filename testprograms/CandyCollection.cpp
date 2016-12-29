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
	
class CandyCollection {
public:
	int solve(vector <int> Type1, vector <int> Number1, vector <int> Type2, vector <int> Number2);
};

struct node
{
	node() {}
	node(int _x, int _w) : x(_x), w(_w) {}
	int x, w;
};

const int inf = 1000000000;

int u[2][2010];
int tot[2][2010];
node adj[2][2010][2];
int N;

int f[2010][2];

void ins(int type, int x, int y, int w)
{
	int cur = tot[type][x] ++;
	adj[type][x][cur] = node(y, w);
}

int make(int shape, int flavor)
{
	if (flavor == adj[0][shape][0].x)
		return adj[0][shape][1].w + 1;
	return adj[0][shape][0].w + 1;
}

int CandyCollection::solve(vector <int> Type1, vector <int> Number1, vector <int> Type2, vector <int> Number2) 
{
	N = Type1.size();
	//make adj[][][]
	memset(tot, 0, sizeof(tot));
	for (int i = 0; i < N; i ++)
	{
		ins(0, i, Type1[i], Number1[i]);
		ins(1, Type1[i], i, Number1[i]);
		ins(0, i, Type2[i], Number2[i]);
		ins(1, Type2[i], i, Number2[i]);
	}
	
	memset(u, 0, sizeof(u));
	int totAns = 0;
	for (int i = 0; i < N; i ++)
		if (! u[1][i])
		{
			vector<int> who[2];
			who[0].clear(), who[1].clear();
			who[0].push_back(-1);
			who[1].push_back(-1);
			
			int curType = 1, curId = i;
			
			for ( ; ; )
			{
				who[curType].push_back(curId);
				u[curType][curId] = 1;
				
				int nextId = -1;
				for (int p = 0; p < 2; p ++)
				{
					int next = adj[curType][curId][p].x;
					if (! u[curType ^ 1][next])
					{
						nextId = next;
						break;
					}
				}
				if (nextId == -1)
					break;
				curType ^= 1;
				curId = nextId;
			}
			
			
			//dp
			int n = who[0].size() - 1;
			int curMin = inf;
			
			//1 does not make 0
			for (int i = 1; i <= n; i ++)
				f[i][0] = f[i][1] = inf;
			
			f[1][0] = 0;
			f[1][1] = make(who[0][1], who[1][2]);
			
			for (int i = 1; i < n; i ++)
			{
				//make w
				int w0, w1;
				w0 = make(who[0][i + 1], who[1][i + 1]);
				w1 = make(who[0][i + 1], (i + 2 > n ? who[1][1] : who[1][i + 2]));
				
				f[i + 1][0] = min(f[i + 1][0], f[i][0] + w0);
				f[i + 1][0] = min(f[i + 1][0], f[i][1]);
				
				f[i + 1][1] = min(f[i + 1][1], f[i][0] + max(w0, w1));
				f[i + 1][1] = min(f[i + 1][1], f[i][1] + w1);
			}
			curMin = min(curMin, f[n][1]);
			
			//1 makes 0
			for (int i = 1; i <= n; i ++)
				f[i][0] = f[i][1] = inf;
			
			f[1][0] = make(who[0][1], who[1][1]);
			f[1][1] = make(who[0][1], who[1][2]);
			f[1][1] = max(f[1][1], f[1][0]);
			
			for (int i = 1; i < n; i ++)
			{
				//make w
				int w0, w1;
				w0 = make(who[0][i + 1], who[1][i + 1]);
				w1 = (i + 2 > n ? 0 : make(who[0][i + 1], who[1][i + 2]));
				
				f[i + 1][0] = min(f[i + 1][0], f[i][0] + w0);
				f[i + 1][0] = min(f[i + 1][0], f[i][1]);
				
				f[i + 1][1] = min(f[i + 1][1], f[i][0] + max(w0, w1));
				f[i + 1][1] = min(f[i + 1][1], f[i][1] + w1);
			}
			curMin = min(curMin, f[n][1]);
			totAns += curMin;
		}
	return totAns;
}

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
