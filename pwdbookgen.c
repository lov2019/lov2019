// 密码本生成程序-by 港南二2322点懂哥

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int bothare(char *s, char a, int c) {
	for (int i=0; i < c; i++){
		if (*(s + i) != a) {
			return 0;
		}
	}
	return 1;
}

void check(char *s, int c) {
	for (int i = 0; i < c - 1; i++) {
		if (*(s + i) > 126) {
			*(s + i) = 33;
			*(s + i + 1) += 1;
		}
	}
}

int main() {
	FILE *book = fopen("password.txt", "a");
	if (!book) {
		printf("打开文件失败!\n");
		return 1;
	}
	char *password;
	char rp[32];
	double completed = 0;
	for(double i = 6; i < 21; i++) {
		password = (char *)malloc(sizeof(char) * i);
		for(int py=0; py < i - 1; py++){
			*(password + py) = 33;
		}
		while (1) {
			completed += 1.0f;
			strcpy(rp, password);
			*(rp + strlen(rp) - 1) = '\0';
			if (bothare(password, 126, i - 1)) {
				fprintf(book, "%s\n", rp);
				break;
			}
			*password += 1;
			check(password, strlen(password));
			fprintf(book, "%s\n", rp);
			printf("\r[ %0f ] %s", completed, rp);
			
		}
		free(password);
	}
	printf("\n");
	fclose(book);
}
