#include <stdio.h>
#include <stdlib.h>

struct CV
{
    char nume[30];
    char prenume[30];
    int varsta;
    int zi;
    int luna;
    int an;
    char pozitii_anterioare[50];
    char studii[20];
    char numar_telefon[15];
    char email[40];

}DataBase[100];

struct CV v[100];
int i = 0, ok=0, caut = 0;

void scriere()
{
    FILE *pf;
    pf = fopen("data.txt","r+");
    for(int k=0; k<i;k++)
        fprintf(pf,"%s^%s^%d^%d^%d^%d^%s^%s^%s^%s",v[k].nume,v[k].prenume,v[k].varsta,v[k].zi,v[k].luna,v[k].an,v[k].pozitii_anterioare,v[k].studii,v[k].numar_telefon,v[k].email);


}

void prelucrare_date(char *num)
{
            char *p = strtok(num,"^");
            strcpy(v[i].nume,p);
            p = strtok(NULL,"^");
            strcpy(v[i].prenume,p);
            p = strtok(NULL,"^");
            v[i].varsta=(atoi)(p);
            p = strtok(NULL,"^");
            v[i].zi=(atoi)(p);
            p = strtok(NULL,"^");
            v[i].luna=(atoi)(p);
            p = strtok(NULL,"^");
            v[i].an=(atoi)(p);
            p = strtok(NULL,"^");
            strcpy(v[i].pozitii_anterioare,p);
            p = strtok(NULL,"^");
            strcpy(v[i].studii,p);
            p = strtok(NULL,"^");
            strcpy(v[i].numar_telefon,p);
            p = strtok(NULL,"^");
            strcpy(v[i].email,p);
            p = strtok(NULL,"^");
}

void vizualizare_CV(int index)
{
    printf("\t\t\t\t\t\t Curriculum Vitae\n\n\n");
    printf("Nume: %s\n\n",v[index].nume);
    printf("Prenume: %s\n\n",v[index].prenume);
    printf("Varsta: %d\n\n",v[index].varsta);
    printf("Data nasterii: %d.%d.%d\n\n",v[index].zi,v[index].luna,v[index].an);
    printf("Pozitia/Pozitii anterioare: %s\n\n",v[index].pozitii_anterioare);
    printf("Nivel studii: %s\n\n",v[index].studii);
    printf("Numar de telefon: %s\n\n",v[index].numar_telefon);
    printf("Email: %s\n\n\n\n",v[index].email);
    if(caut == 0){
    printf("Pentru a reveni la meniul principal, apasati tasta 0.\nPentru a merge la sectiune lista de CV-uri apasati 1.\n");
    int input;
    scanf("%d",&input);
    if(input == 0)
    {
        system("cls");
        menu();
    }
    if(input == 1)
        vizualizare_lista();
    else
    {
        system("cls");
        vizualizare_CV(index);
    }
    }
    else
    {
        system("pause");
    }

}

void creare()
{
    if( ok == 0 )
    {
        int dateint;
        system("cls");
        printf("Introduceti urmatoarele date:\n");
        system("pause");
        system("cls");

        printf("Nume: ");
        char date[60];
        gets(date);
        gets(date);
        strcpy(v[i].nume,date);
        system("cls");

        printf("Prenume: ");
        gets(date);
        strcpy(v[i].prenume,date);

        int valid = 0;

        do{
            system("cls");
            printf("Varsta: ");
            scanf("%d",&dateint);
            if( dateint >=16 && dateint <= 70)
            {
                v[i].varsta = dateint;
                valid = 1;
                system("cls");
            }
            else
            {
                printf("Varsta invalida. Va rog sa reintroduceti datele!\n");
                system("pause");
            }
        }while(valid == 0);

        valid = 0;
        do{
            system("cls");
            printf("Ziua nasterii: ");
            scanf("%d",&dateint);
            if(dateint>=1 && dateint <= 31)
            {
                v[i].zi = dateint;
                valid = 1;
                system("cls");
            }
            else
            {
                printf("Zii de nastere invalida. Va rog sa reintroduceti datele!\n");
                system("pause");
            }
        }while(valid == 0);

        valid = 0;
        do{
            system("cls");
            printf("Luna nasterii: ");
            scanf("%d",&dateint);
            if(dateint >=1 && dateint <=12)
            {
                v[i].luna = dateint;
                valid = 1;
                system("cls");
            }
            else
            {
                printf("Luna nasterii este invalida. Va rog sa reintroduceti datele!\n");
                system("pause");
            }
        }while(valid == 0);

        valid = 0;
        do{
            system("cls");
            printf("Anul nasterii: ");
            scanf("%d",&dateint);
            if(dateint <= 2006 && dateint >= 1953)
            {
                v[i].an = dateint;
                valid = 1;
                system("cls");
            }
            else
            {
                printf("Anul de nastere este invalid. Va rog sa reintroduceti datele!\n");
                system("pause");
            }
        }while(valid == 0);

        printf("Pozitii anterioare: ");
        gets(date);
        gets(date);
        strcpy(v[i].pozitii_anterioare,date);
        system("cls");

        printf("Nivel studii: ");
        scanf("%s",&date);
        strcpy(v[i].studii,date);
        system("cls");

        valid = 0;
        do
        {
            system("cls");
            printf("Numar de telefon: ");
            scanf("%s",&date);
            if(strlen(date) == 10 && date[0] == '0' && date[1] == '7')
            {
                strcpy(v[i].numar_telefon,date);
                valid = 1;
                system("cls");
            }
            else
            {
                printf("Numar de telefon neidentificat. Va rog introduceti un numar de telefon valid");
                system("pause");
            }
        }while(valid == 0);

        valid = 0;
        do
        {
            system("cls");
            printf("Email: ");
            scanf("%s",&date);
            if( strstr(date,"@gmail.com")||strstr(date,"@yahoo.com")||strstr(date,"@e-uvt.ro"))
            {
                strcpy(v[i].email,date);
                valid = 1;
                system("cls");
            }
            else
            {
                printf("Email invalid. Va rog introduceti o adresa de mail valid");
                system("pause");
            }
        }while( valid == 0 );

        i++;
        ok = 1;
        int choice;
        do
        {

        system("cls");
        printf("CV creeat cu succes\nDoriti vizualizare CV-ului?\n1.Da\n2.Nu\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: system("cls");
                vizualizare_CV(i-1);
            break;
            case 2:system("cls");
                 menu();
            break;
            default:printf("Selectie invalida. Va rog reintroduceti!");
        }}
        while(choice != 2);
    }
    else
    {

        int choice;
        do
        {

        system("cls");
        printf("CV deja creat\nSelectati optiunea dorita.\n 1. Recreerea CV-ului\n 2. Vizualizarea CV-ului\n 3. Inapoi la meniul principal\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: i--;
            ok = 0;
            system("cls");
            creare();
            break;

            case 2: system("cls");
                vizualizare_CV(i-1);
            break;
            case 3:system("cls");
                 menu();
            break;
            default:printf("Va rog introduceti o alegere valida!\n");
        }}
        while(choice != 2);
    }
}

void vizualizare_lista()
{
    system("cls");
    printf("Selectati o optiune\n0.Pentru a reveni la meniul principal\n");
    for(int k=0; k<i;k++)
        printf("%d.%s %s\n",k+1,v[k].nume,v[k].prenume);
    int input;
    scanf("%d",&input);
    if( input == 0)
    {
        system("cls");
        menu();
    }
    system("cls");
    vizualizare_CV(input-1);
}

void cautare()
{
    int decision;
    system("cls");
    int choice;
    do
    {
        int index = 0;
        int find[100];
        system("cls");
        printf("Selectati o optiune\n0. Pentru a reveni la meniul principal \n1. Cautare dupa nume\n2. Cautare dupa pozitia anterioara\n3. Cautare dupa studii\n4. Cautare dupa numar de telefon\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            system("cls");
            menu();
            break;
        case 1:
            system("cls");
            do
            {
                printf("Introduceti numele: ");
                index = 0;
                char chosen_name[30];
                scanf("%s",&chosen_name);
                for(int k = 0; k < i; k++)
                {
                    if(strcmp(chosen_name,v[k].nume) == 0)
                    {
                        find[index] = k;
                        index++;
                    }
                }
                if(index != 0)
                {
                    int selection;
                    do
                    {
                    system("cls");

                    int selection;
                    printf("Selectati utilizatorul\n");
                    for(int j = 0; j < index; j++)
                    {
                        printf("%d. %s %s\n",j+1,v[find[j]].nume,v[find[j]].prenume);
                    }
                    printf("Apasati tasta 0 pentru a va intoarce la meniul de cautare.");
                    scanf("%d",&selection);
                    system("cls");
                    if(selection < 0 || selection > index)
                    {
                        printf("Selectie invalida\nVa rog reintroduceti!\n");
                        system("pause");
                    }
                    else
                        if(selection!=0){
                        caut  = 1;
                        vizualizare_CV(find[selection-1]);
                        caut = 0;
                        }
                    else
                        cautare();
                    }while(1);
                }
                do{
                    system("cls");
                    printf("Nu s-a putut gasi nici un utilizator.\nPentru a reveni la meniul prncipal apasati 1\nPentru a reveni la sectiunea cautare apasati 2\nPentru a cauta alt utilizator apasati 3\n");
                    scanf("%d",&decision);
                    switch(decision)
                    {
                        case 1:
                            system("cls");
                            menu();
                            break;
                        case 2:
                            system("cls");
                            cautare();
                            break;
                        case 3:
                            system("cls");
                            break;
                        default:
                            printf("Selectie invalida");
                            system("pause");
                            system("cls");
                    }
                }while(decision < 0 || decision > 3 );
                system("cls");
                system("cls");
            }
            while(index == 0);
            break;
        case 2:
            system("cls");
            do
            {
                printf("Introduceti pozitia anterioara dorita: ");
                index = 0;
                char chosen_name[30];
                gets(chosen_name);
                gets(chosen_name);
                for(int k = 0; k < i; k++)
                {
                    if(strstr(v[k].pozitii_anterioare,chosen_name) != NULL)
                    {
                        find[index] = k;
                        index++;
                    }
                }
                if(index != 0)
                {
                    int selection;
                    do
                    {
                    system("cls");

                    int selection;
                    printf("Selectati utilizatorul\n");
                    for(int j = 0; j < index; j++)
                    {
                        printf("%d. %s %s\n",j+1,v[find[j]].nume,v[find[j]].prenume);
                    }
                    printf("Apasati tasta 0 pentru a va intoarce la meniul de cautare.");
                    scanf("%d",&selection);
                    system("cls");
                    if(selection < 0 || selection > index)
                    {
                        printf("Selectie invalida\nVa rog reintroduceti!\n");
                        system("pause");
                    }
                    else
                        if(selection!=0){
                        caut  = 1;
                        vizualizare_CV(find[selection-1]);
                        caut = 0;
                        }
                    else
                        cautare();
                    }while(1);
                }
                do{
                    system("cls");
                    printf("Nu s-a putut gasi nici un utilizator.\nPentru a reveni la meniul prncipal apasati 1\nPentru a reveni la sectiunea cautare apasati 2\nPentru a cauta alt utilizator apasati 3\n");
                    scanf("%d",&decision);
                    switch(decision)
                    {
                        case 1:
                            system("cls");
                            menu();
                            break;
                        case 2:
                            system("cls");
                            cautare();
                            break;
                        case 3:
                            system("cls");
                            break;
                        default:
                            printf("Selectie invalida");
                            system("pause");
                            system("cls");
                    }
                }while(decision < 0 || decision > 3 );
                system("cls");
            }
            while(index == 0);
            break;
        case 3:
            system("cls");
            do
            {
                printf("Introduceti nivelul studiilor: ");
                index = 0;
                char chosen_name[30];
                scanf("%s",&chosen_name);
                for(int k = 0; k < i; k++)
                {
                    if(strcmp(chosen_name,v[k].studii) == 0)
                    {
                        find[index] = k;
                        index++;
                    }
                }
                if(index != 0)
                {
                    int selection;
                    do
                    {
                    system("cls");

                    int selection;
                    printf("Selectati utilizatorul\n");
                    for(int j = 0; j < index; j++)
                    {
                        printf("%d. %s %s\n",j+1,v[find[j]].nume,v[find[j]].prenume);
                    }
                    printf("Apasati tasta 0 pentru a va intoarce la meniul de cautare.");
                    scanf("%d",&selection);
                    system("cls");
                    if(selection < 0 || selection > index)
                    {
                        printf("Selectie invalida\nVa rog reintroduceti!\n");
                        system("pause");
                    }
                    else
                        if(selection!=0){
                        caut  = 1;
                        vizualizare_CV(find[selection-1]);
                        caut = 0;
                        }
                    else
                        cautare();
                    }while(1);
                }
                do{
                    system("cls");
                    printf("Nu s-a putut gasi nici un utilizator.\nPentru a reveni la meniul prncipal apasati 1\nPentru a reveni la sectiunea cautare apasati 2\nPentru a cauta alt utilizator apasati 3\m");
                    scanf("%d",&decision);
                    switch(decision)
                    {
                        case 1:
                            system("cls");
                            menu();
                            break;
                        case 2:
                            system("cls");
                            cautare();
                            break;
                        case 3:
                            system("cls");
                            break;
                        default:
                            printf("Selectie invalida");
                            system("pause");
                            system("cls");
                    }
                }while(decision < 0 || decision > 3 );
                system("cls");
            }
            while(index == 0);
            break;
        case 4:
            system("cls");
            do
            {
                printf("Introduceti numarul de telefon: ");
                index = 0;
                char chosen_phone[30];
                scanf("%s",&chosen_phone);
                for(int m = 0; m < i; m++)
                {
                    int flag = 0, c = 0;
                    while(chosen_phone[c]!='\0' && v[m].numar_telefon[c]!='\0')
                    {
                        if(chosen_phone[c] != v[m].numar_telefon[c]){
                            flag = 1;
                            break;
                        }
                        c++;
                    }
                    if(strlen(chosen_phone) != 10)
                        break;
                    if(flag == 0)
                    {
                        find[index] = m;
                        index++;
                    }

                }
                if(index != 0)
                {
                    int selection;
                    do
                    {
                    system("cls");

                    int selection;
                    printf("Selectati utilizatorul\n");
                    for(int j = 0; j < index; j++)
                    {
                        printf("%d. %s %s\n",j+1,v[find[j]].nume,v[find[j]].prenume);
                    }
                    printf("Apasati tasta 0 pentru a va intoarce la meniul de cautare.");
                    scanf("%d",&selection);
                    system("cls");
                    if(selection < 0 || selection > index)
                    {
                        printf("Selectie invalida\nVa rog reintroduceti!\n");
                        system("pause");
                    }
                    else
                        if(selection!=0){
                        caut  = 1;
                        vizualizare_CV(find[selection-1]);
                        caut = 0;
                        }
                    else
                        cautare();
                    }while(1);
                }
                do{
                    system("cls");
                    printf("Nu s-a putut gasi nici un utilizator.\nPentru a reveni la meniul prncipal apasati 1\nPentru a reveni la sectiunea cautare apasati 2\nPentru a cauta alt utilizator apasati 3\n");
                    scanf("%d",&decision);
                    switch(decision)
                    {
                        case 1:
                            system("cls");
                            menu();
                            break;
                        case 2:
                            system("cls");
                            cautare();
                            break;
                        case 3:
                            system("cls");
                            break;
                        default:
                            printf("Selectie invalida");
                            system("pause");
                            system("cls");
                    }
                }while(decision < 0 || decision > 3 );
                system("cls");
            }
            while(index == 0);
            break;
        default: printf("Selectie invalida"); break;
        }
    }while(choice!=0);

}

void menu()
{
    char choice;
    printf("Meniu\n");
    printf("0. EXIT\n");
    printf("1. Creare CV\n");
    printf("2. Vizualizare lista CV-uri\n");
    printf("3. Cautare\n");
    do
        {
    scanf("%d",&choice);
    switch(choice)
    {
    case 0:
        scriere();
        exit(0);
        break;

    case 1:
        creare();
        break;

    case 2:
        vizualizare_lista();
        break;

    case 3:
        cautare();
        break;

    default:
        printf("Va rog introduceti o alegere valida!");
    }
        }
    while(choice != 0);
}

int main()
{
    char num[200];
    FILE *fptr;
    fptr = fopen("data.txt","r+");
    if(fptr == NULL)
        return 1;
    while(fgets(num,200,fptr))
        {
            prelucrare_date(num);
            i++;
        }
    menu();

    return 0;
}
