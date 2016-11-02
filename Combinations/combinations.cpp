/*************************************************************************
    > File Name: combinations.cpp
    > Author:heshaofu 
    > Mail: heshaofu@baidu.com 
    > Created Time: 三 11/ 2 19:45:45 2016
 ************************************************************************/
#include <iostream>
#include <String>
#include <Vector>
using namespace std;
class Solution {
    public:
    vector< vector<int> > combine(int n, int k) {
        vector< vector<int> > rtn;
        //resolve two problem (n-1, k-1) && (n-1, k)
        //endian
        if (n == k) {
            vector<int> tmp; 
            for (int i = 1; i <= n; i++) {
                tmp.push_back(i);
            }
            rtn.push_back(tmp);
            return rtn;
        } else if (n < k) {
            //exception
            return rtn;
        }

        if (k == 1) {
            for (int i=1; i <= n; i++) {
                vector<int> tmp;
                tmp.push_back(i);
                rtn.push_back(tmp);
            }
            return rtn;
        }
        
        //sub solution
        vector< vector<int> > left_rtn = combine(n-1, k); // no n
        for(int i =0; i<left_rtn.size(); i++) {
            rtn.push_back(left_rtn[i]);
        }

        vector< vector<int> > right_rtn = combine(n-1, k-1);// need add n
        for (int i=0; i<right_rtn.size(); i++) {
            right_rtn[i].push_back(n);
            rtn.push_back(right_rtn[i]);
        }
        return rtn;
    }
    void show_vector(vector<vector<int> > src)
    {
        for (int i=0; i<src.size(); i++) {
            for (int j=0; j < src[i].size(); j++) {
                cout << src[i][j] << ",";
            }
            cout <<endl;
        }
    }
};
int main(void)
{
    cout<< "hello world" << endl;
    class Solution s;
    int n, k;
    cout << "enter test num: " << endl;
    cin >>n >> k; 
    vector< vector<int> > rtn = s.combine(n,k);
    s.show_vector(rtn);
}

