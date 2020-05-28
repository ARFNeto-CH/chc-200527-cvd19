#pragma once

#define TAM_MAX_NOME	50
#define MAX_PAISES		30
#define MAX_DIAS		20

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// exemplo apenas

struct leitura
{
	char* pais;
	int* dias;
};
typedef struct leitura Leitura;

struct leituras
{
	int nPaises;
	int nDias;
	Leitura* info;
};
typedef struct leituras Leituras;

// de volta ao tema

void    dia_com_mais_contagios(int, int, int*);
void    flush(FILE*);
int*    le_contagios(FILE*, int, int);
char**  le_paises(FILE*, int);
void    maior_contagio_pais(int, int, int*, char*);
void    mostra_contagios(int, int, int*);
int     total_contagios_pais(int, int, int*);
int     maior_sequencia_de_contagios(int, int, int*);
int     total_contagios_pais(int, int, int*);

//https://www.clubedohardware.com.br/forums/topic/
//1453122-alguem-sabe-fazer-essa-atividade-com-linguagem-c-sobre-o-covid19/

// fim
