#include <stdio.h>
#include "calc.h"
#include "logger.h"

int main(void) {
    double a = 10.0;
    double b = 5.0;
    double zero = 0.0;
    int error = 0;

    double result_add = add(a, b);
    double result_sub = sub(a, b);
    double result_mul = mul(a, b);
    double result_div = divf(a, b, &error);

    printf("===== Calculation Summary =====\n");
    printf("%.2f + %.2f = %.2f\n", a, b, result_add);
    printf("%.2f - %.2f = %.2f\n", a, b, result_sub);
    printf("%.2f * %.2f = %.2f\n", a, b, result_mul);

    if (error) {
        printf("Division error\n");
        write_error_log("Division by zero detected");
    } else {
        printf("%.2f / %.2f = %.2f\n", a, b, result_div);
    }

    write_log("Addition completed");
    write_log("Subtraction completed");
    write_log("Multiplication completed");
    write_log("Division completed");

    result_div = divf(a, zero, &error);

    if (error) {
        printf("Error: cannot divide %.2f by %.2f\n", a, zero);
        write_error_log("Cannot divide by zero");
    } else {
        printf("%.2f / %.2f = %.2f\n", a, zero, result_div);
    }

    printf("Current timestamp: ");
    print_timestamp();

    printf("Logs have been written to app.log\n");

    return 0;
}