/* 
 * File:   Instance.cpp
 * Author: eduardoxavier
 * 
 * Created on 19 de Julho de 2013, 14:50
 */

#include "Instance.h"

Instance::Instance() {
}

Instance::Instance(const Instance& orig) {
    this->numberElements = orig.numberElements;
    this->numberSets = orig.numberSets;
    this->k = orig.k;
    this->sets = orig.sets;
}

Instance::~Instance() {
    numberElements = 0;
    numberSets = 0;
    k=0;

}

/*Arquivos tem na 
 primeira linha o total de elementos
 * segunda linha o total de conjuntos
 nas linhas subsequentes
 tamanho do conjunto e seu valor
 indices dos elementos do conjunto */

void Instance::readInstance(){
    using namespace std;

    cin >> this->k;
    cin >> this->numberElements;
    cin >> this->numberSets;
    for(int i=0; i<this->numberSets; i++){
        Set auxSet;
        cin >> auxSet.size;
        cin >> auxSet.value;
        for(int j=0; j<auxSet.size; j++){
            int ind;
            cin >> ind;
            auxSet.elements.push_back(ind);
        }
	this->sets.push_back(auxSet);
    }
}


void Instance::printInstance(){
    using namespace std;

    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    streamsize prec = cout.precision(2);

    cout << "Instance k: " << this->k << endl;
    cout << "Instance has " << this->numberElements << " elements.\n";
    cout << "Instance has " << this->numberSets << " sets.\n";
    for(int i=0; i<this->numberSets; i++){
        Set auxSet = this->sets.at(i);
        cout << "Set " << (i+1) << " with value " << auxSet.value <<endl;
        cout << "Set " << (i+1) << " with  " << auxSet.size << " elements " <<endl;
        for(int j=0; j<auxSet.size; j++){
            cout << "  " << auxSet.elements.at(j) <<endl;
        }
    }
    
    cout.setf(orig,ios_base::floatfield);
    cout.precision(prec);   
}


bool Instance::feasibleSolution(int sol[]){
    int ele[numberElements];
    for(int i=0; i<numberElements;i++){
        ele[i]=0;
    }
    
    int kaux=0;
    for(int i=0; i<numberSets; i++){
        if(sol[i] == 1){
            kaux++;
            for(int j=0; j<sets.at(i).elements.size();j++){
                ele[sets.at(i).elements.at(j) - 1] = 1;
            }
        }
    }
    
    if(kaux>this->k)
        return 0;
    
    int aux=0;
    for(int i=0; i<numberElements; i++){
        aux = aux + ele[i];
    }
    
    
    
    if(aux==numberElements)
        return true;
    else
        return false;
    
}


