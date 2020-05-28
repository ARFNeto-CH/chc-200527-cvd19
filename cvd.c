#define _CRT_SECURE_NO_WARNINGS

#include "covid19.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char** argv)
{
	// abre  arquivo
	const char* padrao = "dados.txt";
	char	    arquivo[30];
	if (argc > 1)
		strcpy(arquivo, argv[1]);
	else
		strcpy(arquivo, padrao);
	FILE* entrada = fopen(arquivo, "r");
	if (arquivo == NULL) return -1;

	// descobre o total de paises
	int N;
	fscanf(entrada, "%d", &N);
	if ((N<0) || (N > MAX_PAISES)) return -2;
	flush(entrada); // scanf() nao consome o '\n'
	printf("Dados referentes a %d paises\n\n", N);

	// cria a tabela de paises N * (maximo + 1)
	char** Pais = le_paises(entrada, N); // o obvio

	// le o total de dias por pais
	int D = 0;
	fscanf(entrada, "%d", &D);
	if ((D < 0) || (D > MAX_DIAS)) return -2;
	printf("\nDados referentes a %d dias\n", D);

	// le os dados referentes a D dias de cada um de N paises
	// cria a tabela de dados N paises x D dias
	int* Tabela = le_contagios(entrada,D,N);
	//mostra_contagios(D,N,Tabela);

	// ja leu tudo do arquivo
	fclose(entrada);
	
	// agora o total de contagios por pais
	printf("\nNumero total de contagios por pais\n");
	for (int p = 0; p < N; p = p + 1)
		printf("%s: %d\n",
			Pais[p],
			total_contagios_pais(D, p, Tabela)
		);

	// agora o dia com o maior numero de contagios
	// por pais. Um pouco diferente:
	// a funcao imprime os valores 'Dia (Valor)'
	printf("\nDia com maior numero de contagios por pais\n");
	for (int p = 0; p < N; p = p + 1)
		maior_contagio_pais(D, p, Tabela, Pais[p]);

	dia_com_mais_contagios(D, N, Tabela);

	// agora o total de contagios por pais
	printf("\nMaior sequencia crescente de contagios por pais\n");
	for (int p = 0; p < N; p = p + 1)
		printf("%s: %d\n",
			Pais[p],
			maior_sequencia_de_contagios(D, p, Tabela)
		);
	// libera tudo que foi alocado:
	// a tabela de contagio e a de paises
	free(Tabela); // apaga as leituras
	for (int i = 0; i < N; i = i + 1) free(Pais[i]);
	free(Pais); // e apaga a tabela de paises
	return 0;
};	