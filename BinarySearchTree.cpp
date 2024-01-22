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

Node *buildTree(int &cnt, int min, int max)
{
  int skip = getRandomNumber(0, 2);
  if (cnt == 0 or min > max or skip == 0)
    return NULL;
  int data = getRandomNumber(min, max);
  Node *root = new Node(data);
  cnt--;
  root->left = buildTree(cnt, min, data - 1);
  root->right = buildTree(cnt, data + 1, max);
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
int numberOfNode(Node *root)
{
  if (root == NULL)
    return 0;
  return 1 + numberOfNode(root->left) + numberOfNode(root->right);
}
int x, y;
int *ptr1 = NULL;
int *ptr2 = NULL;

void takevalues(Node *root, int &cnt)
{
  if (root == NULL)
    return;
  if (cnt == x)
    ptr1 = &(root->data);
  if (cnt == y)
    ptr2 = &(root->data);
  cnt--;
  takevalues(root->left, cnt);
  takevalues(root->right, cnt);
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
  int t = 100;
  cout << t << endl;
  while (t--)
  {
    x = 0, y = 0;
    *ptr1 = NULL;
    *ptr2 = NULL;
    int n = getRandomNumber(2, 10);
    Node *head = buildTree(n, 1, 20);
    int cnt = numberOfNode(head);
    while (cnt < 2)
    {
      n = getRandomNumber(2, 10);
      head = buildTree(n, 1, 20);
      cnt = numberOfNode(head);
    }
    x = getRandomNumber(1, cnt);
    if (x == 1)
      y = getRandomNumber(x + 1, cnt);
    else
      y = getRandomNumber(1, x - 1);
    takevalues(head, cnt);
    assert(ptr1 != NULL);
    assert(ptr2 != NULL);
    assert(x != 0);
    assert(y != 0);
    swap(*ptr1, *ptr2);
    generateStringFromRoot(head);
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