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
	
class BuildingTowersEasy {
public:
	int maxHeight(int N, vector <int> x, vector <int> t);
};

int a[100];
int BuildingTowersEasy::maxHeight(int N, vector <int> x, vector <int> t) 
{
	int n = x.size();
	if (n == 0)
		return N - 1;
	for (int i = n - 2; i >= 0; i --)
		if (t[i] > t[i + 1])
			t[i] = min(t[i], t[i + 1] + x[i + 1] - x[i]);
			
	int ans = 0;
	for (int i = 0; i < n; i ++)
	{
		int X = t[i] - (i ? a[i - 1] : 0);
		int Y = x[i] - (i ? x[i - 1] : 1);
		if (X == Y)
			a[i] = t[i];
		else if (X > Y)
			a[i] = Y + (i ? a[i - 1] : 0);
		else if (X < Y)
		{
			a[i] = t[i];
			ans = max(ans, X + (Y - X) / 2 + (i ? a[i - 1] : 0));
		}
		ans = max(ans, a[i]);
	}
	ans = max(ans, a[n - 1] + N - x[n - 1]);
	return ans;
}



// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, bool hasAnswer, int p3) {
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
	BuildingTowersEasy *obj;
	int answer;
	obj = new BuildingTowersEasy();
	clock_t startTime = clock();
	answer = obj->maxHeight(p0, p1, p2);
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
		res = answer == p3;
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
	int p3;
	
	{
	// ----- test 0 -----
	p0 = 10;
	int t1[] = {3,8};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 100000;
	p1.clear() /*{}*/;
	p2.clear() /*{}*/;
	p3 = 99999;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 2718;
	int t1[] = {1,30,400,1300,2500};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {100000,100000,100000,100000,100000};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 2717;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 20;
	int t1[] = {4,7,13,15,18};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {3,8,1,17,16};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 8;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 447;
	int t1[] = {32,35,55,60,61,88,91,97,128,151,181,186,192,196,198,237,259,268,291,314,341,367,389,390,391,428,435};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {81,221,172,641,25,953,330,141,123,440,692,394,200,649,78,726,50,810,501,4,216,407,2,172,0,29,14};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 120;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 97638;
	int t1[] = {8,1749,4550,5388,6752,7089,9737,14891,16671,16821,17691,19753,24589,25348,30114,32213,34376,36467,37699,41490,44784,44893,57316,58275,58567,61122,61489,63195,64776,65905,68788,69908,72853,78152,78784,82779,84488,86277,88611,92793,93214,97583};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {16610,6,497,14,42892,31,79,1203,518,31147,597,7846,1396,8309,12,14,1148,433,23693,13,1939,244,19,46,27,611,412,10,27023,19141,34,15667,588,10,229,83,390,14,38441,16021,4,39386};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 6343;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
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
