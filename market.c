#include "product.h"

int main(void) {


	Product_1* pp[100];
	int curcount = 0, menu;
	int count = 0;
    
    curcount = loadData(pp);
	count = curcount;

	while (1) {
		menu = selectMenu();
		if (menu == 0) break;
		if (menu == 1) {
		    listProduct(pp, curcount);
		}
		else if (menu == 2) {
			pp[curcount] = (Product*)malloc(sizeof(Product));
			addProduct(pp[curcount]);
			curcount = curcount + 1;
			count = count+1;
		}
		else if (menu == 3) {
			int no = selectDataNo(pp, curcount);
			if (no == 0) {
				printf("=> 취소되었습니다\n");
				continue;
			}
			updateProduct(pp[no - 1]);
		}
		else if (menu == 4) {
			int no = selectDataNo(pp, curcount);
			if (no == 0) {
				printf("=> 취소되었습니다!\n");
				continue;
			}

			int deleteok;
			printf("정말로 삭제하시겠습니까?(삭제 :1) ");
			scanf("%d", &deleteok);
			if (deleteok == 1) {
				if (pp[no - 1]) free(pp[no - 1]);
				pp[no - 1] = NULL;
			}
			else {
				printf("삭제하지 않겠습니다.\n");
			}
		}

	}
	printf("종료됨!\n");
	return 0;
}

