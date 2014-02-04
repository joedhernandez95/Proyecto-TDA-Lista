#include "farraylist.h"
#include "object.h"
#include "tdalist.h"
#include <sstream>

FArrayList::FArrayList(int c){//ctor de la clase
	capacity = c;//se asigna su capacidad
	data = new Object*[capacity];//se crea el arreglo de tipo Object*
}

FArrayList::~FArrayList() {//destructor virtual
	delete[] data;//se elimina todo el arreglo
}

Object* FArrayList::remove(unsigned int p) {//funcion que remueve algun elemento en la posicion p
	if (isEmpty())//si no existen elementos
		return NULL;
	if (!(p >= 0 && p < size()))//si la posicion no es valida
		return NULL;

	Object* retval = data[p];//asignamos a un temporal el elemento en el indice [p]

	if (p == size()-1)//si elimina el ultimo elemento del arreglo, simplmente asignamos ese elemento a NULL
		data[p] = NULL;
	else{//si elimina un elemento que esta en medio, se hacen los corrimientos necesarios
		for(int i=p;i<size()-1;i++)
			data[i] = data[i+1];
		data[size()-1] = NULL;//despues de recorrer y desplazar elementos, el ultimo se deja en NULL
	}

	ssize--;//debido a que removimos, el tamano del arreglo decrementa
	return retval;//retorna el elemento que eliminamos
}

Object* FArrayList::first() const {//devuelve el primer elemento de un arreglo
	if (isEmpty())//si no existen elementos en el arreglo
		return NULL;
	return data[0];
}

Object* FArrayList::last() const{//devuelve el ultimo elemento de un arreglo
	if (isEmpty())//si no existen elementos en el arreglo
		return NULL;
	return data[size()-1];
}

int FArrayList::getCapacity() const{//para obtener la capacidad del arreglo
	return capacity;
}

bool FArrayList::isFull() const {//nos avisa si el arreglo ya esta ha llegado a su capacidd maxima
	return ssize == capacity;
}

void FArrayList::clear() {
	delete[] data;//eliminamos todo el arreglo
	data = new Object*[capacity];//creamos un nuevo arreglo con la misma capacidad del anterior
	ssize = 0;//lo iniciamos con tamano cero
}

int FArrayList::indexOf(Object* E) const {
	for (int i = 0; i < size(); i++) {
		if(data[i]->equals(E))//metodo para comparar objects
			return i;
	}

	return -1;//si despues de recorrer no se encuentran parecidos, se retorna -1
}

Object* FArrayList::get(unsigned int p) const {
	if(isEmpty())//si no existen elementos
		return NULL;
	if(!(p >= 0 && p < size()))//si la posicion no es valida
		return NULL;

	return data[p];
}

bool FArrayList::insert(Object *e, int p) { // inserta un objeto en la posición p del arreglo
	if (isFull())//si el arreglo ya esta lleno, no podemos insertar, por lo que devolvemos NULL
		return false;
	if (!((p >= 0) && (p <= size())))//si la posicion no es valida
		return false;
	if (isEmpty())//si no existen elementos, insertamos al inicio
		data[p] = e;
	else {
		if (p== size())//si inserta al final
			data[p] = e;
		else {//si inserta en medio del arreglo
			for (int i=size()- 1;i >= p;i--)
				data[i+1] = data[i];//se corren los demas elementos	
			data[p]=e;
		} 
	}
	ssize++;//debido a que insertamos, el tamaño del arreglo incrementa
	return true;
    } // fin del Insert

    int FArrayList::prev(int p) const{//retorna el indice anterior al que el usuario envia
    	return (p-1);
    }

    int FArrayList::next(int p) const{//retorna el indice siguiente al que el usuario envia
    	return p+1;
    }

    void FArrayList::print()const{//funcion de impresion del arreglo
    	for(int i=0;i<size();i++)
    		data[i]->print();//utilizamos el print de object
    }