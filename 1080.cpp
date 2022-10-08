#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct List {
    int cnt = 0;
    vector<int>list;
};

struct Grade {
    int ge = 0, sum = 0, id = 0, rk = 0;
    vector<int>list;
};

bool cmp(const Grade& g1, const Grade& g2) {
    if(g1.sum == g2.sum) {
        return g1.ge > g2.ge;
    }
    return g1.sum > g2.sum;
}

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<Grade>student(n);
    vector<List>school(m);
    for(int i = 0; i < m; ++i) {
        cin >> school[i].cnt;
    }
    for(int i = 0; i < n; ++i) {
        student[i].id = i;
        student[i].list.resize(k);
        cin >> student[i].ge >> student[i].sum;
        student[i].sum += student[i].ge;
        for(int j = 0; j < k; ++j) {
            cin >> student[i].list[j];
        }
    }
    sort(student.begin(), student.end(), cmp);
    for(int i = 1; i < n; ++i) {
        if(student[i].sum == student[i - 1].sum &&
            student[i].ge == student[i - 1].ge) {
            student[i].rk = student[i - 1].rk;
        } else {
            student[i].rk = student[i - 1].rk + 1;
        }
    }
    vector<int>last(m, -1);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < k; ++j) {
            int school_id = student[i].list[j];
            if(school[school_id].cnt > 0 ||
                last[school_id] == student[i].rk) {
                --school[school_id].cnt;
                school[school_id].list.push_back(student[i].id);
                last[school_id] = student[i].rk;
                break;
            }
        }
    }
    for(int i = 0; i < m; ++i) {
        if(school[i].list.size() > 0) {
            sort(school[i].list.begin(), school[i].list.end());
            cout << school[i].list[0];
            for(int j = 1; j < school[i].list.size(); ++j) {
                cout << ' ' << school[i].list[j];
            }
        }
        cout << endl;
    }
}
