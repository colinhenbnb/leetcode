/*************************************************************************
	> File Name: two_sum.cpp
	> Author: heshaofu
	> Mail: 15321529030@163.com
	> Created Time: 2017年11月28日 星期二 22时02分07秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<hash_map>
using namespace std;
using namespace __gnu_cxx;
class Solution {
public:
    vector<int> twosum(vector<int> nums, int target) {
        vector<int> rst;
        if (nums.size() < 2) {
            return rst;
        }
        hash_map<int,int> map; 
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                rst.push_back(map[target-nums[i]]);
                rst.push_back(i);
                return rst;
            }
            map[nums[i]] = i;
        }
    }
};

template <class T>
void print_vector(vector<T> &a, int len)
{
    for (int i = 0; i<len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(int args, char * argv[])
{
    vector<int> a;
    for (int i = 1 ; i < args - 1 ; i++) {
        a.push_back(atoi(argv[i]));
    }
    
    int target = atoi(argv[args-1]);

    print_vector(a, a.size());
    Solution s;

    vector<int> rst = s.twosum(a, target);
    print_vector(rst, rst.size());
}
