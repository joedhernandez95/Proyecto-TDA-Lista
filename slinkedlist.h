#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H
#include "object.h"
#include "slnode.h"
#include <tdalist.h>

class SLinkedList : public TDAList{
protected:
	SLNode* head;
public:
	SLinkedList();
	virtual ~SLinkedList();
	virtual bool insert(Object*,int);
	virtual int indexOf(OBject*)const;
	virtual Object* get(unsigned)const;
	virtual bool erase(unsigned);
	virtual int prev(int)const;
	virtual int next(int)const;
	virtual void reset();
	virtual Object* first()const;
	virtual Object* last()const;
	virtual void print()const;
	virtual bool isEmpty()const;
	virtual bool isFull()const;
	/*/
};