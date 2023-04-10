/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात् ||
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl "\n"
const int N = 1e9;
const int inf = 1e12;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937 rng2(chrono::high_resolution_clock::now().time_since_epoch().count());

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine randomShuffle(seed);
// std::shuffle(std::begin(a), std::end(a), randomShuffle);

int getRandomNumber(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

void dfs(int node, int par, vector<vector<int>> &gr, vector<int> &vis)
{
  vis[node] = 1;
  for (auto x : gr[node])
  {
    if (x == par)
      continue;
    if (vis[x])
      assert(false);
    dfs(x, node, gr, vis);
  }
}
bool checkTree(int n, vector<vector<int>> edges)
{
  vector<vector<int>> gr(n + 1);
  for (auto &it : edges)
  {
    assert(it[0] > 0 and it[0] <= n);
    assert(it[1] > 0 and it[1] <= n);
    gr[it[0]].push_back(it[1]);
    gr[it[1]].push_back(it[0]);
  }
  vector<int> vis(n + 1, 0);
  dfs(1, 0, gr, vis);
  return 1;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifndef ONLINE_JUDGE
  // freopen("input.txt","r",stdin);
  freopen("input.txt", "w", stdout);
#endif
  int t = 2;
  // cin>>t;
  cout << t << endl;
  while (t--)
  {
    int n = getRandomNumber(100000, 100000);
    cout << n << endl;

    for (int i = 0; i < n; i++)
    {
      cout << getRandomNumber(100000, 1000000) << ' ';
    }
    cout << endl;

    // edges
    vector<int> parent;
    parent.push_back(1);
    vector<int> child;
    for (int i = 2; i <= n; i++)
      child.push_back(i);
    std::shuffle(std::begin(child), std::end(child), randomShuffle);
    int childId = 0;
    vector<vector<int>> edges;
    for (int i = 0; i < n - 1; i++)
    {
      int m = (int)parent.size();
      int parId = getRandomNumber(0, m - 1);
      // cout << curPar << ' ' << child[childId] << endl;
      edges.push_back({parent[parId], child[childId]});
      parent.push_back(child[childId]);
      childId++;
    }
    checkTree(n, edges);
    for (auto &it : edges)
    {
      cout << it[0] << ' ' << it[1] << endl;
    }
    // queries
    int Q = getRandomNumber(100000, 100000);
    cout << Q << endl;
    for (int i = 0; i < Q; i++)
    {
      cout << getRandomNumber(1, n) << ' ' << getRandomNumber(100000, 1000000) << endl;
    }
    cout << '~' << endl;
  }
  return 0;
}
