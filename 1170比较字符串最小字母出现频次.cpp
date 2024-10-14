#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>

using namespace std;

/*
����һ������ f(s)��ͳ�� s  �У����ֵ���Ƚϣ���С��ĸ�ĳ���Ƶ�� ������ s ��һ���ǿ��ַ�����

���磬�� s = "dcce"����ô f(s) = 2����Ϊ�ֵ�����С��ĸ�� "c"���������� 2 �Ρ�

���ڣ����������ַ����������� queries �ʹʻ�� words ������ÿ�β�ѯ queries[i] ��
��ͳ�� words ������ f(queries[i]) < f(W) �� �ʵ���Ŀ ��W ��ʾ�ʻ�� words �е�ÿ���ʡ�

���㷵��һ���������� answer ��Ϊ�𰸣�����ÿ�� answer[i] �ǵ� i �β�ѯ�Ľ����
*/

vector<int> numSmallerByFrequency(vector<string>& queries,
    vector<string>& words) {
    // ͳ��ĳ���ַ�������С��ĸ���ֵ�Ƶ��
    auto frequency = [&](const string& s) -> int {
        int cnt = 0;
        char pre = 'z';
        for (auto ch : s) {
            if (ch < pre) {
                cnt = 1;
                pre = ch;
            }
            else if (ch == pre) {
                cnt++;
            }
        }
        return cnt;
        };

    int n = words.size();
    vector<int> words_frequency;
    for (auto word : words) {
        words_frequency.push_back(frequency(word));
    }

    // ����Ƶ�γ��ִ�����С�����queries��������
    sort(words_frequency.begin(), words_frequency.end());

    int m = queries.size();
    vector<int> res;

    for (auto query : queries) {
        // �ҵ���һ������Ƶ�δ���target��words���ַ�����λ��
        int left = -1, right = n;
        int target = frequency(query);
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (words_frequency[mid] > target) {
                right = mid;
            }
            else
                left = mid;
        }
        res.push_back(n - right);
    }

    return res;
}