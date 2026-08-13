#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int max_len;   // Longest repeating substring in segment
    int pref_len;  // Length of repeating prefix
    int suff_len;  // Length of repeating suffix
    char pref_char; // Character of prefix
    char suff_char; // Character of suffix
    int length;    // Segment size
};

class Solution {
private:
    vector<Node> tree;

    // Merges two segment tree nodes together
    Node merge(const Node& left, const Node& right) {
        Node res;
        res.length = left.length + right.length;
        res.pref_char = left.pref_char;
        res.suff_char = right.suff_char;

        // Calculate prefix length for combined segment
        res.pref_len = left.pref_len;
        if (left.pref_len == left.length && left.suff_char == right.pref_char) {
            res.pref_len += right.pref_len;
        }

        // Calculate suffix length for combined segment
        res.suff_len = right.suff_len;
        if (right.suff_len == right.length && right.pref_char == left.suff_char) {
            res.suff_len += left.suff_len;
        }

        // Calculate maximum repeating length
        res.max_len = max(left.max_len, right.max_len);
        if (left.suff_char == right.pref_char) {
            res.max_len = max(res.max_len, left.suff_len + right.pref_len);
        }

        return res;
    }

    void build(const string& s, int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(s, 2 * node, start, mid);
        build(s, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {1, 1, 1, ch, ch, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int k = queryIndices.size();
        tree.resize(4 * n);

        build(s, 1, 0, n - 1);

        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].max_len;
        }

        return ans;
    }
};