#include <stdio.h>
#include <math.h>
int main(void) {
    int sides;
    int dice;
    int dice_range;
    double average;
    printf("Enter the number of sides on your dice: ");
    scanf("%d",&sides);
    printf("Enter the number of dice being rolled: ");
    scanf("%d",&dice);
    dice_range= dice*sides;
    average=(dice_range+dice)*0.500000;
    if(sides>0 && dice>0){
    printf("Your dice range is %d to %d.\n",dice,dice_range);
    printf("The average value is %lf\n",average);
    }
    else {
    printf("These dice will not produce a range.\n");
    }
    return 0;
    }
   
