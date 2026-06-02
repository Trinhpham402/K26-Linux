#include <stdio.h>
#include "mathutils.h"

int main() {
    int a, b, n;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("Add result: %d\n", add(a, b));
    printf("Subtract result: %d\n", subtract(a, b));

    printf("Enter a non-negative integer for factorial: ");
    scanf("%d", &n);

    int fact = factorial(n);

    if (fact == -1) {
        printf("Error: factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is: %d\n", n, fact);
    }

    return 0;
}