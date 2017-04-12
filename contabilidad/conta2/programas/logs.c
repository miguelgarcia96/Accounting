#include <stdio.h>
#include <stdlib.h>

char ArMonth1 [12] = {'J','F','M','A','M','J','J','A','S','O','N','D'};
char ArMonth2 [12] = {'a','e','a','p','a','u','u','u','e','c','o','i'};
char ArMonth3 [12] = {'n','b','r','r','y','n','l','g','p','t','v','c'};

struct struct_cuenta {
        int id;
        int id2;
        char account_name [25];
        char account_name2 [25];
        int balance;
        int balance2;
        int move;

        char day [5];
        char month [5];
        int num;
        int year;
        int hour;
        int minute;
        int second;

        struct struct_cuenta *next;
    }; typedef struct struct_cuenta CUENTA;
void print (CUENTA *cuenta) {
    printf("%s ", cuenta->day);
    printf("%s ", cuenta->month);
    printf("%02d ", cuenta->num);
    printf("%02d:", cuenta->hour);
    printf("%02d:", cuenta->minute);
    printf("%02d ", cuenta->second);
    printf("%d\t", cuenta->year);
    printf("%d\t", cuenta->id);
    printf("%s\t", cuenta->account_name);
    printf("(%d)\t  \t ", cuenta->balance);
    printf("%d\t", cuenta->id2);
    printf("%s\t", cuenta->account_name2);
    printf("(%d)\t", cuenta->balance2);
    printf("    %d\n", cuenta->move);
}

void print_all(CUENTA *current) {
    printf("Date\t\t\t\tNo.\tCuenta\tBalance\t a \t No.\tCuenta\tBalance\tMovimiento\n");
    do{
        print(current);
        current = current->next;
    }while(current != NULL);
}

void print_select(CUENTA *current) {

    int id_account;

    printf("Cuenta que quieras saber sus movimientos\n");
    scanf("%d", &id_account);
    printf("Date\t\t\t\tNo.\tCuenta\tBalance\t a \t No.\tCuenta\tBalance\tMovimiento\n");
    do{
        if (id_account == current->id || id_account == current->id2){
            print(current);
        }       
        current = current->next;
    }while(current != NULL);
}

void print_select_date(CUENTA *current) {

    int l, i;
    int day1, day2, month1, month2, year1, year2;
    int hour1, hour2, minute1, minute2;
    char response[] = "no";

    printf("Digita a partir de que fecha en formato dia/mes/año (00/00/0000) quieres saber los registros \n");
    scanf("%02d/%02d/%04d",&day1, &month1, &year1);
    printf("Digita hasta que fecha en formato dia/mes/año (00/00/0000) quieres saber los registros \n");
    scanf("%02d/%02d/%04d",&day2, &month2, &year2);

    printf("El rango de fecha que seleccionaste es del %d/%d/%d al %d/%d/%d \n", day1, month1, year1, day2, month2, year2 );

    printf("Quieres seleccionar un rango de horas? s/n \n");
    scanf("%s",response);
    if (response[0] == 's') {
        printf("Digita a partir de que hora en formato de 24 horas (00:00) quieres saber los registros? \n");
        scanf("%02d:%02d",&hour1, &minute1);
        printf("Digita hasta que hora en formato de 24 horas (00:00) quieres saber los registros? \n");
        scanf("%02d:%02d",&hour2, &minute2);

        if(year1 < year2){
            printf("Date\t\t\t\tNo.\tCuenta\tBalance\t a \t No.\tCuenta\tBalance\tMovimiento\n");
            do{
                if(year1 <= current->year){
                    if(year2 >= current->year){
                        if(current->hour >= hour1 && current->hour <= hour2){                        
                            print(current);
                        }
                        current = current->next;
                    }
                }        
            }while(current->year == year1 || current->year == year2);
            }

        else{
            if(month1 == month2){
                do{
                    l = -1;
                    i = 0;
                    do{
                    l++;
                    i++;
                    }while ((ArMonth1[l] - current->month[0]) + (ArMonth2[l] - current->month[1]) + (ArMonth3[l] - current->month[2]) != 0);

                    if (i == month1 && i == month2){
                        if(day1 <= current->num){
                            if(day2 >= current->num){
                                if(current->hour >= hour1 && current->hour <= hour2){
                                    print(current);
                                }
                            }
                        }
                    }
                        
                    current = current->next;
                }while(i != month2);
            }
            else{
                do{
                    l = -1;
                    i = 0;
                    do{
                    l++;
                    i++;
                    }while ((ArMonth1[l] - current->month[0]) + (ArMonth2[l] - current->month[1]) + (ArMonth3[l] - current->month[2]) != 0);

                    if (i == month1){
                        if(day1 <= current->num){
                            if(current->hour >= hour1 && current->hour <= hour2){
                                print(current);
                            }        
                        }
                    }

                    if (i == month2){
                        if(day2 >= current->num){
                            if(current->hour >= hour1 && current->hour <= hour2){
                                print(current);
                            }
                        }
                    }                
                    current = current->next;
                }while(current->num > day2);
            }
    } 
    }
    
    if(year1 < year2){
        printf("Date\t\t\t\tNo.\tCuenta\tBalance\t a \t No.\tCuenta\tBalance\tMovimiento\n");
        do{
            if(year1 <= current->year){
                if(year2 >= current->year){
                    print(current);
                    current = current->next;
                }
            }        
        }while(current->year == year1 || current->year == year2);
    }
    else{
        if(month1 == month2){
            printf("Date\t\t\t\tNo.\tCuenta\tBalance\t a \t No.\tCuenta\tBalance\tMovimiento\n");
            do{
                l = -1;
                i = 0;
                do{
                l++;
                i++;
                }while ((ArMonth1[l] - current->month[0]) + (ArMonth2[l] - current->month[1]) + (ArMonth3[l] - current->month[2]) != 0);

                if (i == month1 && i == month2){
                    if(day1 <= current->num){
                        if(day2 >= current->num){
                            print(current);
                        }
                    }
                }
                    
                current = current->next;
            }while(current != NULL);
        }
        else{
            do{
                l = -1;
                i = 0;
                do{
                l++;
                i++;
                }while ((ArMonth1[l] - current->month[0]) + (ArMonth2[l] - current->month[1]) + (ArMonth3[l] - current->month[2]) != 0);

                if (i == month1){
                    if(day1 <= current->num){
                            print(current);        
                    }
                }

                if (i == month2){
                    if(day2 >= current->num){
                            print(current);
                    }
                }                
                current = current->next;
            }while(current != NULL);
        }
    }    
}
  
void load_logs(CUENTA *current) {
    FILE *pFile;
    pFile = fopen("logscopia.txt" , "r"); 

    if(pFile != NULL) {
        do {
            
            fscanf(pFile,"%s %s %d %02d:%02d:%02d %d %d %s %d %d %s %d %d", current->day, current->month, &current->num, &current->hour, &current->minute, &current->second, &current->year, &current->id, current->account_name, &current->balance, &current->id2, current->account_name2, &current->balance2, &current->move);
            current->next = malloc(sizeof(CUENTA));
            current = current->next;
            current->next = NULL;

        } while (!feof(pFile));

    fclose (pFile);
    }
}

int main () {

    CUENTA* head = NULL;
    head = malloc(sizeof(CUENTA));
    head->next = NULL;
    CUENTA* current = NULL;
    current = head;

    int menu_option;

    do {
    printf("Que funcion quieres hacer?\n 1. Cargar \n 2. Todos los logs \n 3. Seleccionar log \n 4. Seleccionar por fecha \n 5. Salir del programa \n");
    scanf("%d",&menu_option);    
    
        switch (menu_option) {
            case 1:
                load_logs(current);            
                break;
            case 2:
                print_all(current);            
                break;
            case 3:
                print_select(current);            
                break;
            case 4:
                print_select_date(current);            
                break;
        }
    } while (menu_option != 5); 

    getchar();
    
}