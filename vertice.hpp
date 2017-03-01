#ifndef __VERTICE_HPP__
#define __VERTICE_HPP__

#include <iostream>
#include <cassert>


using std::string;



namespace ed
{

	/*!\brief Clase vertice del grafo*/
	class Vertice
	{
		private:
			string _data; //!<Dato del vertice
			int _etiqueta; //!<Etiqueta del vertice
		
		public:

			//! \name OBSERVADORES

			/*!
				\fn const string & getData()const;
				\brief  Función que permite consultar el dato de un vertice
				\return valor del atributo _data
			*/
			const string & getData()const
			{ 
				return _data;
			}
			
			/*!
				\fn    const int & getEtiqueta()const;
				\brief  Función que permite consultar la etiqueta de un vertice
				\return valor del atributo _etiqueta
			*/
			const int & getEtiqueta()const
			{
				return _etiqueta;
			}
			

			//! \name MODIFICADORES

			/*!
				\fn     void setData(const string &data);
				\brief  Función que permite modificar el dato de un vertice
				\param  data Nuevo valor del atributo _data
			*/
			void setData(const string &data)
			{
				_data = data;
			}
			
			/*!
				\fn     void setEtiqueta(const int &etiqueta);
				\brief  Función que permite modificar la etiqueta de un vértice
				\param  etiqueta Nuevo valor del atributo _etiqueta
			*/
			void setEtiqueta(const int &etiqueta)
			{
				_etiqueta = etiqueta;
			}
			
			//! \name OPERADORES

			/*!
				\fn     bool operator==(const Vertice &v)const;
				\brief  Sobrecarga del operador relacional de igualdad
				\param  v Vertice con el que va a comparar el Vertice actual
				\post   El valor devuelto debe ser true si el vertice actual es igual al vertice v y false en caso contrario
				\return Valor lógico que indica si el vertice actual es igual que el vertice v
			*/
			bool operator==(const Vertice &v)const
			{
				return (v.getData() == getData());
			}
			
			/*!
				\fn     bool operator!=(const Vertice &v)const;
				\brief  Sobrecarga del operador desigualdad
				\param  v Vertice con el que va a comparar al Vertice actual
				\return Valor lógico que indica si el vértice actual es diferente que el vertice v
			*/
			bool operator!=(const Vertice &v)const
			{
				return (v.getData() != getData());
			}
	};
	
	
} //namespace ed

#endif 