#include <iostream>
#include <lemon/lp.h>
#include <math.h>
using namespace lemon;
using namespace std;
int main(int argc, const char *argv[])
{
	Lp lp;
	std::vector<Lp::Col> x(12), y(12);
	lp.addColSet(x);
	lp.addColSet(y);

	char mes[][10] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
	int p1[] = {       10000, 10000, 10000, 10000, 30000, 30000, 30000, 30000, 30000, 100000, 100000, 100000 };
	int p2[] = {        50000, 50000, 15000, 15000, 15000, 15000, 15000, 15000, 15000, 50000, 50000, 50000 };
	int lim[] = { 120000, 20000, 120000, 120000, 40000, 40000, 40000, 40000, 130000, 130000, 130000, 130000 };

	Lp::Expr linha, basex, basey, V;

	lp.min();

	stringstream buffer1;

	for (int j=0; j<6; j++) {
		linha += 5*x[j];
		linha += 4.5*x[j+6];

		linha += 8.5*y[j];
		linha += 7*y[j+6];

		buffer1 << "5*x" << j << " + 5*e" << j << " + ";
	}
	for (int j=0; j<12; j++) {
		for(int i=0; i<=j; i++)
			V += 2*(x[i]-p1[i]) + 4*(y[i]-p2[i]);
	}
	linha += 0.2*V;
	//cout << buffer1.str() << endl;
	lp.obj(linha);

	/*
	*/

	for (int j=0; j<12; j++) {
		linha = 0;
		buffer1.str("");
		linha += x[j] + y[j];
		buffer1 << "x" << j << " + y" << j << " + ";
		lp.addRow(linha <= lim[j]);
		//cout << buffer1.str() << " <= " << lim[j] << endl;
	}

	for (int j=0; j<12; j++) {
		buffer1.str("");

		linha = x[j];
		for(int i=0; i<j;i++) {
			linha += x[i] - p1[i];
			buffer1 << "x" << i << " - p1" << i << " + ";
		}
		lp.addRow(linha >= p1[j]);
		buffer1 << "x" << j << " >= " << p1[j] << endl;

		linha = y[j];
		for(int i=0; i<j;i++) {
			linha += y[i] - p2[i];
			buffer1 << "y" << i << " - p2" << i << " + ";
		}
		lp.addRow(linha >= p2[j]);
		buffer1 << "y" << j << " >= " << p2[j] << endl;

		//cout << buffer1.str();
	}

	for (int j=0; j<12; j++) {
		lp.addRow(2*(x[j]-p1[j]) + 4*(y[j]-p2[j]) <= 150000);
		linha = 0;
		for(int i=0; i<=j; i++)
			linha += 2*(x[i]-p1[i]) + 4*(y[i]-p2[i]);
		lp.addRow(linha <= 150000);
	}
	/*
	*/

	lp.colLowerBound(x, 0);
	lp.colLowerBound(y, 0);

	lp.solve();

	if (lp.primalType() == Lp::OPTIMAL) {
		cout << fixed << "Custo total de producao e armazenagem: " << lp.primal() << endl;
		for (int i=0; i<12; i++) {
			cout << mes[i] << ": produzir " << lp.primal(x[i]) << " unidades do produto 1 e " << lp.primal(y[i]) << " unidades do produto 2" << endl;
		}
		//			cout << lp.col[i] << " ";
		/*
		int i = 0;
		for (LpBase::ColIt c(lp); c != INVALID; ++c) {
			//			cout << 3*lp.primal(c) << " " << endl;
			i++;
			if (i%13==0)
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
