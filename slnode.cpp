#include "slnode.h"
#include "object.h"
#include <iostream>
using namespace std;

SLNode::SLNode(){
	next = NULL;
	data = NULL;
}

SLNode::SLNode(Object* aData){
	data = aData;
}

SLNode::SLNode(Object* aData,SLNode* aNext){
	data = aData;
	next = aNext;
}

SLNode::~SLNode(){
	if(data)
		delete data;
	if(!(next==NULL))
		delete next;
}

void SLNode::print()const{
	data->print();
}

SLNode* SLNode::getNext()const{
	return next;
}

void SLNode::setNext(SLNode* aNext){
	next = aNext;
}

Object* SLNode::getData()const{
	return data;
}

void SLNode::setData(Object* aData){
	data = aData;
}