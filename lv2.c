#include <stdio.h>
#include<stdlib.h>
#include<time.h>


int sekvencijalno(int *P, int n, int br)
{
    int i;
	for ( i = 0; i < n; i++)
		if (*(P+i) == br)
		{
		    return i;
		    }
		    
	return -1;
}
typedef struct sllist {
	int br;
	struct sllist *nextnode;
} SLLIST;

SLLIST *headnode=NULL;

void insert_node(int treaversenode) {
	SLLIST *n;
	 n= (SLLIST*)malloc(sizeof(SLLIST));
	n->br = treaversenode;
	n->nextnode = headnode;
	headnode = n;
}
int sekvencijalno_lista(SLLIST *treaversenode, int n, int trazeni)
{
	while(treaversenode != NULL){
	    		if (treaversenode->br == trazeni)
	    		{
	    		    return treaversenode->br;
	    		}

	    treaversenode = treaversenode->nextnode;
	}
	return -1;
}

int main()
{
    srand((unsigned)time(NULL));
    int i,*p,n,br;
    time_t t1,t2,t3,t4,t5,t6,t7,t8;
    scanf("%d",&n);
    scanf("%d",&br);
    t1=clock();
    p=(int*)malloc(n*sizeof(int));
    
    for(i=0;i<n;i++)    
        {
            *(p+i)=rand()%10;
           
        }
        t2=clock();
       
    
    printf("\nVrijeme generiranja polja je:%ldms\n",t2-t1);
    t3 = clock();
printf("Rezultat sekvencijalnog za polje:%d",sekvencijalno(p, n,br));
	
	t4 = clock();
	printf("\nSekvencijalno za niz %ldms\n", t4 - t3);
t5=clock();
 for(i=0;i<n;i++)    
        { 
            insert_node(*(p+i));
            
        }
        t6=clock();
     printf("\nVrijeme generiranja povezane liste je:%ldms\n",t6-t5);
   	t7 = clock();
   	printf("Rezultat sekvencijalnog za listu:%d",sekvencijalno_lista(headnode, n,br));
t8=clock();
	printf("\nSekvencijalno za listu %ldms\n", t8 - t7);
free(p);
    return 0;
}
