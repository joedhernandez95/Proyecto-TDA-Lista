#ifndef DLCURSORLIST_H
#define DLCURSORLIST_H

#include "tdalist.h"

class DLCursorList : public TDAList
{
	//Define una estructura parecida al nodo de una lista enlazada.
	struct Registry
	{
		int prev, next;
		Object* datum;
	};

	//Mapa que simula la lista enlazada.
	Registry* map;

	//Apunta al primer nodo.
	int head;

	//Determina la capacidad de la lista.
	int capacity;
	

	//Encuentra un nuevo espacio d�nde insertar.
	int findNextSlot() const;

public:
	//Constructor. Recibe un entero que determina su capacidad.
	DLCursorList(int=5);

	//Destructor.
	~DLCursorList();

	//Inserta un elemento a la lista.
	virtual bool insert(Object*, int);

	//Consigue el �ndice del elemento especificado como par�metro.
    	virtual int indexOf(Object*) const;

	//Retorna el objeto localizado en la posici�n especificada.
  	virtual Object* get(unsigned) const;

	//Retorna el elemento especificado y lo borra de la lista.
	virtual Object* remove(unsigned);

	/*
	* Retorna la posici�n (en la lista) del objeto 
	* que est� antes del especificado
	* por el par�metro.
	*/
	virtual int prev(int) const;

	/*
	* Retorna la posici�n (en la lista) del objeto 
	* que est� despu�s del especificado
	* por el par�metro.
	*/
	virtual int next(int) const;

	//Borra todos los elementos de la lista.
	virtual void clear();

	//Retorna el primer elemento de la lista.
	virtual Object* first() const;

	//Retorna el �ltimo elemento de la lista.
	virtual Object* last() const;
	
	//Retorna la representaci�n en cadena de la lista.
	virtual void print() const;

	//Determina si la lista est� llena o no.
	virtual bool isFull() const;
};

#endif
	