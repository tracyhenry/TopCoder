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
	
class CompositeSmash {
public:
	string thePossible(int N, int target);
};

int can[1010100];

string CompositeSmash::thePossible(int N, int target) 
{
	memset(can, 0, sizeof(can));
	for (int i = 2; i <= N; i ++)
	{
		if (i == target)
		{
			can[i] = 1; continue;
		}
		int yes = 0, no = 0;
		for (int j = 2; j <= (int) sqrt(i); j ++)
			if (i % j == 0)
			{
				int x = j, y = i / j;
				if (! can[x] && ! can[y])
					no = 1;
				if (can[x] || can[y]) yes = 1;
			}
		if (no) can[i] = 0;
			else if (yes) can[i] = 1; else can[i] = 0;
	}
	if (can[N]) return "Yes"; else return "No";
}
	
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
