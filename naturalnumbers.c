#include <stdio.h>

void using_dowhile_loop(int n);
void using_for_loop(int n);
void using_while_loop(int n);

int main(void)
{	
    int n, choice;
	printf("n = ");
	scanf("%d",&n);
	
	printf("1. do...while\n2. for\n3. while\nchoice >> ");
	scanf("%d", &choice);
	
	if (choice == 1) using_dowhile_loop(n);
	else if (choice == 2) using_for_loop(n);
	else if (choice == 3) using_while_loop(n);
	
	return 0;
}

void using_dowhile_loop(int n)
{
	int i = 0;
	
	printf("Natural numbers from 1 to %d (using do...while loop): \n", n);
	
	do {
		i++;
		printf("%d ",i);
	} while (i < n);

}

void using_for_loop(int n)
{
	printf("Natural numbers from 1 to %d (using for loop): \n", n);
	
	for (int i = 0; i<=n; i++)
	printf("%d ", i);
}

void using_while_loop(int n)
{
	int i = 0;
	
	printf("Natural numbers from 1 to %d (using while loop): \n", n);
	
	while (i < n) {
		i++;
		printf("%d ", i);
	}
}

