#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	char *week_day;
	int day;
	int month;
} Date;

typedef struct
{
	char *name;
	Date *date;
} Holiday;

void print_holidays()
{

	Date ny = {.week_day = "Monday", .day = 1, .month = 1};
	Holiday hd = {.name = "New Year's Day", .date = &ny};
	Holiday hdays[1];
	hdays[0] = hd;

	printf("%02d/%02d - %-9s - %s\n", hdays[0].date->month, hdays[0].date->day, hdays[0].date->week_day, hdays[0].name);
}

int comp(const void * first, const void * second)
{
	int f = *((int *) first);
	int s = *((int *) second);
	return s - f;
}

int main()
{

	print_holidays();
	// sort
	int myarr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	qsort(myarr, 10, sizeof(int), comp);
	for(int i = 0; i < 10; i++) {
		printf("%d ", myarr[i]);
	}

	return 0;
}
