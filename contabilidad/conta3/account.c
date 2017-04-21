#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lastid;
int *plastid = &lastid;

int a=1,b=1,c=2,j=0,d=1,f=0,i=0;
char comment[100];
int sourceArray [1][5];
int amountArray [50][2];

//General

struct struct_account {
        int id;
        char account_name [25];
        int account_type;
        int balanceArray [50][2];

        char day [5];
        char month [5];
        int num;
        int year;

        struct struct_account *next;
    }; typedef struct struct_account ACCOUNT;

void print (ACCOUNT *account) {//Print id,name and type
    printf("%d\t", account->id);
    printf("%s\t", account->account_name);
    printf("%d\n", account->account_type);
}

void load_all(ACCOUNT *current) {

    FILE *pFile;
    pFile = fopen("accounts.txt" , "r");
    do{
        fscanf(pFile,"%d %s %d", &current->id, current->account_name, &current->account_type);
        current->next = malloc(sizeof(ACCOUNT));
        current = current->next;
        current->next = NULL;
    }while(!feof(pFile));
    fclose (pFile);
}

void save_all(ACCOUNT *current) {
    FILE *pFile;
    pFile = fopen("accounts.txt" , "w");
    while(current != NULL) {
        fprintf(pFile,"%d\t", current->id);
        fprintf(pFile,"%s\t", current->account_name);
        fprintf(pFile,"%d\n", current->account_type);
        current = current->next;
    } 
    fclose (pFile);           
}

//accounts.txt

/*void print (ACCOUNT *account) {//balanceArray
    printf("%d\t", account->id);
    printf("%s\t", account->account_name);
    printf("%d\n", account->account_type);
    printf("%d %d\n", account->balanceArray[0][1], account->balanceArray[0][2]);
    printf("%d %d\n", account->balanceArray[1][1], account->balanceArray[1][2]);

}*/

/*void load_all(ACCOUNT *current) {//balanceArray

    FILE *pFile;
    pFile = fopen("accounts.txt" , "r");
    do{
        fscanf(pFile,"%d %s %d", &current->id, current->account_name, &current->account_type);
        fscanf(pFile,"%d %d", &current->balanceArray[0][1], &current->balanceArray[0][2]);
        fscanf(pFile,"%d %d", &current->balanceArray[1][1], &current->balanceArray[1][2]);
        current->next = malloc(sizeof(ACCOUNT));
        current = current->next;
        current->next = NULL;
    }while(!feof(pFile));
    fclose (pFile);
}*/

/*void save_all(ACCOUNT *current) {
    FILE *pFile;
    pFile = fopen("accounts.txt" , "w");
    while(current != NULL) {
        fprintf(pFile,"%d\t", current->id);
        fprintf(pFile,"%s\t", current->account_name);
        fprintf(pFile,"%d\n", current->account_type);
        current = current->next;
    } 
    fclose (pFile);           
}*/

/*void save_journal(ACCOUNT *current) {//Add operations made in the Journal to accounts

    printf("%d %s %d \n",current->id,current->account_name,current->account_type);
    printf("%d\t",current->balanceArray[0][1]);
    printf("%d\n",current->balanceArray[0][2]);
    printf("%d\t",current->balanceArray[1][1]);
    printf("%d\n",current->balanceArray[1][2]);
    printf("%d\t",amountArray[1][1]);
    printf("%d\n",amountArray[1][2]);
    current = current->next;
    printf("%d %s %d \n",current->id,current->account_name,current->account_type);       
    printf("%d\t",current->balanceArray[0][1]);
    printf("%d\n",current->balanceArray[0][2]);
    printf("%d\t",current->balanceArray[1][1]);
    printf("%d\n",current->balanceArray[1][2]);
    printf("%d\t",amountArray[1][2]);
    printf("%d\n",amountArray[1][1]);
}*/ 

void print_journal(ACCOUNT *current) {
    a = 1;                
    printf("Date\t\tDescription\t\tRef.\tDebit\tCredit \n");
    printf("Apr %d\t\t%s  \t\t%d\t%d\n",19,current->account_name,current->id,amountArray[a][b]);
                
    do{ 
        a++;                 
        current = current->next;
        printf("      \t\t\t%s\t%d\t\t%d\n",current->account_name,current->id,amountArray[a][b]);                    
    } while(a != f);
    printf("\t\t%s\n",comment);        
}

void print_all(ACCOUNT *current) {
    printf("No.\tAccount\t\tType\n");
    while(current != NULL) {
        print(current);
        current = current->next;
    }
}

void add_account(ACCOUNT* current) {

    while(current->next->next != NULL){
        current = current->next;
    }
        printf("Enter the account ID: ");
        scanf("%d", &lastid);
        if(current->id + 1 == lastid){
            current = current->next;
            current->next = malloc(sizeof(ACCOUNT));    
            current->next->next = NULL;  
            current->id = *plastid;  
            printf("Enter the account name: ");
            scanf("%s", current->account_name);
            printf("Enter the account type: \n");
            printf(" 1. Assets\n 2. Liability\n 3. Equity\n 4. Revenue\n 5. Expense\n");
            scanf("%d", &current->account_type);
        }        
        else{
            printf("This ID already exists or is not the next ID in order\n");
        }
}

/*void make_move(ACCOUNT *current){//Debit or credit logic 
    
    char response[] = "no";
    int source,dest;
    int amountArray [50][2];
    
    printf("Do you want to print all accounts? y/n\n");
    scanf("%s", response);
    if (response[0] == 'y'){
        print_all(current);
    }
    printf("Choose account number: \n");
    scanf("%d",&source);
    printf(" 1. Debit or 2. Credit? \n");
    scanf("%d",&dest);
    
    if (dest == 1) {
        do{
            printf("Enter amount: ");
            scanf("%d",&amountArray[a][b]);
            amountArray[a][c] = 0;
            printf("Want to make other entry? y/n\n");
            scanf("%s", response);
            i++;
            a++;
        }while (response[0] == 'y');
        a = 1;
    
        do{
            if(source == current->id){
                print(current);
            }
            current = current->next;
        }while(source == current->id);

        do{
            printf("%d\t", amountArray[a][b]);
            printf("%d\n", amountArray[a][c]);
            a++;
            j++;
        }while (j < i);
    }

    if (dest == 2) {
        do{
            printf("Enter amount: ");
            scanf("%d",&amountArray[a][c]);
            amountArray[a][b] = 0;
            printf("Want to make other entry? y/n\n");
            scanf("%s", response);
            i++;
            a++;
        }while (response[0] == 'y');
        a = 1;

        do{
            if(source == current->id){
                print(current);
            }
            current = current->next;
        }while(source == current->id);

        do{
            printf("%d\t", amountArray[a][b]);
            printf("%d\n", amountArray[a][c]);
            a++;
            j++;
        }while (j < i);
    }
}*/

void journal(ACCOUNT *current) { 

    char response[] = "no";

    do{
        printf("Do you want to print all accounts? y/n\n");
        scanf("%s", response);
        if (response[0] == 'y'){
            print_all(current);
        }
        printf("Select the debit account number: \n");
        scanf("%d",&sourceArray[1][d]);
        printf("Enter amount: ");
        scanf("%d",&amountArray[a][b]);
        amountArray[a][c] = 0;

        do{
            a++;
            j++;
            d++;
            printf("Select the credit account number: \n");
            scanf("%d",&sourceArray[1][d]);
            printf("Enter amount: ");
            scanf("%d",&amountArray[a][b]); 
            amountArray[a][c] = 0;
            printf("Enter another credit account? y/n\n");
            scanf("%s", response);
        }while(response[0] == 'y');
        f = sourceArray[1][d];
        
        printf("Do you want to add a comment? y/n\n");
        scanf("%s", response);
        if (response[0] == 'y'){
            printf("Comment: \n");
            scanf("%s",comment);
            //save_journal(current);
            print_journal(current);
        }
        
        else{
            //save_journal(current);
            print_journal(current);
        }
        printf("Do you want to make another log?? y/n\n");
        scanf("%s", response);
    }while(response[0] == 'y');
}

void balanceArray() {//matrix ARREGLAR VARIABLES

    int BalanceArray [4][4],i,j,k=1;

    //Stored values into the array
    printf("Input elements in the matrix: \n");
    for(i=1;i<4;i++) {
        for(j=1;j<4;j++) {
            printf("element - [%d],[%d] : ",i,j);
            scanf("%d",&BalanceArray[i][j]);
        }
    }  
    //print all 
    printf("\nThe matrix is : \n\n");
    for(j=1;j<4;j++) {
        printf(" \t%d",k++);
    }
    printf("\n");

    for(i=1;i<4;i++) {
        printf("\n");
        printf("%d\t",i);
        for(j=1;j<4;j++) {
            printf("%d\t",BalanceArray[i][j]);
        }
    }
    
    //print balance
    BalanceArray[3][1]=BalanceArray[3][1] - BalanceArray[3][1] - BalanceArray[3][1];
    BalanceArray[3][2]=BalanceArray[3][2] - BalanceArray[3][2] - BalanceArray[3][2];
    BalanceArray[3][3]=BalanceArray[3][3] - BalanceArray[3][3] - BalanceArray[3][3];
    //Make a more efficent loop

    printf("\n\n");
    printf("Balance\t");
    for(j=1;j<4;j++) {
        printf("%d\t",BalanceArray[1][1] + BalanceArray[2][1] + BalanceArray[3][1]);
    }
    printf("\n");
} 

int main () {

    ACCOUNT* head = NULL;
    head = malloc(sizeof(ACCOUNT));
    head->next = NULL;
    ACCOUNT* current = NULL;
    current = head;

    char response[] = "no";
    int menu_option;

    do {
        printf("Which function do want to do?\n 1. Load \n 2. Print all \n 3. Add account \n 4. Journal \n 5. Make a move \n 6. Balance Array \n 9. Save \n 10. Exit \n");
        scanf("%d",&menu_option);    
        switch (menu_option) {
            case 1:
                load_all(current);                                             
                break; 
            case 2:                          
                print_all(current);             
                break;
            case 3:                          
                do {
                    add_account(current);        
                    printf("Add other (y/n) \n");
                    scanf("%s", response);
                    if (response[0] == 'y') {
                    }
                } while (response[0] == 'y');            
                break;
            case 4:                          
                journal(current);            
                break;
            case 5:                          
                make_move(current);            
                break;
            case 6:                          
                balanceArray();            
                break;
            case 9:                          
                save_all(current);            
                break;
            case 10:
                printf("Thank you...\n");
                getchar();
                exit(0);        
                break; 
            
            default:
                printf("Not found");
        }    

    } while (menu_option != 10);


    getchar();

}