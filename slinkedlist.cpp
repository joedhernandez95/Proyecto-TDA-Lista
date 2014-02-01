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
		return false;
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
	if(isEmpty()){
		return NULL;
	}
	if(p < 0 && p >= size){
		return NULL;
	}
	SLNode* tmpn = head;
	for(int i = 0; i < size; i++){
		tmpn = tmpn->getNext();
	}
	return tmpn->getData();
}

Object* SLinkedList::remove(unsigned int pos){
	if(isEmpty()){
		return NULL;
	}
	if(pos < 0 || pos > size){
		return NULL;
	}

	SLNode* neo = head;
	Object* retVal = NULL;
	if(pos == 0){
		head = head->getNext();
	}else{
		for(int i = 0; i < pos-1; i++){
			neo = neo->getNext();
		}
		SLNode* tmpn = neo;
		neo = neo->getNext();
		tmpn->setNext(neo->getNext());
	}
	retVal = neo->getData();
	neo->setData(NULL);
	neo->setNext(NULL);
	delete neo;
	size--;
	return retVal;
}

int SLinkedList::prev(int pos)const{
	return pos-1;
}

int SLinkedList::next(int pos)const{
	return pos+1;
}

void SLinkedList::clear(){
	if(!(isEmpty())){
		delete head;
		head = NULL;
		size = 0;
	}
}

Object* SLinkedList::first()const{
	if(isEmpty()){
		return NULL;
	}

	return head->getData();
}

Object* SLinkedList::last()const{
	if(isEmpty()){
		return NULL;
	}

	SLNode* tmpn = head;
	for(int i = 0; i < size-1; i++){
		tmpn = tmpn->getNext();
	}

	return tmpn->getData();
}

void SLinkedList::print()const{
	if(!(isEmpty())){
		SLNode* tmpn = head;
		for(int i = 0; i < size; i++){
			tmpn->getData()->print();
			tmpn = tmpn->getNext();
		}
	}

}

bool SLinkedList::isEmpty()const{
	if(size == 0){
		return true;
	}
}

bool SLinkedList::isFull()const{
	return false;
}

}
