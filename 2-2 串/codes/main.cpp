#include "mystring.h"
using namespace std;

int main()
{
	String T{ "csahiqwwifjqnfskcvqen" };
	String P{ "wwif" };
	cout << BruteForceMatch(T, P) << endl;
	cout << KMP_Match(T, P) << endl;
	cout << Horspool(T, P) << endl;
	cout << BM_Match(T, P) << endl;
}
