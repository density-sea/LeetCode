#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>

using namespace std;

/*
����һ������Ϊ4���������� cards ������ 4 �ſ�Ƭ��ÿ�ſ�Ƭ�϶�����һ����Χ��[1, 9] �����֡�
��Ӧ��ʹ�������['+', '-', '*', '/'] ������ '(' �� ')' 
����Щ��Ƭ�ϵ��������г���ѧ���ʽ���Ի��ֵ24��

�����������¹��� :
��������� '/' ��ʾʵ������������������������
���磬 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12 ��
ÿ�����㶼����������֮�䡣�ر��ǣ�����ʹ�� �� - �� ��ΪһԪ�������
���磬��� cards = [1, 1, 1, 1] ������ʽ �� - 1 - 1 - 1 - 1�� �� ������ �ġ�
�㲻�ܰ����ִ���һ��
���磬��� cards = [1, 2, 1, 2] ������ʽ ��12 + 12�� ��Ч��
������Եõ������ı��ʽ���������Ϊ 24 ���򷵻� true �����򷵻� false ��
*/

const double eps = 1e-6;
vector<double> cards;
const vector<char> operators = { '+', '-','*','/' };

bool dfs(vector<double>& cards) {
    int n = cards.size();
    if (n == 1) {
        return abs(cards[0] - 24) < eps;
    }

    // ������ѡ��������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;

            // ���ɳ�ȥ i �� j ��������
            vector<double> newCards;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    newCards.push_back(cards[k]);
                }
            }

            for (int k = 0; k < 4; k++) {
                if ((k == 0 || k == 2) && i > j) {
                    // ���ڼӷ��ͳ˷���������������˳��
                    continue;
                }
                switch (operators[k]) {
                case '+':
                    newCards.push_back(cards[i] + cards[j]);
                    break;
                case '-':
                    newCards.push_back(cards[i] - cards[j]);
                    break;
                case '*':
                    newCards.push_back(cards[i] * cards[j]);
                    break;
                case '/':
                    if (cards[j] == 0)
                        continue;
                    newCards.push_back(cards[i] / cards[j]);
                    break;
                }
                if (dfs(newCards))
                    return true;
                newCards.pop_back();
            }
        }
    }
    return false;
}

bool judgePoint24(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cards.push_back(nums[i] * 1.0);
    }
    return dfs(cards);
}

//int main(){
//    vector<int> nums = {4,1,8,7};
//    cout << judgePoint24(nums) << endl;
//    return 0;
//}