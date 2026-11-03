class Solution {
public:

    const long long NEG = -(1LL << 60);
    const long long MOD = 1e9 + 7;

    struct Node {
        long long dp[2][2];
    };

    vector<Node> seg;
    int n;

    Node merge(Node a, Node b) {

        Node c;

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                c.dp[i][j] = NEG;
            }
        }

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {

                for(int x = 0; x < 2; x++) {
                    for(int y = 0; y < 2; y++) {

                        if(j == 1 && x == 1)
                            continue;

                        if(a.dp[i][j] == NEG ||
                           b.dp[x][y] == NEG)
                            continue;

                        c.dp[i][y] = max(
                            c.dp[i][y],
                            a.dp[i][j] + b.dp[x][y]
                        );
                    }
                }
            }
        }

        return c;
    }

    void build(int ind, int low, int high, vector<int>& nums) {

        if(low == high) {

            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    seg[ind].dp[i][j] = NEG;
                }
            }
            seg[ind].dp[0][0] = 0;
            seg[ind].dp[1][1] = nums[low];

            return;
        }

        int mid = low + (high - low) / 2;

        build(2 * ind + 1, low, mid, nums);
        build(2 * ind + 2, mid + 1, high, nums);

        seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    void update(int ind, int low, int high, int pos, int val) {

        if(low == high) {

            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    seg[ind].dp[i][j] = NEG;
                }
            }

            seg[ind].dp[0][0] = 0;
            seg[ind].dp[1][1] = val;

            return;
        }

        int mid = low + (high - low) / 2;

        if(pos <= mid) {
            update(2 * ind + 1, low, mid, pos, val);
        }
        else {
            update(2 * ind + 2, mid + 1, high, pos, val);
        }

        seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {

        n = nums.size();

        seg.resize(4 * n);

        build(0, 0, n - 1, nums);

        long long ans = 0;

        for(int i = 0; i < queries.size(); i++) {

            int pos = queries[i][0];
            int val = queries[i][1];

            nums[pos] = val;

            update(0, 0, n - 1, pos, val);

            long long maxi = 0;

            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    maxi = max(maxi, seg[0].dp[j][k]);
                }
            }

            ans = (ans + maxi) % MOD;
        }

        return ans;
    }
};