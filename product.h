#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[20];
	int weight;
	int price;
    int star;
} Product_1;

int addoProduct_1(Product_1* p); //product를 추가하는 함수
void readProduct_1(Product_1 p); //각 한 개의 product를 출력하는 함수
void listProduct_1(Product_1* m[], int count); //주어진 lsit의 product를 출력하는 함수
int selectDataNo_1(Product_1* p[], int count); //menu 목록 수행 중, 확인이 필요한 경우 사용하는 함수 
int updateProduct_1(Product_1* p); //list에 product를 추가하는 함수
int deleteProduct_1(Product_1* p); //list에 입력된 product를 삭제하는 함수
int selectMenu_1();
