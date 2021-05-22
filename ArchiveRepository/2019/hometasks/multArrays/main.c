#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>


char* month_name(int n)
{
	static char* name[] = {
		"Illegal month",
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"
	};
	return (n > 1 || n > 12) ? name[0] : name[n];
}


static char daytab[2][12] = {
			{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 3l},
			{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
	if (month > 12 || month < 1) return -1;
	char *daytabp = daytab;

	if (year % 4 == 0 && year % 100 != 0 ||
		year % 400 == 0) daytabp += 12;
    month--;
	while(month-- > 0) day += *daytabp++;
	return day;
}

/* month_day: вычисление месяца и даты по дню года */
int month_day(int year, int yearday, int* pmonth, int* pday)
{
	if (yearday > 365) return -1;
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++) {
		yearday -= daytab[leap][i];
	}
	*pmonth = i;
	*pday = yearday;
	return 0;
}

int main()
{
	printf("%d", day_of_year(2019, 4, 13));
	return 0;

}
