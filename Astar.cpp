#include <bits/stdc++.h>
using namespace std;
#define n 3

class node
{

    node *parent;
    int mat[n][n];
    int x, y;
    int level;
    int cost;
    friend class Solution;
};
class Solution
{

public:
    void printMatrix(int mat[n][n])
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    int calculateCost(int initial[n][n], int final[n][n])
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (initial[i][j] && initial[i][j] != final[i][j])
                {
                    count++;
                }
            }
        }
        return count;
    }

    void printPath(node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        printPath(root->parent);
        printMatrix(root->mat);
        cout << "\n";
    }

    bool isSafe(int x, int y)
    {
        return (x >= 0 && x < n && y >= 0 && y < n);
    }

    node *newNode(int mat[n][n], int x, int y, int nx, int ny, int level, node *par)
    {
        node *Node = new node;
        Node->parent = par;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Node->mat[i][j] = mat[i][j];
            }
        }

        swap(Node->mat[x][y], Node->mat[nx][ny]);

        Node->x = nx;
        Node->y = ny;

        Node->cost = INT_MAX;
        Node->level = level;
        return Node;
    }

    class comp
    {

    public:
        bool operator()(node *lhs, node *rhs)
        {
            return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
        }
    };

    void solve(int initial[n][n], int x, int y, int final[n][n])
    {

        int row[] = {1, 0, -1, 0};
        int col[] = {0, -1, 0, 1};
        node *root = newNode(initial, x, y, x, y, 0, nullptr);
        root->cost = calculateCost(initial, final);

        priority_queue<node *, vector<node *>, comp> pq;
        cout << "hi1" << endl;
        pq.push(root);

        while (!pq.empty())
        {
            node *min = pq.top();
            pq.pop();

            if (min->cost == 0)
            {
                printPath(min);
                return;
            }

            for (int i = 0; i < 4; i++)
            {
                if (isSafe(min->x + row[i], min->y + col[i]))
                {

                    node *child = newNode(min->mat, min->x, min->y, min->x + row[i], min->y + col[i], min->level + 1, min);
                    child->cost = calculateCost(child->mat, final);
                    pq.push(child);
                }
            }
        }
    }
};

int main()
{

    int initial[n][n];
    int final[n][n];

    cout << "Enter the initial state\n";

    int x;
    int xc, yc;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter the number\n";
            cin >> initial[i][j];
            if (initial[i][j] == 0)
            {
                xc = i;
                yc = j;
            }
        }
    }

    cout << "Enter the final state\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter the number\n";
            cin >> x;
            final[i][j] = x;
        }
    }

    cout << "Initial state\n";
    cout << "xc:" << xc << " "
         << "yc" << yc << endl;
    Solution s;
    s.solve(initial, xc, yc, final);
}