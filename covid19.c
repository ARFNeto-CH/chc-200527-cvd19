#define _CRT_SECURE_NO_WARNINGS

#include "covid19.h"

void    dia_com_mais_contagios(int nDias, int nPaises, int* dados)
{
	// temos uma tabela com uma linha para cada Pais
	// uma coluna para cada dia
	// vamos mostrar o dia com mais contagios e o 
	// total de contagios
	// no popular: somar os totais por coluna e ve
	// qual o maior
	int total_dia = 0;
	int dia = 0;
	int total_maximo = 0;
	for (int d = 0; d < nDias; d = d + 1)
	{
		total_dia = 0;
		for (int p = 0; p < nPaises; p = p + 1)
		{
			int este_dia = *(dados + nDias * p + d);
			total_dia += este_dia;
		};	// for()
		if (total_dia > total_maximo)
		{
			dia = d;
			total_maximo = total_dia;
		};	// if()
	};
	printf("\nDia com maior numero de contagios\n%d: %d\n",
		1+dia, total_dia);
	return;
};

void    flush(FILE* f)
{
	int c;
	while ((c = fgetc(f)) != '\n' && c != EOF);
};  // flush()

int* le_contagios(
	FILE* entrada,
	int nDias,
	int nPaises
)
{
	//printf("le_contagios(%d, %d)\n", nPaises, nDias);
	// cria a tabela de Contagio: N linhas por D dias
	int* Contagios = (int*)malloc(nPaises * nDias * sizeof(int));
	for (int p = 0; p < nPaises; p = p + 1)
	{	// le os dados de cada nPaises
		//printf("Pais %2d: ", 1 + p);
		for (int d = 0; d < nDias; d = d + 1)
		{	// le os dados de nDias
			int dia = 0;
			fscanf(entrada, "%d", &dia);
			*(Contagios + (nDias * p) + d) = dia;
			//printf("%d ", dia);
		};	// for()
		//printf("\n");
	};	// for()
	return Contagios;
};	// le_contagios()

char** le_paises(FILE* entrada, int N)
{
	char* pc = (char*)malloc(N * sizeof(char*));
	char** Pais = (char**)pc;
	for (int p = 0; p < N; p = p + 1) // le de p[0]..p[N-1]
	{
		Pais[p] = (char*)malloc(1 + TAM_MAX_NOME); // cria o pais
		printf("Pais %2d: ", 1 + p);
		fgets(Pais[p], TAM_MAX_NOME + 1, entrada);
		Pais[p][strlen(Pais[p]) - 1] = 0; // apaga o \0 que veio
		printf("%s\n", Pais[p]);
	};	// for()
	return Pais;
}

void    maior_contagio_pais(
	int nDias,
	int nPais,
	int* dados,
	char* Pais)
{
	int* vetor_pais = dados + nPais * nDias;
	int maior = 0;
	for (int p = 1; p < nDias; p = p + 1)
		if (vetor_pais[p] > vetor_pais[maior]) maior = p;
	printf("%s: %d (%d)\n",
		Pais, 
		1 + maior,
		vetor_pais[maior]);
	return;
};

int     maior_sequencia_de_contagios(int nDias, int nPais, int* dados)
{	// para o pais retorna a maior sequencia crescente
	int maior = 0;
	int n = 1;
	int* vetor_pais = dados + nPais * nDias;
	for (int p = 0; p < nDias-1; p = p + 1)
	{
		if (vetor_pais[p] <= vetor_pais[p + 1])
		{
			n = n + 1;
		}
		else
		{
			if (n > maior)	maior = n;
			n = 1;
		}
	};	// for()
	if (n > maior)	maior = n;
	return maior;
};

void    mostra_contagios(int nDias, int nPaises, int* tabela)
{
	printf("mostra_contagios(%d, %d)\n", nPaises, nDias);
	for (int p = 0; p < nPaises; p = p + 1)
	{	// nPaises
		printf("Pais %2d: ", 1 + p);
		for (int d = 0; d < nDias; d = d + 1)
		{	// nDias
			printf("%d ", *(tabela + (nDias*p) + d));
		};	// for()
		printf("\n");
	};	// for()
	return;
};

int     total_contagios_pais(int nDias, int nPais,	int* dados)
{	// para o pais nPais define o total de contagios
	int nContagios = 0;
	//printf("total_contagios_pais(%d)\n", nPais);
	int* vetor_pais = dados + nPais * nDias;
	for (int p = 0; p < nDias; p = p + 1)
	{
		//printf("Valores de Contagio %d: ", vetor_pais[p]);
		nContagios += vetor_pais[p];
	};	// for()
	return nContagios;
};

// fim
