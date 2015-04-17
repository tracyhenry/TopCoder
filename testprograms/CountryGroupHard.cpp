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
	
class CountryGroupHard {
public:
	string solve(vector <int> a);
};

int F[1010];

string CountryGroupHard::solve(vector <int> a) 
{
	int n = a.size();
	a.resize(n + 1);
	for (int i = n; i; i --)
		a[i] = a[i - 1];

	memset(F, 0, sizeof(F));
	F[0] = 1;

	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < i; j ++)
		{
			bool ok = true;
			int last = 0;
			for (int k = j + 1; k <= i; k ++)
				if (a[k])
					if (last == 0)
						last = a[k];
					else if (last != a[k])
						ok = false;
			if (last && last != i - j)
				ok = false;
			if (ok)
				F[i] += F[j];
		}
	for (int i = 1; i <= n; i ++)
		cout << F[i] << endl;
	if (F[n] == 1)
		return "Sufficient";
	else 
		return "Insufficient";
}
