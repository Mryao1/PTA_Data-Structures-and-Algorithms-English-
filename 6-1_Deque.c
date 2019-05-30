#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node* PtrToNode;
struct Node {
	ElementType Element;
	PtrToNode Next, Last;
};
typedef struct DequeRecord* Deque;
struct DequeRecord {
	PtrToNode Front, Rear;
};
Deque CreateDeque();
int Push(ElementType X, Deque D);
ElementType Pop(Deque D);
int Inject(ElementType X, Deque D);
ElementType Eject(Deque D);

Operation GetOp();          /* details omitted */
void PrintDeque(Deque D); /* details omitted */

int main()
{
	ElementType X;
	Deque D;
	int done = 0;
	D = CreateDeque();
	X = Pop(D);
	if (X == ERROR) printf("Deque is Empty!\n");
	if (!Inject(1, D)) printf("Memory is Full!\n");
	X = Pop(D);
	if (X == ERROR) printf("Deque is Empty!\n");
	X = Eject(D);
	if (X == ERROR) printf("Deque is Empty!\n");
	if (!Push(1, D)) printf("Memory is Full!\n");
	if (!Push(2, D)) printf("Memory is Full!\n");
	X = Eject(D);
	if (X == ERROR) printf("Deque is Empty!\n");
	if (!Inject(3, D)) printf("Memory is Full!\n");
	for (PtrToNode i = D->Front->Next; i != NULL; i = i->Next)
	{
		printf("%d  ", i->Element);
	}

	return 0;
}

/* Your function will be put here */
Deque CreateDeque()
{
	Deque q = (Deque)malloc(sizeof(struct DequeRecord));
	PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
	p->Last = NULL;
	p->Next = NULL;
	q->Front = q->Rear = p;
	return q;
}
int Push(ElementType X, Deque D)
{
	PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
	if (p == NULL)
		return 0;
	p->Element = X;
	PtrToNode t = D->Front->Next;
	if (t == NULL)
	{
		D->Front->Next = p;
		p->Last = D->Front;
		D->Rear = p;
		return 1;
	}
	else
	{
		p->Last = D->Front;
		D->Front->Next = p;
		p->Next = t;
		t->Last = p;
		return 1;
	}
}
ElementType Pop(Deque D)
{
	if (D->Front == D->Rear) return ERROR;
	PtrToNode t = D->Front->Next;
	ElementType e = t->Element;
	if (t->Next == NULL)
	{
		D->Front->Next = NULL;
		D->Front->Last = NULL;
		D->Rear = D->Front;
	}
	else
	{
		D->Front->Next = t->Next;
		t->Next->Last = D->Front;
		free(t);
		return e;
	}
}
int Inject(ElementType X, Deque D)
{
	PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
	if (p == NULL) return 0;
	p->Element = X;
	D->Rear->Next = p;
	p->Last = D->Rear;
	p->Next = NULL;
	D->Rear = p;
	return 1;
}
ElementType Eject(Deque D)
{
	if (D->Front == D->Rear) return ERROR;
	PtrToNode p = D->Rear;
	D->Rear = p->Last;
	p->Last->Next = NULL;
	ElementType e = p->Element;
	free(p);
	return e;
}