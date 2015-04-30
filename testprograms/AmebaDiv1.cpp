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
	
class AmebaDiv1 {
public:
	int count(vector <int> X);
};

int AmebaDiv1::count(vector <int> X) 
{
	set<int> s, e;
	s.clear(), e.clear();
	for (int i = 0; i < X.size(); i ++)
		s.insert(X[i]);
	
	for (set<int>::iterator it = s.begin(); it != s.end(); it ++)
	{
		int cur = (*it);
		for (int i = 0; i < X.size(); i ++)
			if (X[i] == cur)
				cur += cur;
		e.insert(cur);
	}
	
	int ans = 0;
	for (set<int>::iterator it = s.begin(); it != s.end(); it ++)
		if (! e.count(*it))
			ans ++;
	return ans;
}
