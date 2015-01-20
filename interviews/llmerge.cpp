#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// This problem was a huge pain in the neck that I don't think I even finished.
// Write merge sort that uses linked lists.

struct LinkedList {
	int head;
	LinkedList *rest;

	void print();
	int size();
};

int LinkedList::size(){
	int size;
	LinkedList *temp = new LinkedList;
	temp = this;
	for( ;; ){
		size++;
		if( temp->rest == NULL )
			break;
		temp = temp->rest;
	}
	return size;
}

void LinkedList::print(){
	LinkedList *temp = this;
	for( ;; ){
		if( temp == NULL )
			break;
		cout <<  temp->head << " ";
		temp = temp->rest;
	}
}

LinkedList *merge( LinkedList *temp, LinkedList *temp2 ){
	cout << "Merging: ";
	temp->print();
	cout << " and: ";
	temp2->print();
	cout << endl;
	LinkedList *sorted = new LinkedList;
	sorted = NULL;
	for( ;; ){
		LinkedList *number = new LinkedList;
		
		if ( temp == NULL && temp2 == NULL ){
			break;
		}
		else if( temp2 == NULL ){
			number->head = temp->head;
			temp = temp->rest;
		}
		else if( temp == NULL ){
			number->head = temp2->head;
			temp2 = temp2->rest;
		}	
		else if( temp->head < temp2->head ){
			number->head = temp->head;
			temp = temp->rest;
		}
		else{
			number->head = temp2->head;
			temp2 = temp2->rest;
		}	
		number->rest = sorted;
		sorted = number;
	}
	return sorted;
}

void mergeSort( LinkedList *ll, int iteration ){

	if( ll == NULL || ll->rest == NULL )
		return;
	LinkedList *temp = ll, *temp2 = ll;

	for( ;; ){
		if( temp2->rest == NULL || (temp2->rest)->rest == NULL )
			break;
		temp = temp->rest;
		temp2 = (temp2->rest)->rest;
	}

	temp2 = temp->rest;
	temp->rest = NULL;
	temp = ll;

	/*
	cout << "iteration " << iteration << " temp: ";
	temp->print();
	cout << endl;

	cout << "iteration " << iteration << " temp2: ";
	temp2->print();
	cout << endl;*/
	mergeSort( temp, iteration + 1 );
	mergeSort( temp2, iteration + 1);

	ll = merge( temp, temp2 );

	//cout << "iteration " << iteration << " merged: ";
	ll->print();
	cout << endl;

}

int main(){
	istream *infile = &cin;
	LinkedList *ll = new LinkedList;
	ll = NULL;

	try{
		infile = new ifstream( "pleasesort.txt" );
	}
	catch( exception e ){
		cerr << "Something is wrong with your file" << endl;
	}

	int input;
	for( ;; ){
		*infile >> input;
		if( infile->fail() )
			break;
		LinkedList *number = new LinkedList;
		number->head = input;
		number->rest = ll;
		ll = number;
	}


	LinkedList *temp = ll;
	for( ;; ){
		if( temp == NULL )
			break;
		cout << temp->head << " ";
		temp = temp->rest;
	}
	cout << endl;

	mergeSort( ll, 1 );

	if( ll == NULL ){
		cerr << "oh nooo" << endl;
	}

	ll->print();	
	return 0;
}
