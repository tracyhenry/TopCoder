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
#define ULL unsigned long long
using namespace std;
	
class BinaryCards {
public:
	long long largestNumber(long long A, long long B);
};

long long BinaryCards::largestNumber(long long A, long long B) 
{
	ULL ans = B, cur = 1;
	for (int i = 0; i < 63; i ++)
	{
		if (cur <= B)
		{
			ULL tmp = ((ULL) B - cur) / (cur * 2 + 2) * (cur * 2 + 2);
			if (tmp + cur >= (ULL) A && tmp + cur < (ULL) B)
				ans = max(ans, tmp + cur * 2 + 1);
		}
		cur = cur * 2 + 1;
	}
	return ans;
}
