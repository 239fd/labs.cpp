#include <iostream>


struct Spis2 {
	double info;
	Spis2* next, * prev;
} *begin, * end, * t;


void Create_Spis2(Spis2**, Spis2**, int);
void Add_Spis2(int, Spis2**, Spis2**, int);
void View_Spis2(int, Spis2*);
void Del_All(Spis2**);
void Task(Spis2*,double);
double average(Spis2*);


void main()
{
	int i, n, kod, kod1;
	double in;
	double a;
	char Str[2][10] = { "Begin ", "End " };
	while (true) {
		std:: cout << "1.Creat " << std::endl;
		std::cout << "2.Add " << std::endl;
		std::cout << "3.View " << std::endl;
		std::cout << "4.Del " << std::endl;
		std::cout << "5.Task " << std::endl;
		std::cout << "0.EXIT " << std::endl;
		std::cin >> kod;
		switch (kod) {

		case 1: if (begin != NULL) {
			std::cout << "Clear Memory!" << std::endl;
			break;
		}
			  std::cout << "Begin Info = "; std::cin >> in;
			  Create_Spis2(&begin, &end, in);
			  std::cout << "Creat Begin = " << begin->info << std::endl;
			  break;

		case 2:
			std::cout << "Info = "; std::cin >> in;
			std::cout << "0.Add Begin"; 
			std::cout << "1.Add End";
			std::cin >> kod1;
			Add_Spis2(kod1, &begin, &end, in);
			if (kod1 == 0) t = begin;
			else t = end;
			std::cout << "Add to " << Str[kod1] << " " << t->info << std::endl;
			break;

		case 3: if (!begin) {
			std::cout << "Spisok Pyst!" << std::endl;
			break;
		}
			  std::cout << "0.View Begin";
			  std::cout << "1.View End";
			  std::cin >> kod1;
			  if (kod1 == 0) {
				  t = begin;
				  std::cout << "-- Begin --" << std::endl;
			  }
			  else {
				  t = end;
				  std::cout << "--- End --" << std::endl;
			  }
			  View_Spis2(kod1, t);
			  break;
		
		case 4:
			if (begin != NULL) {
				Del_All(&begin);
				std::cout << "Memory Free!" << std::endl;

			}
		 	break;

		case 5:
			 std::cout << "Average = " << average(t) << std::endl;
			 a = average(t);
			 Task(begin, a);
			 break;

		case 0: if (begin != NULL)
		 	Del_All(&begin);
		 	return;
		}
	}
}


void Create_Spis2(Spis2** b, Spis2** e, int in) {

	t = new Spis2;
	t->info = in;
	t->next = t->prev = NULL;
	*b = *e = t;
}

void Add_Spis2(int kod, Spis2** b, Spis2** e, int in) {
	t = new Spis2;
	t->info = in;
	if (kod == 0) {
		t->prev = NULL;
		t->next = *b;
		(*b)->prev = t;
		*b = t;
	}
	else {
		t->next = NULL;
		t->prev = *e;
		(*e)->next = t;
		*e = t;
	}
}
void View_Spis2(int kod, Spis2* t) {
	while (t != NULL) {
		std::cout << t->info << std::endl;
		if (kod == 0) t = t->next;
		else t = t->prev;
	}
}

void Del_All(Spis2** b) {
	Spis2* z;
	while (*b != NULL) {
		z = *b;
		*b = (*b)->next;
		delete z;
	}
}


void Task(Spis2* t, double a) {
	begin->info = a;
}

double average(Spis2* t) {
	t = begin;
	double sum = 0;
	int count = 0;
	while (t != NULL)    
	{
		sum += t->info;   
		t = t->next;                       
		count += 1;                               
	}
	return sum / count;
}