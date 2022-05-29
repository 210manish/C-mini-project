#include <stdio.h>


typedef struct holder_deets{
	char name[20];
	int pin;
	int age;
	double phone;
	double bal;
}acc_deets;


int main()
{	
	int resp=1,correct=1;
	int action;
	//acc_deets x;

	while(resp)
	{
		printf("Welcome to PESU Bank\n");
		printf("How can we help you today?\n");

		printf("Open new account(1)\t\t");
		printf("Deposit money to your account(2)\n");
		printf("Withdraw money from your account(3)\n");
		scanf("%d",&action);

		while (correct)
		{
			if (action==1 || action==2 || action==3)
			{
				switch (action)
				{
					case 1:
					printf("you have entered %d\n",action);
					break;

					case 2:
					printf("you have entered %d\n",action);
					break;

					case 3:
					printf("you have entered %d\n",action);
					break;
				}
				correct=0;
			}


			else
			{
				printf("Enter a valid option\n");
				scanf("%d",&action);
			}
		}

		correct=1;
			
		printf("Would you like to exit?(0)\n");
		printf("Back to main menu(1)\n");
		scanf("%d",&resp);

	}
	
	printf("Thank you for your time!\n");
	return 0;
}