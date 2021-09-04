#include <stdio.h>
#include <stdlib.h>

#define MAXNUM_VERTICES 100

/*!
Struktur data untuk merepresentasikan sebuah graf dengan menggunakan adjacency matrix.
Graph akan memiliki sebanyak n_vertices simpul dan n_edges sisi.
Kita mengasumsikan bahwa graph akan memiliki maksimal MAXNUM_VERTICES simpul.
*/

typedef struct
{
	int n_vertices;
	int n_edges;
	int adjacency_matrix[MAXNUM_VERTICES][MAXNUM_VERTICES];
}Graph;

/*
Fungsi untuk menginisialisasi adjacency matrix graph dg cara mengisi
sub-matrix kiri atas dg ukuran n_vertices x n_vertices dari adjacency matrix
dg nilai 0, sedangkan sisanya (yang tidak relevan untuk tujuan representasi graph
dg jumlah vertex sebanyak n_vertices) akan diisi dengan nilai -1.
*/

void inisialisasi_graph(Graph *g, int n_v, int n_e)
{
	int i, j;
	g->n_vertices = n_v;
	g->n_edges = n_e;
	for(i = 0; i < MAXNUM_VERTICES; i++)
	{
		for(j = 0; j < MAXNUM_VERTICES; j++)
		{
			if(i < n_v && j < n_v)
			{
			/*soal no. 1: lengkapi untuk menyimpan nilai 0 pada sub-matrix
			kiri-atas dari adjacency matrix*/
				g->adjacency_matrix[i][j] = 0;
			}
			else
			{
			/*soal no. 2: lengkapi untuk menyimpan nilai -1 pada elemen
			elemen sisanya*/
				g->adjacency_matrix[i][j] = -1;
			}
		}
	}
}

/*!
Fungsi untuk mencetak adjacency matrix dari sebuah graph g
*/

void print_adjacency_matrix(Graph *g)
{
	int i, j;
	for(i = 0; i < g->n_vertices; i++)
	{
		printf("\t%d", i);
	}
	printf("\n");
	for(i = 0; i < g->n_vertices; i++)
	{
		printf("%d", i);
		for(j = 0; j < g->n_vertices; j++)
		{
			printf("\t%d", g->adjacency_matrix[i][j]);
		}
		printf("\n");
	}
}

typedef enum {WHITE, GRAY, BLACK} COLOR;

#define Inf 1000000000
int finish_time[MAXNUM_VERTICES];
int time = 0;

int ind = 0;
void DFS_visit(Graph *g, COLOR *vertex_colors, int v)
{
	int i;
	printf("%d time = %d\n", v, time);
	vertex_colors[v] = GRAY;
	time++;
	for(i = 0; i < g->n_vertices; i++)
	{
		if(g->adjacency_matrix[v][i] == 1 && vertex_colors[i] != WHITE)
		{
			ind = 1;
		}
		if(g->adjacency_matrix[v][i] == 1 && vertex_colors[i] == WHITE)
		{
			DFS_visit(g, vertex_colors, i);
		}
	}
	vertex_colors[v] = BLACK;
	finish_time[v] = time;
	time++;
}

void DFS(Graph *g)
{
	COLOR vertex_colors[MAXNUM_VERTICES];
	int i;
	for(i = 0; i < g->n_vertices; i++)
	{
		vertex_colors[i] = WHITE;
	}
	for(i = 0; i < g->n_vertices; i++)
	{
		finish_time[i] = Inf;
	}
	for(i = 0; i < g->n_vertices; i++)
	{
		if(vertex_colors[i] == WHITE)
		{
			DFS_visit(g, vertex_colors, i);
		}
	}
	//Perlu dilakukan pengecekan kembali
	//untuk melihat apakah masih ada node yang belum terjelajahi
	//pengecekan dimulai dari node 0
	for(i = 0; i < g->n_vertices; i++)
	{
		if(vertex_colors[i] == WHITE)
		{
			DFS_visit(g, vertex_colors, i);
		}
	}
	printf("\n");
	printf("%d\n", ind);
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int main(void)
{
	int n_v = 0;
	int n_e = 0;
	int i, j;
	scanf("%d %d", &n_v, &n_e);
	Graph g;
	inisialisasi_graph(&g, n_v, n_e);
	for(i = 0; i < n_e; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		/*soal no. 3 : lengkapi agar adjacency matrix pada g menyimpan nilai 1 pada
		baris a kolom b*/
		g.adjacency_matrix[a][b] = 1;
	}
	//soal no 4 : modifikasi untuk menerima graph tak berarah
	/*for(i = 0; i < n_e; i++)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		g.adjacency_matrix[a][b] = 1;
		g.adjacency_matrix[b][a] = 1;
	}*/
	DFS(&g);
	qsort(finish_time, g.n_vertices, sizeof(int), cmpfunc);
	for(i = 0; i < g.n_vertices; i++)
	{
		printf("%d", finish_time[i]);
		if(i != g.n_vertices - 1)
		{
			printf(" ");
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");
	print_adjacency_matrix(&g);
}
