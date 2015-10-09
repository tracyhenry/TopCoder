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
	
class AlternativePiles {
public:
	int count(string C, int M);
};

const int base = 1000000000 + 7;
int dp[5010][52][52];

int AlternativePiles::count(string C, int M) 
{
	memset(dp, 0, sizeof(dp));
	dp[0][M][0] = 1;
	
	int N = C.size();
	
	for (int i = 0; i < N; i ++)
		for (int j = 0; j <= M; j ++)
			for (int mod = 0; mod < M; mod ++)
				if (dp[i][j][mod])
					switch (C[i])
					{
						case 'R' :
							if (j)
							{
								int &r = dp[i + 1][j - 1][mod];
								r += dp[i][j][mod];
								if (r >= base) r -= base;
							}
							break;
						case 'G' :
							if (M - j)
							{
								int &r = dp[i + 1][j + 1][(mod + 1) % M];
								r += dp[i][j][mod];
								if (r >= base) r -= base;
							}
							break;
						case 'B' :
							if (1 == 1)
							{
								int &r = dp[i + 1][j][mod];
								r += dp[i][j][mod];
								if (r >= base) r -= base;
							}
							break;
						case 'W' :
							//R
							if (j)
							{
								int &r = dp[i + 1][j - 1][mod];
								r += dp[i][j][mod];
								if (r >= base) r -= base;
							}
							//G
							if (M - j)
							{
								int &r = dp[i + 1][j + 1][(mod + 1) % M];
								r += dp[i][j][mod];
								if (r >= base) r -= base;
							}
							//B
							if (1 == 1)
							{
								int &r = dp[i + 1][j][mod];
								r += dp[i][j][mod];
								if (r >= base) r -= base;
							}										
							break;
					}
	
	return dp[N][M][0];
}
