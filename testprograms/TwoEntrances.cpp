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
	
class TwoEntrances {
public:
	int count(vector <int> a, vector <int> b, int s1, int s2);
};

//mod
const int mod = 1000000000 + 7;

//tree
vector<int> adj[3010];

//lis and subtree answer
bool u[3010];
vector<int> tmp;
int lisSize[3010];
int lis[3010], islis[3010];
int subAns[3010], size[3010];

//Combinatorics
int C[3010][3010];

//DP
bool v[3010][3010];
int F[3010][3010];
int n, m;
int s1, s2;

void dfs(int x)
{
	if (u[x]) return ;
	u[x] = true;

	tmp.push_back(x);
	if (x == s2)
	{
		m = tmp.size();
		memset(islis, 0, sizeof(islis));
		for (int i = 0; i < m; i ++)
			lis[i] = tmp[i], islis[lis[i]] = 1;
	}
	
	for (int i = 0; i < adj[x].size(); i ++)
		dfs(adj[x][i]);
	
	tmp.pop_back();
}	

void treeDp(int x)
{
	u[x] = true;
	
	size[x] = subAns[x] = 1;
	for (int i = 0; i < adj[x].size(); i ++)
	{
		int j = adj[x][i];
		if (islis[j] || u[j])
			continue;
		//A child
		treeDp(j);
		size[x] += size[j];

		//subAns[x] = subAns[x] * subAns[j] * C[size[x] - 1][size[j]]
		subAns[x] = (int) ((LL) subAns[x] * (LL) subAns[j] % (LL) mod);
		subAns[x] = (int) ((LL) subAns[x] * (LL) C[size[x] - 1][size[j]] % (LL) mod);
	}
}

void dp(int l, int r)
{
	if (v[l][r]) return ;
	v[l][r] = true;

	if (l == r)
	{
		F[l][r] = subAns[lis[l]];
		return ;
	}
	
	dp(l, r - 1);
	dp(l + 1, r);
	
	int totSize = (l == 0 ? lisSize[r] : lisSize[r] - lisSize[l - 1]);
	int tmp;
	//F[l][r] += F[l][r - 1] * subAns[lis[r]] * C[size(l, r)][size[lis[r]]]
	tmp = (int) ((LL) F[l][r - 1] * (LL) subAns[lis[r]] % (LL) mod);
	tmp = (int) ((LL) tmp * (LL) C[totSize - 1][size[lis[r]] - 1] % (LL) mod);
	F[l][r] += tmp;
	F[l][r] %= mod;
	
	//F[l][r] += F[l + 1][r] * subAns[lis[l]] * C[size(l, r)][size[lis[l]]]
	tmp = (int) ((LL) F[l + 1][r] * (LL) subAns[lis[l]] % (LL) mod);
	tmp = (int) ((LL) tmp * (LL) C[totSize - 1][size[lis[l]] - 1] % (LL) mod);
	F[l][r] += tmp;
	F[l][r] %= mod;
}

int TwoEntrances::count(vector <int> a, vector <int> b, int _s1, int _s2) 
{
	n = a.size() + 1;
	s1 = _s1, s2 = _s2;

	//comb
	memset(C, 0, sizeof(C));
	for (int i = 0; i <= n; i ++)
		for (int j = 0; j <= i; j ++)
			if (j == 0)
				C[i][j] = 1;
			else 
				C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;

	//make tree
	for (int i = 0; i < n; i ++)
		adj[i].clear();
	for (int i = 0; i < n - 1; i ++)
	{
		int x = a[i];
		int y = b[i];
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	//make lis
	memset(u, 0, sizeof(u));
	tmp.clear();
	dfs(s1);

	//tree-dp
	memset(u, 0, sizeof(u));
	for (int i = 0; i < m; i ++)
		treeDp(lis[i]);

	lisSize[0] = size[lis[0]];
	for (int i = 1; i < m; i ++)
		lisSize[i] = lisSize[i - 1] + size[lis[i]];
	
	//Final dp
	memset(F, 0, sizeof(F));
	memset(v, 0, sizeof(v));
	dp(0, m - 1);

	return F[0][m - 1];
}
