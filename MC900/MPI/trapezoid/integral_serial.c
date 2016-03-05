/* funcao a ser calculada a integral */
double f(double x) {
	double y;

	y = exp(x);

	return y;
}

/* calcula a area sob a curva do inicio ate o fim passados como argumentos */
double Trap(int rank, double a, double b, double h, int trapCount) {
	double estimate, x, sum = 0;
	int i;

	estimate = (f(a) + f(b))/2.0;
	for(i=1;i<trapCount;i++) {
		x=a + i*h;
		estimate += f(x);
	}
	estimate = estimate*h;

	return estimate;
}
