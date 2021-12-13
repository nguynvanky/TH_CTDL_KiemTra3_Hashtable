#include <stdio.h>
#include <iostream>
#define MAXSIZE 15
#define TRUE 1
#define FALSE 0

typedef int ItemType;
struct HashNode {
	ItemType value;
	HashNode* next;
};
int hashFunction_NguyenVanKy(ItemType value);
HashNode* createHashNode_NguyenVanKy(ItemType n);
void initBucket_NguyenVanKy(HashNode**& bucket);
void insert_Random_NguyenVanKy(HashNode**& bucket);
void push_NguyenVanKy(HashNode**& bucket, int value);
void traversBucket_NguyenVanKy(HashNode**& bucket);
int search_NguyenVanKy(HashNode** bucket, ItemType k);
ItemType pop_NguyenVanKy(HashNode** bucket, int id);
void Delete_X_NguyenVanKy(HashNode** bucket, int id, ItemType x);
void Delete_All_NguyenVanKy(HashNode**& bucket);
void menu_NguyenVanKy();

int main()
{
	HashNode** bucket = new HashNode * [MAXSIZE]; // con tro cap 2
	initBucket_NguyenVanKy(bucket);
	int chon, x, id;
	menu_NguyenVanKy();
	do
	{
		printf("chon: ");
		scanf_s("%d", &chon);
		switch (chon)
		{
		case 1:
			do {
				printf("Nhap gia tri muon them: ");
				scanf("%d", &x);
			} while (x < 0);
			push_NguyenVanKy(bucket, x);
			printf("Nhap thanh cong!\n");
			break;
		case 2:
			insert_Random_NguyenVanKy(bucket);
			break;
		case 3:
			traversBucket_NguyenVanKy(bucket);
			break;
		case 4:
			printf("X = ");
			scanf("%d", &x);
			if (search_NguyenVanKy(bucket, x) == TRUE)
			{
				printf("Co ton tai trong bang bam\n");
			}
			else
				printf("khong ton tai trong bang bam\n");
			break;
		case 5:
			printf("Nhap phan tu X muon xoa = ");
			scanf("%d", &x);
			id = hashFunction_NguyenVanKy(x); // hash ra id
			Delete_X_NguyenVanKy(bucket, id, x);
			break;
		case 6:
			Delete_All_NguyenVanKy(bucket);
			break;
		default:
			break;
		}
	} while (chon != 0);

	system("pause");
	return 0;
}
int hashFunction_NguyenVanKy(ItemType value)
{
	return value % MAXSIZE;
}

HashNode* createHashNode_NguyenVanKy(ItemType n)
{
	HashNode* p = new HashNode;
	if (p == NULL)
		return NULL;
	p->value = n;
	p->next = NULL;
	return p;
}

void initBucket_NguyenVanKy(HashNode**& bucket)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		bucket[i] = NULL;
	}
}
// push theo kieu tang dan
void push_NguyenVanKy(HashNode**& bucket, int value)
{
	int id = hashFunction_NguyenVanKy(value);
	HashNode* current = new HashNode;
	current = bucket[id];
	HashNode* previous = NULL;
	HashNode* p = createHashNode_NguyenVanKy(value);
	if (p == NULL)
		return;
	while (current != NULL && current->value < value)
	{
		previous = current;
		current = current->next;
	}
	if (current == NULL && previous == NULL) // bucket empty, thì thêm vào đầu luôn
	{
		bucket[id] = p;
	}
	else if (current == NULL && previous != NULL) // current after previous and previous is tail , ex: 7->NULL; input = 14 => 7->14->NULL;
	{
		if (previous->value != value)
		{
			previous->next = p;
		}
	}
	else if (current != NULL && previous != NULL)// middle ex: 1->22->NULL, input = 11 => 1->11->22->NULL 
	{
		if (current->value != value && previous->value != value) // khong trùng
		{
			previous->next = p;
			p->next = current;
		}
		else
			return;
	}
	else if (current != NULL && previous == NULL)
	{
		if (current->value != value)
		{
			p->next = bucket[id];
			bucket[id] = p;
		}
	}
}
void traversBucket_NguyenVanKy(HashNode**& bucket)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		printf("Bang bam %d: ", i);
		HashNode* p = bucket[i];
		while (p != NULL)
		{
			printf("%d ", p->value);
			p = p->next;
		}
		printf("\n");
	}
}

void insert_Random_NguyenVanKy(HashNode**& bucket)
{
	srand(time(0));
	int n = 0;
	printf("Ban muon nhap bao nhieu phan tu: ");
	scanf("%d", &n);
	int x;
	for (int k = 0; k < n; k++)
	{
		x = rand() % 100;
		push_NguyenVanKy(bucket, x);
	}
}
int search_NguyenVanKy(HashNode** bucket, ItemType k)
{
	int id = hashFunction_NguyenVanKy(k);
	HashNode* p = bucket[id];
	while (p != NULL)
	{
		if (p->value == k)
			return TRUE;
		p = p->next;
	}
	return FALSE;
}

void menu_NguyenVanKy()
{
	printf("1. Nhap 1 so nguyen tu ban phim\n");
	printf("2. Nhap so nguyen random\n");
	printf("3. Xuat cac bang bam\n");
	printf("4. Tim kiem X\n");
	printf("5. Xoa X\n");
	printf("6. Huy tat ca cac phan tu trong hashtable\n");
	printf("0. Thoat\n");
}
ItemType pop_NguyenVanKy(HashNode** bucket, int id) // xóa thằng đầu tiên của bucket[id]
{
	ItemType x;
	x = bucket[id]->value;
	HashNode* p = bucket[id];
	bucket[id] = p->next;
	delete p;
	return x;
}
void Delete_X_NguyenVanKy(HashNode** bucket, int id, ItemType x) // xóa X trong bảng băm
{
	HashNode* pre = bucket[id];
	HashNode* del = NULL;
	for (HashNode* i = bucket[id]; i != NULL; i = i->next)
	{
		if (i->value == x)
		{
			del = i;
			break;
		}
		pre = i;
	}
	if (del == NULL)
	{
		printf("Khong ton tai X!\n");
		return;
	}
	else
	{
		if (del == bucket[id])
			pop_NguyenVanKy(bucket, id);
		else
		{
			pre->next = del->next;
			del->next = NULL;
			delete del;
		}
	}
}
void Delete_All_NguyenVanKy(HashNode**& bucket)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (bucket[i] != NULL)
		{
			while (bucket[i] != NULL)
				pop_NguyenVanKy(bucket, i); // xoa lien tuc thang dau cua bucket[i] cho toi khi no NULL
		}
	}
}