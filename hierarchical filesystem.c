/*A filesystem is present, where each directory consist of other directories, which subsequently can contain other directories
 or file. Uptil level n, such hierarchy is present. In order to search a particular file, directories needs to be traversed.  
 Starting at an some randon directory, you can find all of the elements in the directory. In a recursive algorithm if, 
 upon find a subdirectory element, you descend to that subdirectory immediately to continue the search rather or  you 
 finding all elements at each directory before descending to any subdirectory. In order to design this model what can be 
 efficient and how. Implement the given model.*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct mfd
{
    char Na_U[10];
    int Num_d;

    struct ufd
    {
        char Na_d[10];
        int Num_f;
        char p[10][10];
    }d[10];

}Usr[10];

int Num_U;

void create(int n)
{
    int i,j;
    printf("\nEnter A Name Of User :\n");
    fflush(stdin);
    scanf("%s",Usr[n].Na_U);

    printf("\nEnter Number Of Directories For User %s: ",Usr[n].Na_U);
    scanf("%d",&Usr[n].Num_d);

    for(i=0;i<Usr[n].Num_d;i++)
    {
        printf("\nEnter Name of Dir-%d : ",i+1);
        fflush(stdin);
        scanf("%s",Usr[n].d[i].Na_d);

        printf("\nEnter Number Of Files: ");
        scanf("%d",&Usr[n].d[i].Num_f);

        printf("\nEnter the Name of File: ");
        for(j=0;j<Usr[n].d[i].Num_f;j++)
        {
            printf("%d- ",j+1);
            fflush(stdin);
            scanf("%s",Usr[n].d[i].p[j]);
        }
    }
    printf("\n");
}

void display(int N)
{
   int i,j,k;

   for(i=0;i<N;i++)
   {
       printf("\n<User>%s",Usr[i].Na_U);
       for(j=0;j<Usr[i].Num_d;j++)
       {
           printf("\n\t<Dir> %s \n\t Files : ",Usr[i].d[j].Na_d);

           for(k=0;k<Usr[i].d[j].Num_f;k++)
           {
               printf("%d - %s",k+1,Usr[i].d[j].p[k]);
           }
       }
   }
   printf("\n\n");
}

void Search()
{
    char s[100];
    printf("Enter The Name You Want to Find\n");
    scanf("%s",s);
    int i,j,k;
    for(i=0;i<Num_U;i++)
    {
        for(j=0;j<Usr[i].Num_d;j++)
        {
            if(strcmp(Usr[i].d[j].Na_d,s))
            {
                for(k=0;k<Usr[i].d[j].Num_f;k++)
                {
                    if(!strcmp(Usr[i].d[j].p[k],s))
                    {
                        printf("\n<User>%s",Usr[i].Na_U);
                        printf("\n\t<Dir> %s \n\t Files : ",Usr[i].d[j].Na_d);
                        printf("%d - %s\n",k+1,Usr[i].d[j].p[k]);
                    }
                    
                }
            }
            else
            {
                printf("\n<User>%s",Usr[i].Na_U);
                printf("\n\t<Dir> %s \n\t Files : ",Usr[i].d[j].Na_d);
            }
            
        }   
    }
}
void main()
{
    int i;
    int c=0; 
    start:
    if(c==0)
    {

    printf("1. Create Whole Structure\n");
    printf("2.Search\n");
    printf("3.Display\n");
    printf("4. Exit\n");

    }
    else if (c==1)
    {
        printf("\n2.Search\n");
        printf("3.Display\n");
        printf("4. Exit\n");
    }

    int choice=0;
    printf("Enter The Choice\n");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
    {
        printf("\nEnter Number of User: ");
        scanf("%d",&Num_U);

        for(i=0;i<Num_U;i++)
        {
        create(i);
        }
        c=1;
        goto start;
        break;
    }
    case 2:
    {
        Search();
        goto start;
        break;
    }
    case 3:
    {
        display(Num_U);
        goto start;
        break;
    }
    case 4:
    {
        printf("THANK YOU!!!!\n19BCE233\tGaurav Sakariya");
        exit(0);
        break;
    }
    default:
        {
            printf("Enter Valid Choice!!!!");
            goto start;
        }
    }
    
}