# include <stdio.h>
# include <stdbool.h>

bool test(){
	int res;
	printf(" 3 * 5 = ?\n");
	scanf("%d", &res);
	return res == 3*5;
}

int main() {
	while (!test())
	{
		printf(" 3 * 5 = 15!\n");
	} 
	printf("Congratuation! \n");
	return 0;
}