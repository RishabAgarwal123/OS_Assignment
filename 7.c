#include<stdio.h>
#include<sys/time.h>

int main()
{
	int i,n, value[10],type[100];
    time_t user_input_time, input_start, input_end;
    
    
    printf("Number of process: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		{			
				 input_start = time(NULL);
				printf("Enter any no: ",i);
				scanf("%d",&value[i]);
				input_end = time(NULL);
    			user_input_time = input_end - input_start;
    			printf("User Input Time : %d second\n",user_input_time);
				if(user_input_time<1)
				{
					type[i]=1;
				}
				else
				{
					type[i]=0;
				}
				
		}
	printf("Process Number\tResponse Time\tType\t\tPriority");
	for(i=0;i<n;i++)
	{
		printf("\n P%d \t\t %dms\t\t",i,value[i]);
		if(type[i]==1)
		{
			printf("Interactive \tHigh");
		}
		else
		{
			printf("Non-Interactive\tLow");
		}
	}
}

   

   
    
    
	
