#include <stdio.h>
#include <stdlib.h> //malloc(),free()
#include <string.h> //strcpy(),strlen()

#define SLEN 81

struct namect
{
    char fname[SLEN];
    char * lanme;
    int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect*);
void showinfo(const struct namect *);
void cleanup(struct namect*);
char* s_gets(char*, int);

int main(void)
{
    struct namect person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);
    return 0;
}

void getinfo(struct namect * pst);
{
    char temp[SLEN];

    puts("Please enter your first name.");
    s_gets(pst->fname, SLEN);
    puts("Please enter your last name.");
    s_gets(temp, SLEN);
    pst->lname = (char*)malloc(strlen(temp) + 1);//·ÖÅäÄÚ´æ
    //char *strcpy(char *dest, const char *src)
    strcpy(pst->lname, temp);
}

void makeinfo(struct namect * pst)
{
    pst->letter = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect * pst)
{
    printf("%s %s, your name contains %d letters.\n",
    pst->fname, pst->lname, pst->letter);
}

void cleanup(struct namect * pst)
{
    free(pst->fname);
    free(pst->lname);
}

char* s_gets(char* st, int n)
{
    char* ret_val;
    char i = 0;

    //char *fgets(char *str, int n, FILE *stream)
    ret_val = fgets(st, n, stdin);
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