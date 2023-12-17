#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int postfixEvaluation(char *arr)
{
    int arr1[100];
    int index = -1;
    int i = 1;
    while (arr[i] != '?')
    {
        if (!(arr[i] >= '0' && arr[i] <= '9'))
        {
            int top = arr1[index];
            int second_top = arr1[index - 1];
            if (arr[i] == '*')
            {
                index -= 1;
                int v = top * second_top;
                arr1[index] = v;
            }
            else if (arr[i] == '+')
            {
                index -= 1;
                int v = top + second_top;
                arr1[index] = v;
            }
            else if (arr[i] == '-')
            {
                index -= 1;
                int v = second_top - top;
                arr1[index] = v;
            }
            else if (arr[i] == '/')
            {
                index -= 1;
                int v = second_top / top;
                arr1[index] = v;
            }
            i += 1;
            continue;
        }
        int unit = 10;
        int val = 0;
        while (arr[i] != ' ')
        {
            val = (arr[i] - '0') + val * unit;
            i += 1;
        }
        i += 1;
        index += 1;
        arr1[index] = val;
    }
    return arr1[0];
}
int main()
{
    assert(postfixEvaluation(" 12 23 + 14 - ?")==21);   
    assert(postfixEvaluation(" 21 12 91 12 14 + * 12 * * + 56 + ?")==340781);   
    assert(postfixEvaluation(" 10 100 10 10 * 75 / + - ?")==-91);   
    assert(postfixEvaluation(" 1 ?")==1);   
    return 0;
}