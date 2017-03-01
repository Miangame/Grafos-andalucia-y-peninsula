#ifndef __LADO_HPP__
#define __LADO_HPP__


#include <cassert>



namespace ed
{
	/*!\brief Lados del grafo*/
	class Lado
	{
		private:
			double _data; //!<Peso del lado
			Vertice _first; //!<Primer vertice del lado
			Vertice _second; //!<Segundo vertice del lado
			
		public:
			//! \name OBSERVADORES

			/*!
				\fn 	const double & getData() const
				\brief  Función que permite consultar el peso de una arista
				\return valor del atributo _data
			*/
			const double & getData() const 
			{
				return _data;
			}
			
			/*!
				\fn 	const Vertex & first() const
				\brief  Función que permite consultar el primer vertice de una arista
				\return valor del atributo _first
			*/
			const Vertice & first() const 
			{
				return _first;
			}
			
			/*!
					\fn 	const Vertex & second() const
					\brief  Función que permite consultar el segundo vertice de una arista
					\return valor del atributo _second
			*/
			const Vertice & second() const 
			{
				return _second;
			}
			
			/*!
					\fn 	bool has(const Vertice & u) const
					\brief  Función que dice si existe o no un vertice
			*/
			bool has(const Vertice & u) const
			{
				return u == first() or u == second();
			}
			
			
			/*!
					\fn 	const Vertice & other(const Vertice & u) const
					\brief  Función que devuelve el vertice contrario al pasado
			*/
			const Vertice & other(const Vertice & u) const
			{
				assert(has(u));
				if (u == first())
				{
					return second();
				}
				else
				{
					return first();
				}
			}
			
			//! \name MODIFICADORES

			/*!
				\fn     void setData(const double & data);
				\brief  Función que permite modificar el dato de una arista
				\param  data Nuevo valor del atributo _data
			*/
     		void setData(const double & data) 
			{
				_data = data;				
			}
			
			/*!
				\fn     void setFirst(const Vertice & first);
				\brief  Función que permite modificar el primer vertice de una arista
				\param  first Nuevo valor del atributo _first
			*/
      		void setFirst(const Vertice & first) 
			{
				_first = first;
				
			}
			
			/*!
				\fn     void setSecond(const Vertice & second)
				\brief  Función que permite modificar el segundo vertice de una arista
				\param  second Nuevo valor del atributo _second
			*/
      		void setSecond(const Vertice & second) 
			{
				_second = second;
			}
			
			//! \name OPERADORES

			/*!
				\fn     bool operator==(const Lado &l)const;
				\brief  Sobrecarga del operador relacional de igualdad
				\param  l Lado con el que va a comparar el Lado actual
				\post   El valor devuelto debe ser true si el lado actual es igual al lado l y false en caso contrario
				\return Valor lógico que indica si el lado actual es igual que el lado l
			*/
			bool operator==(const Lado &l)const
			{
				return (l.first() == first() and l.second() == second());
			}
	};

} //namespace ed

#endif