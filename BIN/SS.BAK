#include <stdio.h>
#include <conio.h>

int main() {
int a[100], n, i, j, position, temp;
clrscr();
printf("Enter number of elements: ");
scanf("%d", &n);
if (n > 100) {
printf("Error: Maximum array size is 100.\n");
return 1;
}

printf("Enter %d integers:\n", n);
for (i = 0; i < n; i++)
scanf("%d", &a[i]);
for (i = 0; i < n - 1; i++) {
position = i;
for (j = i + 1; j < n; j++) {
if (a[position] > a[j])
position = j;
}
if (position != i) {
temp = a[i];
a[i] = a[position];
a[position] = temp;
}
}
printf("Sorted list in ascending order:\n");
for (i = 0; i < n; i++)
printf("%d\n", a[i]);
getch(); // Hold the output screen
return 0;
}
