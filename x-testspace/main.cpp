#include "meethutils.h"
#include "vec2.h"
int main()
{
	int val = min(1, 3);

	vec2 test;
	test.x = 5;
	test.y = 20;

	vec2 testb;
	test.x = 3;
	test.y = 3;

	vec2 result = test + testb;

	while (true);
}