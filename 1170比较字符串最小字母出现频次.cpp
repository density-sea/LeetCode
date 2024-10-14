#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>

using namespace std;

/*
定义一个函数 f(s)，统计 s  中（按字典序比较）最小字母的出现频次 ，其中 s 是一个非空字符串。

例如，若 s = "dcce"，那么 f(s) = 2，因为字典序最小字母是 "c"，它出现了 2 次。

现在，给你两个字符串数组待查表 queries 和词汇表 words 。对于每次查询 queries[i] ，
需统计 words 中满足 f(queries[i]) < f(W) 的 词的数目 ，W 表示词汇表 words 中的每个词。

请你返回一个整数数组 answer 作为答案，其中每个 answer[i] 是第 i 次查询的结果。
*/

vector<int> numSmallerByFrequency(vector<string>& queries,
    vector<string>& words) {
    // 统计某个字符串中最小字母出现的频次
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

    // 按照频次出现次数从小到大对queries数组排序
    sort(words_frequency.begin(), words_frequency.end());

    int m = queries.size();
    vector<int> res;

    for (auto query : queries) {
        // 找到第一个出现频次大于target的words中字符串的位置
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