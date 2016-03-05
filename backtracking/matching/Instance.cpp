/* 
 * File:   Instance.cpp
 * Author: eduardoxavier
 * 
 * Created on 19 de Julho de 2013, 14:50
 */

#include <fstream>
#include<iomanip>

#include "Instance.h"

Instance::Instance() {
    numberVertices = 0;
    s=0;
    t=0;
    adjMatrix = NULL;
}

Instance::Instance(const Instance& orig) {
    this->numberVertices = orig.numberVertices;
    s = orig.s;
    t = orig.t;
    freeMatrix();
    allocateMatrix();
    for(int i=0; i<numberVertices; i++)
        for(int j=0; j<numberVertices; j++)
            adjMatrix[i][j] = orig.adjMatrix[i][j];
    
}

Instance::~Instance() {
    freeMatrix();
}

/*Arquivos tem na 
 primeira linha o total de vertices
 Nas linhas subsequentes temos o grafo representado como uma matriz de adjacencia*/

void Instance::readInstance(/*std::string fileName*/) {
    using namespace std;
    ifstream input;
    
    
//     input.open(fileName.c_str());
    freeMatrix();
    cin >> this->numberVertices;
    allocateMatrix();
    cin >> s;
    cin >> t;

    for (int i = 0; i<numberVertices; i++) {
        for(int j=0; j<numberVertices; j++){
            cin >> adjMatrix[i][j];
        }
    }
    
//     input.close();
}

void Instance::printInstance() {
    using namespace std;

    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    streamsize prec = cout.precision(2);

    cout << "Instance size: " << this->numberVertices << endl;
    cout << "Source: " << s <<endl;
    cout << "Destination " << t << endl;
    for (int i = 0; i<numberVertices; i++) {
        for(int j=0; j<numberVertices; j++){
            cout << setw(2) << adjMatrix[i][j];
	    cout << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}



void Instance::freeMatrix(){
    if(adjMatrix != NULL){
        for(int i=0; i<numberVertices; i++){
            if(adjMatrix[i] != NULL){
                delete[] adjMatrix[i];
            }
        }
        delete[] adjMatrix;
    }
}

void Instance::allocateMatrix(){
    adjMatrix = new int *[numberVertices];
    for(int i=0; i<numberVertices; i++){
        adjMatrix[i] = new int[numberVertices];
        for(int j=0; j<numberVertices; j++)
            adjMatrix[i][j]=0;
    }
}