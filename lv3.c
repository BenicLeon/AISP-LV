#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef struct stog
{
	int sp;
	int polje[50];
}STOG;

int IsEmpty(STOG* s)
{
	if (s->sp == 0){
		return 1;
	}
	else 
	{
	    return 0;
	}
}

void Clear(STOG* s)
{
	s->sp = 0;
}
void Push(STOG* s, int x)
{
	s->sp =s->sp + 1;
	s->polje[s->sp] = x;
}
int Pop(STOG* s)
{
	int x;
	x= s->polje[s->sp];
	s->sp = s->sp - 1;
	return x;
}
int povrh_stog(STOG* s1, STOG* s2, int a, int b)
{
	int n,m,povrh=0;
	Clear(s1);
	Clear(s2);
	Push(s1, a);
	Push(s2, b);
	
	do
	{
		n = Pop(s1);
		m = Pop(s2);
		if (m == n || m == 0 || n == 1)
		{
			povrh +=  1;
		}
		else
		{
			Push(s1, n - 1);
			Push(s2, m - 1);
			Push(s1, n - 1);
			Push(s2, m);
		}
	} while (IsEmpty(s1) == 0);

	return povrh;
}

int povrh(int n, int m)
{
    int a;
	if (m == n || m==0 || n == 1)
	{
		return 1;
	}
	else
	{
	    a=povrh(n - 1, m - 1) + povrh(n - 1, m);
		return a;
	
	}
}




int main()
{
	STOG *s1, *s2;
	s1 = (STOG*)malloc(sizeof(STOG));
	s2 = (STOG*)malloc(sizeof(STOG));
	int n,m,x;
	time_t t1,t2,t3,t4;
	scanf("%d",&n);
	m=n/2;
	t1 = clock();
	x= povrh(n, m);
	t2 = clock();
	printf("Vrijeme izvrsavanja preko rekurzije: %ldms\n", t2 - t1);
	t3 = clock();
	povrh_stog(s1, s2, n, m);
	t4 = clock();
	printf("Vrijeme izvrsavanja preko stoga: %ldms\n",t4-t3);

	printf("Povrh rekurzija: %d\n", povrh(n, m));
	printf("Povrh stog: %d\n", povrh_stog(s1, s2, n, m));
	
	

	free(s1);free(s2);
	return 0;
}



