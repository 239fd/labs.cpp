#include <iostream>
#include <stack>
#include <string>

struct Stack { 
	double info;
	Stack* next;
} *begin, * t;

Stack* Change(Stack*); 
Stack* InStack(Stack*, double);
Stack* DelBegin(Stack*);
void View(Stack*);
void Del_All(Stack**);
double findAverage(Stack* , int);
Stack* Exchange( Stack*, double);
void Sort_p(Stack**, Stack*);
void Sort_info(Stack*);
void Del(Stack**);
void Sort_p(Stack**);



void main()
{
	int i, n, kod;
	double in;
	while (true) {
		std:: cout << "1.Creat " << std::endl;
		std::cout << "2.Add " << std::endl;
		std::cout << "3.View " << std::endl;
		std::cout << "4.Del " << std::endl;
		std::cout << "5.Task " << std::endl;
		std::cout << "6.Sort by first method" << std::endl;
		std::cout << "7.Sort by second method" << std::endl;
		std::cout << "0.Exit " << std::endl;
		std::cout << "Choice: ";
		std::cin >> kod;
		switch (kod) {
		case 1: 
			if (kod == 1 && begin != NULL) {
				std::cout << "Clear Memory!" << std::endl;
				break;
			}
			std::cout << "Input amount = "; std::cin >> n;
			for (i = 1; i <= n; i++) {
				std::cin >> in;
				begin = InStack(begin, in);
			}
			if (kod == 1) std::cout << "Create " << n << std::endl;
			break;
		case 2:
			if (kod == 2 && begin == NULL) {
				
			}
			else {
				std::cout << "Input amount = "; std::cin >> n;
				for (i = 1; i <= n; i++) {
					std::cin >> in;
					begin = InStack(begin, in);
				}
				std::cout << "Add " << n << std::endl;
				
			}

		case 3: if (!begin) {
			std::cout << "Stack Pyst!" << std::endl;
			break;
		}
			  std::cout << "--- Stack ---" << std::endl;
			  View(begin);
			  break;
		case 4:
			if (!begin) {
				std::cout << "Stack Pyst!" << std::endl;
				break;
			}
			else {
				Del_All(&begin);
				std::cout << "Memory Free!" << std::endl;
				break;
			}
			
		case 5:
			if (!begin) {
				std::cout << "Stack Pyst!" << std::endl;
				break;
			}
			else {
				std::cout << "Average: " << findAverage(begin, n) << std::endl;
				double sredn = findAverage(begin, n);
				Exchange(begin, sredn);
				break;
			}
		
		case 6:
			if (!begin) {
				std::cout << "Stack Pyst!" << std::endl;
				break;
			}
			else {
				begin = Change(begin);
				Sort_p(&begin);
				begin = DelBegin(begin);
				std::cout << "Stack otsortirovan" << std::endl;
				break;
			}
			

		case 7:
			if (!begin) {
				std::cout << "Stack Pyst!" << std::endl;
				break;
			}
			else{
				Sort_info(begin);
				std::cout << "Stack otsortirovan" << std::endl;
				break;
			}

		case 0:
			if (begin != NULL)
				Del_All(&begin);
			break; 
		}
	}
}

Stack* InStack(Stack* p, double in) {
	Stack* t = new Stack;
	t->info = in; 
	t->next = p; 
	return t;

}

void View(Stack* p) {
	Stack* t = p;
	while (t != NULL) {
		std::cout << " " << t->info << std::endl;
		t = t->next;
	}
}

void Del_All(Stack** p) {
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

Stack* Change(Stack* begin) {
	begin = InStack(begin, 21);
	Stack* t, * p = begin;
	t = p->next;
	return begin;
}
Stack* DelBegin(Stack* begin) {
	Stack* t, * p = begin;
	t = p->next;

	t = begin;

	begin = begin->next;
	delete t;
	return begin;
}

//
void Sort_p(Stack** p) {

	Stack* t = NULL, * t1, * r;
	if ((*p)->next->next == NULL) {
		return;
	};
	do {
		for (t1 = *p; t1->next->next != t; t1 = t1->next)
			if (t1->next->info > t1->next->next->info) {
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		t = t1->next;
	} while ((*p)->next->next != t);
}

void Sort_info(Stack* p) {
	Stack* t = NULL, * t1;
	int r;
	do {
		for (t1 = p; t1->next != t; t1 = t1->next)
			if (t1->info > t1->next->info) {
				r = t1->info;
				t1->info = t1->next->info;
				t1->next->info = r;
			}
		t = t1;
	} while (p->next != t);
}


Stack* Exchange(Stack* begin, double sredn) {
	Stack* t = begin; 
	begin->info = sredn; 
	return begin; 
}

void Del(Stack** begin) {
	t = *begin;
	delete* begin;
	
}


double findAverage(Stack* t,  int n) {
	double amount = 0;
	int i = 0;
	int in = n;
	for (Stack* temp = t; temp; temp = temp->next, i++)
		amount += temp->info;
	return amount / in;
}
	
