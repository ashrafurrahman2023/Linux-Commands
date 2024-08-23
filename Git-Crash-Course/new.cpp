
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include "iomanip"
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#define ll long long
#define pb push_back
#define ld long double
using namespace std;
#include "stack"
#define ll long long
#define pb push_back
#define ld long double
using namespace std;
#include "stack"
ll mod = 1e9 + 7;
ld pi = 3.14159265359;
ld eps = 0.000000001;
ll Prime = 9011;
#define ll long long
#define pb push_back
class Solution
{
public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    stack<vector<TreeNode *, bool>> s;
    vector<int> ans;
    s.push({root->right, 0});
    s.push({root, 0});
    s.push({root->left, 0});
    while (s.size())
    {
      auto x = s.top()[0];
      auto b = s.top()[1];
      s.pop();
      if (!x)
      {
        continue;
      }
      if (!b)
      {
        s.push({x->right, 0});
        s.push({x, 0});
        s.push({x->left, 0});
      }
      else
      {
        ans.push_back(x->val);
      }
    }
    return ans;
  }
};

#include <iostream>
#include <fstream>
void f(ifstream &input, ofstream &output)
{
  ll n;
  input >> n;
  vector<ll> v(n + 1);
  for (int i = 1; i <= n; i++)
  {
    input >> v[i];
  }
  sort(v.begin(), v.end());
  if (n == 5)
  {
    ld x = max(v[4] - (v[1] + v[2]) / 2.000, (v[4] + v[5]) / 2.000 - v[2]);
    output << setprecision(10) << x;
  }
  else
  {
    ld x = ((v[n - 1] + v[n]) / 2.000 - (v[1] + v[2]) / 2.000);
    output << setprecision(10) << x;
  }
}

class SegmentTree
{
public:
  ll *a;
  ll *tree;
  ll fn(ll n1, ll n2)
  {
    return n1 + n2;
  }
  SegmentTree(int size)
  {
    a = new long long[size + 1];
    tree = new long long[(size + 1) * 4];
  }
  void build(int node, int st, int en)
  {
    if (st == en)
    {
      tree[node] = a[st];
      return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    // the main part--->
    tree[node] = fn(tree[2 * node], tree[2 * node + 1]);
  }
  ll query(int node, int st, int en, int left, int right)
  {
    if (en < left || right < st)
    {
      return 1e17;
    }
    if (left <= st && en <= right)
    {
      return tree[node];
    }
    // the main part----->
    int mid = (st + en) / 2;

    return fn(query(2 * node, st, mid, left, right), query(2 * node + 1, mid + 1, en, left, right));
  }
  void update(int node, int st, int en, int idx, ll val)
  {
    if (st == en)
    {
      a[st] = val;
      tree[node] = val;
      return;
    }
    int mid = (st + en) / 2;
    if (idx <= mid)
    {

      update(2 * node, st, mid, idx, val);
    }
    else
    {
      update(2 * node + 1, mid + 1, en, idx, val);
    }
    // main part----->
    tree[node] = fn(tree[2 * node], tree[2 * node + 1]);
  }
};
class matrix
{
public:
  vector<vector<ll>> v1, v2, res;
  int n;
  ll mod = 1e18;
#define mat vector<vector<ll>>
  matrix(int n)
  {
    this->n = n;
    v1.resize(n + 1);
    v2.resize(n + 1);
    res.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
      v1[i].resize(n + 1);
      v2[i].resize(n + 1);
      res[i].resize(n + 1);
    }
  }
  void multiply(mat m1, mat m2)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        res[i][j] = 0;
        for (int k = 1; k <= n; k++)
        {
          res[i][j] += m1[i][k] * m2[k][j];
          res[i][j] %= mod;
        }
      }
    }
  }

  void exp(mat &x, ll k)
  {
    if (k == 1)
    {
      res = x;
      return;
    }
    if (k % 2 == 0)
    {
      exp(x, k / 2);
      multiply(res, res);
      return;
    }
    else
    {
      exp(x, k / 2);
      multiply(res, res);
      multiply(res, x);
    }
  }
};
class Tricks
{
public:
  void row_to_columns(vector<string> &v, int n, int m)
  {
    vector<string> v2;
    for (int i = 0; i <= m; i++)
    {
      string s;
      for (int j = 0; j <= n; j++)
      {
        s += v[j][i];
      }
      v2.pb(s);
    }
    v = v2;
  }
  ll Min(ll n1, ll n2)
  {
    return min(n1, n2);
  }

  map<int, int> corCompression(set<int> s)
  {
    map<int, int> m;
    int i = 1;
    vector<int> v;
    for (int x : s)
    {
      v.pb(x);
    }
    sort(v.begin(), v.end());
    for (int x : v)
    {
      m[x] = (i++);
    }
    return m;
  }

  int countInversions(vector<int> v, int n)
  {
    SegmentTree st(n);
    for (int i = 1; i <= n; i++)
    {
      st.a[i] = 0;
    }
    st.build(1, 1, n);
    int co = 0;
    for (int i = n; i >= 1; i--)
    {
      co += st.query(1, 1, n, 1, v[i]);
      st.update(1, 1, n, v[i], 1);
    }
    return co;
  }
  string &decimalToBinary(ll n, int len = 61)
  {
    vector<ll> bpow(len);
    bpow[0] = 1;
    for (int i = 1; i < len; i++)
    {
      bpow[i] = (2 * bpow[i - 1]);
    }
    string s(len, '0');
    for (ll i = 0; i < len; i++)
    {
      if ((bpow[i]) & n)
      {
        s[i] = '1';
      }
    }
    return s;
  }
};
Tricks t;
class TrieNode
{
public:
  vector<TrieNode *> children;
  bool isEndOfWord;

  TrieNode()
  {
    children = vector<TrieNode *>(2, nullptr);
    isEndOfWord = false;
  }
};
class Trie
{
public:
  TrieNode *root;

  // Helper function to delete a word
  bool deleteHelper(TrieNode *node, int num, int depth)
  {
    if (!node)
    {
      return false;
    }

    if (depth == -1)
    {
      if (!node->isEndOfWord)
      {
        return false;
      }

      node->isEndOfWord = false;

      return (node->children[0] == nullptr && node->children[1] == nullptr);
    }

    int index = ((1 << depth) & num) > 0;
    if (deleteHelper(node->children[index], num, depth - 1))
    {
      delete node->children[index];
      node->children[index] = nullptr;
      return !node->isEndOfWord && (node->children[0] == nullptr && node->children[1] == nullptr);
    }

    return false;
  }

public:
  Trie()
  {
    root = new TrieNode();
  }

  void insert(int num, int co)
  {
    TrieNode *node = root;
    for (int i = co; i >= 0; i--)
    {
      int index = ((1 << i) & num) > 0;
      if (node->children[index] == nullptr)
      {
        node->children[index] = new TrieNode();
      }
      node = node->children[index];
    }
    node->isEndOfWord = true;
  }

  void deleteWord(int num, int co)
  {
    deleteHelper(root, num, co);
  }
};
Trie tr;
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial)
  {
  }
};

#define ll long long
#define pb push_back
#define ll long long
#define pb push_back
#define ll long long
#define pb push_back
// ll mod=1e9+7;

class Math
{
public:
  int isMultipliable(ll n1, ll n2)
  {
    if ((log10(n1) + 0.00) + (log10(n2) + 0.000) > 18)
    {
      return 1;
    }
    return 0;
  }
  ll mod = 1e9 + 7;
  ll divide(ll a, ll b)
  {
    return (a % mod) * binpow(b, mod - 2) % mod;
  }

  ll fact[2000000 + 1];

  ll gcd(ll a, ll b)
  {
    while (b != 0)
    {
      ll temp = b;
      b = a % b;
      a = temp;
    }
    return a;
  }
  ll lcm(vector<ll> v)
  {
    ll ans = 1;
    for (ll x : v)
    {
      ll gc = gcd(x, ans);
      ans *= x;
      ans /= gc;
    }
    return ans;
  }

  ll fast_mod_exp(ll a, ll b, ll m)
  {
    ll res = 1;
    while (b > 0)
    {
      if (b & 1)
        res = (res * a) % m;

      a = (a * a) % m;
      b = b >> 1;
    }

    return res;
  }

  ll mod_inverse(ll a, ll m)
  {
    // m is prime
    return fast_mod_exp(a, m - 2, m);
  }

  ll ncr(ll n, ll r)
  {

    if (n <= 0)
    {
      return 1;
    }
    if (r <= 0)
    {
      return 1;
    }
    if (r == 0)
      return 1;

    // ll ans = 1;
    // for (ll i = 0; i <= r - 1; i++) {
    // 	ans = (ans * (n - i)) % p;
    // }

    return ((fact[n] * mod_inverse(fact[n - r], mod)) % mod * mod_inverse(fact[r], mod)) % mod;
  }
  long long binpow(long long a, long long b)
  {
    if (b == 0)
      return 1;
    long long res = binpow(a, b / 2);
    res %= mod;
    if (b % 2)
      return (((res * res) % mod) * a) % mod;
    else
      return (res * res) % mod;
  }

  ll exp_sum_from_l_r(ll base, ll l, ll r) // base^l+base^(l+1)+...
  {
    // cout<<base<<" "<<r+1<<" ";
    ll n2 = divide((binpow(base, r + 1) - 1), base - 1);
    n2 = (n2 + mod) % mod;
    if (l == 0)
    {
      return n2;
    }
    ll n1 = divide((binpow(base, l) - 1), base - 1);
    n1 = (n1 + mod) % mod;
    n2 = (n2 - n1 + mod) % mod;
    return n2;
  }
  ll cross(ll n1, ll n2)
  {
    n1 %= mod;
    n2 %= mod;
    n1 *= n2;
    n1 %= mod;
    return n1;
  }
  void math_init()
  {
    fact[0] = fact[1] = 1;
    for (ll i = 1; i <= 2000000; i++)
    {
      fact[i] = (fact[i - 1] * i) % mod;
    }
  }
  ll bigPower(ll a, ll bigPw)
  {
    bigPw %= (mod - 1);
    return binpow(a, bigPw);
  }
};
Math m;

class DSU
{
public:
  int *parent;
  int *len;
  int n;
  DSU(int n2)
  {
    n = n2;
    parent = new int[n + 1];
    len = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
      parent[i] = i;
      len[i] = 0;
    }
  }
  int find_set(int v)
  {
    if (v == parent[v])
      return v;
    return find_set(parent[v]);
  }
  void union_sets(int a, int b)
  {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
      if (len[a] < len[b])
        swap(a, b);
      parent[b] = a;
      len[a] += len[b];
    }
  }
};

#define ll long long
#define ll long long
#define pb push_back

ll giveNum(vector<vector<ll>> v)
{
  ll co = 1;
  for (auto x : v)
  {
    co = m.cross(co, x[1] + 1);
  }
  return co;
}
ll giveSum(vector<vector<ll>> v)
{
  ll res = 1;
  for (auto x : v)
  {
    ll n1 = x[0];
    ll n2 = x[1];
    ll p = m.binpow(n1, n2 + 1) - 1;
    ll q = n1 - 1;
    p = m.divide(p, q);
    res = m.cross(res, p);
  }
  return res;
}

unordered_map<int, int> giveSet(vector<int> v)
{
  int n = v.size();
  unordered_map<int, int> m;
  for (int mask = 0; mask < (1 << n); mask++)
  {
    ll sum = 0;
    for (int j = 0; j < n; j++)
    {
      if ((1 << j) & mask)
      {
        sum += v[j];
      }
    }
    if (sum > 1e9)
    {
      continue;
    }
    m[sum]++;
  }
  return m;
}

class SegmentTreeModified
{
public:
  ll *a; // a[2e5]
  ll **tree;
  ll zero = 0;
  ll fn(ll n1, ll n2)
  {
    return min(n1, n2);
  }
  SegmentTreeModified(int size)
  {
    a = new long long[size + 1];
    tree = new long long *[(size + 1) * 4];
    for (int i = 0; i < (size + 1) * 4; i++)
    {
      tree[i] = new long long[4];
    }
  }
  void build(int node, int st, int en)
  {
    if (st == en)
    {
      tree[node][0] = max(zero, a[st]);
      tree[node][1] = max(zero, a[st]);
      tree[node][2] = max(zero, a[st]);
      tree[node][3] = a[st];
      return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    // the main part--->
    tree[node][0] = max(zero, max(tree[2 * node][0], tree[2 * node][3] + tree[2 * node + 1][0]));
    tree[node][1] = max(zero, max(tree[2 * node + 1][1], tree[2 * node + 1][3] + tree[2 * node][1]));
    tree[node][3] = tree[2 * node][3] + tree[2 * node + 1][3];
    ll n1 = tree[node][0];
    ll n2 = tree[node][1];
    ll n3 = tree[2 * node][1] + tree[2 * node + 1][0];
    ll n4 = tree[2 * node][2];
    ll n5 = tree[2 * node + 1][2];
    tree[node][2] = max(n1, max(n2, max(n3, max(n4, n5))));
  }
  vector<ll> query(int node, int st, int en, int left, int right)
  {
    if (en < left || right < st)
    {
      return {0, 0, 0, 0};
    }
    if (left <= st && en <= right)
    {
      return {tree[node][0], tree[node][1], tree[node][2], tree[node][3]};
    }
    // the main part----->
    int mid = (st + en) / 2;

    vector<ll> v1 = query(2 * node, st, mid, left, right);
    vector<ll> v2 = query(2 * node + 1, mid + 1, en, left, right);
    vector<ll> ans(4);
    ans[0] = max(zero, max(v1[0], v1[3] + v2[0]));
    ans[1] = max(zero, max(v2[1], v2[3] + v1[1]));
    ans[3] = v1[3] + v2[3];
    ll n1 = ans[0];
    ll n2 = ans[1];
    ll n3 = v1[1] + v2[0];
    ll n4 = v1[2];
    ll n5 = v2[2];
    ans[2] = max(n1, max(n2, max(n3, max(n4, n5))));
    return ans;
  }
  void update(int node, int st, int en, int idx, ll val)
  {
    if (st == en)
    {
      a[st] = val;
      tree[node][0] = max(zero, a[st]);
      tree[node][1] = max(zero, a[st]);
      tree[node][2] = max(zero, a[st]);
      tree[node][3] = a[st];
      return;
    }
    int mid = (st + en) / 2;
    if (idx <= mid)
    {

      update(2 * node, st, mid, idx, val);
    }
    else
    {
      update(2 * node + 1, mid + 1, en, idx, val);
    }
    // main part----->
    tree[node][0] = max(zero, max(tree[2 * node][0], tree[2 * node][3] + tree[2 * node + 1][0]));
    tree[node][1] = max(zero, max(tree[2 * node + 1][1], tree[2 * node + 1][3] + tree[2 * node][1]));
    tree[node][3] = tree[2 * node][3] + tree[2 * node + 1][3];
    ll n1 = tree[node][0];
    ll n2 = tree[node][1];
    ll n3 = tree[2 * node][1] + tree[2 * node + 1][0];
    ll n4 = tree[2 * node][2];
    ll n5 = tree[2 * node + 1][2];
    tree[node][2] = max(n1, max(n2, max(n3, max(n4, n5))));
  }
};

void f()
{

  // https://math.stackexchange.com/questions/1126001/product-of-divisors-of-some-n-proof
  // https://www.geeksforgeeks.org/find-abm-where-b-is-very-large/

  /*
   *
   * Lets say we encountered a starting point we can then say that
   * all of the other ranges that came before it and havent been vanished yet
   * their count will be the b[i] of it
   */
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    f();
    cout << "\n";
  }

  //    ifstream input("/Users/almaksud/Desktop/MaIn/here_comes_santa_claus_input.txt");
  //    ofstream output("/Users/almaksud/Desktop/MaIn/out.txt");
  //    if (!input.is_open()) {
  //        cout<< "Unable to open input file" << endl;
  //        return 1;
  //    }
  //    int t;input>>t;
  //    for(int i=1;i<=t;i++){
  //        output<<"Case "<<"#"<<i<<": ";
  //        f(input,output);
  //        output<<"\n";
  //    }

  //    fast_io;
  //
  //    int t;cin>>t;
  //    while(t--){
  //        f();
  //        cout<<"\n";
  //    }
}

ll c_xor(ll a, ll b)
{

  return (a ^ b);
}
vector<vector<int>> prime_factorization(int n)
{
  vector<vector<int>> ans;
  for (int i = 2; i * i <= n; i++)
  {
    int co = 0;
    if (n % i == 0)
    {
      while (n % i == 0)
      {
        co++;
        n /= i;
      }
    }
    else
    {
      continue;
    }
    ans.pb({i, co});
  }
  if (n != 1)
  {
    ans.pb({n, 1});
  }
  return ans;
}
long long binpow(long long a, long long b)
{
  if (b == 0)
    return 1;
  long long res = binpow(a, b / 2);
  res %= mod;
  if (b % 2)
    return (((res * res) % mod) * a) % mod;
  else
    return (res * res) % mod;
}
