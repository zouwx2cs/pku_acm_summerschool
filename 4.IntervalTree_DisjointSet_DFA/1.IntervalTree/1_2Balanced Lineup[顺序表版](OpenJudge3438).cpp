#include <iostream>

using namespace std ;

const int INF = 0x7fffffff ;
const int maxV = INF ;
const int minV = -INF ;
struct Node
{
    int l, r ;
    int M ;
    int m ;
    Node *left, *right ;
    Node(int ll, int rr): l(ll), r(rr), M(minV), m(maxV), left(NULL), right(NULL) {} ;
    Node(void): l(0), r(0), M(minV), m(maxV), left(NULL), right(NULL) {} ;
    int GetMid()
    {
        return (l+r) >> 1 ;
    }
};

Node tree[200099] ;

// 根节点从下标为1开始
void CreateTree(int rIndex, int l, int r)
{
    tree[rIndex].l = l ;
    tree[rIndex].r = r ;
    if (l != r)
    {
        const int mid = (l+r) >> 1 ;
        CreateTree(rIndex << 1, l, mid) ;
        CreateTree((rIndex << 1) + 1, 1 + mid, r) ;
    }
}

void InsertValue(int rIndex, int pos, int value)
{
    if (pos < tree[rIndex].l || pos > tree[rIndex].r)
        return;

    tree[rIndex].M = max(tree[rIndex].M, value);
    tree[rIndex].m = min(tree[rIndex].m, value);

    if (tree[rIndex].l != tree[rIndex].r)
    {
        InsertValue(rIndex << 1, pos, value);
        InsertValue((rIndex << 1) + 1, pos, value);
    }
}

void getMaxAndMin(int rIndex, int l, int r, int &M, int &m)
{
    if (r < tree[rIndex].l || l > tree[rIndex].r)
        return ;

    if (tree[rIndex].M <= M && tree[rIndex].m >= m)
        return ;

    if (l <= tree[rIndex].l && r >= tree[rIndex].r)
    {
        M = max(M, tree[rIndex].M) ;
        m = min(m, tree[rIndex].m) ;
    }

    if (tree[rIndex].l != tree[rIndex].r)
    {
        getMaxAndMin(rIndex << 1, l, r, M, m);
        getMaxAndMin((rIndex << 1) + 1, l, r, M, m);
    }
}

int main(void)
{
    int N, Q ;
    const int ROOT_INDEX = 1 ;
    CreateTree(ROOT_INDEX, 1, 50000) ;
    int in ;
    scanf("%d%d", &N, &Q) ;
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d", &in);
        InsertValue(ROOT_INDEX, i, in);
    }
    for (int i = 0; i < Q; ++i)
    {
        int l, r ;
        int M = minV, m = maxV ;
        scanf("%d%d", &l, &r) ;
        getMaxAndMin(ROOT_INDEX, l, r, M, m) ;
        printf("%d\n", M - m) ;
    }
    return 0 ;
}