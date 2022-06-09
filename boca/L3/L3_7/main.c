#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int area_total(int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2);
int area(int x1, int y1, int x2, int y2);

int main()
{
    int areaTotal = 0;
    int area1 = 0, area2 = 0;
    int r1_x1 = 0, r1_y1 = 0, r1_x2 = 0, r1_y2 = 0, r2_x1 = 0, r2_y1 = 0, r2_x2 = 0, r2_y2 = 0;

    scanf("%d %d %d %d\n", &r1_x1, &r1_y1, &r1_x2, &r1_y2);
    scanf("%d %d %d %d\n", &r2_x1, &r2_y1, &r2_x2, &r2_y2);

    areaTotal = area_total(r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2);

    printf("RESP:%d", areaTotal);

    return 0;
}

int area_total(int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2)
{
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    int area1 = 0, area2 = 0, areaEmComum = 0;
    int i = 0;

    for (i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            x1 = r1_x1;
            y1 = r1_y1;
            x2 = r1_x2;
            y2 = r1_y2;

            area1 = area(x1, y1, x2, y2);
        }

        if (i == 1)
        {
            x1 = r2_x1;
            y1 = r2_y1;
            x2 = r2_x2;
            y2 = r2_y2;

            area2 = area(x1, y1, x2, y2);
        }
    }

    if (r2_x1 == r1_x1 && r1_x2 < r2_x2 && r1_y1 == r2_y1 && r1_y2 < r2_y2)
    {
        areaEmComum = area1;
    }

    else if (r2_x1 == r1_x1 && r1_x2 == r2_x2 && r1_y1 == r2_y1 && r1_y2 < r2_y2)
    {
        areaEmComum = area1;
    }

    else if (r2_x1 == r1_x1 && r1_x2 < r2_x2 && r1_y1 == r2_y1 && r1_y2 == r2_y2)
    {
        areaEmComum = area1;
    }

    else if (r1_x1 < r2_x1 && r1_x2 < r2_x2 && r1_y1 == r2_y1 && r1_y2 == r2_y2)
    {
        areaEmComum = area1;
    }

    else if (r2_x1 == r1_x1 && r1_x2 == r2_x2 && r1_y1 == r2_y1 && r1_y2 == r2_y2)
    {
        areaEmComum = area1;
    }

    else if (r1_x1 < r2_x1 && r1_x2 < r2_x2 && r1_y1 < r2_y1 && r1_y2 < r2_y2 && r1_x1 < r2_x1 && r2_x1 < r1_x2 && r1_y1 < r2_y1 && r2_y1 < r1_y2)
    {
        areaEmComum = (r1_x2 - r2_x1) * (r1_y2 - r2_y1);
    }

    else if (r1_x1 < r2_x1 && r1_x2 == r2_x2 && r1_y1 < r2_y1 && r1_y2 == r2_y2 && r2_x1 < r1_x2 && r1_y1 < r2_y1 && r2_y1 < r1_y2)
    {
        areaEmComum = area2;
    }

    return (area1 + area2 - areaEmComum);
}

int area(int x1, int y1, int x2, int y2)
{
    int area = 0;

    area = abs(x1 - x2) * abs(y1 - y2);

    return (area);
}