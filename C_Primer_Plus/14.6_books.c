#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 40
#define MAX_TITLE 40
#define MAX_BOOKS 100

char* s_gets(char* st, int n);

struct author
{
    char firstName[MAX_NAME];
    char lastName[MAX_NAME];
};
struct books
{
    struct author name;
    char bookTitle[MAX_TITLE];
    float value;
};

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage : %s filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int cnt = 0;
    struct books library[MAX_BOOKS];

    printf("Book %d \n", cnt + 1);
    puts("Please Enter the book tile.");
    puts("Please [Enter] at the start of a line to stop.");

    while (cnt < MAX_BOOKS && s_gets(library[cnt].bookTitle, MAX_TITLE) != NULL
        && library[cnt].bookTitle[0] != '\0')
    {
        puts("Now enter the author's firstName.");
        s_gets(library[cnt].name.firstName, MAX_NAME);
        puts("Now enter the author's lastName.");
        s_gets(library[cnt].name.lastName, MAX_NAME);
        puts("Now enter the value.");
        scanf("%f", &library[cnt].value);
        while (getchar() != '\n')
            continue; //清理输入行
        cnt++;
        if (cnt < MAX_BOOKS)
        {
            printf("book %d \n", cnt + 1);
            puts("Please Enter the book tile.");
            puts("Please [Enter] at the start of a line to stop.");
        }
    }

    FILE* fp;
    struct books * p_book;
    p_book = &library[0];

    if (cnt > 0)
    {
        if ((fp = fopen(argv[1], "a+")) == NULL)
        {
            puts("Cant't open the file.");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < cnt; i++)
        {
            fprintf(fp, "%s-%s %s-%.2f\n",
                library[i].bookTitle,
                library[i].name.lastName,
                p_book -> name.firstName,
                p_book -> value);
        }
    }
    else
    {
        printf("No Books? Too Bad !\n");
    }
    if (fclose(fp) != 0)
    {
        puts("Error in closing the file.");
    }
    return 0;
}

char* s_gets(char* st, int n)
{
    char* ret_val;
    char i = 0;

    ret_val = fgets(st, n, stdin);
    //char *fgets(char *str, int n, FILE *stream)

    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
        {
            i++;
        }
        if (st[i] == '\n')
        {
            st[i] = '\0';
        }
        else
        {
            while (getchar() != '\n')
                continue;
        }

    }
    return ret_val;
}