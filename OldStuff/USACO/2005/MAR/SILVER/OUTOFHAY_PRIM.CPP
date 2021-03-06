/*
Alfonso Alfonso Peterssen
12 - 8 - 2007
USACO 2005 MAR Silver "Sin Heno"
MST -> Prim O( V^2 )
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXV 2001

int V, E, i, j, k, sol;
bool mark[MAXV];
int D[MAXV], C[MAXV][MAXV];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> V >> E;

  memset( C, 127, sizeof( C ) );
  memset( D, 127, sizeof( D ) );

  for ( i = 0; i < E; i++ ) {
    int u, v, w;
    fin >> u >> v >> w;
    C[u][v] = C[v][u] <?= w;
  }

  /* Prim */
  D[1] = 0;
  for ( i = 0; i < V; i++ ) {

    k = 0;
    for ( j = 1; j <= V; j++ )
      if ( !mark[j] && D[j] < D[k] ) k = j;

    for ( j = 1; j <= V; j++ )
      D[j] <?= C[k][j];

    sol >?= D[k];
    mark[k] = true;
  }

  fout << sol << endl;

  return 0;
}

/*
Problema 8: Sin Heno [Entrenadores, 2004]

Las vacas se han quedado sin heno, un suceso horrible que debe ser
remediado inmediatamente. Bessie quiere recorrer algunas de las N (2
<= N <= 2,000) otras granjas (numeradas 1..N) para investigar su
situaci�n de heno. Ella recorrer� algunos de todos los M (1 <= M <=
10,000) caminos de doble v�a cuya longitud no excede 1,000,000,000
que conectan las granjas. Algunas granjas pueden estar conectadas
m�ltiplemente con caminos de diferentes longitudes.

Bessie est� tratando de decidir el tama�o de la cantimplora que ella
necesitar�. Ella sabe que necesita una onza de agua por cada unidad de
distancia de un camino. Dado que ella puede obtener m�s agua en cada
granja, ella �nicamente est� preocupada por la longitud del camino m�s
largo. Por supuesto, ella planea su ruta entre granjas de tal manera
que ella minimice la cantidad de agua que ella debe cargar.

Ayude a que Bessie sepa la cantidad m�s grande de agua que ella tendr�
que cargar: �cu�l es la longitud del camino m�s largo que ella tendr�
que recorrer entre cualesquiera dos granjas, presumiendo que ella
elija rutas que minimicen ese n�mero?

NOMBRE DEL PROBLEMA: outofhay

FORMATO DE ENTRADA:

* L�nea 1: Dos enteros separados por espacio, N y M.

* L�neas 2..1+M: La l�nea i+1 contiene tres enteros separados por
    espacios, A_i, B_i, y L_i, describiendo un camino de A_i a B_i de
    longitud L_i.

ENTRADA EJEMPLO (archivo outofhay.in):

3 3
1 2 23
2 3 1000
1 3 43


FORMATO DE SALIDA:

* L�nea 1: Un solo entero que es la longitud del camino m�s largo que
    necesita ser recorrido.

SALIDA EJEMPLO (archivo outofhay.out):

43

DETALLES DE LA SALIDA:

Con el prop�sito de llegar a la granja 2, Bessie viaja por un camino
de longitud 23. Para llegar a la granja 3, Bessie viaja por un camino
de longitud 43. Con una capacidad de 43, ella puede viajar a lo largo
de estos caminos dado que ella recarga su cantimplora a capacidad
m�xima antes de comenzar un nuevo camino.
*/
