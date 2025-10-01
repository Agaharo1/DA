
using namespace std;
#include <iostream>   
#include <vector>
#include "Grafo.h"


class MaximaCompConexa {
public:  //Visit y maxim son atributos privados de la clase
		 //Visit vector de boolean para marcar que nodos han sido visitados
	MaximaCompConexa(Grafo const& g) : visit(g.V(), false), maxim(0) {
		for (int v = 0; v < g.V(); ++v) { //g.V() es  el numero de vertices del grafo
			if (!visit[v]) {
				int tam = dfs(g, v);
				maxim = max(maxim, tam);
			}
			
		}
	}
	int maximo() const {
		return maxim;
	}
private:
	vector<bool> visit;
	int maxim;

	int dfs(Grafo const& g, int v) { //Funcion para contar los vertices adyacentes
		visit[v] = true;
		int tam = 1;
		for (int w : g.ady(v)) {
			if (!visit[w])
				tam += dfs(g, w);
		}
		return tam;
	}
};


void resuelveCaso() {
	int numPersonas,numParejas;
	cin >> numPersonas >> numParejas;

	Grafo amigos(numPersonas);
	int a, b;
	for (int i = 0; i < numParejas; ++i) {
		cin >> a >> b;
		amigos.ponArista(a - 1, b - 1); //Para crear arista entre dos vertices
	}

	MaximaCompConexa mcc(amigos);
	cout << mcc.maximo() << "\n";


}


int main()
{
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
}
