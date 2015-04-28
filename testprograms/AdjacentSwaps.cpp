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
#include <cmath>
#include <cstdlib>
#include <ctime>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))
using namespace std;

vector<int> getSplitNumbers(string s)
{
	for (int i = 0; i < s.size(); i ++)
		if (! isdigit(s[i])) s[i] = ' ';
	vector<int> ans;
	ans.clear();
	if (! s.size()) return ans;
	for ( ; ; )
	{
		int j = s.find(" ");
		if (j == string::npos)
		{
			ans.push_back(atoi(s.c_str()));
			return ans;
		}
		int x;
		sscanf(s.c_str(), "%d", &x);
		ans.push_back(x);
		s.erase(0, j + 1);
	}
	return ans;
}
	
class AdjacentSwaps {
public:
	int theCount(vector <int> p);
};

int base = 1000000000 + 7;
int F[51][51][51][51], u[51][51][51][51];
int N, a[100], C[100][100];

int work(int L, int R, int curL, int curR)
{
	if (u[L][R][curL][curR]) return F[L][R][curL][curR];
	u[L][R][curL][curR] = 1;
	if (L == R)
		if (curL == L) return F[L][R][curL][curR] = 1; else return F[L][R][curL][curR] = 0;
	F[L][R][curL][curR] = 0;
	for (int i = L; i < R; i ++)
	{
		int ansL = 0, ansR = 0, cL, cR;
		//swap i, i + 1
		
		//ansL
		cR = (i + 1 == R ? curR : a[i + 1]);
		if (i > L) cL = curL; else cL = cR;
		ansL = work(L, i, cL, cR);
		
		//ansR
		cL = (i == L ? curL : a[i]);
		if (i < R - 1) cR = curR; else cR = cL;
		ansR = work(i + 1, R, cL, cR);
		F[L][R][curL][curR] += (int) ((LL) ansL * (LL) ansR % (LL) base * (LL) C[R - L - 1][i - L] % (LL) base);
		F[L][R][curL][curR] %= base;
	}
	return F[L][R][curL][curR];
}
		
int AdjacentSwaps::theCount(vector <int> p) 
{
	//make C[][]
	memset(C, 0, sizeof(C));
	C[0][0] = 1;
	for (int i = 1; i <= 50; i ++)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; j ++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % base;
	}
	N = p.size();
	for (int i = 0; i < N; i ++)
		a[i] = p[i];
	memset(u, 0, sizeof(u));
	int x = work(0, N - 1, a[0], a[N - 1]);
	return x;
}
