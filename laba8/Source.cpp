#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNING

#include "stdio.h"
#include <stdlib.h>
#include "conio.h"
#include "malloc.h"
#include <locale>
#include <queue>
using namespace std;


int diametr = -1;
int Rad = -1;
int radius = 20;



void bfsd(int v, int** arr, int* dist, int m) {


	queue <int> q;
	q.push(v);
	dist[v] = 0;
	printf("Порядок обхода: ");
	while (!q.empty()) {
		v = q.front();
		q.pop();
		printf("%d, ", v);



		for (int j = 0; j < m; j++) {
			if ((arr[v][j] != 0) && (dist[j] == -1)) {
				q.push(j);
				dist[j] = dist[v] + arr[v][j];
				if (diametr < dist[j]) { diametr = dist[j]; }
				if (Rad < dist[j]) { Rad = dist[j]; }
			}

		}
	}



}



void main() {

	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	int n;

	printf("Введите размер массива: ");
	scanf("%d", &n);

	int** arr1 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		arr1[i] = (int*)malloc(n * sizeof(int));
	}
	



	int* dista = (int*)malloc(n * sizeof(int));

	int** distaMn = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		distaMn[i] = (int*)malloc(n * sizeof(int));
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			arr1[i][j] = rand() % 2;
			if (arr1[i][j] == 1) {
				arr1[i][j] = rand() % 5;
			}


		}
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			arr1[j][i] = arr1[i][j];
			if (i == j) { arr1[i][j] = 0; }
			printf("%d  ", (arr1[i][j]));

		}
		printf("\n");
	}



	printf("\n\n\n");


	for (int i = 1; i < n; i++) {

		dista[i] = -1;

	}


	for (int i = 0, j = 0; i < n; i++) {


		bfsd(i, arr1, dista, n);
		printf("\nДлина путей: ");
		for (int i = 0; i < n; i++) {
			distaMn[j][i] = dista[i];
			printf("%d ", dista[i]);
			dista[i] = -1;
			if ((Rad <= diametr) && (Rad <= radius) && (Rad != -1)) { radius = Rad; }
		}
		printf("\n");

		j++;
		if ((i == 0) && (Rad != -1)) { radius = Rad; }
		Rad = -1;
		printf("\n");
	}


	printf("\n\n\n");


	if (radius == 20) { radius = diametr; }
	printf("Диаметр графа - %d  ", diametr);
	printf("Радиус графа - %d  ", radius);

	printf("\n"); printf("\n"); printf("\n");

	Rad = -1;
	printf("Множество радиусов графа:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			 if (Rad < distaMn[i][j]) { 
				 Rad = distaMn[i][j];
			}
		}
		if (Rad == radius) {
			printf("%d, ", i);
		}
		Rad = -1;
		
	}

	printf("\n");

	printf("Множество диаметров графа:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (Rad < distaMn[i][j]) {
				Rad = distaMn[i][j];
			}
		}
		if (Rad == diametr) {
			printf("%d, ", i);
		}
		Rad = -1;

	}

	printf("\n");
	printf("\n");
	printf("Изолированные вершины:\n");

	int ch = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr1[i][j] > 0) { ch = ch + 1; }

		}
		if (ch == 0) { printf("%d ", i); }
		ch = 0;
	}

	printf("\n");


	printf("Концевые вершины:\n");

	ch = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr1[i][j] > 0) { ch = ch + 1; }

		}
		if (ch == 1) { printf("%d ", i); }
		ch = 0;
	}

	printf("\n");


	printf("Доминирующие вершины:\n");

	ch = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr1[i][j] > 0) { ch = ch + 1; }

		}
		if (ch == (n - 1)) { printf("%d ", i); }
		ch = 0;
	}


}
