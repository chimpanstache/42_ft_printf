#include <stdio.h>
int main(){
	unsigned long a = 81767869452;
	unsigned long _a = -a;
	int b = -1897145;
	int _b =  -b;
	char *string = "|%u|%u|%d|%d|%x|%x|%X|%X|%c|%c|%c|%c\n";
	int c = printf(string, a, _a, b, _b, a, _a, b, _b, a, _a, b, _b);
	int d = printf(string, a, _a, b, _b, a, _a, b, _b, a, _a, b, _b);
	printf("Ton printf: %d\nprintf:%d\n", c, d);
}