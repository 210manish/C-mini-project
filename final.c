#include <stdio.h>
#include <string.h>

typedef struct holder_deets{
	char name[20];
	int pin;
	int age;
	long int phone;
	float bal;
}acc_deets;



acc_deets acc_open()
{
	acc_deets x;
	int temp_pin;
	int flag3=1;

	printf("Enter your name\n");
	scanf("%[^\n]s",x.name);


	TAB:printf("\nEnter your age\n");
	scanf("%d",&x.age);
	if (x.age<18)
	{
		printf("\nYou are too young to open an account\n");
		goto TAB;
	}
	else
	{
		if (x.age>120)
		{
			printf("\nNot a valid age\n");
			goto TAB;
		}
	}

	TAB1:printf("\nEnter your phone number\n");
	scanf("%ld",&x.phone);
	char ph_len[20];
	sprintf(ph_len,"%ld",x.phone);
	if (strlen(ph_len)!=10)
	{
		printf("\nNot a valid phone number\n");
		goto TAB1;
	}

	while (flag3==1)
	{
		TAB2:printf("\nEnter your secret 4-digit pin\n");
		scanf("%d",&x.pin);
		char pin_len[20];
		sprintf(pin_len,"%d",x.pin);
		if (strlen(pin_len)!=4)
		{
			printf("\nYour pin should have exactly 4 digits\n");
			goto TAB2;
		}

		printf("\nConfirm your secret 4-digit pin\n");
		scanf("%d",&temp_pin);
		flag3=0;
		if (x.pin!=temp_pin)
		{
			flag3=1;
			printf("\nPin not matching\n");
		}

	}	
	printf("\nWe request you to make an initial deposit(min 10000rs)\n");
	scanf("%f",&x.bal);
	while (x.bal<10000)
	{
		printf("\nDeposit an amount more than 10000rs\n");
		scanf("%f",&x.bal);
	}

	return x;
}



void deposit(acc_deets *a)
{
	int temp_pin;
	float amount;
	while (1)
	{
		printf("Enter the pin: ");
		scanf("%d",&temp_pin);
		if (a->pin==temp_pin)
		break;
		else
		printf("Pin unmatched \n");
		continue;
	}
	while(1)
	{	
		printf("Amount to be deposited: ");
		scanf("%f",&amount);
		if(amount>=0)
		{ 
			a->bal=a->bal+amount;
		  	break;
		}
		if (amount<0)
		{ 
			printf("Enter a positive amount:\n");
		  	continue;
		}
	}
	printf("Amount successfully deposited\n");
	printf("Current balance: %.2f\n",a->bal);
}



void withdraw(acc_deets *a)
{
	int temp_pin;
	float amount;
	while (1)
	{
		printf("Enter the pin: ");
		scanf("%d",&temp_pin);
		if (a->pin==temp_pin)
		break;
		else
		printf("Pin unmatched\n");
		continue;
	}
	while (1)
	{	
		printf("Enter the amount to be withdrawn: \n");
		scanf ("%f",&amount);
		if (amount>0)
		{ 
			if (a->bal-amount>10000)
			{
				a->bal=a->bal-amount;
				break;
			}
			else
			{
				printf("Minimum balance must be 10000\n");
				continue;
			}
		}
		else
		{
			printf("Enter a positive amount\n");
			continue;
		}
	}
	printf("Amount successfully withdrawn\n");
	printf("%.2f\n",a->bal);
}




void update(acc_deets* x)
{
	int op;
	LOOP1:printf("Please, Enter your old pin to change the details.\n");
	scanf("%d",&op);
	if(op==x->pin)
	{
		int temp_pin;
		int choice;

		LOOP2:printf("Choose the detail which you want to update\n");
		printf("Name(1)\n");
		printf("Age(2)\n");
		printf("Phone Number(3)\n");
		printf("Pin(4)\n");
		scanf("%d",&choice);

		if (choice==1 || choice==2 || choice==3 || choice==4)
		{
				switch (choice)
				{
					case 1:
					printf("Update your name\n");
					scanf("%[^\n]s",x->name);
					scanf("%s",x->name);
					break;

					case 2:
					TAB3:printf("\nUpdate your age\n");
					scanf("%d",&x->age);
					if (x->age<18)
					{
						printf("\nYou are too young to open an account\n");
						goto TAB3;
					}
					else
					{
						if (x->age>120)
						{
							printf("\nNot a valid age\n");
							goto TAB3;
						}
					}
					break;

					case 3:
					TAB4:printf("\nUpdate your phone number\n");
					scanf("%ld",&x->phone);
					char ph_len[20];
					sprintf(ph_len,"%ld",x->phone);
					if (strlen(ph_len)!=10)
					{
						printf("\nNot a valid phone number\n");
						goto TAB4;
					}
					break;

					case 4:
					LOOP3:printf("\nUpdate secret 4-digit pin\n");
					scanf("%d",&x->pin);
					char pin_len[20];
					sprintf(pin_len,"%d",x->pin);
					if (strlen(pin_len)!=4)
					{
						printf("\nYour pin should have exactly 4 digits\n");
						goto LOOP3;
					}
					printf("\nConfirm your secret 4-digit pin\n");
					scanf("%d",&temp_pin);
					if (x->pin!=temp_pin)
					{
						printf("\nPin not matching\n");
						goto LOOP3;
					}			
					break;
				}
		}
		else
		{
			printf("Enter a valid choice\n");
			goto LOOP2;
		}

		printf("Your account details is successfully changed\n");
		printf("Name:%s\n",x->name);
		printf("Age:%d\n",x->age);
		printf("Phone Number:%ld\n",x->phone);
		printf("Pin:%d\n",x->pin);

	}
	else
	{
		printf("Pin unmatched\n");
		goto LOOP1;
	}
}



void loan(int* pin)
{

	int temp_pin;
	LOOP:printf("Enter your pin\t");
	scanf("%d",&temp_pin);
	if(*pin == temp_pin)
	{
		printf("We in pes bank provide 5 types of loan:-\n");
		printf("(1)Home loan @9%% p.a.\n");
		printf("(2)Car loan @10%% p.a.\n");
		printf("(3)Stuent loan @7%% p.a.\n");
		printf("(4)Business loan @9%% p.a.\n");
		printf("(5)Gold loan @12%% p.a.\n");
		printf("Enter the type of loan you want\n");
		int loan_type,f3=1;
		scanf("%d",&loan_type);
		while(f3)
		{
			if(loan_type>=1 && loan_type<=5)
			{
				float p,r,si,tot;
				int t;
				printf("Enter the amount of loan you want.\n");
				scanf("%f",&p);
				printf("Enter the time period for which you want the loan.\n");
				scanf("%d",&t);
				switch(loan_type)
				{
					case 1:
					r=9; f3 =0; break;
					case 2:
					r=10; f3 =0; break;
					case 3:
					r=7; f3 =0; break;
					case 4:
					r=9; f3 =0; break;
					case 5:
					r=12; f3 =0; break;
				}
				si=p*t*r/100;
				tot = p+si;
				printf("At the end of %d years you will have to pay a maturity value of %.2frs \nWith simple interest %.2frs\n",t,tot,si);
		    }
		    else
		    {
		    	printf("Please enter a valid option\n");
		    	scanf("%d",&loan_type);
		    }

		}
	}
	else
	{
		printf("Pin unmatched\n");
		goto LOOP;
	}

}


void fd(acc_deets* x)
{
	int amount;

	TAB5:
	printf("Enter fixed deposit amount\n");
	scanf("%d",&amount);
	if (amount>x->bal)
	{
		printf("\nEntered amount exceeds balance\n");
		goto TAB5;
	}
	if (amount<1000)
	{
		printf("\nMinimum deposit amount for FD account is 1000rs\n");
		goto TAB5;
	}
	printf("We in pes bank provide 3 interest rates:-\n");
	printf("(1)5%% for 1yr\n");
	printf("(2)5.25%% for 3yrs\n");
	printf("(3)5.50%% for 5yrs\n");
	TAB6:printf("Enter the type of FD account you want\n");
	int choice;
	scanf("%d",&choice);
	if(choice>=1 && choice<=3)
		{
			float r,si,tot;
			int t;
			switch(choice)
			{
				case 1:
				r=5; t=1; break;
				case 2:
				r=5.25; t=3; break;
				case 3:
				r=5.5; t=5; break;
			}
			si=amount*t*r/100;
			tot = amount+si;
			printf("At the end of %d years you will recieve a maturity value of %.2frs \nWith an interest of %.2frs\n",t,tot,si);
	    }
	else
	{
		printf("\nInvalid choice\n");
		goto TAB6;
	}

}




int main()
{	
	int flag1=1,flag2=1;
	int action;
	acc_deets x;

	printf("\n");
	printf("====================\n");
	printf("Welcome to PESU Bank\n");
	printf("====================\n\n");
	printf("We request you to open an account with us before proceeding\n");
	x=acc_open(); //the variable x is a struct which has acc_details
					//use this to program the next functions



	while(flag1==1)
	{
		
		printf("\nHow can we help you today?\n");

		printf("Deposit money to your account(1)\n");
		printf("Withdraw money from your account(2)\n");
		printf("Change your account details(3)\n");
		printf("Apply for a loan(4)\n");
		printf("Apply for a fixed deposit(5)\n");
		scanf("%d",&action);

		while (flag2)
		{
			if (action==1 || action==2 || action==3 || action==4 || action==5)
			{
				switch (action)
				{
					case 1:
					deposit(&x);
					break;

					case 2:
					withdraw(&x);
					break;

					case 3:
					update(&x);
					break;

					case 4:
					loan(&x.pin);
					break;

					case 5:
					fd(&x);
					break;

				}
				flag2=0;
			}


			else
			{
				printf("Enter a valid option\n");
				scanf("%d",&action);
			}
		}

		flag2=1;

		printf("Would you like to exit?(0)\n");
		printf("Back to main menu(1)\n");
		scanf("%d",&flag1);

	}
	printf("Thank you for your time!\n");
	return 0;
}



