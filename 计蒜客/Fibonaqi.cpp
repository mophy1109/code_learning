/*
 * @Author: USTB.mophy1109
 * @Date: 2018-04-28 16:40:15
 * @Last Modified by:   USTB.mophy1109
 * @Last Modified time: 2018-04-28 16:40:15
 *
 * 计蒜客 -- 斐波那契数列
 */
#include <iostream>

using namespace std;
int Fib(int N) {
	if (N == 0) {
		return 0;
	}
	if (N == 1) {
		return 1;
	}
	return Fib(N - 1) + Fib(N - 2);
}
int main() {
	int N;
	cin >> N;
	cout << Fib(N) << endl;
	return 1;
}
