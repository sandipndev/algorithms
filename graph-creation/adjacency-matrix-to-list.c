#define LIM 100

#include <stdio.h>
#include <stdlib.h>
#include "../common/list.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s [file]\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("File not found.\n");
        exit(1);
    }

    char line[LIM];
    fgets(line, LIM, fp);
    int len = atoi(line);

    node **List = calloc(len, sizeof(node *));
    int i;
    for (i = 0; i < len; i++)
        List[i] = NULL;

    i = 0;
    while (fgets(line, LIM, fp) != NULL)
    {
        char ch = line[0];
        int j = 0;
        while (ch != '\0')
        {
            if (ch == '1')
                List[i] = insert_last(List[i], j / 2);
            ch = line[++j];
        }
        i++;
    }

    for (i = 0; i < len; i++)
    {
        printf("%d -> ", i);
        print_list(List[i]);
    }

    fclose(fp);
    return 0;
}
