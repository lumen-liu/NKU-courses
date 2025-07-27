#include<bits/stdc++.h>
using namespace std;
// 定义二叉树结点
struct Node {
    int freq;
    char ch;
    Node* left, * right;
    Node(int f, char c) : freq(f), ch(c), left(nullptr), right(nullptr) {}
};

// 定义结点比较函数，用于建立最小堆
struct NodeComparator {
    bool operator() (const Node* a, const Node* b) {
        return a->freq > b->freq;
    }
};

// 构建Huffman编码的贪心算法
string huffman(int n, vector<int>& freq) {
    // 初始化最小堆，每个结点都是一棵单独的树
    priority_queue<Node*, vector<Node*>, NodeComparator> pq;
    for (int i = 0; i < n; i++) {
        pq.push(new Node(freq[i], char(i + 'a')));
    }

    // 构建Huffman树，直到堆中只有一棵树
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* parent = new Node(left->freq + right->freq, '-');
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    // 遍历Huffman树，生成编码
    map<char, string> codes;
    string code;
    Node* root = pq.top();
    function<void(Node*, string)> traverse = [&](Node* node, string code) {
        if (node->left == nullptr && node->right == nullptr) {
            codes[node->ch] = code;
            return;
        }
        traverse(node->left, code + '0');
        traverse(node->right, code + '1');
    };
    traverse(root, code);

    // 计算平均编码长度
    double avg_len = 0;
    for (auto p : codes) {
        avg_len += freq[p.first - 'a'] * p.second.size();
    }
    avg_len /= accumulate(freq.begin(), freq.end(), 0);

    // 返回编码结果和平均编码长度
    return to_string(avg_len);
}

int main() {
    // 读入数据
    int n;
    cin >> n;
    vector<int> freq(n);
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

    // 计算Huffman编码并输出结果
    string code = huffman(n, freq);
    cout << fixed << setprecision(2) << code << endl;

    return 0;
}