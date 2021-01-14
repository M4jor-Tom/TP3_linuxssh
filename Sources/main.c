#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void setVentilo(unsigned short int pwm);
void printVentilo();

int main(int argc, char *argv[])
{
	//Désactivation de la gestion automatique du ventilateur
	system("ngc -d wyclim");
	system("echo 0 > /sys/devices/platform/stm-pwm/pwm1");
	
	unsigned short int pwm = 0;
	bool rising = true;
	while(1)
	{
		if(rising)
			setVentilo(pwm = pwm + 5);
		else
			setVentilo(pwm = pwm - 5);
		
		usleep((unsigned int)(25000000.0/255.0));
		
		if(pwm == 255)
		{
			rising = false;
			printVentilo();
		}
		else if(pwm == 0)
		{
			rising = true;
			printVentilo();
		}
	}
	return 0;
}


void setVentilo(unsigned short int pwm)
{
	char
		stringPwm[4],
		command[50] = "echo ",
		commandEnd[] = " > /sys/devices/platform/stm-pwm/pwm1";
	
	sprintf(stringPwm, "%d", pwm);
	
	strcat(command, stringPwm);
	strcat(command, commandEnd);
	
	system(command);
}

void printVentilo()
{
	printf("Puissance du ventilateur: ");
	system("cat /sys/devices/platform/stm-pwm/pwm1");
	printf("\n");
}
