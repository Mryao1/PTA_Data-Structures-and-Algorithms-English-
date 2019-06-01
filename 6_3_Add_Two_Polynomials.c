#include <stdio.h>
#include <stdlib.h>
typedef struct Node* PtrToNode;
struct Node {
	int Coefficient;
	int Exponent;
	PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read(); /* details omitted */
void Print(Polynomial p); /* details omitted */
Polynomial Add(Polynomial a, Polynomial b);

int main()
{
	Polynomial a, b, s;
	a = Read();
	b = Read();
	s = Add(a, b);
	Print(s);
	return 0;
}

/* Your function will be put here */
//ע�ⲻҪ���ϵ����ָ���Ķ�Ӧ��ϵ��������������СʱҲ�Ǻ�����˼��
Polynomial Add(Polynomial a, Polynomial b)
{
	if (!a->Next) return b;
	if (!b->Next) return a;		//һ��Ҫע��a�շ���b��b�շ���a
	Polynomial h = (Polynomial)malloc(sizeof(struct Node));
	PtrToNode pr;
	pr = h;
	h->Next = NULL;
	PtrToNode i, j;
	i = a->Next;
	j = b->Next;
	while (i && j)
	{
		PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
		p->Next = NULL;
		if (i->Exponent > j->Exponent) {
			p->Exponent = i->Exponent;
			p->Coefficient = i->Coefficient;
			i = i->Next;
			pr->Next = p;
			pr = p;
		}
		else if (i->Exponent < j->Exponent) {
			p->Exponent = j->Exponent;
			p->Coefficient = j->Coefficient;
			j = j->Next;
			pr->Next = p;
			pr = p;
		}
		else
		{
			if (i->Coefficient + j->Coefficient) {
				p->Exponent = i->Exponent;
				p->Coefficient = i->Coefficient + j->Coefficient;
				pr->Next = p;
				pr = p;
			}
			i = i->Next;
			j = j->Next;
		}
	}
	while (i) {
		PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
		p->Coefficient = i->Coefficient;
		p->Exponent = i->Exponent;
		p->Next = NULL;
		pr->Next = p;
		pr = p;
		i = i->Next;
	}
	while (j && j->Coefficient != 0) {
		PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
		p->Coefficient = j->Coefficient;
		p->Exponent = j->Exponent;
		p->Next = NULL;
		pr->Next = p;
		pr = p;
		j = j->Next;
	}
	return h;
}

Polynomial Read()
{
	int n;
	scanf("%d", &n);
	Polynomial h = (Polynomial)malloc(sizeof(struct Node));
	h->Next = NULL;
	PtrToNode pr = h;
	while (n--)
	{
		int e, c;
		scanf("%d %d", &c, &e);
		PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
		p->Next = NULL;
		p->Coefficient = c;
		p->Exponent = e;
		pr->Next = p;
		pr = p;
	}
	return h;
}

void Print(Polynomial p)
{
	while (p)
	{
		printf("%d %d", p->Coefficient, p->Exponent);
		p = p->Next;
	}
	putchar(10);
}
