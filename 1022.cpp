#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

static struct Book {
	string id, title, author, publisher, key, year;
};

//int main() {
//	int n, m; cin >> n;
//	Book book;
//	unordered_map<string, priority_queue<string, vector<string>, greater<string>>> m_title;
//	unordered_map<string, priority_queue<string, vector<string>, greater<string>>> m_author;
//	unordered_map<string, priority_queue<string, vector<string>, greater<string>>> m_key;
//	unordered_map<string, priority_queue<string, vector<string>, greater<string>>> m_publisher;
//	unordered_map<string, priority_queue<string, vector<string>, greater<string>>> m_year;
//	for (int i = 0; i < n; ++i) {
//		cin >> book.id; cin.get();
//		getline(cin, book.title);
//		getline(cin, book.author);
//		do {
//			cin >> book.key;
//			m_key[book.key].push(book.id);
//		} while (cin.get() != '\n');
//		getline(cin, book.publisher);
//		getline(cin, book.year);
//
//		m_title[book.title].push(book.id);
//		m_author[book.author].push(book.id);
//		m_publisher[book.publisher].push(book.id);
//		m_year[book.year].push(book.id);
//	}
//	cin >> m; cin.get();
//	string query, str;
//	while (m--) {
//		getline(cin, query);
//		cout << query << endl;
//		str = query.substr(3);
//		priority_queue<string, vector<string>, greater<string>> tmp;
//		switch (query[0]) {
//		case '1':
//			if(m_title.count(str) > 0)tmp = m_title[str];
//			break;
//		case '2':
//			if (m_author.count(str) > 0)tmp = m_author[str];
//			break;
//		case '3':
//			if (m_key.count(str) > 0)tmp = m_key[str];
//			break;
//		case '4':
//			if (m_publisher.count(str) > 0)tmp = m_publisher[str];
//			break;
//		case '5':
//			if (m_year.count(str) > 0)tmp = m_year[str];
//			break;
//		}
//		if (tmp.empty()) {
//			cout << "Not Found" << endl;
//		}
//		else {
//			while (!tmp.empty()) {
//				cout << tmp.top() << endl;
//				tmp.pop();
//			}
//		}
//	}
//}