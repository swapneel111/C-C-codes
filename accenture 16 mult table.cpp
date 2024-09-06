#include<stdio.h>
int main ()
{
  int n, i, value = 0, sum = 0;
  printf ("Enter the number for which you want to know the table : ");
  scanf ("%d", &n);
  for (i = 1; i <= 10; ++i)
    {
      value = n * i;
      printf ("%d ", value);
      sum = sum + value;
    }
  printf ("\nsum is %d", sum);
  return 0;
}
