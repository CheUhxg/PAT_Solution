#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Team {
	string name, passwd;
};

int main() {
	bool mod;
	vector<Team> res;
	string name, passwd;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> name >> passwd;
		mod = false;
		for (int j = 0; j < passwd.size(); ++j) {
			switch (passwd[j]) {
			case '1':
				mod = true;
				passwd[j] = '@';
				break;
			case 'l':
				mod = true;
				passwd[j] = 'L';
				break;
			case '0':
				mod = true;
				passwd[j] = '%';
				break;
			case 'O':
				mod = true;
				passwd[j] = 'o';
				break;
			default:
				break;
			}
		}
		if (mod) res.push_back({ name, passwd });
	}
	if (res.empty()) {
		if (n == 1)
			cout << "There is 1 account and no account is modified" << endl;
		else
			cout << "There are " << n
			<< " accounts and no account is modified" << endl;
	}
	else {
		cout << res.size() << endl;
		for (const Team& t : res) {
			cout << t.name << ' ' << t.passwd << endl;
		}
	}
}