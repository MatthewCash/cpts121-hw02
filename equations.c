/*******************************************************************************
* Programmer: Matthew Bruggeman                                                *
* Class: CptS 121, Fall 2021; Lab Section 2                                    *
* Programming Assignment: Hw02                                                 *
* Date: September 15, 2021                                                     *
* Description: Evaluate selected equation                                      *
*******************************************************************************/

#include <stdio.h>
#include <math.h>

#define PI acos(-1)
#define G 6.67e-11

int main(void)
{

    char should_continue = 1;

    while (should_continue) {
        char equation;

        printf("Select an equation by typing one of the following characters:\n");
        printf("N: Newton's Second Law\n");
        printf("V: Volume of a cylinder\n");
        printf("C: Character encoding\n");
        printf("G: Gravity\n");
        printf("R: Resistive divider\n");
        printf("D: Distance between two points\n");
        printf("E: General equation\n");

        scanf(" %c", &equation);

        if (equation == 'N')
        {
            double mass = 0;
            double accel = 0;

            printf("Enter mass and acceleration: ");
            scanf(" %lf %lf", &mass, &accel);

            double force = mass * accel;

            printf("force = mass * acceleration -> %lf = %lf * %lf\n", force, mass, accel);
        } else if (equation == 'V')
        {
            double radius;
            double height;

            printf("Enter radius and height: ");
            scanf(" %lf %lf", &radius, &height);

            double volume = PI * radius * radius * height;

            printf("volume = PI * radius^2 * height -> %lf = PI * %lf^2 %lf\n", volume, radius, height);
        } else if (equation == 'C')
        {
            char plaintext_char;

            printf("Enter plaintext char: ");
            scanf(" %c", &plaintext_char);

            char encoded_char = plaintext_char - 'a' + 'A';

            printf("encoded char = %c\n", encoded_char);
        } else if (equation == 'G') {
            double mass1;
            double mass2;
            double distance;

            printf("Enter mass1, mass2, and distance: ");
            scanf(" %lf %lf %lf", &mass1, &mass2, &distance);

            double force = G * mass1 * mass2 / (distance * distance);

            printf("force = G * mass1 * mass2 / distance^2 -> %lf = G * %lf * %lf / %lf^2\n", force, mass1, mass2, distance);
        } else if (equation == 'R')
        {
            double r1;
            double r2;
            double vin;

            printf("Enter v1, v2, and vin: ");
            scanf(" %lf %lf %lf", &r1, &r2, &vin);

            double vout = r2 / (r1 + r2) * vin;

            printf("vout = r2 / (r1+r2) * vin -> %lf = %lf / (%lf + %lf) * %lf\n", vout, r2, r2, r2, vin);
        } else if (equation == 'D')
        {
            double x1;
            double y1;
            double x2;
            double y2;

            printf("Enter x1, y1, x2, y2: ");
            scanf(" %lf %lf %lf %lf", &x1, &y1, &x2, &y2);

            double distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

            printf("distance = %lf\n", distance);
        } else if (equation == 'E')
        {
            double z;
            double x;
            int a;

            printf("Enter a, z, x: ");
            scanf(" %d %lf %lf", &a, &z, &x);

            double y = ((double) 89 / 27) - z * x + a / (a % 2);

            printf("y = %lf\n", y);
        } else {
            printf("Invalid equation selector, try again\n");
        }

        char continue_char;

        printf("Do you want to continue ('C': continue, 'S': stop): ");
        scanf(" %c", &continue_char);

        should_continue = continue_char == 'C';
    }
    return 0;
}
