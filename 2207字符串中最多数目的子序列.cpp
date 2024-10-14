#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>

using namespace std;

/*
����һ���±�� 0 ��ʼ���ַ��� text ����һ���±�� 0 ��ʼ�ҳ���Ϊ 2 ���ַ��� pattern ��
���߶�ֻ����СдӢ����ĸ��

������� text ������λ�ò��� һ�� �ַ������������ַ������� pattern[0] ���� pattern[1] ��
ע�⣬����ַ����Բ����� text ��ͷ���߽�β��λ�á�

���㷵�ز���һ���ַ���text �����������ٸ����� pattern �� ������ ��

������ ָ���ǽ�һ���ַ���ɾ�����ɸ��ַ���Ҳ���Բ�ɾ������ʣ���ַ�����ԭ��˳��õ����ַ�����
*/

// ����ע�⵽��pattern[0]���뵽�����,��pattern[1]���뵽���Ҳ�,
// ��ʱ�õ��ĵ���pattern����������ࡣ
long long maximumSubsequenceCount(string text, string pattern) {
    char x = pattern[0], y = pattern[1];
    int cntx = 0, cnty = 0;
    long long res = 0;
    for (char ch : text) {
        // ע�⵽û�е����ж�x=y,����Ҫ�ȸ��´�,�ٸ���cntx
        if (ch == y) {
            res += cntx;
            cnty++;
        }
        if (ch == x) {
            cntx++;
        }
    }
    return res + max(cntx, cnty);
}