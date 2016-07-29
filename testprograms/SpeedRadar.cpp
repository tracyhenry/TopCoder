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
	
class SpeedRadar {
public:
	double averageSpeed(int minLimit, int maxLimit, vector <int> readings);
};

double SpeedRadar::averageSpeed(int minLimit, int maxLimit, vector <int> readings) 
{
	int sum = 0, tot = 0;
	for (int i = 0; i < readings.size(); i ++)
	{
		int x = readings[i];
		if (minLimit <= x && x <= maxLimit)
			sum += x, tot ++;
	}
	if (((int) readings.size() - tot) / (double) readings.size() > 0.1)
		return 0.0;
	return (double) sum / tot;
}
	

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
