#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char *argv[]) {
	float hours, minutes;
	uint8_t th1, tm1, th2, tm2;

	if(argc != 3) {
		fputs("failed - example usage: \"timetaken 12:00 15:00\" \n", stderr);
		return 1;
	}

	else if(strnlen(argv[1], 6) != 5 || strnlen(argv[2], 6) != 5) {
		fputs("failed - incorrect format of argument\n", stderr);
		return 1;
	}

	th1 = ((argv[1][0] - '0') * 10 + argv[1][1] - '0');
	th2 = ((argv[2][0] - '0') * 10 + argv[2][1] - '0');
	tm1 = ((argv[1][3] - '0') * 10 + argv[1][4] - '0');
	tm2 = ((argv[2][3] - '0') * 10 + argv[2][4] - '0');

	hours = th2 - th1; 

	if(hours < 0) {
		th2 += 24;
		hours = th2 - th1;
	}

	if(hours != 0) {
		hours--;
		minutes = 60 - tm1;
		minutes += 60 * hours;
		minutes += tm2;
	}
	else
		minutes = tm2 - tm1;

	hours = minutes / 60;

	printf("%01.2f hours or %01.0f minutes\n", hours, minutes);

	return 0;
}
