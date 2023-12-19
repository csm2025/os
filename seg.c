#include <stdio.h>
int main()
{
    int a[100][100], b[100];
    int n;
    printf("Enter Number of Segments: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter The Size");
        int size;
        scanf("%d", &size);
        printf("Enter The Base:");
        int base;
        scanf("%d", &base);
        a[i][0] = size;
        a[i][1] = base;
        for (int j = 0; j < n; j++)
        {
            /* code */
            int x;
            scanf("%d", &x);
            base++;
            b[base] = x;
        }
    }

    return 0;
}