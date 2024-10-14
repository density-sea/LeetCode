#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
#include <unordered_set>

using namespace std;

/*
����һ�����ַ� 'a'��'b'��'c' ��ɵ��ַ��� s ��һ���Ǹ����� k ��
ÿ���ӣ������ѡ��ȡ�� s ����� ���� ���Ҳ� ���Ǹ��ַ���
�����ȡ��ÿ���ַ� ���� k ����������Ҫ�� ���� ������������޷�ȡ�����򷵻� - 1 ��
*/

// �������ڵ�˼��
// ��˼ά,��������Ҳ�������k���ַ��ȼ������м��������ַ���������a-k,b-k,c-k������������
// ��һ�����Կ��Ǽ�¼�ַ�����ÿ���ַ����ֵ��ַ���,�����ڵı�ʾ�Ƴ����ַ������ͳ���Ƴ��ַ�������������
int takeCharacters(string s, int k) {
    int n = s.size();
    vector<int> map(3);
    // int map[3];
    // ͳ��a,b,cÿ���ַ����ֵĴ���
    for (auto ch : s) {
        map[ch - 'a']++;
    }
    if (map[0] < k || map[1] < k || map[2] < k) {
        return -1;
    }
    int mx = 0;
    int left = 0, right = 0;
    while (right < n) {
        map[s[right] - 'a']--;
        // ��������
        while (map[s[right] - 'a'] < k) {
            map[s[left] - 'a']++;
            left++;
        }
        mx = max(mx, right - left + 1);
        // ���󴰿�
        right++;
    }
    return n - mx;
}