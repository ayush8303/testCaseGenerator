#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define endl "\n"
int mod = 1000ll * 1000ll * 1000ll + 7;
const int inf = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
#define cout std::cout
#define cin std::cin

const int N = 500023;
long long readInt(long long l, long long r, char endd)
{
  long long x = 0;
  int cnt = 0;
  int fi = -1;
  bool is_neg = false;
  // integer must not be started from zero
  while (true)
  {
    char g = getchar();
    if (g == '-')
    {
      assert(fi == -1);
      is_neg = true;
      continue;
    }
    if ('0' <= g && g <= '9')
    {
      x *= 10;
      x += g - '0';
      if (cnt == 0)
      {
        fi = g - '0';
      }
      cnt++;
      assert(fi != 0 || cnt == 1);
      assert(fi != 0 || is_neg == false);

      assert(!(cnt > 19 || (cnt == 19 && fi > 1)));
    }
    else if (g == endd)
    {
      if (is_neg)
      {
        x = -x;
      }

      if (!(l <= x && x <= r))
      {
        cerr << l << ' ' << r << ' ' << x << '\n';
        assert(1 == 0);
      }

      return x;
    }
    else
    {
      assert(false);
    }
  }
}
string readString(int l, int r, char endd)
{
  string ret = "";
  int cnt = 0;
  while (true)
  {
    char g = getchar();
    assert(g != -1); // if invalid character
    if (g == endd)
    {
      break;
    }
    cnt++;
    ret += g;
  }
  assert(l <= cnt && cnt <= r);
  return ret;
}
long long readIntSp(long long l, long long r)
{
  return readInt(l, r, ' ');
}
long long readIntLn(long long l, long long r)
{
  return readInt(l, r, '\n');
}
string readStringLn(int l, int r)
{
  return readString(l, r, '\n');
}
string readStringSp(int l, int r)
{
  return readString(l, r, ' ');
}

int sumN = 0;

void solve()
{
  int n = readInt(1, 1000, '\n');
  sumN += n;
  vector<int> arr(n);
  for (int i = 0; i < n - 1; i++)
  {
    arr[i] = readInt(1, n, ' ');
  }
  arr[n - 1] = readInt(1, n, '\n');

  cerr << "Input read successfully" << endl;

  // solution

  cerr << "tested ok" << endl;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int T = readInt(1, 2000, '\n');
  cerr << "#Testcases read successfully" << endl;
  while (T--)
  {
    solve();
    // cout<<'\n';
  }
  cerr << sumN << '\n';
  assert(sumN <= 6000);
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}