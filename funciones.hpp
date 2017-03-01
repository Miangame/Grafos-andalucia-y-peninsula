/*! 
  \file funciones.hpp
  \brief Funcion para mostrar un menu del programa en el main()
  \author Miguel Angel Gavilan Merino
  \date 25/05/2016
*/

#ifndef __FUNCIONES_HPP
#define __FUNCIONES_HPP


//Funciones de cabecera
#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include "vertice.hpp"
#include "lado.hpp"
#include "grafo.hpp"
#include "macros.hpp"


//Facilita la entrada y salida
using namespace ed;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;



bool cargarGrafo(Grafo * &g, string nombreF);
void mostrarGrafo(Grafo & g);
void floyd(Grafo &g, float ** distancias, int ** intermedios);
float caminoMin(Grafo &g,float** distancias,int ** intermedios, const Vertice &origen, const Vertice &destino);
void copiaMatrix(double ** matrix, float ** copia, const int &tam);
void sumarDist(Grafo *g,int *suma);




//! \name Funcion menu para el programa

/*! 
	\brief Muestra un menu en el main para hacer funcionar el programa
*/
void menu()
{	
	Grafo * g = 0;
	int opc;
	string nombreF;
	bool cargado;	
	float ** distancias;
	int ** intermedios;
	string nodo1, nodo2;
	Vertice origen;
	Vertice destino;
	float caminoMinimo;
	bool existe1, existe2;
	int * sumaM;
	int aux;
	string aux2;
	

	do
	{
		BORRAR;
		LUGAR(5, 10);
		cout << "\e[34;1m-----Escoja alguna de las siguientes opciones-----\e[0m";
		LUGAR(7,10);
		cout << "\e[31m0. Salir del programa\e[0m" << endl;
		LUGAR(8,10);
		cout << "\e[31m1. Cargar grafo desde fichero\e[0m" << endl;
		LUGAR(9,10);
		cout << "\e[31m2. Mostrar el grafo por pantalla\e[0m" << endl;
		LUGAR(10,10);
		cout << "\e[31m3. Algoritmo de Floyd\e[0m" << endl;
		LUGAR(15,10);
		cout << "\e[33mOpcion --> \e[0m";
		cin >> opc;	


		switch(opc)
		{
			case 0:
				BORRAR;
				LUGAR(10,50);
				INVERSO;
				cout << "\n>>>Saliendo del programa...\n" << endl;
				APAGA;

				LUGAR(23,25);
				printf("pulse ");
				SUBRAYADO;
				printf("ENTER");
				APAGA;
				printf(" para ");
				INVERSO;
				printf("continuar"); 
				APAGA;
				getchar();
				getchar();
				BORRAR;
			break;
			
			case 1:
				BORRAR;
				LUGAR(10, 5);
				cout << "Introduzca el nombre del fichero: ";
				cin >> nombreF;

				cargado=cargarGrafo(g, nombreF);

				if(cargado==false)
				{
					getchar();
					BORRAR;
					LUGAR(10, 5);
					cout << "Error al cargar el fichero...!!";

					LUGAR(23,25);
					printf("pulse ");
					SUBRAYADO;
					printf("ENTER");
					APAGA;
					printf(" para ");
					INVERSO;
					printf("continuar"); 
					APAGA;
					getchar();
				}
				else
				{
					getchar();
					
					LUGAR(15, 5);
					cout << ">>>Fichero cargado correctamente...!!";

					distancias=(float**)malloc(sizeof(float*)*(g->capacidad()));
					for (unsigned int i=0; i<g->capacidad(); i++)
					{
						distancias[i]=(float*)malloc(sizeof(float)*(g->capacidad()));
					}

					intermedios=(int**)malloc(sizeof(int*)*(g->capacidad()));
					for (unsigned int i=0; i<g->capacidad(); i++)
					{
						intermedios[i]=(int*)malloc(sizeof(int)*(g->capacidad()));
					}

					//Copia la matriz del grafo a la matriz de distancias
					copiaMatrix(g->getMatrix(), distancias, g->capacidad());

					//Inicializa la matriz de intermedios a 0
					for (unsigned int i = 0; i < g->capacidad(); ++i)
					{
						for (unsigned int j = 0; j < g->capacidad(); ++j)
						{
							intermedios[i][j]=0;
						}
					}

					LUGAR(23,25);
					printf("pulse ");
					SUBRAYADO;
					printf("ENTER");
					APAGA;
					printf(" para ");
					INVERSO;
					printf("continuar"); 
					APAGA;
					getchar();
				}
			break;

			case 2:
				if (g==0)
				{
					getchar();
					BORRAR;
					LUGAR(10, 5);
					cout << "Grafo vacio, por favor use primero la opcion 1";

					LUGAR(23,25);
					printf("pulse ");
					SUBRAYADO;
					printf("ENTER");
					APAGA;
					printf(" para ");
					INVERSO;
					printf("continuar"); 
					APAGA;
					getchar();
				}
				else
				{
					mostrarGrafo(*g);
				}				
			break;

			case 3:
				if (g==0)
				{
					getchar();
					BORRAR;
					LUGAR(10, 5);
					cout << "Grafo vacio, por favor use primero la opcion 1";

					LUGAR(23,25);
					printf("pulse ");
					SUBRAYADO;
					printf("ENTER");
					APAGA;
					printf(" para ");
					INVERSO;
					printf("continuar"); 
					APAGA;
					getchar();
				}
				else
				{
					int cont=5;
					existe1=false;
					existe2=false;
					aux=10000;
					aux2="NULL";

					floyd(*g, distancias, intermedios);

					getchar();
					BORRAR;
					sumaM=new int[g->numVertices()];
					sumarDist(g,sumaM);
					
					
					for(unsigned int i=0;i<g->numVertices();i++)
					{
					
						g->goTo(i);
						origen=g->currVertex();
						LUGAR(cont, 15);
						cout<<"Nodo Origen: "<<origen.getData()<<"-> "<<sumaM[origen.getEtiqueta()]<<" km al resto de ciudades"<<endl;
						
						
						if(sumaM[origen.getEtiqueta()]<aux)
						{
							aux2=origen.getData();
							aux=sumaM[origen.getEtiqueta()];
						}
						
						
						cont++;
						if (cont==13)
						{
							LUGAR(23,25);
							printf("pulse ");
							SUBRAYADO;
							printf("ENTER");
							APAGA;
							printf(" para ");
							INVERSO;
							printf("continuar"); 
							APAGA;
							getchar();
							BORRAR;

							cont=5;
						}
					}

						BORRAR;
						LUGAR(10, 5);
						cout << "El vértice que tiene la menor suma de distancias a los demás vértices es: " << endl;
						LUGAR(13, 30);
						cout << aux2 << " con " << aux << " km" << endl;

						LUGAR(23,25);
						printf("pulse ");
						SUBRAYADO;
						printf("ENTER");
						APAGA;
						printf(" para ");
						INVERSO;
						printf("continuar"); 
						APAGA;
						getchar();


						do
						{
							BORRAR;
							LUGAR(10, 5);
							cout << "Introduzca el nodo origen: ";
							cin>>nodo1;
							getchar();


							if( (existe1=g->searchVertex(nodo1))==true )
							{
								origen=g->currVertex();
							}
							else
							{
								
								BORRAR;
								LUGAR(10, 30);
								cout << "No existe ese nodo!";

								LUGAR(23,25);
								printf("pulse ");
								SUBRAYADO;
								printf("ENTER");
								APAGA;
								printf(" para ");
								INVERSO;
								printf("continuar"); 
								APAGA;
								getchar();
							}
						}while((existe1=g->searchVertex(nodo1))==false);

						do
						{
							BORRAR;
							LUGAR(10, 5);
							cout << "Introduzca el nodo destino: ";
							cin>>nodo2;
							getchar();						

							if( (existe2=g->searchVertex(nodo2)) ==true)
							{
								destino=g->currVertex();
							}
							else
							{
								
								BORRAR;
								LUGAR(10, 30);
								cout << "No existe ese nodo!";

								LUGAR(23,25);
								printf("pulse ");
								SUBRAYADO;
								printf("ENTER");
								APAGA;
								printf(" para ");
								INVERSO;
								printf("continuar"); 
								APAGA;
								getchar();
							}
						}while((existe2=g->searchVertex(nodo2)) ==false);

						//Si existen los nodos se imprime el recorrido entre las dos localidades y devuelve la distancia entre ellas
						if(existe1 && existe2)
						{
							BORRAR;
							LUGAR(10, 30);
							cout << "----Camino minimo----" << endl;

							caminoMinimo=caminoMin(*g, distancias, intermedios, origen, destino);
							cout<<destino.getData()<<endl;

							
							LUGAR(12, 5);
						  	cout<<endl<<"El nodo origen "<<nodo1<<" dista "<<caminoMinimo<<" del nodo destino "<<nodo2<<"."<<endl;

						  	LUGAR(23,25);
							printf("pulse ");
							SUBRAYADO;
							printf("ENTER");
							APAGA;
							printf(" para ");
							INVERSO;
							printf("continuar"); 
							APAGA;
							getchar();
				  		}

				}	
			break;

			default: 
				BORRAR;
				PARPADEO;
				LUGAR(10,25);
				cout << "\n>>>Opcion incorrecta, vuelva a introducir una opcion valida..\n" << endl;
				APAGA;

				LUGAR(23,25);
				printf("pulse ");
				SUBRAYADO;
				printf("ENTER");
				APAGA;
				printf(" para ");
				INVERSO;
				printf("continuar"); 
				APAGA;
				getchar();
				getchar();
		}
	}while(opc!=0);

	//Fin de la funcion
}




/*! 
	\brief Carga un grafo de un fichero introducido por teclado
	\param g de tipo grafo
	\param nombreF de tipo string
	\return true o false si se carga o no correctamente
*/
bool cargarGrafo(Grafo * &g, string nombreF)
{
	BORRAR;
	ifstream f(nombreF.c_str()); //Se define el stream de lectura y se abre el fichero.
	if (not f)
	{
		return false;
	}
  
  	//Se definen variables auxiliares para cargar el grafo.
	unsigned int vertices;
	int type;
	bool isDirected;
	string dataVertice;
	string dataEdgeFirst, dataEdgeSecond;
	Vertice first, second;
	double peso;
	
  	f >> vertices; //Se lee el numero de nodos.
  	f >> type; //Se lee el tipo.
  
 	if (type == 0)
		isDirected = false;
	else
		isDirected = true;
	
	LUGAR(10, 5);
	cout << "-> Cargados tipo y numero de nodos\n";

  	g = new Grafo (vertices, isDirected); //Se reserva espacio para el grafo y se invoca al constructor.
	
	//Lectura de los data de los nodos
	for(unsigned int i = 1; i <= vertices; i++)
	{
		f >> dataVertice;
		g->addVertex(dataVertice);
	}
	
	LUGAR(11, 5);
	cout << "-> Cargados nodos\n";
	//Lectura de los lados.
	
	//Inicializamos todos los lados a infinito y después se sobreescriben

	while(f >> dataEdgeFirst >> dataEdgeSecond >> peso )
	{
		//Creamos los nodos que forman parte del lado
		//Para localizar el indice del nodo
		g->searchVertex(dataEdgeFirst);
		first.setEtiqueta((g->currVertex()).getEtiqueta()); 
		
		first.setData(dataEdgeFirst);
		
		//Para localizar el indice del nodo
		g->searchVertex(dataEdgeSecond);
		second.setEtiqueta((g->currVertex()).getEtiqueta());
		
		second.setData(dataEdgeSecond);
		
		//Añade el lado(first, second) con peso peso;
		g->addEdge(peso, first, second);
		
	}
	f.close();
	
	LUGAR(12, 5);
	cout << "-> Cargados lados\n";
	
	return true;
}




/*! 
	\brief Imprime el grafo por pantalla
	\param g de tipo grafos
*/
void mostrarGrafo(Grafo & g)
{	
	int i=13;
	int j=14;
	g.beginVertex();
	
	getchar();
	BORRAR;
	LUGAR(10, 30);
	cout << "Nodos del grafo\n";
	LUGAR(11, 30);
	cout << "===============\n";
	
	Vertice v;
	
	do
	{
		v = g.currVertex();

		LUGAR(i, 30);
		cout << v.getData() << endl;
		g.nextVertex();
		i++;
		if (i==21)
		{
			LUGAR(23,25);
			printf("pulse ");
			SUBRAYADO;
			printf("ENTER");
			APAGA;
			printf(" para ");
			INVERSO;
			printf("continuar"); 
			APAGA;
			getchar();
			BORRAR;

			LUGAR(10, 30);
			cout << "Nodos del grafo\n";
			LUGAR(11, 30);
			cout << "===============\n";
			i=13;
		}
	}while(not g.afterEndVertex());

	
	
	//Lados del grafo
	BORRAR;
	LUGAR(10, 30);
	cout << "Lados del grafo\n";
	LUGAR(11, 30);
	cout << "===============\n";
	LUGAR(12, 30);
	cout << "Lados = " << g.numLados() << endl;

	Vertice aux;
	g.beginVertex();

	while(not g.afterEndVertex())
	{
		aux = g.currVertex();
		
		g.beginEdge(aux); //Se posiciona en el primer lado que tiene a aux como nodo origen
		while (not g.afterEndEdge())
		{
			LUGAR(j,30);
			cout << g.currEdge().first().getData() << " -> " << g.currEdge().second().getData() << " = " << g.currEdge().getData() << endl;
			g.nextEdge();
			j++;
			if(j==22)
			{
				LUGAR(23,25);
				printf("pulse ");
				SUBRAYADO;
				printf("ENTER");
				APAGA;
				printf(" para ");
				INVERSO;
				printf("continuar"); 
				APAGA;
				getchar();
				BORRAR;

				LUGAR(10, 30);
				cout << "Lados del grafo\n";
				LUGAR(11, 30);
				cout << "===============\n";
				LUGAR(12, 30);
				cout << "Lados = " << g.numLados() << endl;
				j=14;
			}
		}
		g.nextVertex();
	}
}




/*! 
	\brief Funcion que realiza el algoritmo de Floyd
	\param g de tipo Grafo
	\param distancias de tipo float **
	\param intermedios de tipo int **
*/
void floyd(Grafo &g, float ** distancias, int ** intermedios)
{
	float suma;
	int n=g.capacidad();

	//En primer lugar inicializamos la diagonal de la matriz distancias a 0
	for(int i = 0; i < n; i++)
        distancias[i][i] = 0;

	//Hacemos un bucle triple para recorrer la matriz de distancias a la vez que se recorre la fila y columna por cada elemento
    for(int k = 0; k < n; k++)
    	//Para cada elemento k se recorre la matriz para comprobar si utilizando k como intermedio se recorta la distancia
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
            	//Si alguna distancia al elemento k desde i a k o de k a j fuera infinito, la suma es infinito
            	if(distancias[i][k]==std::numeric_limits<float>::infinity() || distancias[k][j]==std::numeric_limits<float>::infinity())
            	{
					suma=std::numeric_limits<float>::infinity();
				}
            	else
            	{
					suma = distancias[i][k] + distancias[k][j];
				}

            	//Si la distancia de i a j con k de intermedio es menor que la distancia anterior entonces se coloca la nueva distancia y k como intermedio
                if(distancias[i][j] > suma)
                {
                    distancias[i][j] = suma;
                    intermedios[i][j]= k;
            	}
            }
}




/*! 
	\brief Calcula el camino minimo entre dos vertices
	\param g de tipo grafo
	\param distancias de tipo float **
	\param intermedios de tipo int **
	\param origen de tipo Vertice
	\param destino de tipo Vertice
*/
float caminoMin(Grafo &g,float** distancias,int ** intermedios, const Vertice &origen, const Vertice &destino)
{
	float suma=0;
	Vertice aux;
	unsigned int label;

	//Si el valor intermedio entre origen y destino es 0 quiere decir que la distancia minima es directa
	if(intermedios[origen.getEtiqueta()][destino.getEtiqueta()]==0)
	{
		cout<<origen.getData()<<" -> ";
		return (distancias[origen.getEtiqueta()][destino.getEtiqueta()]);
	}
	else
	{
		//Sino se trata con la etiqueta del valor intermedio
		label=intermedios[origen.getEtiqueta()][destino.getEtiqueta()];
		//Se apunta al vertice con esa etiqueta
		g.goTo( label );
		//Y si recoge el vertice
		aux=g.currVertex();

		//Una vez aqui evaluamos de forma recursiva la distancia del origen a ese vertice y de ese vertice al destino
		suma+= caminoMin(g, distancias, intermedios, origen, aux);
		suma+= caminoMin(g, distancias, intermedios, aux, destino);

		return (suma);
	}

}



/*! 
	\brief copia una matriz en otra auxiliar
	\param matrix de tipo double **
	\param copia de tipo float **
	\param tam de tipo int
*/
void copiaMatrix(double ** matrix, float ** copia, const int &tam)
{
	for (int i = 0; i < tam; ++i)
	{
		for (int j = 0; j < tam; ++j)
		{
			copia[i][j]=matrix[i][j];
		}
	}
}



/*! 
	\brief Suma las distancias de un nodo al resto de nodos
	\param g de tipo grafo
	\param suma de tipo int
*/
void sumarDist(Grafo *g,int *suma)
{

	Vertice u,v;
	double x,total=0;
	
	for(unsigned int i=0;i<g->numVertices();i++){
		
		total=0;
		g->goTo(i);
		u=g->currVertex();
		
		for(unsigned int j=0;j<g->numVertices();j++){
	
			g->goTo(j);
			v=g->currVertex();
			
			x=g->adjacent(u,v);
			
			if(x!=std::numeric_limits <double>::infinity()){
			
				total+=x;
			}
		}
	
		suma[i]=total;	
	}
}




#endif