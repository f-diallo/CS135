//Name:combine_strings.c
//Purpose: to get familiar with command line arguments and dynamic memory allocation
//Author:Fatima Diallo

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int strlength(char *str);

int strcomp(char *str1, char *str2);

char *intersperse(char *str1, char *str2);

char *widen_stars(char *str1, char *str2);


int main(int argc, char *argv[]){

char str1[31], str2[31];
char *result;
char *str[2]={"-i", "-w"};

printf("Please enter a string of maximum 30 characters: ");
scanf("%s", str1);


printf("Please enter a string of maximum 30 characters: ");
scanf("%s", str2);



if(strcomp(argv[1], str[0])==0){
	result=intersperse(str1, str2);
	printf("The combined string is: %s\n", result);
	
}

else if(strcomp(argv[1], str[1])==0){
	
	result=widen_stars(str1, str2);
	printf("The combined string is: %s\n", result);
	
}

free(result);
return 0;
}


//intersperse function
char *intersperse(char *str1, char *str2){

int n, i;
char *combined_string, *begin;


n=strlength(str1)+strlength(str2)+1;


combined_string=malloc(sizeof(char)*n);
begin=combined_string;

for(i=0; i<n; i++){
	if((i%2==0)&&(i!=1)&&(*str1!='\0'))
	{
		*combined_string=*str1;
		combined_string++;
		str1++;
	}
	else if(*str2!='\0')
	{
		*combined_string=*str2;
		combined_string++;
		str2++;
	}
}
*combined_string='\0';

return begin;
}

//widen with stars function
char *widen_stars(char *str1, char *str2){
int n, i;
char *combined_string, *begin;
n=(strlength(str1)+strlength(str2))*2;

combined_string=malloc(sizeof(char)*n);
begin=combined_string;

for(i=0; *str1!='\0'; i++){
	*combined_string=*str1;
	combined_string++;
	str1++;
	*combined_string='*';
	combined_string++;
}



for(i=0; *str2!='\0'; i++){
	*combined_string=*str2;
	combined_string++;
	str2++;
	if(*str2!='\0'){
		*combined_string='*';
		combined_string++;
	}
}

*combined_string='\0';

return begin;
}



//string length function
int strlength(char *str)
{
int length=0;
int i;

for(i=0; str[i]!='\0'; i++)
{

	length++;
}
return length;
}

//string compare function
int strcomp(char *str1, char *str2)
{
int order;


do
{
	if((tolower(*str1))<(tolower(*str2)))//string 1 first alphabetically
		return 1;
	else if((tolower(*str1))>(tolower(*str2)))//string 2 first alphabetically
		return -1;
	*str1++;
	*str2++;
}
while((*str1 != '\0')&&(*str2 != '\0'));


//same


if(*str1==*str2){
	return 0;
}


}

