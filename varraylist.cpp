#include "varraylist.h"
#include "object.h"
//#include "tdalist.h"

	VArrayList::VArrayList(int c,int p){//ctor de la clase
		capacity = c;//se asigna su capacidad
		data=new Object*[capacity];//se crea el arreglo de tipo Object*
	}

	VArrayList::~VArrayList(){//dtor virtual de la clase
		delete[] data;//eliminamos el arreglo
	}

 bool VArrayList::makebigger(){ //incrementa el tamaño del arreglo, en este caso, de 50%
      Object** tmp = new Object*[(int)((size()*0.5) + size())]; // Crea un arreglo nuevo con 50% más de tamaño
      if (!tmp) // si no hay memoria para crear el arreglo retornamos false
        return false;
      for (int i=0;i<size();i++) // llena el nuevo arreglo con los elementos del arreglo anterior
        tmp[i] = data[i];//relleno del nuevo arreglo
      data = tmp; // se hace que data apunte al nuevo arreglo
      capacity += (size()*0.5)+size(); // se aumenta la variable capacity en un 50%
   
     return true;//retorna true si la funcion trabajo correctamente
    }

     

     

    bool VArrayList::insert(Object* E,int p){ //añade un elemento a el arreglo.
      if(isFull()) // si el arreglo ya alcanzo su maxima capacidad
        if(!makebigger())//si makebigger retorna false, es porque ya no existe memoria para insertar mas elementos
          return false; // el arreglo y no se puede insertar el nuevo objeto. 
      if(!(p >= 0 && p <= size())) //si p es un índice valido
        return false;
      if(isEmpty()) //si el arreglo esta vacio, insertamos en la primera posicion
        data[p] = E;
      else{
        if(p == size()) // Si se desea insertar al final del arreglo
          data[p]=E;
        else{//si insertamos en medio del arreglo
          for(int i = size() - 1; i >= p; i--) // corremos los elementos del arreglo un espacio a la derecha 
            data[i + 1] = data[i];
          data[p] = E; 
        }
      }

      ssize++; // ya que insertamos, incrementamos el tamaño de size
      makebigger();//engrandecemos el arreglo una vez insertado el elemento

      return true; // Retorna verdadero que la inserción se realizo con éxito 

    } //Fin de insert

     

    Object* VArrayList:: remove (unsigned int p ) { // elimina un elemento en el indice p del arreglo
      if (!(p >= 0 && p < size())) // revisa que p sea un indice valido
        return NULL;
      if (isEmpty())// si el arreglo esta vacio retorna NULL
        return NULL;
      Object* retval = data[p]; // asigna a un temporal el elemento que se va a remover
      if (p == size()-1) //si se elimina el ultimo elemento, simplmente lo eliminamos
        data[p]=NULL;
      else { //si se elimina un elemento de en medio
        for ( int i = p; i<size()-1; i++ )
          data[i]=data[i+1];//corremos los elementos
        data[size()-1]=NULL;//eliminamos el ultimo elemento
      }
      ssize--; // reduce el tamaño de size
      return retval; // retorna true si el objeto fue eliminado

    } // fin del remove

     

     

    Object* VArrayList::first() const{//devuelve el primer elemento del arreglo
      if(isEmpty())//Si el arreglo se encuentra vacio
        return NULL;
      if (size()>= 1)//si el elemento tiene elementos
        return data[0];//devolvemos el primer elemento
    } // fin de first

     

     

    Object* VArrayList::last() const{//devuelve el ultimo elemento de un arreglo
      if( isEmpty() )//Si el arreglo se encuentra vacio
        return NULL;
      if (size()>= 1)//si tiene por lo menos un elemento
        return data[size()- 1];//devolvemos el ultimo elemento del arreglo
    }
     

    Object* VArrayList::get(unsigned int p) const{//retorna un elemento del arreglo en dada posicion
      if(isEmpty())//si el arreglo esta vacío
        return NULL;
      if(!(p>=0)&&(p<size()))// si la posicion no es valida
        return NULL;
      return data[p];// retorna el elemento en la posicion p
    }   

    int VArrayList::indexOf(Object* E) const{ // devuelve el indice de un elemento en el arreglo
      if(isEmpty())//si el arreglo esta vacio 
        return -1;
      int posicion = -1;//valor a retornar
      for(int i = 0; i < size() ; i++){ //recorremos el arreglo
        if(data[i] == E){ // si el elemento en ese indice es igual al que estamos comparando 
          posicion = i; // asignamos ese indice a la variable que vamos a retornar
          break;
        } //Fin del if
      } //Fin del for
      return posicion; // retorna el valor de posición
    }


    bool VArrayList::isFull() const{ //nos dice si el arreglo ya esta lleno
      if( size() == capacity )//si el tamano del arreglo es el mismo que su capacidad, ya esta lleno
        return true;
    //de lo contrario, retornamos false
      return false;
    } 

    void VArrayList::clear(){ // limpia todos los elementos del arreglo
      delete[] data; // liberamos la memoria del arreglo
      data = new Object*[capacity]; //creamos un nuevo arreglo
      ssize = 0;
    } //Fin de clear

    int VArrayList::prev(int p) const{//retorna el indice anterior al que se envia a la funcion
    	return (p-1);
    }

    int VArrayList::next(int p) const{//retorna el indice siguiente al que se envia a la funcion
    	return p+1;
    }

    void VArrayList::print()const{//metodo de impresion
	for(int i=0;i<size();i++)
		data[i]->print();//utilizamos el print de la clase object
}

	int VArrayList::getCapacity() const{//retorna la capacidad del arreglo
		return capacity;
	}	