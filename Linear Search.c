#include <stdio.h>
int main()
{
int array[100];
int n;
int key, i;
int found = 0;
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter elements:\n");
for(i = 0; i < n; i++)
{
scanf("%d", &array[i]);
}
printf("Enter element to search in array: ");
scanf("%d", &key);

for(i = 0; i < n; i++)
{
if(array[i] == key)
{
printf("Element found at position %d in array \n", i + 1);
found = 1;
break;
}
}
if(found == 0)
{
printf("Element not found\n");
}
return 0;
}
