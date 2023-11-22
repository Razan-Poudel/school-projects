#include<stdio.h>


void add(){

FILE* fp;
fp=fopen("class12.dat","w");

 	int roll,clas,age;
 	char name[20],a;

 while (a!='n'){
 
//take input from the user
 	printf("Enter the roll number: ");
 	scanf("%d",&roll);

 	printf("Enter the class: ");
 	scanf("%d",&clas);

 	printf("Enter the age of student: ");
 	scanf("%d",&age);

	 while ((getchar()) != '\n');  //to prevent buffer overflow

 	printf("Enter the name of the student: ");
 	fgets(name,30,stdin);
 	

 	
//write the data into the file
 	fprintf(fp, "%d %d %d %s",roll,clas,age,name);

//ask for confirmation
 	printf("Do you want to continue?(Y/n) ");
 	scanf("%c",&a);

 	//decoration :)
 	printf("\n");
 }


fclose(fp);

	}




void read(int agelimit){
	
	FILE* fp;
	fp=fopen("class12.dat","r");
	

while(!feof(fp)){
	int age,roll,clas;
	char name[30];
	fscanf(fp,"%d",&roll);
	fscanf(fp,"%d",&clas);
	fscanf(fp,"%d",&age);	
	fgets(name,30,fp);

if(age > agelimit){


printf("\nName: %s \n Roll-no: %d \n Class: %d \n Age: %d  \n",name,roll,clas,age);
	}

}


fclose(fp);
}



void deleteroll(){
int targetroll;
printf("Enter the roll number you want to delete: \n");
scanf("%d",&targetroll);

	FILE* old;
	old=fopen("class12.dat","r");

	FILE* neww;
	neww=fopen("temp.dat","w");

while(!feof(old)){
	int roll,clas,age;
	char name[30];
	//scan data from old file
	fscanf(old,"%d",&roll);	
	fscanf(old,"%d",&clas);
	fscanf(old,"%d",&age);
	fgets(name,30,old);
		

//lookout for target roll no and delete it
if(roll==targetroll){
printf("Deleted data of roll no %d \n",roll);	

}else{
fprintf(neww, "%d %d %d %s",roll,clas,age,name);

}
	

}


fclose(old);
fclose(neww);

//delete old file and rename new file to old file name
 remove("class12.dat");
 rename("temp.dat","class12.dat");





}


   int  main(){
printf("Welcome to the Class Management App \n Please enter any one option \n");
int a=11;
while(a){
printf("1. Display all records \n 2. Display records above age 18 \n 3. Add records \n 4. Delete a record \n 0. Exit \n");
scanf("%d",&a);
switch(a){
	case 1: 
		read(0);
		break;
	case 2:
		read(18);
		break;
	case 3:
		add();
		break;
	case 4:
		deleteroll();
		break;
	default: 
		break;

	}

}




return 0;
   }