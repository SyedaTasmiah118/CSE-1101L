#include <stdio.h>

int main() {

    float cartvalue, total, discount, point = 0;

    float totalpurchase = 0;
    float totaldiscount = 0;

    int usepoint;
    int i;

    printf("Enter your first cart value: ");
    scanf("%f", &cartvalue);

    printf("Enter your initial user points: ");
    scanf("%f", &point);

    for (i = 1; ; i++) {

        if (cartvalue > 5000 && cartvalue <= 6000) {
            discount = (cartvalue * 0.2) + (point / 400);
        }

        else if (cartvalue == 2027) {
            discount = 270 + (point / 400);
        }

        else if (cartvalue >= 2000 && cartvalue <= 3000) {
            discount = (cartvalue * 0.05) + (point / 400);
        }

        else if (cartvalue >= 500) {
            discount = 50 + (point / 400);
        }

        else {
            discount = point / 400;
        }

        total = cartvalue - discount;

        if (total < 0) {
            total = 0;
        }

        printf("\n-- BILL SUMMARY --\n");

        printf("Cart value: %.2f\n", cartvalue);
        printf("Discount: %.2f\n", discount);
        printf("Payable total: %.2f\n", total);

        totalpurchase += cartvalue;
        totaldiscount += discount;

        point += cartvalue * 0.01;

        printf("Updated user points: %.2f\n", point);

        printf("\nEnter next cart value to continue or -1 to exit: ");
        scanf("%f", &cartvalue);

        if (cartvalue == -1) {
            break;
        }

        printf("Do you want to use your points for next purchase? (1 = yes, 0 = no): ");
        scanf("%d", &usepoint);

        if (usepoint == 1) {
            printf("Using points in next purchase...\n");
        }

        else {
            point = 0;
        }
    }

    printf("\n--- FINAL PURCHASE SUMMARY --- \n");

    printf("Total purchase amount: %.2f\n", totalpurchase);

    printf("Total discount received: %.2f\n", totaldiscount);

    printf("Remaining user points: %.2f\n", point);

    return 0;
}
