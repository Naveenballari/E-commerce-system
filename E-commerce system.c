// This is a c program for maintaining orders of the company FLIPKART a e-commerce site
// Required header files for the program

#include <stdio.h>
#include "stdlib.h"
#include "string.h"

// Function to print the cases in switch:
void menu()
{
    printf("\nWELCOME TO E-COMMERCE SYSTEM\n");
    printf("\n----------------------------------\n");
    printf("\t\tMENU\n");
    printf("----------------------------------\n");
    printf("0-exit\n");
    printf("1-Show all shop\n");
    printf("2 shop by categories\n");
    printf("3-Show men's clothing \n");
    printf("4-Login\n");
    printf("5-Register\n");
    printf("6-sort mobiles by price\n");
    printf("7-search itmes\n");
    printf("8-my orders\n");
    printf("9-Sort appliances by price\n");
    printf("10-Sort men's fashion by price\n");
    printf("11-Sort womens's fashion by price\n");

    printf("--------------------------------\n");
}

// Function for displaying Categories
void categories()
{
    int k;
    // the values of k are scanned
    scanf("%d", &k);
    switch (k)
    {
    case 1:;
        printf("1-Men\n2-Women");
        int b;
        scanf("%d", &b);
        // implementing 'if' statements :
        // if the command is given as 1 then file called men is displayed
        if (b == 1)
        {

            // *f is a pointer
            FILE *f;
            char s;
            // fopen is used to open file
            // men file is opened in read mode
            f = fopen("men.txt", "r");
            while ((s = fgetc(f)) != EOF)
            {
                printf("%c", s);
            }
            // closes a file which has been opened for use
            fclose(f);
            // Reads a character from a file
            getch();
            printf("\n");
            // Buy function is called
            buy();
        }
        // if the command is given as 2 then file called women is displayed
        if (b == 2)
        {
            // *f is a pointer
            FILE *f;
            char s;
            // fopen is used to open file
            // women file is opened in read mode
            f = fopen("women.txt", "r");
            while ((s = fgetc(f)) != EOF)
            {
                printf("%c", s);
            }
            // closes a file which has been opened for use
            fclose(f);
            // Reads a character from a file
            getch();
            printf("\n");
            // Buy function is called
            buy();
        }
        // Break terminates a statement sequence.
        break;

        // *f is a pointer
    case 2:;
        FILE *f;
        char s;
        // fopen is used to open file
        // new1 file is opened in read mode
        f = fopen("new1.txt", "r");
        while ((s = fgetc(f)) != EOF)
        {
            printf("%c", s);
        }
        // closes a file which has been opened for use
        fclose(f);
        // Reads a character from a file
        getch();
        // Buy function is called
        buy();
        // Break terminates a statement sequence.
        break;

    case 3:; // *f2 is a pointer
        FILE *f2;
        char s2;
        printf("\n\n\n");
        // fopen is used to open file
        // new2 file is opened in read mode
        f = fopen("new2.txt", "r");
        while ((s = fgetc(f)) != EOF)
        {
            printf("%c", s);
        }
        // closes a file which has been opened for use
        fclose(f);
        // Reads a character from a file
        getch();

        printf("\n");
        // Buy function is called
        buy();
        // Break terminates a statement sequence.
        break;
    }
}

// Structure called login which is aliased as l
// includes first name,last name,username,password
typedef struct login
{
    char fname[30];
    char lname[30];
    char username[30];
    char password[20];
} l;

// Function login which helps login process
void login()
{
    char username[30], password[20];
    // *log is a pointer
    FILE *log;
    // fopen is used to open file
    // login file is opened in read mode
    log = fopen("login.txt", "r");
    struct login l;

    printf("\nPlease Enter your login credentials below\n\n");
    printf("Username:  ");
    scanf("%s", username);
    printf("\nPassword: ");
    scanf("%s", password);
    printf("\n");
    fscanf(log, "%s %s", l.fname, l.lname);

    // if values in the file are matched to the values being given then login is successful
    if (strcmp(username, l.fname) == 0 && strcmp(password, l.lname) == 0)

    {
        printf("\nSuccessful Login\n");
    }
    // otherwise login is failed and if interested can continue with registration process
    else
    {
        printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
        registration();
    }
}

// Function registration which helps registration process
void registration()
{
    int j;
    char username[30];
    char password[20];
    char firstname[15];
    // *log is a pointer
    FILE *log;
    // fopen is used to open file
    // login file is opened in write mode
    log = fopen("login.txt", "w");
    // *log is a pointer
    FILE *log1;
    // fopen is used to open file
    // login1 file is opened in write mode
    log1 = fopen("login1.txt", "w");
    struct login l;

    printf("\nWelcome to your Flipkart. We need to enter some details for registration.\n\n");
    printf("\nEnter First Name:\n");
    // scans first name
    scanf("%s", l.fname);

    printf("\nEnter Surname:\n");
    // scans last name
    scanf("%s", l.lname);

    printf("Thank you.\nNow please choose a username and password as credentials for system login.\nEnsure the username is no more than 30 characters long.\nEnsure your password is at least 8 characters long and contains lowercase, uppercase, numerical and special character values.\n");

    printf("\nEnter Username:\n");
    // scans user name
    scanf("%s", l.username);
    printf("\nEnter Password:\n");
    // scans password
    scanf("%s", l.password);
    // fprintf writes a set of data values to a file
    fprintf(log, "%s %s\n", l.username, l.password);

    printf("\nRegistration Successful!\n");
    // fscanf reads a set of data values to a file
    fscanf(log1, "%d", &j);
    j = j + 1;
    open_base(j);
    // closes a file
    fclose(log);
}

open_base(j)
{
    FILE *log2;
    log2 = fopen("2.txt", "w");
    j = j + 1;
    -fprintf(log2, "%d", j);
}

// product is a structure including code,name,cost and rating

struct product
{
    char code[30];
    char name[30];
    char *cost[30];
    int rating;
};

typedef struct product RD;
RD search_list[200];
int global_count = 0;

int comparator(const void *p, const void *q)
{
    return strcmp(((struct product *)p)->cost,
                  ((struct product *)q)->cost);
}
// sort by price function
int sort_by_price()
{
    // *fp is a pointer
    FILE *fp;
    // global count is set to zero
    int global_count = 0;

    /// Open the file in read mode
    fp = fopen("new1.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return 0;
    }

    /// Until the end of the file, read all the file data
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s %d", search_list[global_count].code, search_list[global_count].name, search_list[global_count].cost,
               &search_list[global_count].rating);
        //  printf("%s %s %s %d\n",search_list[global_count].code,search_list[global_count].movie_name, search_list[global_count].recommendation_name,
        //    search_list[global_count].viewers);
        global_count++;
    }

    int i, j;

    // sorting w.r.t ratings
    qsort(search_list, global_count, sizeof(struct product), comparator);

    // Print the Sorted Structure
    printf("\n\nMobiles sorted by price :\n");
    for (i = 0; i < global_count; i++)
    {
        printf("%s %s %s %d\n", search_list[i].code, search_list[i].name, search_list[i].cost,
               search_list[i].rating);
    }
    buy();
    fclose(fp);
}
// search function
int search()
{
    // * fp is a pointer
    FILE *fp;

    /// Open the file in read mode
    fp = fopen("new3.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return 0;
    }

    /// Until the end of the file, read all the file data
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s %d", search_list[global_count].code, search_list[global_count].name, search_list[global_count].cost,
               &search_list[global_count].rating);
        global_count++;
    }

    search1();
}

// search1 function
int search1()
{

    char s[100];
    char s1[100];
    // * p is a pointer
    char *p;

    printf("enter what you are searching\n");
    printf("enter the first letter in capital");
    scanf("%s", s1);
    // * fp is a pointer
    FILE *fp;

    /// Open the file in read mode
    fp = fopen("new3.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return 0;
    }

    int i = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%s", s);
        p = strstr(s, s1);
        i++;
        if (p)
        {
            printf("found \n");
            i = (i / 4);
            // printf("%s%d\n",p,i);
            printf("%s %s %s %d\n", search_list[i].code, search_list[i].name, search_list[i].cost,
                   search_list[i].rating);
            buy();
            break;
        }
    }
    if (p == 0)
    {
        printf("not found\n");
    }
}
// buy function
void buy()
{
    // * fp is a pointer
    FILE *fp;

    /// Open the file in read mode
    fp = fopen("new3.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
    }

    /// Until the end of the file, read all the file data
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s %d", search_list[global_count].code, search_list[global_count].name, search_list[global_count].cost,
               &search_list[global_count].rating);
        global_count++;
    }
    // * f1 is a pointer
    FILE *f1;
    global_count--;
    // Open the file in read mode
    f1 = fopen("new2.txt", "r");
    while (!feof(f1))
    {
        fscanf(f1, "%s %s %s %d", search_list[global_count].code, search_list[global_count].name, search_list[global_count].cost,
               &search_list[global_count].rating);
        global_count++;
    }

    int a;
    printf("enter your choice \n");
    printf("not interested then press 0\n");
    scanf("%d", &a);
    // if a=0 then the cart is empty
    if (a == 0)
    {
        printf("\n\t\t\t\tnothing on the cart\n");
    }

    // if a not equal to zero i.e any value or any product  selected is displayed
    if (a != 0)
    {
        printf("itemno |       name         |  cost  | delivery charge  |  total  \n");
        a = a - 1;
        printf("%s       %s        %s        free       %s\n", search_list[a].code, search_list[a].name, search_list[a].cost,
               search_list[a].cost);

        printf("                  order successfully placed    \n  \n");

        // order function is called
        order(a);
    }
}

struct order
{
    int code;
};

typedef struct order O;
O orderlist[200];
int acount = 1;

void order(int a)
{

    orderlist[acount].code = a;

    /// Until the end of the file, read all the file data
    //  for(int i;i<=acount;i++)
    // printf("%d",orderlist[i]);
    acount++;
}

void orders1()
{
    int a;
    printf("                your orders \n");
    for (int i = 1; i < acount; i++)
    {
        a = orderlist[i].code;
        printf("itemno |       name         |  cost  | delivery charge  |  total  \n");
        printf("%s       %s         %s          free                 %s\n", search_list[a].code, search_list[a].name, search_list[a].cost,
               search_list[a].cost);
    }
}

// Product1 structure including code,name,cost,rating
struct product1
{
    char code[30];
    char name[30];
    char *cost[30];
    int rating;
};

typedef struct product RD;
RD search_list1[200];

struct product3
{
    char code[30];
    char name[30];
    int *cost;
    int rating;
};

typedef struct product3 Rl;
Rl search_list10[200];

void a()
{
    char arr[100][100];

    int arr1[100];
    //*fp is a pointer
    FILE *fp;
    int global_count = 0;

    // opens new1 file in read mode
    fp = fopen("new1.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return 0;
    }
    int j = 0;
    /// Until the end of the file, read all the file data
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %d %d", search_list10[global_count].code, search_list10[global_count].name, &search_list10[global_count].cost,
               &search_list10[global_count].rating);

        global_count++;
    }
    /// Until the end of the file, read all the file data
    for (j = 0; j < global_count; j++)
    {
        arr1[j] = search_list10[j].cost;
    }

    int i, swap, a[100];
    char swap1;

    // starts from zero and continues upto i++ with i is less than global count-1
    for (i = 0; i < global_count - 1; i++)
    {
        // starts from zero and continues upto j++ with j is less than global count-1
        for (j = 0; j < global_count - i - 1; j++)
        {
            // then aar1[j] and arr1[j+1]are compared
            if (arr1[j] > arr1[j + 1])
            {
                // when arr1[j] is greater than arr1[j+1] then aar1[j] stored swap
                swap = arr1[j];
                // aar1[j] is stored in arr1[j+1]
                arr1[j] = arr1[j + 1];
                // then arr1[j+1] and arr1[j] are swapped
                arr1[j + 1] = swap;
            }
        }
    }

    printf("\nsorted by price\n");
    // starts from two and continues upto i++ with i is less than global count
    for (i = 2; i < global_count; i++)
    {
        // starts from zero and continues upto j++ with j is less than global count
        for (j = 0; j < global_count; j++)
        {

            if (arr1[i] == search_list10[j].cost)
                printf("%s %s %d %d\n", search_list10[j].code, search_list10[j].name, search_list10[j].cost, search_list10[j].rating);
        }
    }

    return 0;
}

void a1()
{
    char arr[100][100];

    int arr1[100];
    //*fp is a pointer
    FILE *fp;
    int global_count = 0;

    // opens file in read mode
    fp = fopen("new2.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return 0;
    }
    // j is initialized to zero
    int j = 0;
    /// Until the end of the file, read all the file data
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %d %d", search_list10[global_count].code, search_list10[global_count].name, &search_list10[global_count].cost,
               &search_list10[global_count].rating);

        global_count++;
    }
    /// Until the end of the file, read all the file data
    // starts from zero and continues upto j++ with j is less than global count
    for (j = 0; j < global_count; j++)
    {
        arr1[j] = search_list10[j].cost;
    }

    int i, swap, a[100];
    char swap1;

    // starts from zero and continues upto i++ with i is less than global count-1
    for (i = 0; i < global_count - 1; i++)
    {
        // starts from zero and continues upto j++ with j is less than global count-1
        for (j = 0; j < global_count - i - 1; j++)
        {
            // then aar1[j] and arr1[j+1]are compared
            if (arr1[j] > arr1[j + 1])
            {
                // when arr1[j] is greater than arr1[j+1] then aar1[j] stored swap
                swap = arr1[j];
                // aar1[j] is stored in arr1[j+1]
                arr1[j] = arr1[j + 1];
                // then arr1[j+1] and arr1[j] are swapped
                arr1[j + 1] = swap;
            }
        }
    }

    printf("\nsorted by price\n");

    // starts from two and continues upto i++ with i is less than global count
    for (i = 2; i < global_count; i++)
    {
        // starts from zero and continues upto j++ with j is less than global count
        for (j = 0; j < global_count; j++)
        {
            if (arr1[i] == search_list10[j].cost)
                printf("%s %s %d %d\n", search_list10[j].code, search_list10[j].name, search_list10[j].cost, search_list10[j].rating);
        }
    }

    return 0;
}

void a2()
{
    char arr[100][100];

    int arr1[100];
    // *fp isa pointer
    FILE *fp;
    // global count is intialized to zero
    int global_count = 0;

    // open men file in read mode
    fp = fopen("men.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return 0;
    }
    // j is initialized to zero
    int j = 0;
    /// Until the end of the file, read all the file data
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %d %d", search_list10[global_count].code, search_list10[global_count].name, &search_list10[global_count].cost,
               &search_list10[global_count].rating);

        global_count++;
    }
    /// Until the end of the file, read all the file data
    // starts from zero and continues upto j++ with j is less than global count
    for (j = 0; j < global_count; j++)
    {
        arr1[j] = search_list10[j].cost;
    }

    int i, swap, a[100];
    char swap1;

    // starts from zero and continues upto i++ with i is less than global count-1
    for (i = 0; i < global_count - 1; i++)
    {
        // starts from zero and continues upto j++ with j is less than global count-1
        for (j = 0; j < global_count - i - 1; j++)
        {
            // then aar1[j] and arr1[j+1]are compared
            if (arr1[j] > arr1[j + 1])
            {

                // when arr1[j] is greater than arr1[j+1] then aar1[j] stored swap
                swap = arr1[j];
                // aar1[j] is stored in arr1[j+1]
                arr1[j] = arr1[j + 1];
                // then arr1[j+1] and arr1[j] are swapped
                arr1[j + 1] = swap;
            }
        }
    }

    printf("\nsorted by price\n");

    // starts from two and continues upto i++ with i is less than global count
    for (i = 2; i < global_count; i++)
    {
        // starts from zero and continues upto j++ with i is less than global count
        for (j = 0; j < global_count; j++)
        {
            if (arr1[i] == search_list10[j].cost)
                printf("%s %s %d %d\n", search_list10[j].code, search_list10[j].name, search_list10[j].cost, search_list10[j].rating);
        }
    }

    return 0;
}

void a3()
{
    char arr[100][100];

    int arr1[100];
    //*fp is a pointer
    FILE *fp;
    // global count is intitalized to zero
    int global_count = 0;

    // opens women file in read mode

    fp = fopen("women.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return 0;
    }
    // j is intialized to zero
    int j = 0;
    /// Until the end of the file, read all the file data
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %d %d", search_list10[global_count].code, search_list10[global_count].name, &search_list10[global_count].cost,
               &search_list10[global_count].rating);

        global_count++;
    }
    /// Until the end of the file, read all the file data
    // starts from zero and continues upto j++ with j is less than global count
    for (j = 0; j < global_count; j++)
    {
        arr1[j] = search_list10[j].cost;
    }

    int i, swap, a[100];
    char swap1;

    // starts from zero and continues upto i++ with i is less than global count-1
    for (i = 0; i < global_count - 1; i++)
    {
        // starts from zero and continues upto j++ with j is less than global count-1
        for (j = 0; j < global_count - i - 1; j++)
        {
            // then aar1[j] and arr1[j+1]are compared
            if (arr1[j] > arr1[j + 1])
            {

                // when arr1[j] is greater than arr1[j+1] then aar1[j] stored swap
                swap = arr1[j];
                // aar1[j] is stored in arr1[j+1]
                arr1[j] = arr1[j + 1];
                // then arr1[j+1] and arr1[j] are swapped
                arr1[j + 1] = swap;
            }
        }
    }

    printf("\nsorted by price\n");

    // starts from two and continues upto i++ with i is less than global count
    for (i = 2; i < global_count; i++)
    {
        // starts from zero and continues upto j++ with j is less than global count
        for (j = 0; j < global_count; j++)
        {
            if (arr1[i] == search_list10[j].cost)
                printf("%s %s %d %d\n", search_list10[j].code, search_list10[j].name, search_list10[j].cost, search_list10[j].rating);
        }
    }

    return 0;
}

int main()
{
    int choice;
    // Switch case implementation
    while (1)
    {
        menu();
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("exiting application.......");
            return 0;

        case 1:;
            // *f3 is a pointer
            FILE *f3;
            char s3;
            printf("\tMobiles\n");
            // fopen is used to open file
            // new1 file is opened in read mode
            f3 = fopen("new1.txt", "r");
            while ((s3 = fgetc(f3)) != EOF)
            {
                printf("%c", s3);
            }

            // *f1 is a pointer
            FILE *f1;
            char s1;
            printf("\n\tHome appliances\n");
            // fopen is used to open file
            // new2 file is opened in read mode
            f1 = fopen("new2.txt", "r");
            while ((s1 = fgetc(f1)) != EOF)
            {
                printf("%c", s1);
            }

            printf("\n\n       Men's fashoion");
            // *f5 is a pointer
            FILE *f5;
            char s5;
            printf("  \n");
            // fopen is used to open file
            // men file is opened in read mode
            f5 = fopen("men.txt", "r");
            while ((s5 = fgetc(f5)) != EOF)
            {
                printf("%c", s5);
            }

            printf("\n\n        womens's fashion");
            // *f4 is a pointer

            FILE *f4;
            char s4;
            printf("  \n");
            // fopen is used to open file
            // women file is opened in read mode
            f4 = fopen("women.txt", "r");
            while ((s4 = fgetc(f4)) != EOF)
            {
                printf("%c", s4);
            }
            // buy function is called
            buy();

        case 2:
            printf("1 Clothing\n 2 Mobiles \n 3 Home appliances \n 0 menu");
            categories();
            break;

        case 3:;
            int k;
            // *f is a pointer
            FILE *f;
            char s;
            printf("\n\n\n");
            // fopen is used to open file
            // men file is opened in read mode
            f = fopen("men.txt", "r");
            while ((s = fgetc(f)) != EOF)
            {
                printf("%c", s);
            }
            fclose(f);
            getch();
            buy();
            break;

        case 4:
            printf("Login\n");
            login();
            break;

        case 5:
            registration();
            break;

        case 6:
            a();
            buy();
            break;

        case 7:
            search();
            break;

        case 8:
            orders1();
            break;

        case 9:
            a1();
            buy();
            break;

        case 10:
            a2();
            buy();
            break;

        case 11:
            a3();
            buy();
            break;
        }
    }
}
