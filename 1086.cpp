#include <iostream>
#include <vector>
#include <string>

using namespace std;

static struct Node {
    int left, right;
};

static int n, tree_root, times;
static string pattern;

static void dfs(int root, vector<Node>& tree) {
    int index;

    if(--times == 0)return;
    cin >> pattern;
    if(pattern == "Push") {
        cin >> index;
        tree[root].left = index;
        dfs(index, tree);
    }
    if(--times == 0)return;
    cin >> pattern;
    if(pattern == "Push") {
        cin >> index;
        tree[root].right = index;
        dfs(index, tree);
    }
}

static void show(int root, const vector<Node>& tree) {
    if(tree[root].left > 0) show(tree[root].left, tree);
    if(tree[root].right > 0) show(tree[root].right, tree);
    cout << root << ' ';
}

//int main() {
//    cin >> n;
//    times = 2 * n;
//    vector<Node> tree(n+1, {0, 0});
//    cin >> pattern >> tree_root; cin.get();
//    dfs(tree_root, tree);
//    if(tree[tree_root].left > 0) show(tree[tree_root].left, tree);
//    if(tree[tree_root].right > 0) show(tree[tree_root].right, tree);
//    cout << tree_root << endl;
//}