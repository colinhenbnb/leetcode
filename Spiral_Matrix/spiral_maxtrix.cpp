/*************************************************************************
    > File Name: spiral_maxtrix.cpp
    > Author:heshaofu 
    > Mail: heshaofu@baidu.com 
    > Created Time: 四 11/ 3 19:21:16 2016
 ************************************************************************/
#include <iostream>
#include <String>
#include <Vector>
using namespace std;
class maxtrix_solution {
public:
    void sub_spiral(vector<vector<int> > &maxtrix, vector<int> &dst, int rt, int ct, int re, int ce) {
        if ((rt > re) || (ct > ce)) {
            return;
        }

        if (rt==re && ct==ce) {
            dst.push_back(maxtrix[rt][ct]);
            return;
        }
        //r = 1 or c = 1
        if (re == rt) {
            for (int i=ct; i <= ce; i++ ) {
                dst.push_back(maxtrix[rt][i]);
            }
            return;
        }
        if (ct == ce) {
            for (int i=rt; i <= re; i++ ) {
                dst.push_back(maxtrix[i][ce]);
            }
            return;
        }

        //turn right
        for (int i=ct; i <= ce; i++ ) {
            dst.push_back(maxtrix[rt][i]);
        }

        //trun down
        for (int i=rt +1; i <= re; i++ ) {
            dst.push_back(maxtrix[i][ce]);
        }

        //trun left 
        for (int i=ce-1; i >= ct; i-- ) {
            dst.push_back(maxtrix[re][i]);
        }

        //trun up 
        for (int i=re-1; i > rt; i-- ) {
            dst.push_back(maxtrix[i][ct]);
        }

        if ((re-rt < 2) || (ce -ct < 2)) {
            return;
        } else {
            sub_spiral(maxtrix, dst, rt+1, ct+1, re-1, ce-1);
        }
    }
    vector<int> spiralOrder(vector<vector<int> > &maxtrix) {
        vector<int> dst;
        if (maxtrix.size() == 0) {
            return dst;
        }

        if (maxtrix[0].size() == 0) {
            return dst;
        }
        
        sub_spiral(maxtrix, dst, 0, 0, maxtrix.size()-1 , maxtrix[0].size()-1);
        return dst;
    }
};

vector<vector<int> > creat_matrix(int n, int m) 
{
    vector<vector<int> > dst;
    int sul = 1;
    for(int i = 0; i< n; i++) {
        vector<int> tmp;
        for (int j = 0; j<m; j++) {
            tmp.push_back(sul++);
        }
        dst.push_back(tmp);
    }
    return dst;
}
void show_matrix(vector<vector<int> > dst) 
{
    for(int i = 0; i< dst.size(); i++) {
        for (int j = 0; j< dst[i].size(); j++) {
            cout << dst[i][j] << ",";
        }
        cout << endl;
    }

}

int main(void)
{
    int n, m;
    cout << "enter n * m" << endl;
    cin >> n >> m;
    vector<vector<int> > dst = creat_matrix(n, m);
    show_matrix(dst);
    class maxtrix_solution slt;

    vector<int> result = slt.spiralOrder(dst);
    for (int i =0; i<result.size(); i++) {
        cout << result[i] << ",";
    }
    cout <<endl;
}
