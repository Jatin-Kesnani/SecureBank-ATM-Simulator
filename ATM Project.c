#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
struct database {
	char f_name[50];
	char l_name[50];
	char address[200];
	char phone_no[20];
	char cnic[15];
	char email[100];
	int day, month, year;
	long int balance_amount;
	long long int account_no;
	int pin, verify_pin;
}customer[200];

int main(){
	long long int min=9999999999999999, max=99999999999999999;
	int i=0,y, choice, login_pin, choose_account, wrong_pin=0;
	static int customer_count=0;
	int options;
	char kk;
	long int withdraw_amount=0;
	char receiver_name[50];
	long long int Raccount_number;
	long int transferamount=0, amount=0, deposit_cash=0, bill=0;
	int choice_ser, r;
	long int  max_bill=5000 , min_bill= 1000;	
	int npin, cpin, npin_verify, jjj=4;
	FILE *fp;
	time_t t;

	printf("\n\n\t\t\t\t\tWELCOME TO FAST-NU ATM\n\n");

	printf("\n\n\t\t\t\t\tWhat do you want to do?\n\n");
	printf("\t\t\t\t\t1. Create new account\n");
	printf("\t\t\t\t\t2. Login to your account\n");
	printf("\n\n\t\t\t\t\tEnter your choice: ");
	scanf("%d", &choice);
	system("cls");
	switch(choice){
		case 1:
			fp=fopen("Database.bin", "a");
			if(fp==NULL){
				printf("\nFile not open/found\n");
				exit(0);
			}
			fflush(stdin);
			printf("\n\n\t\t\t\t\tEnter Your First Name \t\t\t:");
			gets(customer[customer_count].f_name);
			fflush(stdin);
			printf("\t\t\t\t\tEnter You Last Name \t\t\t:");
			gets(customer[customer_count].l_name);
			fflush(stdin);
			printf("\t\t\t\t\tEnter Your Address \t\t\t:");
			gets(customer[customer_count].address);
			fflush(stdin);
			printf("\t\t\t\t\tEnter Your Phone Number (MAX LENGTH 11) :");
			for(i=0 ; i<12 ; i++){
				if(i==4)
				{
					printf("-");
					customer[customer_count].phone_no[i] = '-';
				}else{
					customer[customer_count].phone_no[i] = getche();
				}
			}
			fflush(stdin);
			printf("\n\t\t\t\t\tEnter Your CNIC Number (xxxxx-xxxxxxx-x):");
			for(i=0 ; i<15 ; i++){
				if(i==5 || i==13){
					printf("-");
					customer[customer_count].cnic[i]='-';
				}
				else{
					customer[customer_count].cnic[i] = getche();
				}
			}
			fflush(stdin);
			printf("\n\t\t\t\t\tEnter Your Email \t\t\t:");
			gets(customer[customer_count].email);
			printf("\t\t\t\t\tEnter Date of Birth (dd-mm-yyyy) \t:");
			scanf("%d%c%d%c%d",&customer[customer_count].day,&kk,&customer[customer_count].month,&kk,&customer[customer_count].year);
			y = 2021 - customer[customer_count].year;
			if(y<18){
				printf("\n\n\t\t\t\t\tCustomer is under 18! Execute the program again...\n");
				exit(0);
			}
			printf("\t\t\t\t\tEnter The First Deposit Amount \t\t:");
			scanf("%ld",&customer[customer_count].balance_amount);
			printf("\n\n\n\t\t\t\t\tPlease Wait! Automated Account number is being generated!\n\n\n");
			for(i=0 ; i<200000000 ; i++){
				srand(time(NULL));
				customer[customer_count].account_no = rand()% (max-min)+min;
			}
			system("cls");
			printf("\t\t\t\t\tYour Account Number is: %lld\n", customer[customer_count].account_no);
			fscanf(fp, "%lld", &customer[customer_count].account_no);
			Pin_Check:
			printf("\t\t\t\t\tEnter your PIN\t\t\t:");
			scanf("%d",&customer[customer_count].pin);
			printf("\t\t\t\t\tEnter your PIN again to verify\t:");
			scanf("%d",&customer[customer_count].verify_pin);
			if(customer[customer_count].pin == customer[customer_count].verify_pin){
				fscanf(fp, "%d", &customer[customer_count].pin);
				printf("\n\n\t\t\t\t\tThank you! Your Account has been successfully created.\n\n");
			}
			else{
				printf("\n\n\t\t\t\t\tYou have entered incorrect PIN. Kindly enter same PIN.\n\n");
				goto Pin_Check;	
			}
			fwrite(&customer[customer_count], sizeof(struct database), 1, fp);
			
			customer_count++;
			if(fwrite != 0){
		        printf("\t\t\t\t\tContents to file written successfully!\n");
			}
		    else{
		        printf("\t\t\t\t\tError writing File!\n");
			}
			fclose(fp);
			break;
			
		case 2:
			fp=fopen("Database.bin", "r");
			if(fp==NULL){
				printf("\nFile not open/found\n");
				exit(0);
			}
			while(fread(&customer[customer_count], sizeof(struct database), 1, fp)){
				printf("\n\n\t\t\t\t\t(%d) %lld", i, customer[customer_count].account_no);
				
				i++;
			}
			
			printf("\n\n");
			printf("\n\t\t\t\t\tChoose your Account Number: ");
			scanf("%d", &choose_account);
			Again_pin:
			printf("\n\t\t\t\t\tEnter your pin number for this account: ");
			scanf("%d", &login_pin);
			if(login_pin==customer[choose_account].pin){
				goto MyServices;	
			}
			else{
				wrong_pin++;
				if(wrong_pin==3){
					printf("\n\n\t\t\tYOUR ACCOUNT HAS BEEN BLOCKED FOR 24 HOURS! PLEASE VISIT THE BANK TO RE-OPEN OR VISIT AGAIN AFTER 24 HOURS!");
					exit(0);
				}
				customer_count++;
				goto Again_pin;
		}
			break;
		default:
			printf("\n\n\n\t\t\t\t\tIncorrect Choice! Execute the program again...\n\n\n\n");
			exit(0);
	}



	MyServices:
	while(options!=8){
		printf("\n\n\n\t\t\t\t\t(1) Withdraw Cash\t\t(5) Change your pin\n\t\t\t\t\t(2) Transfer fund\t\t(6) Check account balance\n");
		printf("\t\t\t\t\t(3) Deposit Money\t\t(7) Receipt\n\t\t\t\t\t(4) Bill Payments\t\t(8) Log Out\n\n");
	
		printf("\n\nEnter your choice: ");
		scanf("%d", &options);
		switch(options){
			case 1:
				system("cls");
				printf("\t\t\t\t\tHow much ammount you want to withdraw: ");
				scanf("%ld",&withdraw_amount);
				if(withdraw_amount>customer[choose_account].balance_amount){
					printf("\n\n\t\t\t\t\t\"You have insufficent Balance\"");
				}
				else{
					customer[choose_account].balance_amount = customer[choose_account].balance_amount - withdraw_amount;
					printf("\n\t\t\t\t\tRemaining Balance : %ld", customer[choose_account].balance_amount);
				}
				break;
			case 2:
				system("cls");
				fflush(stdin);
				printf("\t\t\t\t\tReceiver Name: ");
				gets(receiver_name);
				printf("\t\t\t\t\tReceiver Account number: ");
				scanf("%lld", &Raccount_number);
				printf("\n\n");
				printf("\t\t\t\t\tEnter the amount you want to transfer: ");
				scanf("%ld", &transferamount);
				customer[choose_account].balance_amount=customer[choose_account].balance_amount - transferamount;
				fscanf(fp, "%ld", &transferamount);
				printf("\n\n\t\t\t\t\t!!!Amount transfered Successfully!!!\n\t\t\t\t\tCurrent balance is: Rs %ld", customer[choose_account].balance_amount);
				break;
			case 3:
				system("cls");
				printf("\t\t\t\t\tEnter your amount you want to deposit in your account: ");
				scanf("%ld", &deposit_cash);
				customer[choose_account].balance_amount = customer[choose_account].balance_amount + deposit_cash;
				printf("\n\t\t\t\t\t!!!Cash Deposited Successfully!!!");
				printf("\n\n\t\t\t\t\tYour new balance is: %ld", customer[choose_account].balance_amount);
				break;
			case 4:
				printf("\n\n\t(1) For electricity  \n\t(2) For Gas \n\t(3) For Internet \n\t(4) For Telephone");
				printf("\n\n\tEnter the choice: ");
				scanf("%d",&choice_ser);
				switch(choice_ser){
					case 1:
						system("cls");
						printf("\t\t\t\t\tEnter the Reference Number: ");
						scanf("%d",&r);
						srand(time(NULL));
						bill = 	rand() % (max_bill-min_bill)+min_bill;
						printf("\n\t\t\t\t\tYour Total bill amount %ld is due",bill);
						if(bill>customer[choose_account].balance_amount){
							printf("\n\t\t\t\t\tYou have insufficient balance to pay your bill.");
						}
						else{
							char wish;
							printf("\n\t\t\t\t\tDo you wish to pay the bill (Y/N) : ");
							scanf(" %c",&wish);
							if(wish=='Y' || wish=='y'){
								customer[choose_account].balance_amount = customer[choose_account].balance_amount - bill;
								printf("\n\t\t\t\t\tYour Current Balance is: %ld", customer[choose_account].balance_amount);	
							}
							else{
								printf("\n\t\t\t\t\tTHANK YOU !!");
							}
						}	
						break;
					case 2:
						system("cls");
						printf("\t\t\t\t\tEnter the Reference Number: ");
						scanf("%d",&r);
						srand(time(NULL));
						bill= 	rand() % (max_bill-min_bill)+min_bill;
						printf("\n\t\t\t\t\tYour Total bill amount %ld is due",bill);
						if(bill>customer[choose_account].balance_amount){
							printf("\n\t\t\t\t\tYou have insufficient balance to pay your bill.");
						}
						else{
							char wish;
							printf("\n\t\t\t\t\tDo you wish to pay the bill (Y/N) : ");
							scanf(" %c",&wish);
							if(wish=='Y' || wish=='y'){
								customer[choose_account].balance_amount = customer[choose_account].balance_amount - bill;
								printf("\n\t\t\t\t\tYour Current Balance is: %ld", customer[choose_account].balance_amount);	
							}
							else{
								printf("\n\t\t\t\t\tTHANK YOU !!");
							}
						}
						break;
					case 3:
						system("cls");
						printf("\t\t\t\t\tEnter the Reference Number: ");
						scanf("%d",&r);
						srand(time(NULL));
						bill= 	rand() % (max_bill-min_bill)+min_bill;
						printf("\n\t\t\t\t\tYour Total bill amount %ld is due",bill);
						if(bill>customer[choose_account].balance_amount){
							printf("\n\t\t\t\t\tYou have insufficient balance to pay your bill.");
						}
						else{
							char wish;
							printf("\n\t\t\t\t\tDo you wish to pay the bill (Y/N) : ");
							scanf(" %c",&wish);
							if(wish=='Y' || wish=='y'){
								customer[choose_account].balance_amount = customer[choose_account].balance_amount - bill;
								printf("\n\t\t\t\t\tYour Current Balance is: %ld", customer[choose_account].balance_amount);	
							}
							else{
								printf("\n\t\t\t\t\tTHANK YOU !!");
							}		
						}
						break;
					case 4:
						system("cls");
						printf("\t\t\t\t\tEnter the Reference Number: ");
						scanf("%d",&r);
						srand(time(NULL));
						bill= 	rand() % (max_bill-min_bill)+min_bill;
						printf("\n\t\t\t\t\tYour Total bill amount %ld is due",bill);
						if(bill>customer[choose_account].balance_amount){
							printf("\n\t\t\t\t\tYou have insufficient balance to pay your bill.");
						}
						else{
							char wish;
							printf("\n\t\t\t\t\tDo you wish to pay the bill (Y/N) : ");
							scanf(" %c",&wish);
							if(wish=='Y' || wish=='y'){
								customer[choose_account].balance_amount = customer[choose_account].balance_amount - bill;
								printf("\n\t\t\t\t\tYour Current Balance is: %ld", customer[choose_account].balance_amount);	
							}
							else{
								printf("\n\t\t\t\t\tTHANK YOU !!");
							}			
						}
						break;
					default:
						printf("\n\t\t\t\t\tYou currently have no bill due");
						break;
					}
				break;
			case 5:	
					system("cls");
					fp=fopen("Database.txt", "a+");
					if(fp==NULL){
						printf("\nFile not open/found\n");
						exit(0);
					}
					while(jjj!=0){
						printf("\t\t\t\t\tPlease Enter Your Current PIN Code: ");
						scanf("%d", &cpin);
						if(cpin==customer[customer_count].pin){
							printf("\t\t\t\t\tEnter New PIN Code\t\t:");
							scanf("%d", &npin);
							printf("\t\t\t\t\tEnter your New PIN Code again to verify\t:");
							scanf("%d", &npin_verify);
							if(npin==npin_verify){
								customer[customer_count].pin=npin;
								fscanf(fp, "%d", &customer[customer_count].pin);
								printf("\n\n\t\t\t\t\tYou Have Successfully Changed Your PIN Code!");
								break;
							}
							else{
								printf("\n\n\t\t\t\t\tEnter the correct Pin!!!\n\n\n");
							}
						}
						else{
							jjj--;
							printf("\n\n\t\t\t\t\tIncorrect PIN Code! Try Again!\n\t\t\t\t\tYou have %d Tries left...", jjj);
							if(jjj==0){
								printf("\n\n\t\t\tYOUR ACCOUNT HAS BEEN BLOCKED FOR 24 HOURS! PLEASE VISIT THE BANK TO RE-OPEN OR VISIT AGAIN AFTER 24 HOURS!");
							}
						}
					}
				fclose(fp);
				break;
			case 6:
				printf("\n\n\t\t\t\t\tYour current account balance is: %ld\n\n", customer[choose_account].balance_amount);
				break;
			case 7:
				system("cls");
					time(&t);
					t = time(NULL);
   					struct tm tm = *localtime(&t);
					printf("\n\n\t\t\t\t||\t--------------------------------------\t||\n\t\t\t\t||\t\t\t\t\t\t||\n");
					printf("\t\t\t\t||\t\tFAST-NU ATM SYSTEM\t\t||\n\t\t\t\t||\t\t\t\t\t\t||\n");
					printf("\t\t\t\t||\t\t\t\t\t\t||\n\t\t\t\t||\t--------------------------------------\t||\n\t\t\t\t||\t\t\t\t\t\t||\n");
					printf("\t\t\t\t||\tDate Time: %d-%d-%d\t%d:%d:%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
					printf("\t\t||\n\t\t\t\t||\t\t\t\t\t\t||\n\t\t\t\t||\tFull Name\t:%s %s", customer[choose_account].f_name, customer[customer_count].l_name);
					printf("\t\t||\n\t\t\t\t||\tAccount Number\t:%lld\t||", customer[choose_account].account_no);
					printf("\n\t\t\t\t||\tDeposited Amount:%ld\t\t\t||", deposit_cash);
					printf("\n\t\t\t\t||\tWithdrawn Amount:%ld\t\t\t||", withdraw_amount);
					printf("\n\t\t\t\t||\tTransfer Amount\t:%ld\t\t\t||", transferamount);
					printf("\n\t\t\t\t||\tCurrent Balance :%ld\t\t\t||", customer[choose_account].balance_amount);
					printf("\n\t\t\t\t||\t\t\t\t\t\t||\n\t\t\t\t||\tThankyou for Visitng! Have a great day! ||");
				break;
			case 8:
				system("cls");
				printf("\n\n\n\n\t\t\t\t\tPlease wait! Logging out...\n\n\n\n");
				for(i=0 ; i<200000000 ; i++){
					srand(time(NULL));
				}
				system("cls");
				printf("\n\n\n\n\t\t\t\t\tAccount Logged out successfully!\n\n\n\n");
				for(i=0 ; i<200000000 ; i++){
					srand(time(NULL));
				}
				break;
		}
	}
}
