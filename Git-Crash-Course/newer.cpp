https : // cses.fi/problemset/task/1136/
        video -
        editorial : https : // www.google.com/search?q=cses+counting+paths&oq=cses+counting+path&gs_lcrp=EgZjaHJvbWUqBwgAEAAYgAQyBwgAEAAYgAQyBggBEEUYOTINCAIQABiGAxiABBiKBTINCAMQABiGAxiABBiKBTIKCAQQABiABBiiBDIKCAUQABiABBiiBDIKCAYQABiABBiiBDIGCAcQRRg8qAIIsAIB&sourceid=chrome&ie=UTF-8#fpstate=ive&vld=cid:e594bc22,vid:eMFawQ7VnMc,st:0

                            It kinda example of how to use aggregation on a grpah.Like we use prefix sum to get the net value after some opertations in the same way.The cheat code : is the last dfs we used to sum up unlike a 1d array where we start from the beginning and keep adding up,
    we add up from the leaf.Lca-- n1++ n2++ parent[lca]-- keep summing from the leaf.

    code :

    vector<int>
        adj[200000 + 1];
vector<int> level(200000 + 1);
int bl[200000 + 1][20];
vector<int> traversal_order;
void dfs(int n, int p)
{
  bl[n][0] = p;
  traversal_order.pb(n);
  for (int x : adj[n])
  {
    if (x != p)
    {
      dfs(x, n);
    }
  }
}
void level_finder(int n, int p, int co = 0)
{
  level[n] = co;
  for (int x : adj[n])
  {
    if (x != p)
    {
      level_finder(x, n, co + 1);
    }
  }
}
int level_up(int n, int k)
{
  for (int j = 0; j < 20 && n != -1; j++)
  {
    if ((1 << j) & k)
    {
      n = bl[n][j];
    }
  }
  return n;
}
int lcaFinder(int n1, int n2)
{
  int lca;
  int x, y;
  x = n1;
  y = n2;
  if (level[n1] > level[n2])
  {
    swap(n1, n2);
  }
  n2 = level_up(n2, level[n2] - level[n1]);
  if (n1 == n2)
  {
    lca = n1;
  }
  else
  {
    for (int j = 19; j >= 0; j--)
    {
      if (bl[n1][j] == bl[n2][j])
      {
      }
      else
      {
        n1 = bl[n1][j];
        n2 = bl[n2][j];
      }
    }
    lca = bl[n1][0];
  }
  return lca;
}
vector<int> val(200000 + 1);
void final_dfs(int n, int p)
{
  for (int x : adj[n])
  {
    if (x != p)
    {
      final_dfs(x, n);
      val[n] += val[x];
    }
  }
}
void f()
{

  int n, m;
  cin >> n >> m;
  memset(bl, -1, sizeof(bl));
  for (int i = 2; i <= n; i++)
  {
    int n1, n2;
    cin >> n1 >> n2;
    adj[n1].pb(n2);
    adj[n2].pb(n1);
  }
  dfs(1, -1);
  level_finder(1, 1, 0);

  for (int x : traversal_order)
  {

    for (int j = 1; j < 20; j++)
    {
      if (bl[x][j - 1] != -1)
      {
        bl[x][j] = bl[bl[x][j - 1]][j - 1];
      }
    }
  }

  while (m--)
  {
    int n1, n2;
    cin >> n1 >> n2;
    int lca = lcaFinder(n1, n2);
    val[n1]++;
    val[n2]++;
    val[lca]--;
    if (bl[lca][0] != -1)
    {
      val[bl[lca][0]]--;
    }
  }
  final_dfs(1, 1);

  for (int i = 1; i <= n; i++)
  {
    cout << val[i] << " ";
  }
}
