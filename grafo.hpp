#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <vector>
#include <iostream>
#include <cassert>
#include <limits>
#include "vertice.hpp"
#include "lado.hpp"


using std::string;
using std::vector;
using std::cout;
using std::endl;




/*!
\brief Espacio de nombres para la asignatura Estructura de datos.

*/
namespace ed
{
	/*! 	
		\brief Class of GraphMatrix.
	*/
	class Grafo
	{
		private:
			vector <Vertice> _v;		//!<Vector de vertices
		    double **_e;				//!<Matriz de adyacencia
			bool _dirigido;				//!<Saber si el grafo es dirigido o no
			Vertice * _cursorVertex;	//!<cursor de vertices
			Lado * _cursorEdge; 		//!<cursor de lados
			int _vertices;				//!<Número de vértices (número de ciudades que tengo. Corresponde con el primer número del fichero)
			int _edge;					//!<Número de lados
			int _tam;					//!<Capacidad del grafo (Número máximo de posibilidades que hay)

		public:
			//! \name Constructor

			/*!
				\fn Grafo (const unsigned int & _capacity=0, const bool & _directed = true);
				\brief Crea un grafo vacío con la capacidad a 0 y suponiendo que es dirigido por defecto.
			 */
			Grafo (const unsigned int & capacity=0, const bool & isDirected = true)
			{

				assert (capacity > 0);

				_e=new double*[capacity];
				
				for(unsigned int i=0;i<capacity;i++)
				{
					_e[i]=new double[capacity];
				}

				for(unsigned int i=0;i< capacity;i++)
				{
					for(unsigned int j=0;j<capacity;j++)
					{
						_e[i][j]=std::numeric_limits<double>::infinity();
					}
				}

				_cursorVertex=NULL;
				_cursorEdge=NULL;
				_vertices=0;
				_edge=0;
				_tam=capacity;
				_dirigido=isDirected;
			}



			//! \name OBSERVADORES

			/*!
				\fn 	const unsigned int numVertices()const;
				\brief  Función que permite consultar el numero de vertices de un grafo.
				\return valor del atributo __vertices
			*/
			const unsigned int numVertices()const
			{
				return _vertices;
			}
			
			/*!
				\fn 	const unsigned int numLados()const;
				\brief  Función que permite consultar el numero de lados de un grafo.
				\return valor del atributo _edge
			*/
			const unsigned int numLados()const
			{
				return _edge;
			}
			
			/*!
				\fn 	const unsigned int capacidad()const;
				\brief  Función que permite consultar la capacidad de un grafo
				\return valor del atributo _tam
			*/
			const unsigned int capacidad()const
			{
				return _tam;
			}

			/*!
				\fn 	float ** getMatrix();
				\brief  Función que devuelve la matriz
			*/
			double ** getMatrix()
			{
				return _e;
			}

			
			/*!
				\fn 	bool isEmpty() const;
				\brief  Función que permite consultar si el grafo está vacío
				\return true si está vacío y false en caso contrario
			*/
			bool isEmpty() const
			{
				if (numVertices()==0 && numVertices()==0)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			
			/*!
				\fn 	const bool isDirected() const;
				\brief  Función que permite consultar si el grafo es dirigido
				\return true si es dirigido y false en caso contrario
			*/
			const bool  isDirected() const
			{
				if(_dirigido==0)
				{
					return false;
				}
				else
				{
					return true;
				}
			}	

			
			/*!
				\fn 	  	const double adjacent(const Vertice & u, const Vertice & v) const;
				\brief      Función que devuelve el elemento de la matriz de adyacencia (INFINITO si no hay lado)
				\param      u de tipo Vertex
				\param      v de tipo Vertex
				\return 	Elemento de la matriz de adyacencia
			 */
			const double adjacent(const Vertice & u, const Vertice & v) const
			{
				double* retVal=NULL;
				retVal=&_e[u.getEtiqueta()][v.getEtiqueta()];

				if(retVal==NULL)
				{
					return ( std::numeric_limits<double>::infinity() );
				}

				return (*retVal);

			}
			
			/*!
				\fn 	   	bool hasCurrVertex() const;
				\brief      Función para saber si está el cursor de vértices en una posición válida
				\return 	true si e stá en una posición válida y false en caso contrario
			 */
			bool hasCurrVertex() const
			{
				return _cursorVertex!=NULL;		
			} 
			
			/*!
				\fn 	   	const Vertex & currVertex() const;
				\brief      Función que devuelve el vértice referenciado por cursor de vértices
				\pre		hasCurrVertex() is true.
			 */
			const Vertice & currVertex() const
			{
				assert(hasCurrVertex());

				return (*_cursorVertex);
			}
      
			/*!
				\fn 	   	bool hasCurrEdge() const;
				\brief      Función para saber si está el cursor de lados en una posición válida
				\return 	true si e stá en una posición válida y false en caso contrario
			 */
			bool hasCurrEdge() const
			{
				return _cursorEdge!=NULL;
			}
			
			/*!
				\fn 	   	const Edge currEdge();
				\brief      Función que devuelve el vértice referenciado por cursor de lados
				\pre		hasCurrEdge() is true.
			*/
			const Lado currEdge()
			{
				assert(hasCurrEdge());

				return (*_cursorEdge);
			}
			
			//! \name MODIFICADORES
			
			/*!
				\fn 	   	void makeDirected();
				\brief      Función que crea un grafo dirigido
			*/
			void makeDirected()
			{
				_dirigido=1;
			};
			
			/*!
				\fn 	   	void makeDirected();
				\brief      Función que crea un grafo no dirigido
			*/
			void makeUndirected()
			{
				_dirigido=0;
			};

			/*!
				\fn 	   	void addVertex(const string & data);
				\brief      Función que añade un vertice al grafo a partir del data
				\param 		data que va ser el punto de partida
				\pre 		numVertices() < capacidad()
			*/
			void addVertex(const string & data)
			{
				assert(numVertices() < capacidad() );
				Vertice v;
				v.setData(data);
				v.setEtiqueta(_vertices);
				_vertices++;
				_v.push_back(v);
			
			}

			/*!
				\fn 	 	void addEdge(const double & data, const Vertice & u, const Vertice & v);
				\brief      Función que añade un lado al grafo a partir de sus dos vértices y su peso. Esto se reflejará sólo en la matriz de adyacencia
				\param 		data que va ser el peso del cual se va a partir
				\param  	u primer vertice
				\param		v segundo vertice
				\pre 		u y v pertenecen al grafo
			*/
			void addEdge(const double & data, const Vertice & u, const Vertice & v)
			{
				//Comprobar si está u y v en el grafo
				_e[u.getEtiqueta()][v.getEtiqueta()]=data;
				_edge++;
				if(!isDirected())
				{
					_e[v.getEtiqueta()][u.getEtiqueta()]=data;
				}
			}
					
			/*!
				\fn			void searchVertex(const string &data);
				\brief      Función que busca un vertice a partir de su data, colocando el cursor en dicho vértice
				\param 		data que va ser el punto de partida
			*/
			bool searchVertex(const string &data)
			{
				bool retVal=false;

				for (unsigned int i = 0; i < _v.capacity() && retVal==false; ++i)
				{
					if(_v[i].getData() ==data)
					{
						_cursorVertex=&_v[i];
						retVal=true;
					}
				}

				return retVal;
			}
      
			/*!
				\fn	void goTo(const Vertice & u);
				\brief      Función que lleva el cursor a un vertice a partir de dicho vertice
				\param 		u que va ser el vertice de partida
				\pre 		u pertenece al grafo
			*/
			void goTo(const Vertice & u)
			{
				searchVertex(u.getData());
				assert(hasCurrEdge());

				for (unsigned int i = 0; i < _v.capacity(); ++i)
				{
					if(_v[i].getData()==u.getData())
					{
						_cursorVertex=&_v[i];
					}
				}
			}
			
			/*!
				\fn		void goTo(const int &idx);
				\brief          Función que lleva el cursor a un vertice a partir de la posición de dicho vertice
				\param 		idx que va a ser la posición de dicho vertice
				\pre 		0 <= idx < numVertexes()
			*/
			void goTo(const int &idx)
			{
				assert(0<=idx && unsigned(idx)<numVertices());
				_cursorVertex=&_v[idx];
			}
			
			
			/*!
				\fn		void searchEdge(const Vertice & u, const Vertice & v);
				\brief          Función que lleva el cursor a un lado a partir de sus vertices
				\param 		u primer vertice de partida
				\param 		v segundo vertice de partida
				\pre 		u y v pertenecen al grafo
			*/
			void searchEdge(const Vertice & u, const Vertice & v)
			{
				assert( searchVertex(u.getData()) && (_cursorVertex!=NULL) );
				assert( searchVertex(v.getData()) && (_cursorVertex!=NULL) );

				Lado aux;

				_cursorEdge->setData(_e[u.getEtiqueta()][v.getEtiqueta()]);
				_cursorEdge->setFirst(u);
				_cursorEdge->setSecond(v);
			}

			
			/*!
				\fn			void beginVertex();
				\brief      Función que lleva el cursor al primer vertice
			*/
			void beginVertex()
			{
				_cursorVertex=&_v[0];
			}
			
			/*!
				\fn			void nextVertex();
				\brief      Función que avanza el cursor al siguiente vertice
			*/
			void nextVertex()
			{
				_cursorVertex++;
			}
			
			/*!
				\fn			bool afterEndVertex() const;
				\brief      Función que comprueba si el cursor ha sobrepasado su última posicion válida
			*/
			bool afterEndVertex() const
			{
				bool retVal=true;

				if(_cursorVertex!=&_v[capacidad()])
				{
					retVal=false;
				}

				return(retVal);
			}	
			
			/*!
				\fn			void beginEdge(const Vertice & u);
				\brief      Función que lleva el cursor al primer lado que sale del vertice u
			*/
			void beginEdge(const Vertice & u)
			{
				bool encontrado=false;
				Lado* aux=new Lado;
				aux->setFirst(u);

								for (unsigned int i = 0; i <capacidad() && encontrado==false; i++)
								{
									if (_e[u.getEtiqueta()][i]>0 && _e[u.getEtiqueta()][i]<std::numeric_limits<float>::infinity())
									{
										aux->setSecond(_v[i]);
										aux->setData(_e[u.getEtiqueta()][i]);
										encontrado=true;
									}
								}
								if(encontrado==true)
									_cursorEdge=aux;
								else
									_cursorEdge=NULL;
			}
			
			/*!
				\fn			void nextEdge();
				\brief      Función que avanza el cursor al siguiente lado que sale de currEdge().first()
			*/
			void nextEdge()
			{
				bool encontrado=false;
				Lado* aux=new Lado;

				for (unsigned int i = currEdge().second().getEtiqueta()+1; i <capacidad() && encontrado==false; ++i)
				{
					if (_e[currEdge().first().getEtiqueta()][i]>0 && _e[currEdge().first().getEtiqueta()][i]<std::numeric_limits<float>::infinity())
					{
						aux->setFirst(currEdge().first());
						aux->setSecond(_v[i]);
						aux->setData(_e[aux->first().getEtiqueta()][i]);
						encontrado=true;
					}
				}
				if(encontrado==true)
				{
					_cursorEdge=aux;
				}
				else
				{
					_cursorEdge=NULL;
				}
			}
			
			/*!
				\fn			bool afterEndEdge();
				\brief      Función que comprueba si el cursor ha sobrepasado su última posicion válida para los lados que salen de currEdge().first()
			*/			bool afterEndEdge()
			{
				Lado* aux=new Lado;
				aux=_cursorEdge;

				if (aux==NULL)
				{
					return(true);
				}
				else
				{
					return(false);
				}
			}
	};
} //namespace ed

#endif 
