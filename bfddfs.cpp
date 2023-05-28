#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vec vector
#define loop(i, n) for (int i = 0; i < n; i++)
using namespace std;
vector<vector<int>> v1;

void dfs(vector<int> &vis, int st)
{
    cout << st << " -> ";
    vis[st] = 1;
    for (auto it : v1[st])
    {
        if (vis[it] == 0)
        {
            dfs(vis, it);
        }
    }
}

void bfs(queue<int> &q, vector<int> &vis)
{
    if (q.empty())
    {
        return;
    }
    int nd = q.front();
    q.pop();

    cout << nd << " -> ";
    for (auto it : v1[nd])
    {
        if (vis[it] == 0)
        {
            q.push(it);
            vis[it] = 1;
        }
    }
    bfs(q, vis);
}
int main()
{

    int n, m;
    cout << "Enter the no . of. nodes" << endl;
    cin >> n;
    cout << "Enter the no.of .edges in graph" << endl;
    cin >> m;
    v1.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cout << "Enter the Starting and Ending node " << endl;
        cin >> s >> e;
        v1[s].push_back(e);
        v1[e].push_back(s);
    }

    int ch = 1;
    cout << "\nMenu" << endl;
    while (ch)
    {
        cout << "ENTER THE  CHOICE \n 1.DFS \n 2.BFS \n  ";
        cin >> ch;
        if (ch == 1)
        {
            vector<int> vis(n + 1);
            int st;
            cout << "Enter The Starting Point \nn";
            cin >> st;
            dfs(vis, st);
            cout << "\n DFS" << endl;
        }
        else if (ch == 2)
        {
            vector<int> vis(n + 1);
            int st;
            cout << "Enter The Starting Point \nn";
            cin >> st;
            queue<int> q;
            q.push(st);
            vis[st] = 1;
            cout << " BFS \n";
            bfs(q, vis);
        }
        else
        {
            cout << "Enter the Valid Input" << endl;
        }
        cout << "\nDo you want to continue (0/1):";
        cin >> ch;
    }

    return 0;
}
