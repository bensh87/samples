#include<stdio.h>
#include<math.h>

float
find_power_of(float num, float pow)
{

    if(pow == 1.0 )
        return num;
    else if  ( pow == 0.0 )
        return 1.0;
    else
       return ( num * find_power_of(num, (pow - 1)));
}

int
find_nearest_power(float number , float base)
{
    int pwr = 0;
    float value = 0.0;

    while(1)
    {
        if( value > number )
            break;

        pwr++;
        value = find_power_of(base, pwr);
        /*printf("value of %f^%d is : %f\n", base,pwr, value);*/

    }

    return (pwr - 1);
}

int
main()
{

    int     base,number;
    float   log_value, div_value, temp;
    int     dec_position = 0;
    int     power_value;

    printf("Enter the Base Number:");
    scanf("%d",&base);

    printf("Enter the Number to find Log Value to the base %d : ",base);
    scanf("%d",&number);

    power_value = find_nearest_power(number,base);
    /*printf("The Nearest Power is : %d\n",power_value);*/

    if(number == find_power_of(base,power_value))
        printf("The Log value of %d to base %d is : %d\n",number,base,power_value);
    else
    {
        printf("The Log Value contains Decimals\n");
        log_value = power_value;
        temp = number;
        while(1)
        {
            dec_position++;
            div_value = temp/find_power_of(base,power_value);
            /*printf("The Div value is : %f\n",div_value);*/
            temp = find_power_of(div_value,base);
            /*printf("The Value of %f^%d is  : %f\n",div_value, base, temp);*/
            power_value = find_nearest_power(temp,base);
            /*printf("The nearest Power Value is : %d\n",power_value);
            printf("Addition Value is : %f\n",(power_value/find_power_of(10,dec_position)));*/
            log_value = log_value + (power_value/find_power_of(base,dec_position));
            /*printf("The log value is : %f\n",log_value);*/

            if ( dec_position == 6 || (temp == find_power_of(base,power_value)))
            {
                printf("The Log value of %d to base %d is : %f\n",number,base,log_value);
                break;
            }

        }
    }

    return(0);
}
