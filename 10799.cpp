#include <iostream>

using namespace std;

class stack {
private:
	char * gwal;
	int cnt;
	int size;
public:
	stack*init();
	void push(stack* loc, char g);
	char pop(stack* loc);
	char top(stack* loc);
	int isfull(stack*loc);
	int isempty(stack*loc);
};

stack* stack::init() {
	stack * real = (stack*)malloc(sizeof(stack));
	real->gwal = (char*)malloc(sizeof(char) * 100000);
	real->cnt = 0;
	real->size = 1000000;
	return real;
}

void stack::push(stack* loc, char g){
	if (!isfull(loc)) {
		*(loc->gwal + loc->cnt) = g;
		loc->cnt++;
	}

	else
		puts("error : stack full");
}

char stack::pop(stack* loc){
	if (!isempty(loc)) {
		return *(loc->gwal + loc->cnt - 1);
		loc->cnt--;
	}
	else
		puts("error : stack empty");
}
char stack::top(stack* loc){
	return *(loc->gwal + loc->cnt - 1);
}

int stack::isfull(stack*loc) {
	if (loc->cnt > loc->size)
		return 1;
	return 0;
}

int stack::isempty(stack*loc) {
	if (loc->cnt == 0)
		return 1;
	return 0;
}

int main() {
	stack razor;

	stack *cut = razor.init();

	char c;

	int polc = 0;

	int cnt = 0;

	int prev = 0;

	while ((c = getchar()) != '\n') {
		if (c == '(') {
			razor.push(cut, '1');
			polc++;
			prev = 1;
		}

		else if (c == ')') {
			razor.pop(cut);
			polc--;
			if (prev == 1)
				cnt += polc;

			else if (prev == 0)
				cnt += 1;

			prev = 0;
		}
	}

	cout << cnt << endl;
}

