//#include <iostream>
//#include <stdio.h>
//#include <conio.h>
//#include <Windows.h>
//#include <string.h>
//int MAXSIZE = 15;
//#define THESHOLD 0.6
//int count = 0;
//int maxCount = MAXSIZE * THESHOLD;
//struct webSite {
//	char tenWeb[12], tenMien[30];
//	int namThanhLap, luotTruyCap;
//};
//void TextColor(int color); // to mau
//typedef webSite ItemType;
//int hashFunction_NguyenVanKy(char* key);
//void initBucket_NguyenVanKy(ItemType*& bucket);
//int P_NguyenVanKy(int i);
//void push_NguyenVanKy(ItemType*& bucket, ItemType value);
//void resize_NguyenVanKy(ItemType*& bucket);
//void insert_File_NguyenVanKy(ItemType*& bucket);
//void in_1_Website_NguyenVanKy(ItemType x);
//void display_NguyenVanKy(ItemType* bucket);
//void nhap_1_Website_NguyenVanKy(ItemType*& bucket);
//int search_NguyenVanKy(ItemType* bucket, char tenMien[]);
//void Xoa_X_NguyenVanKy(ItemType*& bucket, char tenMien[]);
//void backup_NguyenVanKy(ItemType* bucket);
//void menu_NguyenVanKy();
//
//int main()
//{
//	ItemType* bucket = new ItemType[MAXSIZE];
//	char tenMien[30], X[30];
//	int chon, id;
//	initBucket_NguyenVanKy(bucket);
//	menu_NguyenVanKy();
//	do {
//		printf("chon: ");
//		scanf_s("%d", &chon);
//		switch (chon)
//		{
//		case 0:
//			backup_NguyenVanKy(bucket);
//			break;
//		case 1:
//			insert_File_NguyenVanKy(bucket);
//			break;
//		case 2:
//			nhap_1_Website_NguyenVanKy(bucket);
//			break;
//		case 3:
//			display_NguyenVanKy(bucket);
//			break;
//		case 4:
//			printf("Nhap ten mien: ");
//			std::cin.ignore();
//			gets_s(tenMien);
//			id = search_NguyenVanKy(bucket, tenMien);
//			if (id != -1)
//				in_1_Website_NguyenVanKy(bucket[id]);
//			else
//				printf("Khong ton tai ten mien nay\n");
//			break;
//		case 5:
//			printf("Nhap ten mien: ");
//			std::cin.ignore();
//			gets_s(X);
//			Xoa_X_NguyenVanKy(bucket, X);
//			break;
//		default:
//			break;
//		}
//	} while (chon != 0);
//	_getch();
//	return 0;
//}
//int hashFunction_NguyenVanKy(char* key)
//{
//	int n = strlen(key);
//	int s = 0;
//	for (int i = 0; i < n; i++)
//	{
//		s += (int)key[i];
//	}
//	return s % MAXSIZE;
//}
//void initBucket_NguyenVanKy(ItemType*& bucket)
//{
//	for (int i = 0; i < MAXSIZE; i++)
//	{
//		bucket[i].tenMien[0] = '\0';
//	}
//}
//int P_NguyenVanKy(int i)
//{
//	return (i * i + i) / 2;
//}
//
//void resize_NguyenVanKy(ItemType*& bucket)
//{
//	int old = MAXSIZE;
//	MAXSIZE = MAXSIZE * 2;
//	maxCount = MAXSIZE * THESHOLD;
//	ItemType* newBucket = new ItemType[MAXSIZE];
//	initBucket_NguyenVanKy(newBucket);
//	count = 0;
//	for (int i = 0; i < old; i++)
//	{
//		if (bucket[i].tenMien[0] != '\0')
//			push_NguyenVanKy(newBucket, bucket[i]);
//	}
//	delete bucket;
//	bucket = newBucket;
//}
//
//void push_NguyenVanKy(ItemType*& bucket, ItemType value)
//{
//	int id = hashFunction_NguyenVanKy(value.tenMien);
//	int res = id;
//	int i = 1;
//	while (bucket[id].tenMien[0] != '\0')
//	{
//		if (_strcmpi(bucket[id].tenMien, value.tenMien) == 0)
//		{
//			printf("Ten mien da ton tai\n");
//			return;
//		}
//		id = (res + i) % MAXSIZE;
//		i++;
//	}
//	bucket[id] = value;
//	count++;
//	if (count > maxCount) // vuot nguong cho phep thi resize
//		resize_NguyenVanKy(bucket);
//
//}
//
//void insert_File_NguyenVanKy(ItemType*& bucket)
//{
//	FILE* f;
//	fopen_s(&f, "websites.txt", "rt");
//	if (!f)
//		return; // NULL
//	int n;
//	ItemType value;
//	fscanf(f, "%d\n", &n);
//	for (int i = 0; i < n; i++)
//	{
//		fscanf(f, "%[^-]-%[^-]-%d-%d\n", &value.tenWeb, &value.tenMien, &value.namThanhLap, &value.luotTruyCap);
//		push_NguyenVanKy(bucket, value);
//	}
//	fclose(f);
//}
//void in_1_Website_NguyenVanKy(ItemType x)
//{
//	TextColor(11);
//	printf("================================================================================\n");
//	printf("|%-15s|%-30s|%-10s|%-20s|\n", "Ten web", "Ten mien", "Nam", "Luot truy cap");
//	printf("================================================================================\n");
//	printf("|%-15s|%-30s|%-10d|%-20d|\n", x.tenWeb, x.tenMien, x.namThanhLap, x.luotTruyCap);
//	printf("================================================================================\n");
//	TextColor(7);
//
//}
//void display_NguyenVanKy(ItemType* bucket)
//{
//	for (int i = 0; i < MAXSIZE; i++)
//	{
//		if (bucket[i].tenMien[0] != '\0')
//		{
//			printf("bucket[%d]: \n", i);
//			in_1_Website_NguyenVanKy(bucket[i]);
//		}
//		else
//		{
//			printf("bucket[%d]: ", i);
//			TextColor(13);
//			printf("NULL\n");
//			TextColor(7);
//
//		}
//	}
//}
//void nhap_1_Website_NguyenVanKy(ItemType*& bucket)
//{
//	ItemType x;
//	std::cin.ignore(); // tuong tu fflush(stdin)
//	printf("Ten web: ");
//	gets_s(x.tenWeb);
//	printf("Ten mien: ");
//	gets_s(x.tenMien);
//	printf("Nam thanh lap: ");
//	scanf("%d", &x.namThanhLap);
//	printf("Luot truy cap: ");
//	scanf("%d", &x.luotTruyCap);
//	push_NguyenVanKy(bucket, x);
//}
//int search_NguyenVanKy(ItemType* bucket, char tenMien[])
//{
//	int id = hashFunction_NguyenVanKy(tenMien);
//	int res = id;
//	int i = 1;
//	while (bucket[id].tenMien[0] != '\0')
//	{
//		if (strcmpi(bucket[id].tenMien, tenMien) == 0)
//		{
//			return id;
//		}
//		id = (res + i) % MAXSIZE;
//		i++;
//	}
//	if (strcmpi(bucket[id].tenMien, tenMien) == 0)
//	{
//		return id;
//	}
//	else
//		return -1;
//}
//void Xoa_X_NguyenVanKy(ItemType*& bucket, char tenMien[])
//{
//	int id = hashFunction_NguyenVanKy(tenMien);
//	int res = id;
//	int i = 1;
//	while (bucket[id].tenMien[0] != '\0')
//	{
//		if (strcmpi(bucket[id].tenMien, tenMien) == 0)
//		{
//			bucket[id].tenMien[0] = '\0';
//			return;
//		}
//		id = (res + i) % MAXSIZE;
//		i++;
//	}
//	if (strcmpi(bucket[id].tenMien, tenMien) == 0)
//	{
//		bucket[id].tenMien[0] = '\0';
//		return;
//	}
//	else
//		printf("Khong ton tai ten mien nay\n");
//}
//void backup_NguyenVanKy(ItemType* bucket)
//{
//	FILE* f;
//	fopen_s(&f, "websites.txt", "wt");
//	if (!f)
//		return; // NULL
//	fprintf(f, "%d", count);
//	for (int i = 0; i < MAXSIZE; i++)
//	{
//		if (bucket[i].tenMien[0] != '\0')
//			fprintf(f, "\n%s-%s-%d-%d", bucket[i].tenWeb, bucket[i].tenMien, bucket[i].namThanhLap, bucket[i].luotTruyCap);
//	}
//	fclose(f);
//}
//void menu_NguyenVanKy()
//{
//	printf("1. Nhap du lieu tu file txt\n");
//	printf("2. Nhap du lieu tu ban phim\n");
//	printf("3. Xuat du lieu\n");
//	printf("4. Tim kiem thong tin bang ten mien\n");
//	printf("0. Sao luu va thoat!\n");
//}
//void TextColor(int color)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
//}
