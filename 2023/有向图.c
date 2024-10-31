#define MAXV 100
typedef struct  //图的类型定义 
{
    int numVertices, numEdges; //图的顶点数和有向边数
    char VerticesList[MAXV]; //顶点表，MAXV为已定义常量
    int Edge[MAXV][MAXV]; //邻接矩阵
}MGrapg;

int printVertices(MGrapg G)
{
    
}