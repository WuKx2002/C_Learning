#include <stdio.h>
#include <stdlib.h>
#define MAX 40

int main(void)
{
    FILE * fp;
    char words[MAX];

    if ((fp = fopen("wordy", "a+")) == NULL )
    {
        puts("Sorry,can't open the file \"wordy\"");
        exit(EXIT_FAILURE);
    }
    puts("Enter words to add to the file.Press [#] to stop.");
    while ((gets(words) != NULL) && (words[0] != '#'))
    {
        fprintf(fp, "%s", words);
    }
    puts("File contents:");
    rewind(fp);
    while (fscanf(fp, "%s", words) == 1)
    {
        puts(words);
    }
    puts("Done!");
    if (fclose(fp) != 0)
    {
        puts("Errot closing file");
    }
    return 0;
}