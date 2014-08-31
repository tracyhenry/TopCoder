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
	
class TorusSailing {
public:
	double expectedTime(int N, int M, int goalX, int goalY);
};

double F[1100][110][110];

double TorusSailing::expectedTime(int N, int M, int goalX, int goalY) 
{
	memset(F, 0, sizeof(F));
	F[0][0][0] = 1.0;
	for (int step = 0; step < 1090; step ++)
		for (int x = 0; x < N; x ++)
			for (int y = 0; y < M; y ++)
				if (F[step][x][y] != 0 && (x != goalX || y != goalY))
				{
					F[step + 1][(x + 1) % N][y] += F[step][x][y] * 0.5;
					F[step + 1][x][(y + 1) % M] += F[step][x][y] * 0.5;
				}
	double ans = 0.0;
	for (int step = 0; step <= 290; step ++)
		ans += F[step][goalX][goalY] * step;//, cout << F[step][goalX][goalY] << endl;
	return ans;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, double p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	TorusSailing *obj;
	double answer;
	obj = new TorusSailing();
	clock_t startTime = clock();
	answer = obj->expectedTime(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == answer && fabs(p4 - answer) <= 1e-9 * max(1.0, fabs(p4));
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	int p2;
	int p3;
	double p4;
	
	{
	// ----- test 0 -----
	p0 = 2;
	p1 = 2;
	p2 = 1;
	p3 = 1;
	p4 = 4.0;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 3;
	p2 = 0;
	p3 = 2;
	p4 = 8.0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 7;
	p1 = 10;
	p2 = 3;
	p3 = 2;
	p4 = 51.80060107964039;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 100;
	p1 = 100;
	p2 = 99;
	p3 = 99;
	p4 = 9992.616372325532;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING





//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
