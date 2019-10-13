//Name: complex_calculator.c
//Purpose: to calculate with user input, pointers, and functions
//Author: Fatima Diallo

#include <stdio.h>


void add(float real_part_1, float imaginary_part_1, float real_part_2, float imaginary_part_2, float* real_result, float* imaginary_result);

void subtract(float real_part_1, float imaginary_part_1, float real_part_2, float imaginary_part_2, float* real_result, float* imaginary_result);

void multiply(float real_part_1, float imaginary_part_1, float real_part_2, float imaginary_part_2, float* real_result, float* imaginary_result);

void read_num(float *real_part, float *imaginary_part);

void read_nums(float* real_part_1, float* imaginary_part_1, float* real_part_2, float* imaginary_part_2);

void print_complex(float real_part, float imaginary_part);

void divide(float real_part_1, float imaginary_part_1, float real_part_2, float
imaginary_part_2, float* real_result, float* imaginary_result);



int main(void)
{

int option;
float real_part_1, imaginary_part_1, real_part_2, imaginary_part_2;
float* real_result,* imaginary_result;

printf("Complex Number Arithmetic Program:\n");

do
{
	printf("1) Add two complex numbers\n");
	printf("2) Subtract two complex numbers\n");
	printf("3) Multiply two complex numbers\n");
	printf("4) Divide two complex numbers\n");
	printf("5) Quit\n");
	printf("Choose an option (1 - 5): ");
	scanf("%d", &option);	
	
	switch(option){
		case 1:
			add(real_part_1, imaginary_part_1, real_part_2, imaginary_part_2, real_result, imaginary_result);
			break;
		case 2:
			subtract(real_part_1, imaginary_part_1, real_part_2, imaginary_part_2, real_result, imaginary_result);
			break;
		case 3:
			multiply(real_part_1, imaginary_part_1, real_part_2, imaginary_part_2, real_result, imaginary_result);
			break;
		case 4:
			divide(real_part_1, imaginary_part_1, real_part_2, imaginary_part_2, real_result, imaginary_result);
			break;
		case 5:
			printf("Bye!\n");
			break;
		default:
			printf("Please input a valid menu option\n");
			break;
		}
}
while(option !=5);



return 0;
}

//Option 1: Read in two imaginary numbers, add them together, and print out the result
void add(float real_part_1, float imaginary_part_1, float real_part_2, float imaginary_part_2, float* real_result, float* imaginary_result)
{
float real_part, imaginary_part;


read_nums(&real_part_1, &imaginary_part_1, &real_part_2, &imaginary_part_2);

real_part=real_part_1+real_part_2;
imaginary_part= imaginary_part_1+imaginary_part_2;

real_result=&real_part;
imaginary_result=&imaginary_part;

print_complex(real_part, imaginary_part);

}
//Option 2: Read in two imaginary numbers, subtract the second one from the first, and print the result.
void subtract(float real_part_1, float imaginary_part_1, float real_part_2, float imaginary_part_2, float* real_result, float* imaginary_result)
{
float real_part, imaginary_part;


read_nums(&real_part_1, &imaginary_part_1, &real_part_2, &imaginary_part_2);

real_part=real_part_1-real_part_2;
imaginary_part= imaginary_part_1-imaginary_part_2;

real_result=&real_part;
imaginary_result=&imaginary_part;

print_complex(real_part, imaginary_part);

}
//Option 3: Read in two imaginary numbers, multiply them together, and print the result.
void multiply(float real_part_1, float imaginary_part_1, float real_part_2, float imaginary_part_2, float* real_result, float* imaginary_result)
{
float real_part, imaginary_part;


read_nums(&real_part_1, &imaginary_part_1, &real_part_2, &imaginary_part_2);

real_part=-(imaginary_part_1*imaginary_part_2)+(real_part_1*real_part_2);
imaginary_part=(imaginary_part_1*real_part_2)+(real_part_1*imaginary_part_2);

real_result=&real_part;
imaginary_result=&imaginary_part;

print_complex(real_part, imaginary_part);
// ask about this function
}

//Option 4: Read in two imaginary numbers, divide the first by the second, and print the result.
void divide(float real_part_1, float imaginary_part_1, float real_part_2, float
imaginary_part_2, float* real_result, float* imaginary_result)
{
float real_part, imaginary_part;


read_nums(&real_part_1, &imaginary_part_1, &real_part_2, &imaginary_part_2);

real_part=((real_part_1*real_part_2)+(imaginary_part_1*imaginary_part_2))/((imaginary_part_2*imaginary_part_2)+(real_part_2*real_part_2));

imaginary_part=((imaginary_part_1*real_part_2)-(real_part_1*imaginary_part_2))/((imaginary_part_2*imaginary_part_2)+(real_part_2*real_part_2));

real_result=&real_part;
imaginary_result=&imaginary_part;

print_complex(real_part, imaginary_part);
// ask about this function
}

//These functions appear in other functions.
void read_num(float *real_part, float *imaginary_part)
{
printf("Please type in the real component: ");
scanf("%f", real_part);
printf("Please type the imaginary component: ");
scanf("%f", imaginary_part);
}

void read_nums(float* real_part_1, float* imaginary_part_1, float* real_part_2, float* imaginary_part_2)
{
printf("Reading the first imaginary number...\n");
read_num(real_part_1, imaginary_part_1);

printf("Reading in the second imaginary number...\n");
read_num(real_part_2, imaginary_part_2);
}

//Option 5: Print the message below and end the program
void print_complex(float real_part, float imaginary_part)
{

printf("The operation yields %6.3f + %6.3fi\n", real_part, imaginary_part);

}
