#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>

using namespace std;

/*
����һ��������ɫ����ɫ����ɫ���� n ��Ԫ�ص����� nums ��
ԭ�� �����ǽ�������ʹ����ͬ��ɫ��Ԫ�����ڣ������պ�ɫ����ɫ����ɫ˳�����С�
����ʹ������ 0�� 1 �� 2 �ֱ��ʾ��ɫ����ɫ����ɫ��
�����ڲ�ʹ�ÿ����õ� sort ����������½��������⡣

ʾ�� 1��
���룺nums = [2, 0, 2, 1, 1, 0]
�����[0, 0, 1, 1, 2, 2]
ʾ�� 2��
���룺nums = [2, 0, 1]
�����[0, 1, 2]
*/

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int zero = 0, two = n - 1;
    int i = 0;
    // [0, zero] = 0
    // (zero, i) = 1
    // [two, n - 1] = 2
    while (i <= two) {
        if (nums[i] == 0) {
            swap(nums[zero++], nums[i]);
            i++;
        }
        else if (nums[i] == 1) {
            i++;
        }
        else {
            swap(nums[i], nums[two--]);
        }
    }
}