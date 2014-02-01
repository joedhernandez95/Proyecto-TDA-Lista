#include "object.h"
#include "slinkedlist.h"

SLinkedList::SLinkedList(){
	head = NULL;
}

SLinkedList::~SLinkedList(){
	if(head)
		delete head;
}

/*Insertar:
a) Si la lista esta vacia
b) Si se inserta al frente
c) Si se inserta al medio*/
bool SLinkedList::insert(Object* data,int pos){
	if(pos < 0 || pos > size)
		return false:

	SLNode* neo = new SLNode(data);

	if(!neo)
		return false;

	if(isEmpty()){
		head = neo;
	}else{
		if(pos == 0){
			neo->setNext(head);
			head = neo;
		}else{
			SLNode* tmpn = head;
			for(int i = 0; i < pos-1; i++){
				tmpn = tmpn->getNext();
			}
			neo->setNext(tmpn->getNext());
			tmpn->setNext(neo);
		}
	}

	size++;
	return true;
}

int SLinkedList::indexOf(Object* data)const{
	if(isEmpty()){
		return -1;
	}

	SLNode* tmpn = head;

	for(int i = 0; i < size; i++){
		if(tmp->getData()->equals(data)){
			return i;
		}
		tmpn->tmpn->getNext();
	}

	return -1;
}

Object* SLinkedList::get(unsigned int pos)const{
	is(isEmpty()){
		return NULL;
	}

	
}

