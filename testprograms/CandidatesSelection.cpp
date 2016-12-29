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
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))
using namespace std;
	
class CandidatesSelection {
public:
	string possible(vector <string> score, vector <int> result);
};

int u[1010];

string CandidatesSelection::possible(vector <string> score, vector <int> result) 
{
	int m = score[0].size();
	
	memset(u, 0, sizeof(u));
	while (true)
	{
		int changed = 0;
		for (int i = 0; i < m; i ++)
		{
			int flag = 1;	
			for (int j = 0; j < result.size() - 1; j ++)
			{
				if (u[j]) continue;
				if (score[result[j]][i] > score[result[j + 1]][i])
				{
					flag = 0; break;
				}
			}
		
			if (flag)
			for (int j = 0; j < result.size() - 1; j ++)
			{
				if (u[j]) continue;
				if (score[result[j]][i] < score[result[j + 1]][i])
					u[j] = 1, changed = 1;
			}
		}
		if (! changed) break;
	}
	int flag = 1;
	for (int j = 0; j < result.size() - 1; j ++)
		if (u[j] == 0 && result[j] > result[j + 1])
			flag = 0;
	if (flag) return "Possible"; else return "Impossible";
}	

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
