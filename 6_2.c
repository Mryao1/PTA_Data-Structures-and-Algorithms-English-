#include <stdio.h>
#include <stdlib.h>
#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;

typedef struct StackRecord* Stack;
struct StackRecord {
	int Capacity;       /* maximum size of the stack array */
	int Top1;           /* top pointer for Stack 1 */
	int Top2;           /* top pointer for Stack 2 */
	ElementType* Array; /* space for the two stacks */
};

Stack CreateStack(int MaxElements);
int IsEmpty(Stack S, int Stacknum);
int IsFull(Stack S);
int Push(ElementType X, Stack S, int Stacknum);
ElementType Top_Pop(Stack S, int Stacknum);

Operation GetOp();  /* details omitted */
void PrintStack(Stack S, int Stacknum); /* details omitted */

int main()
{
	int N, Sn, X;
	Stack S;
	int done = 0;

	S = CreateStack(5);
	if (!Push(1, S, 1)) printf("Stack %d is Full!\n", 1);
	X = Top_Pop(S, 2);
	if (X == ERROR) printf("Stack %d is Empty!\n", 2);
	if (!Push(11, S, 2)) printf("Stack %d is Full!\n", 2);
	if (!Push(2, S, 1)) printf("Stack %d is Full!\n", 1);
	if (!Push(12, S, 2)) printf("Stack %d is Full!\n", 2);
	X = Top_Pop(S, 1);
	if (X == ERROR) printf("Stack %d is Empty!\n", 1);
	if (!Push(13, S, 2)) printf("Stack %d is Full!\n", 2);
	if (!Push(14, S, 2)) printf("Stack %d is Full!\n", 2);
	if (!Push(3, S, 1)) printf("Stack %d is Full!\n", 1);
	X = Top_Pop(S, 2);
	if (X == ERROR) printf("Stack %d is Empty!\n", 2);
	return 0;
}

/* Your function will be put here */
Stack CreateStack(int MaxElements)		//ע�⵽����ջ��ͬʹ��Max�ռ䣬һ����-1��һ����max�ܺܺõ����ÿռ�
{										//Ҳ���Ժܺõ��ж��Ƿ�����
	Stack s = (Stack)malloc(sizeof(struct StackRecord));
	s->Capacity = MaxElements;
	s->Array = (int*)malloc(sizeof(int) * MaxElements);
	s->Top1 = -1;
	s->Top2 = MaxElements;
	return s;
}
int IsEmpty(Stack S, int Stacknum)
{
	if (S == NULL) return ERROR;
	if (Stacknum == 1)
	{
		if (S->Top1 == -1) return 1;
		else return 0;
	}
	else if (Stacknum == 2) {
		if (S->Top2 == S->Capacity) return 1;
		else return 0;
	}
	else
		return ERROR;
}
int IsFull(Stack S)
{
	if (S == NULL) return ERROR;
	if (S->Top1 + 1 == S->Top2) return 1;
	else return 0;
}
int Push(ElementType X, Stack S, int Stacknum)
{
	if (S == NULL) return 0;
	if (IsFull(S)) return 0;
	if (Stacknum == 1)
	{
		S->Array[++S->Top1] = X;		//ջ1�������ϣ���-1��ʼ����������������ջ
		return 1;
	}
	else if (Stacknum == 2)
	{
		S->Array[S->Top2--] = X;		//ջ2�������ϣ���max��ʼ����������ջ���Լ�
		return 1;
	}
	else return 0;
}
ElementType Top_Pop(Stack S, int Stacknum)
{
	if (S == NULL) return ERROR;
	if (Stacknum == 1)
	{
		if (IsEmpty(S, 1) == 1) return ERROR;
		else {
			return S->Array[S->Top1--];		//��ջ����ջ�෴���ȳ�ջ���Լ�
		}
	}
	else if (Stacknum == 2)
	{
		if (IsEmpty(S, 2) == 1)return ERROR;
		else {
			return S->Array[++S->Top2];		//��ջ����ջ�෴���������ٳ�ջ
		}
	}
}