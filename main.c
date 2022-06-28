#include <stdio.h>

// Fahrenheit-Celsius table
void fahrCelsTempConversion()
{
	printf("Fahrenheit to Celsius Conversion Table\n");
	printf("--------------------------------------\n");
	
	for (int fahr = 300; fahr >= 0; fahr -= 20)
		printf("%3d %6.1f\n", fahr, (5.0 / 9) * (fahr - 32));
}

// Celsius-Fahrenheit table
void celsFahrTempConversion()
{
	printf("Celsius to Fahrenheit Conversion Table\n");
	printf("--------------------------------------\n");
	float fahr, cels;
	int lower, upper, step;
	
	lower = -60;
	upper = 200;
	step = 20;
	
	cels = lower;
	while (cels <= upper)
	{
		fahr = (9.0 / 5) * cels + 32;
		printf("%3.0f %6.1f\n", cels, fahr);
		cels += step;
	}
}

int main()
{
	fahrCelsTempConversion();
	celsFahrTempConversion();
	return 0;
}

