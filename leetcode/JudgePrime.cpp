/*
 * @Author: USTB.mophy1109
 * @Date: 2018-04-28 16:33:21
 * @Last Modified by: USTB.mophy1109
 * @Last Modified time: 2018-04-28 16:41:03
 *
 * 计蒜客 -- 判断 1000 以内的素数
 */

/* 1000 ^ 1/2 ≈ 31.6 < 32
   prime littler than 32 are N = {2,3,5,7,11,13,17,19,23,29,31};
   so only need to calculate all the M mod N: if any one is 0, it means "NO"
*/
#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	int t[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
	if (N == 2 || N == 3) {
		cout << "YES" << endl;
		return 1;
	}

	if (N % 6 == 1 || N % 6 == 5) {
		for (int i = 0; i < 12; i++) {
			if (N % t[i] == 0) {
				cout << "NO" << endl;
				return 1;
			}
		}
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 1;
}