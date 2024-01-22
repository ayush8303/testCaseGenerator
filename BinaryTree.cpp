/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात् ||
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl "\n"
const int N = 100000;
int mod = 1000ll * 1000ll * 1000ll + 7;
const int inf = 1000ll * 1000ll * 1000ll;
#define cout std::cout
#define cin std::cin
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937 rng2(chrono::high_resolution_clock::now().time_since_epoch().count());

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine randomShuffle(seed);
// std::shuffle(std::begin(a), std::end(a), randomShuffle);
// sort(pairs.begin(), pairs.end());
// pairs.resize(unique(pairs.begin(), pairs.end()) - pairs.begin());

int getRandomNumber(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

Node *buildTree(int &cnt)
{
  int skip = getRandomNumber(0, 2);
  if (cnt == 0 or skip == 0)
    return NULL;
  int data = getRandomNumber(1, 50);
  Node *root = new Node(data);
  cnt--;
  root->left = buildTree(cnt);
  root->right = buildTree(cnt);
  return root;
}

// using bfs traversal
void generateStringFromRoot(Node *root)
{
  queue<Node *> q;
  q.push(root);
  while (!q.empty())
  {
    Node *cur = q.front();
    q.pop();
    if (cur == NULL)
    {
      cout << "N ";
    }
    else
    {
      cout << cur->data << ' ';
      q.push(cur->left);
      q.push(cur->right);
    }
  }
  cout << endl;
}
void printTree(Node *root)
{
  if (!root)
    return;
  cout << root->data << ' ';
  printTree(root->left);
  printTree(root->right);
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
  int t = 80;
  cout << t << endl;
  while (t--)
  {
    int n = getRandomNumber(1, 1000);
    Node *head = buildTree(n);
    generateStringFromRoot(head);
    cout << endl;
    cout << '~' << endl;
  }
  return 0;
}
// make sure to use cin.ignore();
/*
  remove spaces use getline to take input
  string str;
  getling(cin,str);
  vector<string> ip;
  istringstream iss(str);
  for (string str; iss >> str;)
    ip.push_back(str);
 */