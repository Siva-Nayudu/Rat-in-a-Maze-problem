#include <iostream>
using namespace std;
#define MAX 5

int ansMatrix[MAX][MAX];

int solution(int r, int c,int mat[MAX][MAX])
{
    if ((r == 0) && (c == MAX - 1))
    {
        ansMatrix[r][c] = 1;
        return true;
    }
    if (r >= 0 && r < MAX && c >= 0 && c < MAX && mat[r][c] == 0 && ansMatrix[r][c] == 0)
    {
        ansMatrix[r][c] = 1;
        if (solution(r - 1, c, mat))
        {
            return true;
        }
        if (solution(r + 1, c, mat))
        {
            return true;
        }
        if (solution(r, c - 1, mat))
        {
            return true;
        }
        if (solution(r, c + 1, mat))
        {
            return true;
        }
        ansMatrix[r][c] = 0;
        return false;
    }
    return false;
}
int main()
{
    int i, j, x = 0;
    int mat[MAX][MAX];
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            cin>>mat[i][j];
        }
    }
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            ansMatrix[i][j] = 0;
        }
    }
    if (solution(MAX - 1, 0,mat) == true)
    {
        cout << "The solution path:\n";
        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
            {
                if (ansMatrix[i][j] == 0)
                {
                    cout << "1"
                         << " ";
                }
                else
                {
                    cout << "0"
                         << " ";
                }
                if (ansMatrix[i][j] == 1 && i % 2 == 0)
                {
                    x = x + 1;
                }
                else if (ansMatrix[i][j] == 1 && i % 2 == 1)
                {
                    x = x + 2;
                }
            }
            cout << "\n";
        }
        cout << "\n";
        cout << "The total cost of followed way is:" << x;
    }
    else
        cout << "There is no possible way";
    return 0;
}
