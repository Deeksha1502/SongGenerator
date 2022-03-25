#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>

#define size 6

//input number of songs n
//input n song names
//these songs have to be inserted into hash table
//insert function creates a new node for the hash table

//input a number from 0 to 9 because size is 10
//the songs stored in that number is returned

struct node
{
    char song[200];
    struct node *next;
};
//declare an array of struct node
struct node *chain[size];

//initialise all elements as null
void init()
{
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}


void insert(char songname[],int N)
{
    int key;
    //create a newnode
    struct node *newNode = malloc(sizeof(struct node));
    strcpy(newNode->song,songname);
    newNode->next = NULL;

    key=N%size;
    
    //check if chain[key] is empty
    if (chain[key] == NULL)
    {
        chain[key] = newNode;
        //printf("Song inserted without collision\n");
    }

    //collision
    else
    {
        //add the node at the end of chain[key].
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
 
    }
}

void print(int num)
{

    printf("This is your generated playlist:\n");
    //to print the hash table
    if(num==6)
    {
        for(int i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp)
        {
            printf("%s -->",temp->song);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    }else
    {
        struct node *temp = chain[num];
        if(temp==NULL) printf("Empty :(\nTry again\n");

        while(temp)
        {
            printf("\t%s\t",temp->song);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main()
{
    init();
    int n,num,key;
    char song[100];

    printf("=======================================================================\n");
    printf("\tWelcome To Playlist Generator\n");
    printf(" A program that tells you which songs to listen to based on your mood!\n");
    printf("======================================================================\n");
    printf("\n");

    printf("How many songs would you like to enter?\n");
    scanf("%d",&n);
    printf("\n");
    //insert n songs in the hash table
    printf("Enter the songs below\n");
    do
    {
        gets(song);
        int val[100],N=0;
        for(int j=0;j<strlen(song);j++)
         {
             val[j]=toupper(song[j])-65;
             N+=val[j];
            }
        insert(song,N);

    }while(n--);
    printf("\n");

    printf("On a scale of 0 to 5 how would you rate your mood? \n");
    scanf("%d",&num);
    if(num>7) printf("Invalid entry.\n");
    else
    //print its corresponding hashed values
    print(num);

    return 0;
}
