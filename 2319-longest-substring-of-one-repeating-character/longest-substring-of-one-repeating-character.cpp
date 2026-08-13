class Solution {
public:
    struct Node {
        char lc, rc;

        int len;    // length of this segment
        int left;   // same-character prefix
        int right;  // same-character suffix
        int best;   // longest repeating substring
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        Node res;

        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        // Start with the best from either side
        res.left = a.left;
        res.right = b.right;
        res.best = max(a.best, b.best);

        // Characters at the boundary are equal
        if (a.rc == b.lc) {

            // Join suffix of left + prefix of right
            res.best = max(res.best, a.right + b.left);

            // Entire left segment has the same character
            if (a.left == a.len) {
                res.left = a.len + b.left;
            }

            // Entire right segment has the same character
            if (b.right == b.len) {
                res.right = b.len + a.right;
            }
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = {
                s[l],  // lc
                s[l],  // rc
                1,     // len
                1,     // left
                1,     // right
                1      // best
            };

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    void update(int node, int l, int r, int pos, char c) {
        if (l == r) {
            tree[node] = {
                c, c,
                1,
                1,
                1,
                1
            };

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(node * 2, l, mid, pos, c);
        } else {
            update(node * 2 + 1, mid + 1, r, pos, c);
        }

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {
            int pos = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, pos, c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};
