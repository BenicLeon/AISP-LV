#include<stdlib.h>
#include<stdio.h>
#include<time.h>
void gen_arr(float V[], int n, float dg, float gg) {
	int i;
	for (i = 0; i < n; i++) {
		V[i] = (dg)+((float)rand()/(float)(RAND_MAX)*(gg-(dg)));
	}
}
int sekv_pret( float V[], int n, float x ){
    int i;
    for(i=0;i<n;i++){
	
        if(V[i]==x)
        {
            return i;
        }
     }
            return -1;
        
        
            
}
void swap (float *x, float *y) {
 float aux;
 aux = *x;
 *x = *y;
 *y = aux;
}

void sort( float V[], int n ){
    int i, j;
 for (i = 0; i < n-1; i++){
 
 for (j = 0; j < n-1-i; j++){
 
 if (V[j+1] < V[j])
 swap(&V[j], &V[j+1]);
		}
	}
 
}

int bin_pret( float V[], int n, float x ){
    int dg, gg, s;

 dg = 0;
 n=sizeof(V)/sizeof(float);
 gg=n-1;

 while (dg<=gg) {
 s = (dg+gg)/2;

 if (x == V[s]) {
 return s;
 }
 else if (x>V[s]) {
 
 dg = s+1;
}
 else if (x<V[s]) {
 
 gg = s-1;
}
 }
 if (dg>gg) {
 	
 return -1;
}

 }



int main()
{
    srand((unsigned)time(NULL));
    float x,dg,gg;
    int n,i;
    printf("Unesite veličinu polja:"); scanf("%d",&n);
    time_t t1,t2,t3,t4,t5,t6;
    
 float *V=(float*)calloc(n,sizeof(float));

printf("Unesite donju granicu polja:"); scanf("%f",&dg);
printf("Unesite gornju granicu polja:");scanf("%f",&gg);
printf("Unesite trazeni broj polja:"); scanf("%f",&x);

   
    


gen_arr(V,n,dg,gg);
for(i=0;i<n;i++)
    printf("\n%f",V[i]);


t1=clock();
printf("Broj je pronadjen sekvencijalno:%d",sekv_pret(V,n,x));
t2=clock();
printf("\nVrijeme trajanja sekvencijalne pretrage je %dms\n",t2-t1);
t3=clock();
sort(V,n);


t4=clock();
printf("\nVrijeme trajanja sortiranja  je %dms\n",t4-t3);

t5=clock();
printf("Broj je pronaden binarno:%d",bin_pret(V,n,x ));
t6=clock();
printf("\nVrijeme trajanja binarne pretrage je %dms\n",t6-t5);


    return 0;
}