struct Node {
    int max_len = 0;
    int prefix_len = 0;
    int suffix_len = 0;
    char first_char = ' ';
    char last_char = ' ';
};

class Solution {
    vector<Node> tree;
    string str;

    Node merge(const Node& left, const Node& right, int left_size, int right_size) {
        Node parent;
        parent.first_char = left.first_char;
        parent.last_char = right.last_char;

        parent.max_len = max(left.max_len, right.max_len);
        parent.prefix_len = left.prefix_len;
        parent.suffix_len = right.suffix_len;

        if (left.last_char == right.first_char) {
            parent.max_len = max(parent.max_len, left.suffix_len + right.prefix_len);

            if (left.prefix_len == left_size) {
                parent.prefix_len = left.prefix_len + right.prefix_len;
            }

            if (right.suffix_len == right_size) {
                parent.suffix_len = right.suffix_len + left.suffix_len;
            }
        }

        return parent;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, str[start], str[start]};
            return;
        }

        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        int left_size = mid - start + 1;
        int right_size = end - mid;
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], left_size, right_size);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {1, 1, 1, ch, ch};
            return;
        }

        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }

        int left_size = mid - start + 1;
        int right_size = end - mid;
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], left_size, right_size);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        str = s;
        tree.resize(4 * n);

        build(1, 0, n - 1);

        int k = queryIndices.size();
        vector<int> ans(k);

        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].max_len;
        }

        return ans;
    }
};