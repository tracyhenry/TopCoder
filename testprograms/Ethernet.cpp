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
	
class Ethernet {
public:
	int connect(vector <int> parent, vector <int> dist, int maxDist);
};

int inf = 10000000;

int lenLimit;
int n;
vector<pair<int, int> > ch[100];

int f[100][1000];
int g[100][1000];

void dp(int x)
{
	if (ch[x].size() == 0)
	{
		f[x][0] = 1;
		for (int i = 1; i <= lenLimit; i ++)
			f[x][i] = inf;
		return ;
	}
	
	int totCh = (int) ch[x].size();
	for (int i = 0; i < totCh; i ++)
		dp(ch[x][i].first);
	
	//second dp
	for (int i = 0; i <= totCh; i ++)
		for (int j = 0; j <= lenLimit; j ++)
			g[i][j] = inf;
	g[0][0] = 0;
	for (int i = 0; i < totCh; i ++)
		for (int j = 0; j <= lenLimit; j ++)
			if (g[i][j] < inf)
			{
				//next
				int curCh = ch[x][i].first;
				int curDist = ch[x][i].second;
				
				//link with x
				for (int k = 0; k <= lenLimit; k ++)
					if (f[curCh][k] < inf && j + k + curDist <= lenLimit)
						g[i + 1][max(j, k + curDist)] = min(g[i + 1][max(j, k + curDist)], g[i][j] + f[curCh][k] - 1);
				
				//not link with x
				for (int k = 0; k <= lenLimit; k ++)
					g[i + 1][j] = min(g[i + 1][j], g[i][j] + f[curCh][k]);
			}
	for (int i = 0; i <= lenLimit; i ++)
		f[x][i] = g[totCh][i] + 1;
}
			
int Ethernet::connect(vector <int> parent, vector <int> dist, int maxDist) 
{
	n = parent.size() + 1;
	lenLimit = maxDist;
	
	for (int i = 0; i < n; i ++)
		ch[i].clear();
	for (int i = 0; i < parent.size(); i ++)
	{
		int curChild = i + 1;
		int curParent = parent[i];
		int curDist = dist[i];
		
		ch[curParent].push_back(make_pair(curChild, curDist));
	}
	
	//dp
	dp(0);
	
	int ans = inf;
	for (int i = 0; i <= maxDist; i ++)
		ans = min(ans, f[0][i]);
	return ans;
}
