#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>

using namespace std;
/*
����һ���ַ��� s ���������� x �� y �������ִ���������ֲ�������Ρ�
ɾ�����ַ��� "ab" ���õ� x �֡�
�ȷ�˵���� "cabxbae" ɾ�� ab ���õ� "cxbae" ��
ɾ�����ַ���"ba" ���õ� y �֡�
�ȷ�˵���� "cabxbae" ɾ�� ba ���õ� "cabxe" ��
�뷵�ض� s �ַ���ִ������������ɴ��ܵõ������÷֡�
*/
int maximumGain(string s, int x, int y) {
    int a_cnt = 0, b_cnt = 0;
    int right = 0;
    int n = s.size();
    int res = 0;
    // ͳ�Ƶ�ǰ��
    int cnt = 0;
    while (right < n) {
        char ch = s[right++];
        if (ch == 'b') b_cnt++;
        if (ch == 'a') a_cnt++;
        // ͳ�Ƶ�ǰ�ܹ����ɵ�x,y�нϴ�ֵ���ַ����и���cnt
        if ((ch == 'b' && a_cnt > 0 && x > y) || (ch == 'a' && b_cnt > 0 && x <= y)) {
            cnt++;
            a_cnt--;
            b_cnt--;
        }
        // ��ǰ���н������ǵ���s��ĩβ
        if ((ch != 'a' && ch != 'b') || (right == n)) {
            int mn = min(b_cnt, a_cnt);
            res += y >= x ? cnt * y + mn * x : cnt * x + mn * y;
            a_cnt = 0;
            b_cnt = 0;
            cnt = 0;
        }
    }
    return res;
}