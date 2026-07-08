class Solution {
    // by using SegTree concept
    public:
        using ll = long long;
        const int MOD = 1e9 + 7;
    
        struct Node {
            ll val;      // number formed by non-zero digits
            ll sum;      // sum of non-zero digits
            int cnt;     // number of non-zero digits
    
            Node(ll v = 0, ll s = 0, int c = 0) {
                val = v;
                sum = s;
                cnt = c;
            }
        };
    
        vector<ll> pow10;
    
        Node merge(Node L, Node R) {
            Node res;
            res.cnt = L.cnt + R.cnt;
            res.sum = (L.sum + R.sum) % MOD;
            res.val = (L.val * pow10[R.cnt] + R.val) % MOD;
            return res;
        }
    
        void build(int idx, int l, int r, vector<Node> &seg, string &s) {
    
            if (l == r) {
                int d = s[l] - '0';
    
                if (d == 0)
                    seg[idx] = Node(0, 0, 0);
                else
                    seg[idx] = Node(d, d, 1);
    
                return;
            }
    
            int mid = (l + r) / 2;
    
            build(2 * idx + 1, l, mid, seg, s);
            build(2 * idx + 2, mid + 1, r, seg, s);
    
            seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
        }
    
        Node query(int idx, int l, int r,
                   int ql, int qr,
                   vector<Node> &seg) {
    
            if (r < ql || l > qr)
                return Node();
    
            if (ql <= l && r <= qr)
                return seg[idx];
    
            int mid = (l + r) / 2;
    
            Node left = query(2 * idx + 1, l, mid, ql, qr, seg);
            Node right = query(2 * idx + 2, mid + 1, r, ql, qr, seg);
    
            return merge(left, right);
        }
    
        vector<int> sumAndMultiply(string s, vector<vector<int>> &queries) {
    
            int n = s.size();
    
            pow10.assign(n + 1, 1);
    
            for (int i = 1; i <= n; i++)
                pow10[i] = (pow10[i - 1] * 10LL) % MOD;
    
            vector<Node> seg(4 * n);
    
            build(0, 0, n - 1, seg, s);
    
            vector<int> ans;
    
            for (auto &q : queries) {
    
                Node cur = query(0, 0, n - 1, q[0], q[1], seg);
    
                ans.push_back((cur.val * cur.sum) % MOD);
            }
    
            return ans;
        }
    };

// Optimal Approach

class Solution {
    public:
        int mod = 1e9+7;
        typedef long long ll;
        vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
            int n = s.size();
            vector<ll> digitSum(n, 0), x(n, 0), nonZeroCount(n), pow10(n+1, 1);
            digitSum[0] = s[0]-'0';
            x[0] = s[0]-'0';
            nonZeroCount[0] = (s[0] == '0' ? 0 : 1);
            for(int i = 1;i <= n;i++){
                pow10[i] = (pow10[i-1] * 10)%mod;
            }  
            for(int i = 1;i < n;i++){
                digitSum[i] = (digitSum[i-1] + s[i] - '0')%mod;
                nonZeroCount[i] = nonZeroCount[i-1] + (s[i] == '0' ? 0 : 1);
                if(s[i] != '0') x[i] = (x[i-1] * 10LL + (s[i]-'0'))%mod;
                else x[i] = x[i-1];
            }
            vector<int> ans;
            for(auto it:queries){
                int sum;
                int a = it[0], b = it[1];
                if(a != 0) sum = (digitSum[b] - digitSum[a-1] + mod) % mod;
                else sum = digitSum[b];
                if(a == 0) {
                    ans.push_back((1LL*x[b]*sum)%mod);
                }
                else {
                    int digitdiff = nonZeroCount[b]-nonZeroCount[a-1];
                    int temp = (1LL * x[a-1] * pow10[digitdiff])%mod;
                    ll value = (x[b] - temp + mod) % mod;
                    ans.push_back((1LL * value * sum) % mod);
                }
            }
            return ans;
        }
    };