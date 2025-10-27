#include <stdio.h>
#include <stdlib.h>
typedef struct { int u,v,w; } Edge;
int p[100];
int find(int x)
{ 
	return p[x]==x?x:(p[x]=find(p[x])); 
}
int cmp(const void *a,const void *b)
{ 
	return ((Edge*)a)->w-((Edge*)b)->w; 
}
int main(){
    int V,E;
    printf("Enter the number of vertices: ");
    scanf("%d",&V);
    printf("Enter the number of edges: ");
    scanf("%d",&E);
    Edge e[E];
    printf("Enter each edge as: source destination weight\n");
    for(int i=0;i<E;i++){
        printf("Edge %d: ",i+1);
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    for(int i=0;i<V;i++) 
    	p[i]=i;
    qsort(e,E,sizeof(Edge),cmp);
    int cost=0,c=0;
    printf("\nEdges in the Minimum Spanning Tree:\n");
    for(int i=0;i<E&&c<V-1;i++)
        if(find(e[i].u)!=find(e[i].v)){
            printf("%d -- %d == %d\n",e[i].u,e[i].v,e[i].w);
            cost+=e[i].w; p[find(e[i].u)]=find(e[i].v); c++;
        }
    printf("Total cost of MST: %d\n",cost);
}
Output:
Enter the number of vertices Enter the number of edges: 5 
Enter each edge as: source destination weight Edge 1: e 1 10
  Edge 2: e 2 6
  Edge 3: e 3 5
  Edge 4: 1 3 15 
  Edge 5: 2 3 4
  Edges tn the Minimum Spanning Tree: 1 10 
  Total cost of MST: 19 
