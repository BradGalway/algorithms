#include <iostream>
#include <stack>
using namespace std;


class Stack{
	char value;
	Stack *next;
	bool isset;
   public:
	Stack(): next( NULL ), isset( false ){};
	char head();
	void pop();
	void push( char c );
};



void Stack::push( char c ){
	Stack *s = new Stack();
	s->value = c;
	s->next = next;
	next = s;
	return;
}

void Stack::pop(){
	if( next == NULL ) return;
	else next = next->next;
	return;
}

char Stack::head(){
	return next->value;
}

int main(){
	Stack s;
	s.push( 'a' );
	cout << s.head() << endl;
	s.push( 'b' );
	cout << s.head() << endl;
	s.pop();
	cout << s.head() << endl;
	return 0;
}
