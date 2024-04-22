
#include <stdio.h>
#include <stdlib.h>
#include<string.h>




typedef struct cvor{ 
    char x; 
    struct cvor *left;
    struct cvor *right; 
    
}CVOR;
typedef struct Stack
	{
		int size;
		int top;
		struct cvor* *array;
	}STACK;
	
void ubaci(CVOR *r, CVOR *p){
	if ((r->right == NULL) && (p->x > r->x))
	{ 
	    r->right = p;
	}
	else if ((r->right != NULL) && (p->x > r->x))
	{
	    ubaci(r->right, p);
	    }
		if ((r->left == NULL) && (p->x < r->x)){
		    r->left = p;
		    }
		else if ((r->left != NULL) && (p->x < r->x)){
		    ubaci(r->left, p);
		    }
} 

	int isFull(STACK* stack)
	{
		return stack->top - 1 == stack->size;
	}
	
	int isEmpty(STACK* stack)
	{
		return stack->top == -1;
	}
	
	void push(STACK* stack, CVOR* node)
	{
		if (isFull(stack)){
			return;
		}
		stack->array[++stack->top] = node;
	}
	
	CVOR* pop(STACK* stack)
	{
		if (isEmpty(stack)){
			return NULL;
		}
		return stack->array[stack->top--];
	}
	
	CVOR* peek(STACK* stack)
	{
		if (isEmpty(stack)){
			return NULL;
		}
		return stack->array[stack->top];
	}
	
	STACK* createStack(int size)
	{
		STACK* stack = (STACK*) malloc(sizeof(STACK));
		stack->size = size;
		stack->top = -1;
		stack->array = (CVOR**) malloc(stack->size * sizeof(CVOR*));
		return stack;
	}

	void preOrder(CVOR* root){ 
	    if (root == NULL) 
	    return;  
	    else{ 
	        printf("%c ", root->x);  
	        preOrder(root->left);  
	        preOrder(root->right); 
	        
	    } 
	    
	}


	void inOrder(CVOR* root){ 
	    if (root == NULL) return;  
	    else{ 
	        inOrder(root->left);  
	        printf("%c ", root->x); 
	        inOrder(root->right); 
	        
	    } 
	    
	}

	void postOrder(CVOR* root)
		{
			
			if (root == NULL)
				return;
		
			STACK* stack = createStack(100);
			do
			{
				while (root)
				{
					if (root->right)
						push(stack, root->right);
					push(stack, root);
		
					root = root->left;
				}
		
				root = pop(stack);
		
				if (root->right && peek(stack) == root->right)
				{
					pop(stack); 
					push(stack, root); 
					root = root->right; 
					
				}
				else 
				{
					printf("%c ", root->x);
					root = NULL;
				}
			} while (!isEmpty(stack));
		}



	CVOR* newNode(char znak)
		{
			CVOR* node = (CVOR*) malloc(sizeof(CVOR));
			node->x = znak;
			node->left = node->right = NULL;
			return node;
		}

	int main()
	{
		CVOR* root = NULL;
		root = newNode(76);
		CVOR* slovo2 = newNode(69);
	    CVOR* slovo3 = newNode(79);
		CVOR* slovo4 = newNode(78);
		CVOR* slovo5 = newNode(66);
		CVOR* slovo6 = newNode(69);
		CVOR* slovo7 = newNode(78);
		CVOR* slovo8 = newNode(73);
		CVOR* slovo9 = newNode(67);
	

		ubaci(root, slovo2);
		ubaci(root, slovo3);
		ubaci(root, slovo4);
		ubaci(root, slovo5);
		ubaci(root, slovo6);
		ubaci(root, slovo7);
		ubaci(root, slovo8);
		ubaci(root, slovo9);
		
    printf("preOrder:\n");preOrder(root);
    printf("\ninOrder:\n");inOrder(root);
    printf("\npostOrder:\n");postOrder(root);
	
		return 0;
	}

