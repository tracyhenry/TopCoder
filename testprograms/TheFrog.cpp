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
	
class TheFrog {
public:
	double getMinimum(int D, vector <int> L, vector <int> R);
};

double TheFrog::getMinimum(int D, vector <int> L, vector <int> R) 
{
	double ans = D;
	int n = L.size();

	for (int i = 0; i < n; i ++)
		for (int k = 1; k <= D; k ++)
		{
			double cur = L[i] / (double) k;
			int can = 1;
			for (int p = 0; p < n; p ++)
			{
				int step = (int) (L[p] * k / (double) L[i]);
				if ((step + 1) * L[i] >= R[p] * k)
					continue;
				can = 0; break;
			}
			if (can) ans = min(ans, cur);

			cur = R[i] / (double) k;
			can = 1;
			//a[i][j].second
			for (int p = 0; p < n; p ++)
			{
				int step = (int) (L[p] * k / (double) R[i]);
				if ((step + 1) * R[i] >= R[p] * k)
					continue;
				can = 0; break;
			}
			if (can) ans = min(ans, cur);
		}
	return ans;
}






// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, bool hasAnswer, double p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	TheFrog *obj;
	double answer;
	obj = new TheFrog();
	clock_t startTime = clock();
	answer = obj->getMinimum(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == answer && fabs(p3 - answer) <= 1e-9 * max(1.0, fabs(p3));
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
	vector <int> p1;
	vector <int> p2;
	double p3;
	
	{
	// ----- test 0 -----
	p0 = 16;
	int t1[] = {2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {7};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 7.0;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 25;
	int t1[] = {11,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {21,7};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 10.5;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 100;
	int t1[] = {0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {100};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 100.0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 100;
	int t1[] = {0,50};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {50,100};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 50.0;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 30000;
	int t1[] = {17,25281,5775,2825,14040};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {55,26000,5791,3150,14092};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 787.8787878787879;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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
