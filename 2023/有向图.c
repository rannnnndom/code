//使用一个初值为0的计数器记录K顶点的个数。对图G的每个顶点，根据邻接矩阵计算其出度count和入度flag。若count-flag > 0，则输出该顶点且计数器加1
//最后返回计数器的值。
#define MAXV 100
typedef struct  //图的类型定义 
{
    int numVertices, numEdges; //图的顶点数和有向边数
    char VerticesList[MAXV]; //顶点表，MAXV为已定义常量
    int Edge[MAXV][MAXV]; //邻接矩阵
}MGrapg;

int printVertices(MGrapg G)
{
    int count = 0, flag = 0, res = 0, i, j;
    for(i = 0; i < G.numVertices; i++)
    {
        count = 0;
        flag = 0;
        for(j = 0; j < G.numEdges; j++)
        {
            count += G.Edge[i][j];
            flag += G.Edge[j][i];
        }

        if(count > flag)
        {
            printf("%c", &G.VerticesList[i]);
            res++;
        }
    }

    return res;
}
//时间复杂度O(n2),空间复杂度O(1)