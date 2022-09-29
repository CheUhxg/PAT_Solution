#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    bool visited;
    int id, totle, perfect;
    vector<int>problem;
    Student(const vector<int>& problem)
        : visited(false), id(0), totle(0), perfect(0), problem(problem) {}
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
        students[id].problem[prob] = max(score, students[id].problem[prob]);
        if(score != -1)students[id].visited = true;
        else if(students[id].problem[prob] == -1) students[id].problem[prob] = -2;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= k; ++j) {
            if(students[i].problem[j] != -1 && students[i].problem[j] != -2)
                students[i].totle += students[i].problem[j];
            if(students[i].problem[j] == full_score[j])
                ++students[i].perfect;
        }
    }
    sort(students.begin() + 1, students.end(), cmp);
    for(int i = 1; i <= n; ++i) {
        if(students[i].visited) {
            if(i > 0 && students[i].totle < students[i-1].totle)rk = i;
            printf("%d %05d %d", rk, students[i].id, students[i].totle);
            for(int j = 1; j <= k; ++j) {
                if(students[i].problem[j] != -1 && students[i].problem[j] != -2) {
                    printf(" %d", students[i].problem[j]);
                }
                else if(students[i].problem[j] == -1){
                    printf(" -");
                }
                else {
                    printf(" 0");
                }
            }
            printf("\n");
        }
    }
}