#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(void)
{
    int rotate_cycles, rotate = 0;
    uint8_t num, mask, temp;

    /* unsigned char Number between 0 to 255 */
    printf("Please enter a number between 0 and 255 \n");
    scanf("%hhu", &num);

    printf("Please enter the number of rotate cycles \n");
    scanf("%d", &rotate_cycles);

    printf("To rotate right please enter 1 \nTo rotate left please enter 0 \n");
    scanf("%d", &rotate);
    
    // Rotate Right
    if (rotate == 1)
    {
        for (int i = 1; i <= rotate_cycles; i++)

            {
                mask = 1;   // 0000 0001
                temp = num & mask;  // save the last bit on the right
                temp = temp << 7;   // move it to the most left bit
                num = num >> 1;     // shift num to right
                num = num | temp;   // assign the bit to the shifted num to get num rotated correctly

            }
    
    }

    // Rotate Left
    else if (rotate == 0)
    {
        for (int i = 1; i <= rotate_cycles; i++)
 
            {
                mask = 128;     // 1000 0000
                temp = num & mask;  // save the last bit on the left
                temp = temp >> 7;   // move it to the most right bit
                num = num << 1;     // shift num to left
                num = num | temp;   // assign the bit to the shifted num to get num rotated correctly
            }
    }
 
    printf("Number after rotation is %hhu \n" , num);

    return 0;
}