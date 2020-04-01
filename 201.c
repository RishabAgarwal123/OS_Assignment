#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
pthread_t tid[3]; 
pthread_mutex_t lock;
int n1, n2;
void studentResource()
{
    printf("Student 1 has Pen \n");
    printf("Student 2 has Paper \n");
    printf("Student 3 has Question Paper \n");
}
  
void* student(void* arg) 

{ 
    pthread_mutex_lock(&lock); 
 	if((n1==2 && n2==3) || (n1==3 && n2==2))
    {
		printf("Student 1 has started\n"); 
    	printf("Student 1 has finished\n"); 
	}
	else if((n1==1 && n2==3) || (n1==3 && n2==1))
	{
		printf("Student 2 has started\n"); 
    	printf("Student 2 has finished\n");
	}
	else if((n1==1 && n2==2) || (n1==2 && n2==1))
	{
		printf("Student 3 has started\n"); 
    	printf("Student 3 has finished\n");
	}
	
    pthread_mutex_unlock(&lock); 
  
    return NULL; 
} 
  
int main(void) 
{ 
    studentResource();
    int i = 0;
    int error;
    for (i = 0; i < 3; i++)
    {
		printf("\nEnter resources on table\n");
		scanf("%d",&n1);
		scanf("%d",&n2);
		if((n1==2 && n2==3) || (n1==3 && n2==2))
		{
            printf("\nTeacher put Paper and Question Paper on Desk \n");
            error = pthread_create(&(tid[0]), NULL, &student, NULL);
            pthread_join(tid[0], NULL);		
		}
		else if((n1==1 && n2==3) || (n1==3 && n2==1))
		{
			printf("\nTeacher put Pen and Question Paper on Desk \n");
            error = pthread_create(&(tid[1]), NULL, &student, NULL);
            pthread_join(tid[1], NULL);	
		}
		else if((n1==1 && n2==2) || (n1==2 && n2==1))
		{
			printf("\nTeacher put Pen and  Paper on Desk \n");
            error = pthread_create(&(tid[2]), NULL, &student, NULL);
            pthread_join(tid[2], NULL);
		}
		else
		{
			printf("Wrong Options Entered");
		}
	}
    pthread_mutex_destroy(&lock); 
  
    return 0; 
} 
