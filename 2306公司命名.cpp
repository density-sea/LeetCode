#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <unordered_set>

using namespace std;

/*
����һ���ַ������� ideas ��ʾ�ڹ�˾����������ʹ�õ������б���˾�����������£�

�� ideas ��ѡ�� 2 �� ��ͬ ���֣���Ϊ ideaA �� ideaB ��
���� ideaA �� ideaB ������ĸ��
����õ������������� �� ���� ideas �У���ô ideaA ideaB������ ideaA �� ideaB ���м���һ���ո�ָ���
��һ����Ч�Ĺ�˾���֡�
���򣬲���һ����Ч�����֡�
���� ��ͬ ����Ч�Ĺ�˾���ֵ���Ŀ��
*/

long long distinctNames(vector<string>& ideas) {
	unordered_set<string> groups[26];
	for (auto& s : ideas) {
		groups[s[0] - 'a'].insert(s.substr(1));
	}
	long long res = 0;
	for (int a = 1; a < 26; a++) {
		for (int b = 0; b < a; b++) {
			int m = 0;
			for (auto& s : groups[a]) {
				m += groups[b].count(s);
			}
			res += (long long)(groups[a].size() - m) * (groups[b].size() - m) * 2;
		}
	}
	return res;
}