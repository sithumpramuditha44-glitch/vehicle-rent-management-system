#include<stdio.h>
#include<string.h>
#include"addvehicle.h"
#include"changing.h"
int avilability(int cm,int sm,int avl,char err[300]){
	if((sm - 100)<=cm){
		strcpy(err,"\n-----------------------------------------------------\nThe Service time.\nbecouse of that the availibility is change to '0'\n--------------------------------------------\n");
		return 0;
	}else{
		err[0]='\0';
		return avl;
	}
}

int addvehicle(){
	int tot_vehi=0,cm,sm,x=0,y,t=0;
	char name[20];
	char chassinum[40];
	float charge,kmcharge;
	char err[300];
	int avl;
	
	FILE *file1 = fopen("available.txt","a");
	FILE *file2 = fopen("vehicledetails.txt","a");
	FILE *file3 = fopen("onekmcharge.txt","a");
	
	if(file1 == NULL || file2 == NULL || file3 == NULL){
		printf("ERROR: Couldn't open the file for writing\n");
	}
	fprintf(file2,"Vnum\tname\tvehinum\tchassinum\tcharge\t\tcm\tsm\n\n");
	printf("\nEnter the total count of Vehicle:");
	scanf("%d",&tot_vehi);
	char vehinum[100][20];
	
	int tot_count = 0;
	int num;
	do{
		int num_type = 0;
		printf("\nEnter the vehicle name and count of vehicle types:");
		scanf("%s %d" ,name,&num_type);
		y = 0;
		t = t + num_type;
		
		if(t > tot_vehi){
			printf("Entered vehicle count exceeds the total limit (%d)!\n", tot_vehi);
			t = t-num_type; 
			break;
        } else {
        	printf("Enter the Charge of Vehicle:");
			scanf("%f",&charge);
			printf("Enter the Charge per One Kilo meter :");
			scanf("%f",&kmcharge);
			do{
				printf("Enter the Index of Number:");
				scanf("%d",&num);
				printf("\nEnter the vehicle number :");
				scanf("%s",vehinum[tot_count]);
				int i;
				for(i=0;i<x;i++){
					if(strcmp(vehinum[i],vehinum[tot_count])==0){
						printf("You entered this vehicle number previously");
					}
				}
				printf("\nEnter the chassi number :");
				scanf("%s",chassinum);
				printf("\nCurrent meter value(km):");
				scanf("%d",&cm);
				printf("\nService meter value(km):");
				scanf("%d",&sm);
				printf("\nAvailibility (If available = 1 , Not = 0) :");
				scanf("%d",&avl);	
				printf("\n-------------------------------------------------------\n");
				avl = avilability(cm,sm,avl,err);
				printf("%s",err);
				fprintf(file1,"%d\t%s\t%s\t%d\t%d\t%d\n",num,name,vehinum[tot_count],cm,sm,avl);
				fprintf(file3,"%d\t%.2f",num,kmcharge);
				fprintf(file2,"%d\t%s\t%s\t%s\tRs:%.2f\t%d\t%d\n",num,name,vehinum[tot_count],chassinum,charge,cm,sm);
				tot_count++;
				y++;
			}while(y<num_type);
		}
		fprintf(file1,"\n--------------------------------------------------------\n");
		fprintf(file2,"\n--------------------------------------------------------\n");
		x++;
	}while(x<tot_vehi);
	fclose(file1);
	fclose(file2);
	fclose(file3);
	return 0;
}
