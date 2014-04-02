#include <iostream>
#include <lemon/lp.h>
#include <math.h>

using namespace lemon;
using namespace std;
int main(int argc, const char *argv[])
{
	Lp lp;
	std::vector<Lp::Col> a(4), b(4), c(4);
	lp.addColSet(a);
	lp.addColSet(b);
	lp.addColSet(c);

	Lp::Expr linha, linha2;

	lp.min();

	stringstream buffer1;

	//cout << buffer1.str() << endl;
	lp.obj(4*a[0]+4*a[1]+5*a[2]+7*a[3] +
		6*b[0]+7*b[1]+5*b[2]+6*b[3] +
		12*c[0]+10*c[1]+8*c[2]+11*c[3]);

	lp.addRow(a[0]+a[1]+a[2]+a[3] == 3000);
	lp.addRow(b[0]+b[1]+b[2]+b[3] == 6000);
	lp.addRow(c[0]+c[1]+c[2]+c[3] == 4000);
	/*
*/
	lp.addRow(0.3*a[0]+0.2*b[0]+0.8*c[0] <= 1500);
	lp.addRow(0.25*a[1]+0.3*b[1]+0.6*c[1] <= 1200);
	lp.addRow(0.2*a[2]+0.2*b[2]+0.6*c[2] <= 1500);
	lp.addRow(0.2*a[3]+0.25*b[3]+0.5*c[3] <= 2000);
	lp.colLowerBound(a, 0);
	lp.colLowerBound(b, 0);
	lp.colLowerBound(c, 0);

	lp.solve();

	if (lp.primalType() == Lp::OPTIMAL) {

		cout << fixed << "Custo de producao: " << lp.primal() << endl;
		cout << "Maquina 1: " << lp.primal(a[0]) << " " << lp.primal(b[0]) << " " << lp.primal(c[0]) << endl;
		cout << "Maquina 2: " << lp.primal(a[1]) << " " << lp.primal(b[1]) << " " << lp.primal(c[1]) << endl;
		cout << "Maquina 3: " << lp.primal(a[2]) << " " << lp.primal(b[2]) << " " << lp.primal(c[2]) << endl;
		cout << "Maquina 4: " << lp.primal(a[3]) << " " << lp.primal(b[3]) << " " << lp.primal(c[3]) << endl;

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
