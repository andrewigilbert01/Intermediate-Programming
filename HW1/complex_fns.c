#include <stdio.h>
#include <math.h>
#include "my_complex.h"

double magnitude(Complex c) {
	double ans = sqrt((c.real*c.real) + (c.imag*c.imag));
	printf("%lf\n", ans);
	return ans;
}

double phase(Complex c) {
	double ph = atan(c.imag/c.real);
	ph = ph * (180/M_PI);
	double ans = (ph<0) ? -ph : ph;
	printf("%lf\n", ans);
	return ans;
}

void print_complex(Complex c) {
	if(c.imag < 0) {
		printf("%.3lf - %.3lf\n", c.real, -c.imag);
	}
	else {
		printf("%.3lf + %.3lf\n", c.real, c.imag);
	}
}

Complex complex_conj(Complex c) {
	c.imag *= -1;
	print_complex(c);
	return c;
}

Complex complex_add(Complex c1, Complex c2) {
	Complex c = {c1.real+c2.real, c1.imag+c2.imag};
	print_complex(c);
	return c;
}
		
Complex complex_sub(Complex c1, Complex c2) {
	Complex c = {c1.real-c2.real, c1.imag-c2.imag};
	print_complex(c);
	return c;
}

Complex complex_mult(Complex c1, Complex c2) {
	Complex c = {(c1.real*c2.real)+(c1.imag*c2.imag*-1), (c1.imag*c2.real) + (c1.real*c2.imag)};
	print_complex(c);
	return c;
}

Complex complex_div(Complex c1, Complex c2) {
	double denom = magnitude(c2)*magnitude(c2);
	if(denom == 0)
	{
		printf("Error: Attempt to divide by zero.\n");
	} else {
	Complex c = complex_mult(c1, complex_conj(c2));
	c.real /= denom;
	c.imag /= denom;
	print_complex(c);
	return c;
	}
}

void logic_handler(Complex (*ptr)(Complex, Complex),Complex c1, Complex c2){
	(*ptr)(c1,c2);
}

void complex_handler(Complex (*ptr)(Complex),Complex c1){
	(*ptr)(c1);
}

void complex_call(Complex (*ptr)(Complex, Complex) ,Complex c1, Complex c2)
{
	print_complex(((*ptr)(c1,c2)));
}
void complex_call_dos(double (*ptr)(Complex), Complex c)
{
	printf("%lf",((*ptr)(c)));	
}
