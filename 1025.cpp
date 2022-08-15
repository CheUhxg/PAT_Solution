#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
struct TestData {
    string registration_number;
    int score;
    int location_number;
    int local_rank;    
};
bool cmp(const TestData& data1, const TestData& data2) {
    if(data1.score != data2.score)return data1.score > data2.score;
    else return data1.registration_number < data2.registration_number;
}
int main() {
    int n, k, last_rank;
    cin >> n;
    vector<TestData> all_datas;
    for(int i = 1; i <= n; ++i) {
        cin >> k;
        vector<TestData> datas(k);
        for(int j = 0; j < k; ++j) {
            cin >> datas[j].registration_number 
                >> datas[j].score;
            datas[j].location_number = i;
        }
        sort(datas.begin(), datas.end(), cmp);
        last_rank = 1;
        for(int j = 0; j < k; ++j) {
            if (j != 0 && datas[j].score != datas[j - 1].score) last_rank = j + 1;
            datas[j].local_rank = last_rank;
        }
        all_datas.insert(all_datas.end(), datas.begin(), datas.end());
    }
    sort(all_datas.begin(), all_datas.end(), cmp);
    last_rank = 1;
    cout << all_datas.size() << endl;
    for(size_t i = 0; i < all_datas.size(); ++i) {
        if (i != 0 && all_datas[i].score != all_datas[i - 1].score) last_rank = i + 1;
        cout << all_datas[i].registration_number << " "
            << last_rank << " "
            << all_datas[i].location_number << " "
            << all_datas[i].local_rank << endl;
    }
}