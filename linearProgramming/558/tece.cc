#include <iostream>
#include <lemon/lp.h>
#include <math.h>

#define T 24*90

using namespace lemon;
using namespace std;
int main(int argc, const char *argv[])
{
	Lp lp;
	std::vector<Lp::Col> r(5), i(5), d(5);
	lp.addColSet(r);
	lp.addColSet(i);
	lp.addColSet(d);

	int dem[] = { 16e3, 48e3, 37e3, 21e3, 82e3 };
	double pI[] = { 0.8, 0.7, 0.75, 0.9, 0.7 };
	double pP[] = { 0.6, 0.5, 0.6, 0.7, 0.3 };
	double dobby[] = { 4.6, 4.6, 5.2, 3.8, 4.2 };
	double regular[] = { 0, 0, 5.2, 3.8, 4.2 };

	Lp::Expr linha, linha2;

	lp.min();

	stringstream buffer1;

	for (int j=0; j<5; j++) {
		linha += 10*pP[j]*dobby[j]*d[j] + 80*pP[j]*regular[j]*r[j] + pI[j]*i[j];
	//	buffer1 << "5*x" << j << " + 5*e" << j << " + ";
	}
	//cout << buffer1.str() << endl;
	lp.obj(linha);

	/*
	*/
	linha = 0;
	linha2 = 0;
	for (int j=0; j<5; j++) {
		linha += d[j];
		linha2 += r[j];
	}
	lp.addRow(linha <= T);
	lp.addRow(linha2 <= T);

	lp.addRow(r[0] == 0);
	lp.addRow(r[1] == 0);


	for (int j=0; j<5; j++) {
		lp.addRow(  80*r[j]*regular[j] + 10*d[j]*dobby[j]  + i[j] == dem[j]);
	}

	lp.colLowerBound(i, 0);
	lp.colLowerBound(r, 0);
	lp.colLowerBound(d, 0);

	lp.solve();

	if (lp.primalType() == Lp::OPTIMAL) {
		/*
		for (int i=0; i<12; i++) {
			cout << mes[i] << ": produzir " << lp.primal(x[i]) << " unidades do produto 1 e " << lp.primal(y[i]) << " unidades do produto 2" << endl;
		}
		*/
		//			cout << lp.col[i] << " ";
		//
		//

		cout << fixed << "Custo total da producao: " << lp.primal() << endl;
		cout <<	"Dobby:";
		for (int j=0; j<5; j++) cout << " " << 10*lp.primal(d[j]);
		cout << endl;
		cout <<	"Regular:";
		for (int j=2; j<5; j++) cout << " " << 80*lp.primal(r[j]);
		cout << endl;
		cout <<	"Comprar:";
		for (int j=0; j<5; j++) cout << " " << lp.primal(i[j]);
		cout << endl;

		/*
		int i = 0;
		for (LpBase::ColIt c(lp); c != INVALID; ++c) {
			//			cout << 3*lp.primal(c) << " " << endl;
			i++;
			if (i%6==0)
				cout << endl;
			cout << 1*lp.primal(c) << " ";
		}

		cout << endl;
		*/
	} else {
		cout << "Solucao otima nao foi encontrada." << endl;
	}

	return 0;
}
