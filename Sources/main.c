#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//Désactivation de la gestion automatique du ventilateur
	system("ngc -d wyclim");
	system("echo 0 > /sys/devices/platform/stm-pwm/pwm1");
	
	while(1)
	{
		//Ecriture d'une PWM
		system("echo 150 > /sys/devices/platform/stm-pwm/pwm1");
		//Lecture d'une PWM
		printf("Puissance du ventilateur:\n");
		system("cat /sys/devices/platform/stm-pwm/pwm1");
		//Attente
		sleep(3);
		
		//Ecriture d'une PWM
		system("echo 200 > /sys/devices/platform/stm-pwm/pwm1");
		//Lecture d'une PWM
		printf("Puissance du ventilateur:\n");
		system("cat /sys/devices/platform/stm-pwm/pwm1");
		//Attente
		sleep(3);
		
		//Ecriture d'une PWM
		system("echo 255 > /sys/devices/platform/stm-pwm/pwm1");
		//Lecture d'une PWM
		printf("Puissance du ventilateur:\n");
		system("cat /sys/devices/platform/stm-pwm/pwm1");
		//Attente
		sleep(4);
	}
	return 0;
}
