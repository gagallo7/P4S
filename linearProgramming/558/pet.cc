#include <iostream>
#include <lemon/lp.h>
#include <math.h>

using namespace lemon;
using namespace std;
int main(int argc, const char *argv[])
{
	Lp lp;
	std::vector<Lp::Col> p(2);
	lp.addColSet(p);

	Lp::Expr linha, linha2;

	lp.min();

	stringstream buffer1;

	//cout << buffer1.str() << endl;
	lp.obj(20*(p[0]) + 15*(p[1]));

	lp.addRow(p[0]*0.4 + p[1]*0.32 >= 1e6);
	lp.addRow(p[0]*0.2 + p[1]*0.4 >= 0.5e6);
	lp.addRow(p[0]*0.35 + p[1]*0.2 >= 0.3e6);

	lp.colLowerBound(p, 0);

	lp.solve();

	if (lp.primalType() == Lp::OPTIMAL) {

		cout << fixed << "Custo de producao: " << lp.primal() << endl;
		cout << "numero de barris do tipo leve: " << lp.primal(p[0]) << endl;
		cout << "numero de barris do tipo pesado: " << lp.primal(p[1]) << endl;
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
