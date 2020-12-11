//Write a program to identify does a grammar is left recursive or right recursive
#include<stdio.h>  
#include<string.h>  
#define SIZE 20 
int main () 
{  
    char non_terminal;  
    char beta,alpha;  
    int num;  
    char production[10][SIZE];  
    int index=3; /* starting of the string following "->" */  
    printf("=== Program to check whether the given grammar is left recursive or right recursive grammar ===\n");
    printf("Enter Number of Production : ");  
    scanf("%d",&num);  
    printf("Enter the grammar as E->E-A :\n");  
    for(int i=0;i<num;i++)
    {
        scanf("%s",production[i]);  
    }  
    for(int i=0;i<num;i++){  
    printf("\nGRAMMAR ===> %s",production[i]);  
    non_terminal=production[i][0];  
    if(non_terminal==production[i][index]) 
    {  
    printf("  is left recursive.\n"); 
    }
    else
    {
        printf("  not left recursive\n");
    }
    }
    int n=0,flag_s[num];
    int index_s[num];
    for(int i=0;i<num;i++)
    {
        flag_s[i]=0;
        index_s[i] =-1;
        n = strlen(production[i]);
        for(int j=0;j<n;j++)
        {
            if(production[i][j] == '|')
            {
                index_s[i] = j-1;
                flag_s[i]=1;
            }
        }   
    }
    for(int i=0;i<num;i++)
    {
        n = strlen(production[i]);
        printf("\nGRAMMAR ===> %s",production[i]);
        non_terminal=production[i][0]; 
        if(flag_s[i]==1)
        {
            if(non_terminal == production[i][index_s[i]] || non_terminal == production[i][n-1])
            {
                printf("  is right recursive\n");
            }
            else
            {
                printf("  not right recursive\n");
            }  
        }
        else
        {
            if(non_terminal == production[i][n-1])
            {
               printf(" is right recursive\n");
            }
            else
            {
                printf(" not right recursive\n");
            } 
        }
    }      
return 0;
}
    
