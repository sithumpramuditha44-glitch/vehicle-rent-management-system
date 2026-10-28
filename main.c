#include<stdio.h>
#include<time.h>
#include "addvehicle.h"
#include"return.h"
int main(){
	FILE *file3 = fopen("LoggingHistory.txt","a");
	if(file3 == NULL){
		printf("ERROR: Couldn't open the file for writing\n");
	}
	int pw = 12341234;
	int x = 0,state=0;
	
	time_t rawtime;
	struct tm*timeinfo;
	
	time(&rawtime);
	timeinfo = localtime(&rawtime);
		
	do{
		printf("Enter the password :");
		scanf("%d",&pw);
		if(pw==12341234){
			printf("Loggin Successfully...!\n\n");
			printf("\n");
			state = 1;
			break;
		}
		else{
			printf("Unauthorized Loggin\n\n");
		}
		x++;	
	}while(x<3);
	
	if(state==1){
		fprintf(file3,"Authorized loggin...!  date =   time = %s\n",asctime(timeinfo));
		while(1){
			int state;
			printf("\n================================================================================\nVEHICLE RENTAL MANAGEMENT SYSTEM\n================================================================================\n\n");
			printf("1.Add Vehicle\n2.View all vehicles\n3.Rent Vehicle\n4.Return a Vehicle\n5.View File Details\n6.Exit\n");
			printf("\n================================================================================\n\nEnter Your Choice :");
			scanf("%d",&state);
			if(state != 6){
				switch(state){
					case 1:
						addvehicle();
						break;
					case 2:
						viewvehicle();
						break;
					case 3:
						rentvehicle();
						break;
					case 4:
						returnvehicle();
						break;
					case 5:
						file();
						break;
					default:
						printf("\nWrong number:\n--------------------------------------------\n\n");
						break;
				}
			}else{
				break;
			}
		}
	}else{
		printf("Unauthorized people entering and time was recorded:");
		fprintf(file3,"****Unauthorized loggin...!  date =   time = %s****\n",asctime(timeinfo));
	}
	fclose(file3);
}