#include "manager.h"

int addProduct(Product* p) {
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

void readProduct(Product p) {
	printf("%10s %5d [g] %5d [원] %2d [star] \n", p.name, p.weight, p.price, p.star);
}

void listProduct(Product* p[], int count) {
	printf("*******************************************************\n");

	for (int i = 0; i < count; i++) {
		if (p[i] != NULL) {
			printf("%2d ", i + 1);
			readProduct(*p[i]);
		}
	}
	printf("\n");
}

int selectDataNo(Product* p[], int count) {
	int no;
	listProduct(p, count);
	printf("번호는 (취소 :0)? ");
	scanf("%d", &no);
	return no;
}

int updateProduct(Product* p) {
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

int deleteProduct(Product* p) {
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

int selectMenu() {
	int menu;
	printf("\n*** ProductYaho ***\n");
	printf("1. 메뉴조회\n");
	printf("2. 메뉴추가\n");
	printf("3. 메뉴수정\n");
	printf("4. 메뉴삭제\n");
	printf("5. 파일저장\n");
	printf("6. 파일검색\n");
	printf("0. 종료\n\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d", &menu);
	return menu;
}

void searchName(Product* p[], int count) {
	int scount = 0;
	char search[20];

	printf("원하는 제품명은? ");
	scanf("%s", search);

    printf("*******************************************************\n");

	for (int i = 0; i < count; i++) {
		if (p[i] == NULL) continue;
		if (strstr(p[i]->name, search)) {
			readProduct(*p[i]);
		} scount++;
	}
	if (scount == 0) printf("==> 검색결과 없음!!!\n");

}

void saveData(Product* p[], int count) {
	FILE* fp;

	fp = fopen("product.txt", "w");
	for (int i = 0; i < count; i++) {
		if (p[i] != NULL) fprintf(fp, "%s %d %d %d\n", p[i]->name, p[i]->weight, p[i]->price, p[i]->star);
	}
	fclose(fp);
	printf("==> 저장됨! \n");
}

int loadData(Product* p[]) {
	FILE* fp;

	fp = fopen("product.txt", "r");
	if (fp == NULL) {
		printf("==> 파일이 없습니다!\n");
		return 0;
	}

	int count = 0;
	for (;; count++) {
		p[count] = (Product*)malloc(sizeof(Product));
		fscanf(fp, "%s %d %d %d\n", p[count]->name, &p[count]->weight, &p[count]->price, &p[count]->star);
		if (feof(fp)) break;
	}
	fclose(fp);

	printf("==> 로딩성공!!!\n");
	return count+1;
}
