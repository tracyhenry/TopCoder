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
	
class HappyLetterDiv1 {
public:
	string getHappyLetters(string letters);
};

string HappyLetterDiv1::getHappyLetters(string letters) 
{
	map<char, int> M;
	M.clear();
	for (int i = 0; i < letters.size(); i ++)
		M[letters[i]] ++;
	
	vector<pair<int, char> > l; l.clear();
	for (map<char, int>::iterator i = M.begin(); i != M.end(); i ++)
		l.push_back(make_pair(i->second, i->first));
	
	sort(l.begin(), l.end());
	
	set<char> ans;
	for (int k = 0; k < l.size(); k ++)
	{
		int curChar = l[k].second;
		int curNum = l[k].first;
		
		priority_queue<int> a;
		for (int i = 0; i < l.size(); i ++)
			if (i - k)
				a.push(l[i].first);
		
		for ( ; a.size() > 1; )
		{
			int x = a.top(); a.pop();
			int y = a.top(); a.pop();
			x -= y;
			a.push(x);
		}
		if (a.size() == 1 && a.top() < curNum)
			ans.insert(curChar);
	}
	string s = "";
	for (set<char>::iterator it = ans.begin(); it != ans.end(); it ++)
		s += (*it);
	return s;
}
	


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	HappyLetterDiv1 *obj;
	string answer;
	obj = new HappyLetterDiv1();
	clock_t startTime = clock();
	answer = obj->getHappyLetters(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	string p0;
	string p1;
	
	{
	// ----- test 0 -----
	p0 = "aabbacccc";
	p1 = "abc";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "aaaaaaaccdd";
	p1 = "a";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "ddabccadb";
	p1 = "abcd";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "aaabbb";
	p1 = "";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "rdokcogscosn";
	p1 = "cos";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
