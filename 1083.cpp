#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static struct Record {
    string name, id;
    uint16_t score;
};

static uint16_t low, high;

static bool cmp(const Record& r1, const Record& r2) {
    if(r1.score >= low && r1.score <= high &&
        r2.score >= low && r2.score <= high) {
        return r1.score > r2.score;
    } else if(r1.score >= low && r1.score <= high) {
        return true;
    } else {
        return false;
    }
}

//int main() {
//    int n; cin >> n;
//    vector<Record>records(n);
//    for(auto & r : records) {
//        cin >> r.name >> r.id >> r.score;
//    }
//    cin >> low >> high;
//    sort(records.begin(), records.end(), cmp);
//    if(records[0].score < low || records[0].score > high) {
//        cout << "NONE" << endl;
//    } else {
//        for(auto & r : records) {
//            if(r.score < low || r.score > high)break;
//            cout << r.name << ' '
//                << r.id << endl;
//        }
//    }
//}