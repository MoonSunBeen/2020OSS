#include "product.h"

int addoProduct_1(Product_1* p) {
	printf("제품명는 ? ");
	scanf(" %[^\n]", p->name);
	printf("그램 수는 ? ");
	scanf("%d", &p->weight);
	printf("가격은 ? ");
	scanf("%d", &p->price);
    printf("별점은 ? ");
	scanf("%d", &p->star);

    printf("=> upload!\n");

	return 1;
}

void readProduct_1(Product_1 p) {
	printf("%10s %5d [g] %5d [원] %2d [star] \n", p.name, p.weight, p.price, p.star);
}

void listProduct_1(Product_1* m[], int count) {
	printf("*******************************************************\n");

	for (int i = 0; i < count; i++) {
		if (p[i] != NULL) {
			printf("%2d ", i + 1);
			readProduct(*p[i]);
		}
	}
	printf("\n");
}

int selectDataNo_1(Product_1* p[], int count) {
	int no;
	listProduct(p, count);
	printf("번호는 (취소 :0)? ");
	scanf("%d", &no);
	return no;
}

int updateProduct_1(Product_1* p) {
	printf("제품명는 ? ");
	scanf(" %[^\n]", p->name);
	printf("그램 수는 ? ");
	scanf("%d", &p->weight);
	printf("가격은 ? ");
	scanf("%d", &p->price);
    printf("별점은 ? ");
	scanf("%d", &p->star);

	printf("=> 수정성공!\n");
	return 1;
}

int deleteProduct_1(Product_1* p) {
	int i = 0;
	for (; i < sizeof(p->name); i++) {
		p->name[i] = '\0';
	}
	p->weight = -1;
	p->price = -1;
    p->star = -1;

	printf("=> 삭제됨!\n");
	return 1;
}

int selectMenu_1() {
	int menu;
	printf("\n*** ProductYaho ***\n");
	printf("1. 메뉴조회\n");
	printf("2. 메뉴추가\n");
	printf("3. 메뉴수정\n");
	printf("4. 메뉴삭제\n");
	printf("0. 종료\n\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d", &menu);
	return menu;
}

