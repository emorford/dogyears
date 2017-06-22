/*
Emily Morford
April 22, 2017
Dog year conversion
Cis 170-03
*/

struct Dogs
{ 
char name[10];     //char *name;  //trying pointer because only one string
int weight;
int age;
char *size;  //why not char size[10] ????
int dogyears;	
};      // need this semi colon!!!!!!!!!!!!!!

 
void calc(struct Dogs emlist[]);

void display(struct Dogs emlist[]);

void sort(struct Dogs emlist[]);




#include  <stdio.h>   
#include  <stdlib.h> //because of exit(0)
#include <string.h>   //for tokenizing string 
int main()       
{
FILE *fp;

struct Dogs emlist[6];

char line[50];

fp= fopen("dogs.csv", "r");

if (fp==NULL)
{
printf("Unable to find the file. Exiting.");
exit(0);
}
	
char *p;  //string pointer
int x=0;
while(fgets(line, 50,fp )!=NULL)
{
	//printf("\n%s\n",line);

p=strtok (line, ",");
strcpy(emlist[x].name,p);              // was emlist[x].name=p;     but had issues
//printf("%s\t\t",emlist[x].name);

p=strtok (NULL, ",");
sscanf(p, "%d", &emlist[x].weight);
//printf("%d\t\t", emlist[x].weight);

p=strtok (NULL, ",");
sscanf(p, "%d", &emlist[x].age);
//printf("%d\t\t\n\n", emlist[x].age);	

x++;
}
calc( emlist);

display(emlist);

sort(emlist);
	
display(emlist);
	
	
	
	return 0;
}

void calc(struct Dogs emlist[6])
{ int x=0;

for (x=0;x<6; x++)
{
		if (emlist[x].weight < 20)
				{
					emlist[x].size="small";

					switch (emlist[x].age)
					{
						case 1:
						emlist[x].dogyears=15;
						break;

						case 2:
						emlist[x].dogyears=15+8;
						break;

						case 3:
						emlist[x].dogyears=15+8 +5;
						break;

						default:
						emlist[x].dogyears=(15+8+5 +((emlist[x].age)-3)*4);
					}
				}
		else if (emlist[x].weight > 50)
				{
					emlist[x].size="large";

					switch (emlist[x].age)
					{
						case 1:
						emlist[x].dogyears=12;
						break;

						case 2:
						emlist[x].dogyears=12+9;
						break;

						case 3:
						emlist[x].dogyears=12+9+8;
						break;

						default:
						emlist[x].dogyears=(12+9+8+ ((emlist[x].age)-3)*7);
					}
				}	
		else  
				{
					emlist[x].size="medium";

					switch (emlist[x].age)
					{
						case 1:
						emlist[x].dogyears=14;
						break;

						case 2:
						emlist[x].dogyears=14+9;
						break;

						case 3:
						emlist[x].dogyears=14+9+7;
						break;

						default:
						emlist[x].dogyears=(14+9+7+ ((emlist[x].age)-3)*5);
					}
				}
				
}
}
									

void sort(struct Dogs emlist[6])
{
/*	char choice;
	
	printf("Would you like to sort the array based on name or size?");
	scanf("%s", &choice);
	if (choice=='name')
	*/
	
	int i,j=0;
	//char *temp;
	struct Dogs temp;
	
 for(i=0; i < 6 ; i++){
        for(j=i+1; j < (6-i); j++)
        {
            if(strcmp(emlist[i].name,emlist[j].name) > 0)
            {
                //strcpy(temp,emlist[i].name);
                //strcpy(emlist[i].name,emlist[j].name);
                //strcpy(emlist[j].name,temp);
                temp = emlist[i];
                emlist[i]=emlist[j];
                emlist[j]=temp;
                
                
            }
        }
    }
}




  /*  for (i = 0; i < 6; i++){
        printf("%s\n", emlist[i].name);
    }
    
    
    
 //   	int i,j=0;
	char *sub;
 for(i=0; i < 6 ; i++){
        for(j=i+1; j < (6-i); j++)
        {
            if(strcmp(emlist[i].size,emlist[j].size) > 0)
            {
                strcpy(sub,emlist[i].size);
                strcpy(emlist[i].size,emlist[j].size);
                strcpy(emlist[j].size,sub);
            }
        }
    }

    for (i = 0; i < 6; i++){
        printf("%s\n", emlist[i].size);
    }
} */




void display(struct Dogs emlist[6])
{
	
	int x =0;
//printf("Dog Name\tWeight\t\tHuman Years\tSize\t\tDog Years\n\n");
printf("Dog Name\tSize\t\tHuman Years\tDog Years\n\n");

for (x=0;x<6; x++)
{
	printf("%s\t\t",emlist[x].name);
	//printf("%d\t\t",emlist[x].weight);
	printf("%s\t\t", emlist[x].size);
	printf("%d\t\t", emlist[x].age);
	printf("%d\t\t", emlist[x].dogyears);

	printf("\n\n");
}
}










