#include <stdio.h>
#include <stdlib.h> //exit()
#include <string.h>
#define LEN 5

int main(int argc, char *argv[])
{
    FILE *in, *out;
    char name[LEN];
    int ch;
    int cnt = 0;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);  
    }
    if ((in = fopen(argv[1], "r") == NULL))  //"r"-read
    {
        fprintf(stderr, "I could't open the file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    //char * strncpy(char *_Destination, const char *_Source, size_t _Count)
    strncpy(name, argv[1], LEN - 5);
    if (out = fopen(name, "w") == NULL) //"w"-write
    {
        fprintf(stderr, "I could't open the file \"%s\"\n");
        exit(EXIT_FAILURE);
    }
    //int getc(FILE *_Stream)
    while((ch = getc(in)) != EOF)
    {
        if (cnt % 3 == 0)
        {
            putc(ch, out);
            cnt++;
        }
    }
    if (fclose(in) != 0 || fclose(out) != 0)
    {
        fprintf(stderr, "Error in closing files.\n");
    }

    return 0;
}