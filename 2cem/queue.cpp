
#include <iostream>
#include <stack>
#include <string>

struct Spis {
	double info;
	Spis* next;
} *begin, * t;

Spis* Change(Spis*);
Spis* Change1(Spis*, double);
Spis* InStack(Spis*, double);
Spis* DelBegin(Spis*);
void View(Spis*);
void Del_All(Spis**);
double findAverage(Spis*, int);
Spis* Exchange(Spis*, double);
void Sort_p(Spis**, Spis*);
void Sort_info(Spis*);
void Del(Spis**);
void Sort_p(Spis**);
Spis* Create(Spis**, Spis*, double);
Spis* Add(Spis**, Spis*, double);

void main()
{
	int i, n, kod;
	double in;
	while (true) {
		std::cout << "1.Creat " << std::endl;
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
				t = Create(&begin, t, in);
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
					t = Create(&begin, t, in);
				}
				std::cout << "Add " << n << std::endl;

			}

		case 3: if (!begin) {
			std::cout << "Spisok Pyst!" << std::endl;
			break;
		}
			  std::cout << "--- Spisok ---" << std::endl;
			  View(begin);
			  break;
		case 4:
			if (!begin) {
				std::cout << "Spisok Pyst!" << std::endl;
				break;
			}
			else {
				Del_All(&begin);
				std::cout << "Memory Free!" << std::endl;
				break;
			}

		case 5:
			if (!begin) {
				std::cout << "Spisok Pyst!" << std::endl;
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
				std::cout << "Spisok Pyst!" << std::endl;
				break;
			}
			else {
				begin = Change(begin);
				Sort_p(&begin);
				begin = DelBegin(begin);
				std::cout << "Spisok otsortirovan" << std::endl;
				break;
			}


		case 7:
			if (!begin) {
				std::cout << "Spisok Pyst!" << std::endl;
				break;
			}
			else {
				Sort_info(begin);
				std::cout << "Spisok otsortirovan" << std::endl;
				break;
			}

		case 8:
			if (kod == 2 && begin == NULL) {

			}
			else {
				std::cout << "Input amount = "; std::cin >> n;
				for (i = 1; i <= n; i++) {
					std::cin >> in;
					begin = Change1(begin, in);
				}
				std::cout << "Add " << n << std::endl;

			}



		case 0:
			if (begin != NULL)
				Del_All(&begin);
			break;
		}
	}
}

Spis* Add(Spis** begin, Spis* e, double in) {
	Spis* t = new Spis;
	t->info = in;
	t->next = NULL;
	e->next = t;
	e = t;
	return t;
}

Spis* Create(Spis** begin, Spis* e, double in) {
	Spis* t = new Spis;
	t->info = in;
	t->next = NULL;
	if (*begin == NULL)
		*begin = e = t;
	else {
		e->next = t;
		e = t;
	}
	return e;
}


Spis* InStack(Spis* p, double in) {
	Spis* t = new Spis;
	t->info = in;
	t->next = p;
	return t;

}

void View(Spis* p) {
	Spis* t = p;
	while (t != NULL) {
		std::cout << " " << t->info << std::endl;
		t = t->next;
	}
}

void Del_All(Spis** p) {
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}
Spis* Change(Spis* begin) {
	t = Create(&begin, t, 21);
	Spis* t, * p = begin;
	t = p->next;

	

	return begin;
}

Spis* Change1(Spis* begin, double in) {
	begin = InStack(begin, in);
	Spis* t, * p = begin;
	t = p->next;
	while (t != NULL) {
		if (t->info < 0) {
			p->next = t->next;
			delete t;
			t = p->next;
		}
		else {
			p = t;
			t = t->next;
		}
	}

	return begin;
}
Spis* DelBegin(Spis* begin) {
	Spis* t, * p = begin;
	t = p->next;

	t = begin;

	begin = begin->next;
	delete t;
	return begin;
}

//
void Sort_p(Spis** p) {

	Spis* t = NULL, * t1, * r;
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

void Sort_info(Spis* p) {
	Spis* t = NULL, * t1;
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


Spis* Exchange(Spis* begin, double sredn) {
	Spis* t = begin;
	begin->info = sredn;
	return begin;
}

void Del(Spis** begin) {
	t = *begin;
	delete* begin;

}


double findAverage(Spis* t, int n) {
	double amount = 0;
	int i = 0;
	int in = n;
	for (Spis* temp = t; temp; temp = temp->next, i++)
		amount += temp->info;
	return amount / in;
}

