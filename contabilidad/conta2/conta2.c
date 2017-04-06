#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char password [10], l=' ';
char str [10], m=' ';

int lenght (char *s){
    char *start = s;
    while (*s) s++;
    return s - start;
}

void trim(char *s){
    while (*s) s++; 
    while(*s == ' ' || *s == '\0' || *s == '\n') s--;
    *(s+1) = '\0';
}

int compare(char *s, char*t){
    while (*s != '\0' && *t != '\0' && *s - *t == 0){
        s++;
        t++;
    } return *s - *t;
}

int new_password(){
    int i=0;
    printf("\n Enter the password [max length 10] : ");
    while (i<=9){
    password[i]=getch();
    l=password[i];
    if(l==13) break;
    else printf("*");
    i++;
    }
    password[i]='\0';
    i=0;
    FILE *pFile;
    pFile = fopen("password.txt" , "w");
    fprintf (pFile,"%s",password);
    fclose (pFile);
    return 0;
}

int old_password (){

    int i=0;
    printf("Password?");
    while (i<=9){
        str[i]=getch();
        m=str[i];
        if(m==13) break;
        else printf("*");
        i++;
    }
    str[i]='\0';
    i=0;
    trim(str);
    compare (str, password);
    return 0;
}



struct struct_cuenta {
        int id;
        char account_name [25];
        int balance;
        struct struct_cuenta *next;
        struct struct_cuenta *previous;
    }; typedef struct struct_cuenta CUENTA;

void print (CUENTA *cuenta) {
    printf("%d\t", cuenta->id);
    printf("%s\t", cuenta->account_name);
    printf("(%d)\n", cuenta->balance);
} 

void add_account(CUENTA* current) {
    while(current->next != NULL){
        current = current->next;
    }
        printf("Dame el id de la cuenta: ");
        scanf("%d", &current->id );
        printf("Dame el nombre de la cuenta: ");
        scanf("%s", current->account_name);
        printf("Dame el balance de la cuenta: ");
        scanf("%d", &current->balance );
        
        current->next = malloc(sizeof(CUENTA));    
        current->next->next = NULL;
}

void print_all(CUENTA *current) {
    while(current != NULL) {
        print(current);
        current = current->next;
    }
}

void save_all(CUENTA *current) {
    FILE *pFile;
    pFile = fopen("accounts.txt" , "w");
    while(current != NULL) {
        fprintf(pFile,"%d\t", current->id);
        fprintf(pFile,"%s\t", current->account_name);
        fprintf(pFile,"%d\n", current->balance);
        current = current->next;
    } 
    fclose (pFile);           
}

void load_all(CUENTA *current) {
    FILE *pFile;
    pFile = fopen("accounts.txt" , "r");
    fscanf(pFile,"%d\t%s\t%d\n", &current->id, current->account_name, &current->balance);
    fclose (pFile);
    printf("Hey\n");
    } 
    

void make_move(CUENTA *current){ 
    
    int source,qty;

    printf("Elige el numero de cuenta de retiro:");
    scanf("%d",&source);
    /*printf("Elige el numero de cuenta de deposito:");
    scanf("%d",&source);*/
    printf("Elige la cantidad a mover");
    scanf("%d",&qty);
    while (current->id != source){
        current = current->next;
    }
    current->balance = current->balance - qty;
    print(current);
}

/*void source(CUENTA *current){
    int source; //destination, qty;
    

    printf("Elige el numero de cuenta de retiro:");
    scanf("%d",&source);
    while (current->id != source){
        current = current->next;
    }print(current);
}*/
        

int main() {

    CUENTA* head = NULL;
    head = malloc(sizeof(CUENTA));
    head->next = NULL;
    CUENTA* current = NULL;
    current = head;

    char response[] = "no";
    int menu_option;

    char c;

    FILE * fPointer;
    fPointer = fopen ("password.txt","r");
    if (fPointer != NULL){
        do{
            c = fgetc(fPointer);
            if (c != EOF && c != ' ' && c != '\n'){
                fclose(fPointer);
            //pasword_pass-begin HACER MENU
                FILE * fPointer;
                fPointer = fopen ("password.txt", "r");
                while (!feof(fPointer)){
                fgets (password, 10, fPointer);
                }
                old_password ();
                if (compare(str,password) == 0){
                    printf(" Accesso permitido\n");
            
                    do {
                    printf("Que funcion quieres hacer?\n 1. Listar cuentas \n 2. Agregar cuentas \n 3. Realizar un movimiento \n 4. Salir del programa \n 5. Save \n 6. Load\n");
                    scanf("%d",&menu_option);    
                    switch (menu_option) {
                        case 1:                          
                            print_all(current);            
                            break; 
                        case 2:
                            do {                
                                add_account(current);        
                                printf("Quieres agregar otra (s/n)");
                                scanf("%s", response);
                                if (response[0] == 's') {
                                }
                            } while (response[0] == 's');                   
                            break;
                        case 3:
                            make_move(current);                    
                            break;   
                        case 4:
                            printf("Gracias...\n");
                            getchar();
                            exit(0);        
                            break;
                        case 5: 
                            save_all(current);
                            break;
                        case 6: 
                            load_all(current);
                            break;
                        default:
                            printf("No encontrado");
                    }    
        
                } while (menu_option != 4);
                }

                else
                printf("Accesso denegado\n");
                fclose(fPointer);
                return 0;
                }
            //password_pass-ends 
            else{
            new_password();
            }
        }while(1>2);
    }
}


    