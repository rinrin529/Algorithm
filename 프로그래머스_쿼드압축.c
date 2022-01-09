#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void DFS(int x, int y, int Size, int** arr, int* answer)
{
    bool Zero, One;
    Zero = One = true;
    for (int i = x; i < x + Size; i++)
    {
        for (int j = y; j < y + Size; j++)
        {
            if (arr[i][j] == 0) One = false;
            if (arr[i][j] == 1) Zero = false;
        }
    }
 
    if (Zero == true)
    {
        answer[0]++;
        return;
    }
    if (One == true)
    {
        answer[1]++;
        return;
    }
 
    DFS(x, y, Size / 2, arr,answer);
    DFS(x, y + Size / 2, Size / 2, arr,answer);
    DFS(x + Size / 2, y, Size / 2, arr,answer);
    DFS(x + Size / 2, y + Size / 2, Size / 2, arr,answer);
}

int* solution(int** arr, size_t arr_rows, size_t arr_cols) {
    int* answer = (int*)malloc(sizeof(int) * 2);
    answer[0] = 0, answer[1] = 0;
    DFS(0, 0, arr_rows, arr, answer);
    return answer;
}
