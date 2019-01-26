#include "pch.h"
#include <iostream>

using namespace std;

struct node {
	int data;
	node *next;
	node *prev;
};

node *listeyeekle(node *r, int data) {
	// Liste boş ise
	if (r == NULL) {
		r = new node();
		r->data = data;
		r->next = NULL;
		r->prev = NULL;
	}

	// Listede eleman var ise
	else {
		// Listede 1 eleman var ise
		if (r->next == NULL) {
			if (r->data > data) {
				node *yrd;
				yrd = r;

				while (yrd->next != NULL) {
					yrd = yrd->next;
				}
				yrd->next = new node();
				yrd->next->data = data;
				yrd->next->next = NULL;
				yrd->next->prev = yrd;
				yrd = NULL;
				delete yrd;
			}

			else {
				node *yrd;
				yrd = r;

				yrd->prev = new node;
				yrd->prev->data = data;
				yrd->prev->prev = NULL;
				yrd->prev->next = yrd;
				r = yrd->prev;
			}
		}

		// Listede çok eleman var ise
		else {
			node *yrd;
			yrd = r;
			int sayac = 1;

			// Ara eleman ise
			while (yrd->next != NULL) {
				yrd = yrd->next;
				sayac++;
			}

			yrd = r;
				
			if (data>yrd->data) {
				yrd->prev = new node;
				yrd->prev->data = data;
				yrd->prev->prev = NULL;
				yrd->prev->next = yrd;
				r = yrd->prev;
			}

			else {
				yrd = r;

				for (int i = 0; i < sayac-1; i++) {
					if (data < yrd->next->data)
					{
						yrd = yrd->next;
					}
				}
				if (yrd->next == NULL) {
					yrd->next = new node();
					yrd->next->data = data;
					yrd->next->next = NULL;
					yrd->next->prev = yrd;
					yrd = NULL;
					delete yrd;
				}

				else {
					node *tmp;
					tmp = yrd->next;
					yrd->next = new node();
					yrd->next->data = data;
					yrd->next->next = tmp;
					yrd->next->prev = yrd;
					tmp = yrd = NULL;
					delete tmp, yrd;
				}
			}
		}
	}
	return r;
}

void listeyiyazdir(node *r) {
	if (r == NULL) {
		cout << "Listede yazdırılacak eleman yok..";
	}
	
	else {
		node *yrd;
		yrd = r;

		while (yrd->next != NULL) {
			cout << yrd->data << " ";
			yrd = yrd->next;
		}

		cout << yrd->data;
	}
}

int main()
{
	setlocale(LC_ALL, "Turkish");

	node *root;		
	root = NULL;

	int sayi;
	char karar;

	do {
		cout << "Listeye bir sayı gir: ";
		cin >> sayi;

		root = listeyeekle(root, sayi);
		listeyiyazdir(root);

		cout << endl;
		cout<< "Listeye yeni bir sayı eklemek ister misiniz? [E/e]: ";
		cin >> karar;

		system("cls");
	} while (karar=='E' || karar=='e');

	system("pause");
}
