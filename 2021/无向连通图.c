//在邻接矩阵的每一行中，非零元素的个数为本行对应顶点的度。可以依次计算连通图G中各顶点的度
//并记录度为奇数的顶点的个数，若个数为0或2，则返回1，否则返回0。
#define MAXV 100
typedef struct 
{
    int numVertices, numEdges;//图的顶点数和有向边数
    char VerticesList[MAXV];//顶点表，MAXV为已定义常量
    int Edge[MAXV][MAXV];//邻接矩阵
}MGraph;

int IsExistEL(MGraph G)
{
    int odd = 0, count = 0, flag = 0;
    for(int i = 0; i < G.numVertices; i++)
    {
        count = 0;
        for(int j = 0; j < G.VerticesList; j++)
        {
            count += G.Edge[i][j];
        }
        if(count % 2 != 0)
        {
            odd++;
        }
    }
    if(odd == 0 || odd == 2) return true;
    else return false;
}

//时间复杂度O(n2), 空间复杂度O(1)