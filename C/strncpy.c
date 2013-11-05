#include <stdio.h>
#include <string.h>

int main()
{
  char str1[] = "abcde";
  char str2[] = "012345";
  char str3[] = "ABCDEFG";

  printf("Before strncpy\n");
  printf(str1);
  printf("\n");
  printf("%i is length of str1\n", sizeof(str1));
  printf(str2);
  printf("\n");
  printf("%i is length of str2\n", sizeof(str2));
  printf(str3);
  printf("\n");
  printf("%i is length of str3\n", sizeof(str3));


  strncpy(str1, str2, sizeof(str2));
  strncpy(str2, str3, sizeof(str3));
  
  printf("\n");
  printf("After strncpy\n");
  printf(str1);
  printf("\n");
  printf("%i\n", sizeof(str1));
  printf(str2); 
  printf("\n");
  printf("%i\n", sizeof(str2));
  printf(str3);
  printf("\n");
  printf("%i\n", sizeof(str3));
  
}
