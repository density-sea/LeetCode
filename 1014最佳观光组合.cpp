#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>

using namespace std;

/*
����һ������������ values������ values[i] ��ʾ�� i ���۹⾰������֣�
������������ i �� j ֮��� ���� Ϊ j - i��
һ�Ծ��㣨i < j����ɵĹ۹���ϵĵ÷�Ϊ values[i] + values[j] + i - j ��
Ҳ���Ǿ��������֮�� ��ȥ ��������֮��ľ��롣
����һ�Թ۹⾰����ȡ�õ���߷֡�
ʾ�� 1��
���룺values = [8, 1, 5, 2, 6]
�����11
���ͣ�i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
ʾ�� 2��
���룺values = [1, 2]
�����2
*/

// ���÷ָ�дΪ(values[i]+i)+(values[j]-j)����ʽ
int maxScoreSightseeingPair(vector<int>& values) {
	int n = values.size();
	int mx = values[0] + 0;
	int res = 0;
	for (int j = 1; j < n; j++) {
		res = max(res, mx + values[j] - j);
		mx = max(mx, values[j] + j);
	}
	return res;
}

//int main() {
//	// vector<int> values = { 8,1,5,2,6 };
//	vector<int> values = { 1,2 };
//	cout << maxScoreSightseeingPair(values);
//
//	return 0;
//}
