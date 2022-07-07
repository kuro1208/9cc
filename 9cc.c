#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "引数の個数が正しくありません\n");
		return 1;
	}

	char *p=argv[1];
	printf(".intel_syntax noprefix\n");
	printf(".globl _main\n");
	printf("_main:\n");

	printf("  mov rax, %ld\n",strtol(p, &p,10));
	// strtol(char*,char**,int) 
	// strから、long型に変換する。第一引数を第三引数進数に変換。数字でない場合、第二引数char**に格納。読み込んだ数字の次の文字を示す。

	while(*p){
		if(*p=='+'){
				p++;
				printf("  add rax, %ld\n",strtol(p,&p,10));
				continue;
		}
		if(*p=='-'){
				p++;
				printf("  sub rax, %ld\n",strtol(p,&p,10));
				continue;
		}

		fprintf(stderr, "予期しない文字です: '%c'\n", *p);
		return 1;
	}
	printf("  ret\n");
	return 0;
}