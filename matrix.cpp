/*
 * @Author: USTB.mophy1109
 * @Date: 2018-04-28 16:16:01
 * @Last Modified by: USTB.mophy1109
 * @Last Modified time: 2018-04-28 16:28:13
 *
 * 计蒜客 -- 矩阵翻转
 */

#include <iostream>

using namespace std;
int main() {
	int M, N, T;
	cin >> M >> N >> T;
	int in[M][N], out[M][N];
	// cout << "请输入矩阵" << endl;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> in[i][j];
		}
	}

	if (T == 1) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				out[M - i - 1][j] = in[i][j];
			}
		}
	} else {

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				out[i][N - j - 1] = in[i][j];
			}
		}
	}

	// output
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << out[i][j] << " ";
		}
		cout << endl;
	}
	return 1;
}
