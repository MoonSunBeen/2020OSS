#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#pragma warning(disable : 4996)

typedef struct {
	char name[20];
	int weight;
	int price;
	int star;
} Product;

int addProduct(Product* p); //product를 추가하는 함수
void readProduct(Product p); //각 한 개의 product를 출력하는 함수
void listProduct(Product* m[], int count); //주어진 lsit의 product를 출력하는 함수
int selectDataNo(Product* p[], int count); //menu 목록 수행 중, 확인이 필요한 경우 사용하는 함수 
int updateProduct(Product* p); //list에 product를 추가하는 함수
int deleteProduct(Product* p); //list에 입력된 product를 삭제하는 함수
void saveData(Product* p[], int count);
int loadData(Product* p[]);
void searchName(Product* p[], int count);
int selectMenu();
