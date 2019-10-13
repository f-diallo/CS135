//Name: calc.c
//Purpose: to write an interactive program that works as a scientific calculator
//Author: Fatima Diallo

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
int cmd=0, T1=0, T2=0, T3=0;
double t1=0.0f, t2=0.0f, t3=0.0f;
//doubp tells if calc is in integer or doubles mode
bool doubp=true;


printf("This program implements a calculator.");

printf("\nOptions:\n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\n");
printf("5 - exp(x)\n6 - log(x)\n7 - toggle calculator type\n8 - exit program\n");
printf("Please enter your option: ");
scanf("%d", &cmd);

while(cmd !=8){
	switch(cmd){
		
		case 1:
			if(doubp==true){
				printf("Enter first term: ");
				scanf("%lf", &t1);
				printf("Enter second term: ");
				scanf("%lf", &t2);
				t3=t1+t2;
				printf("The sum is: %.15lf\n", t3); 
				}
			else if(doubp==false){
				printf("Enter first term: ");
				scanf("%d", &T1);
				printf("Enter second term: ");
				scanf("%d", &T2);
				T3=T1+T2;
				printf("The sum is: %d\n", T3); 
				}
				break;
		case 2:
			if(doubp==true){
				printf("Enter first term: ");
				scanf("%lf", &t1);
				printf("Enter second term: ");
				scanf("%lf", &t2);
				t3=t1-t2;
				printf("The difference is: %.15lf\n",t3);
				}
			else if(doubp==false){
				printf("Enter first term: ");
				scanf("%d", &T1);
				printf("Enter second term: ");
				scanf("%d", &T2);
				T3=T1-T2;
				printf("The difference is: %d\n",T3);
				}
				break;
		case 3:
			if(doubp==true){
				printf("Enter first term: ");
				scanf("%lf", &t1);
				printf("Enter second term: ");
				scanf("%lf", &t2);
				t3=t1*t2;
				printf("The product is: %.15lf\n", t3); 
				}
			else if(doubp==false){
				printf("Enter first term: ");
				scanf("%d", &T1);
				printf("Enter second term: ");
				scanf("%d", &T2);
				T3=T1*T2;
				printf("The product is: %d\n", T3); 
				}
				break;
		case 4:
			if(doubp==true){
				printf("Enter first term: ");
				scanf("%lf", &t1);
				printf("Enter second term: ");
				scanf("%lf", &t2);
				if(t2==0){
					printf("Cannot divide by zero!\n");
					break;}
				t3=t1/t2;
				printf("The quotient is: %.15lf\n", t3); 
				}
			else if(doubp==false){
				printf("Enter first term: ");
				scanf("%d", &T1);
				printf("Enter second term: ");
				scanf("%d", &T2);
				if(T2==0){
					printf("Cannot divide by zero!\n");
					break;}
				T3=T1/T2;
				printf("The quotient is: %d\n", T3); 
				}
				break;
		case 5:
			if(doubp==true){
				printf("Enter term: ");
				scanf("%lf", &t1);
				printf("The result of exp(%lf) is: %.15lf\n", t1, exp(t1));
			}
			else if(doubp==false){
				printf("Cannot calculate with integers.\n");
			}
			break;

		case 6:
			if(doubp==true){
				printf("Enter term: ");
				scanf("%lf", &t1);
				if(t1<0){
					printf("Cannot take the log of that number!\n");
					break;}
				printf("The result of log(%lf) is: %.15lf\n", t1, log(t1));
			}
			else if(doubp==false){
				printf("Cannot calculate with integers.\n");
			}
			break;

		case 7:			
			if(doubp==true){
				printf("Calculator now works with integers.\n");
				doubp=false;
				}
			else if(doubp==false){
				printf("Calculator now works with doubles.\n");
				doubp=true;
				}
				break;
		case 8:
			break;
		default: printf("Invalid Option.\n");
			break;
		
	}

		printf("Options:\n1 - addition\n2 - subtraction\n3 - multiplication\n");
		printf("4 - division\n5 - exp(x)\n6 - log(x)\n");
		printf("7 - toggle calculator type\n8 - exit program\n");
		printf("Please enter your option: ");
		scanf("%d", &cmd);


}


return 0;
}
