#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int id, totle, perfect;
    vector<int>problem;
    Student(const vector<int>& problem)
        : id(0), totle(0), perfect(0), problem(problem) {}
};

bool cmp(const Student& s1, const Student& s2) {
    if(s1.totle == s2.totle) {
        if(s1.perfect == s2.perfect) return s1.id < s2.id;
        return s1.perfect > s2.perfect;
    }
    return s1.totle > s2.totle;
}

int main() {
    int n, k, m, id, prob, score, rk = 1; cin >> n >> k >> m;
    vector<int> full_score(k + 1);
    for(int i = 1; i <= k; ++i) {
        cin >> full_score[i];
    }
    vector<Student> students(n + 1, Student(vector<int>(k + 1, -1)));
    while(m--) {
        cin >> id >> prob >> score;
        students[id].id = id;
        if(score == -1 && students[id].problem[prob] == -1) {
            students[id].problem[prob] = 0;
        }
        else if(students[id].problem[prob] < score) {
            if(students[id].problem[prob] == -1)
                students[id].totle += score;
            else 
                students[id].totle += score - students[id].problem[prob];
            students[id].problem[prob] = score;
            if(score == full_score[prob]) {
                ++students[id].perfect;
            }
        }
    }
    sort(students.begin(), students.end(), cmp);
    for(int i = 0; i < n; ++i) {
        if(students[i].totle == 0)break;
        if(i > 0 && students[i].totle < students[i-1].totle)rk = i + 1;
        printf("%d %05d %d", rk, students[i].id, students[i].totle);
        for(int j = 1; j <= k; ++j) {
            if(students[i].problem[j] >= 0) {
                printf(" %d", students[i].problem[j]);
            }
            else {
                printf(" -");
            }
        }
        printf("\n");
    }
}