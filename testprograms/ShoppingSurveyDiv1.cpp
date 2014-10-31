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
	
class ShoppingSurveyDiv1 {
public:
	int minValue(int N, int K, vector <int> s);
};

int ShoppingSurveyDiv1::minValue(int N, int K, vector <int> s) 
{
	int lo, hi, ans;	
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	
	lo = 0, hi = N, ans = -1;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		
		vector<int> a; a.clear();
		for (int i = 1; i <= mid; i ++)
			a.push_back(s.size());
		
		for (int i = 1; i <= N - mid; i ++)
			a.push_back(K - 1);
		
		int flag = 1;
		for (int i = 0; i < s.size(); i ++)
		{
			int cur = s[i];
			sort(a.begin(), a.end());
			reverse(a.begin(), a.end());
			for (int i = 0; i < cur; i ++)
				if (a[i] == 0) 
				{
					flag = 0; break;
				}
				else a[i] --;
		}
		
		if (! flag)
			lo = mid + 1;
		else ans = mid, hi = mid - 1;
	}
	return ans;
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	ShoppingSurveyDiv1 *obj;
	int answer;
	obj = new ShoppingSurveyDiv1();
	clock_t startTime = clock();
	answer = obj->minValue(p0, p1, p2);
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
	int p1;
	vector <int> p2;
	int p3;
	
	{
	// ----- test 0 -----
	p0 = 10;
	p1 = 2;
	int t2[] = {1,2,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 0;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 5;
	p1 = 2;
	int t2[] = {1,2,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 4;
	p1 = 4;
	int t2[] = {4,4,4,2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 2;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 20;
	p1 = 3;
	int t2[] = {1,10,3,4,8,15,3,16,18,2,7,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 10;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 4;
	p1 = 2;
	int t2[] = {1,2,1,1,3,1,2,2,1,2,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 2;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 2;
	p1 = 3;
	int t2[] = {1,1,1,2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1;
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