//Nomes: Samuel Gomes Duque / Matrículas : 0002857
//       Renato Boaventura  /              0021620  

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "ordena.h"




struct medida
{
	double tempo, comparacoes, trocas;
	double vet_tempo[3], vet_comparacoes[3], vet_trocas[3];
};

struct vet
{
	unsigned long int *vetor;
};



int main ()
{
	//unsigned long int* vetor;
	vetor Vetor[3];
	unsigned long int* copia;
	double tempo_medio=0.0, comparacoes_medias=0.0, trocas_medias=0.0, desvio_tempo=0.0, desvio_comparacoes=0.0, desvio_trocas=0.0;
	int exec;
	medidas m;
	FILE *arquivo;
        arquivo = fopen ("resultados.txt", "wt");
		if (!arquivo)
		{
			printf ("Erro ao criar arquivo");
			exit (EXIT_FAILURE);
		}
		

	srand (time(NULL)); // A funcao srand () configura a semente inicial para o gerador de numeros pseudo-aleatorio
	m = (medidas) malloc (sizeof (struct medida));
	Vetor[0].vetor = (unsigned long int*) malloc(TAM*sizeof(unsigned long int));
    Vetor[1].vetor = (unsigned long int*) malloc(TAM*sizeof(unsigned long int));  //aloca os tres vetores que serao usados nos testes
    Vetor[2].vetor = (unsigned long int*) malloc(TAM*sizeof(unsigned long int));
    copia = (unsigned long int*) malloc(TAM*sizeof(unsigned long int));
    m->comparacoes = 0.0;
    m->trocas = 0.0;
    m->tempo = 0.0;
  
	if (!Vetor[0].vetor || !Vetor[1].vetor || !Vetor[2].vetor)
	{
		exit (EXIT_FAILURE);
	}
	
	if (!copia)
	{
		exit (EXIT_FAILURE);
	}
	

         
        preenche_vetor (Vetor[0].vetor, TAM); 
        preenche_vetor (Vetor[1].vetor, TAM);    //preenche os tres vetores que serao usados nos testes
        preenche_vetor (Vetor[2].vetor, TAM);
        fprintf (arquivo, "Bubble sort para o tamanho: %d. \n", TAM);
	for ( exec = 1; exec <= 3; exec = exec + 1)
	{
        copia_vetor (copia, Vetor[exec-1].vetor, TAM);  //copia sempre o vetor original para nao altera-lo
        printf ("Ordenando vetor usando o método bubble sort\n");
		bubble_sort (copia, TAM, m);
        if (ordenado_corretamente (copia, TAM))
		{
            tempo_medio = tempo_medio + m->tempo;
            m->vet_tempo[exec-1] = m->tempo;
			comparacoes_medias = comparacoes_medias + m->comparacoes;
			m->vet_comparacoes[exec-1] = m->comparacoes;
			trocas_medias = trocas_medias + m->trocas;
			m->vet_trocas[exec-1] = m->trocas;
			fprintf (arquivo, "Tempo gasto na %dª ordenação: %lf. ||  ", exec, m->tempo);
			fprintf (arquivo, "Número de comparações da %dª ordenação: %lf. || ", exec, m->comparacoes);
			fprintf (arquivo, "Número de trocas da %dª ordenação: %lf. \n", exec, m->trocas);
			m->comparacoes = 0.0;
        	m->trocas = 0.0;    //zera as variaveis
        	m->tempo = 0.0;
		}
		else
			printf("ERRO: Vetor nao ordenado\n");
       }

    	tempo_medio = tempo_medio / 3.0;
    	comparacoes_medias = comparacoes_medias / 3.0;
		trocas_medias = trocas_medias / 3.0;
    	desvio_tempo = calcula_desvio(m->vet_tempo, tempo_medio);
    	desvio_comparacoes = calcula_desvio(m->vet_comparacoes, comparacoes_medias);   //calcula os desvios padrao
    	desvio_trocas = calcula_desvio(m->vet_trocas, trocas_medias);  
        gravar_resultado (arquivo, tempo_medio, comparacoes_medias, trocas_medias, desvio_tempo, desvio_comparacoes, desvio_trocas);
        tempo_medio =0.0;
        comparacoes_medias=0.0;
        trocas_medias = 0.0;
        fprintf (arquivo, "Insertion sort para o tamanho: %d. \n", TAM); 
	for ( exec = 1; exec <= 3; exec = exec + 1)
	{
		
	    copia_vetor (copia, Vetor[exec-1].vetor, TAM);
   	    printf ("Ordenando vetor usando o metodo de inserção\n");
		insercao(copia, TAM, m);
                if (ordenado_corretamente (copia, TAM))
		{
			tempo_medio = tempo_medio + m->tempo;
            m->vet_tempo[exec-1] = m->tempo;
			comparacoes_medias = comparacoes_medias + m->comparacoes;
			m->vet_comparacoes[exec-1] = m->comparacoes;
			trocas_medias = trocas_medias + m->trocas;
			m->vet_trocas[exec-1] = m->trocas;
			fprintf (arquivo, "Tempo gasto na %dª ordenação: %lf. ||  ", exec, m->tempo);
			fprintf (arquivo, "Número de comparações da %dª ordenação: %lf. || ", exec, m->comparacoes);
			fprintf (arquivo, "Número de trocas da %dª ordenação: %lf. \n", exec, m->trocas);
			m->comparacoes = 0.0;
        	m->trocas = 0.0;    //zera as variaveis
        	m->tempo = 0.0;
		}
		else
			printf("ERRO: Vetor nao ordenado\n");
        
        
        }
        tempo_medio = tempo_medio / 3.0;
    	comparacoes_medias = comparacoes_medias / 3.0;
		trocas_medias = trocas_medias / 3.0;
    	desvio_tempo = calcula_desvio(m->vet_tempo, tempo_medio);
    	desvio_comparacoes = calcula_desvio(m->vet_comparacoes, comparacoes_medias);
    	desvio_trocas = calcula_desvio(m->vet_trocas, trocas_medias);  
        gravar_resultado (arquivo, tempo_medio, comparacoes_medias, trocas_medias, desvio_tempo, desvio_comparacoes, desvio_trocas);
        tempo_medio =0.0;
        comparacoes_medias=0.0;
        trocas_medias = 0.0;
        
      	fprintf (arquivo, "Quicksort para o tamanho: %d. \n", TAM);
        for ( exec = 1; exec <= 3; exec = exec + 1)
	{
		
	
	    copia_vetor (copia, Vetor[exec-1].vetor, TAM);
        printf ("Ordenando vetor usando o método quicksort\n");
		quick_sort(copia,TAM, m);
                if (ordenado_corretamente (copia, TAM))
		{
			tempo_medio = tempo_medio + m->tempo;
            m->vet_tempo[exec-1] = m->tempo;
			comparacoes_medias = comparacoes_medias + m->comparacoes;
			m->vet_comparacoes[exec-1] = m->comparacoes;
			trocas_medias = trocas_medias + m->trocas;
			m->vet_trocas[exec-1] = m->trocas;
			fprintf (arquivo, "Tempo gasto na %dª ordenação: %lf. ||  ", exec, m->tempo);
			fprintf (arquivo, "Número de comparações da %dª ordenação: %lf. || ", exec, m->comparacoes);
			fprintf (arquivo, "Número de trocas da %dª ordenação: %lf. \n", exec, m->trocas);
			m->comparacoes = 0.0;
        	m->trocas = 0.0;    //zera as variaveis
        	m->tempo = 0.0;
		}
		else
			printf("ERRO: Vetor nao ordenado\n");
        
        }
        tempo_medio = tempo_medio / 3.0;
    	comparacoes_medias = comparacoes_medias / 3.0;
		trocas_medias = trocas_medias / 3.0;
    	desvio_tempo = calcula_desvio(m->vet_tempo, tempo_medio);
    	desvio_comparacoes = calcula_desvio(m->vet_comparacoes, comparacoes_medias);
    	desvio_trocas = calcula_desvio(m->vet_trocas, trocas_medias);  
        gravar_resultado (arquivo, tempo_medio, comparacoes_medias, trocas_medias, desvio_tempo, desvio_comparacoes, desvio_trocas);
        tempo_medio =0.0;
        comparacoes_medias=0.0;
        trocas_medias = 0.0;
        

       	fprintf (arquivo, "Quicksort turbinado para o tamanho: %d. \n", TAM);
        for ( exec = 1; exec <= 3; exec = exec + 1)
	{
		
		
	    copia_vetor (copia, Vetor[exec-1].vetor, TAM);
	    printf ("Ordenando vetor usando o método Quicksort turbinado\n");
		quick_sort2(copia,TAM, m);
                 if (ordenado_corretamente (copia, TAM))
		{
			tempo_medio = tempo_medio + m->tempo;
            m->vet_tempo[exec-1] = m->tempo;
			comparacoes_medias = comparacoes_medias + m->comparacoes;
			m->vet_comparacoes[exec-1] = m->comparacoes;
			trocas_medias = trocas_medias + m->trocas;
			m->vet_trocas[exec-1] = m->trocas;
			fprintf (arquivo, "Tempo gasto na %dª ordenação: %lf. ||  ", exec, m->tempo);
			fprintf (arquivo, "Número de comparações da %dª ordenação: %lf. || ", exec, m->comparacoes);
			fprintf (arquivo, "Número de trocas da %dª ordenação: %lf. \n", exec, m->trocas);
			m->comparacoes = 0.0;
        	m->trocas = 0.0;    //zera as variaveis
        	m->tempo = 0.0;
		}
		else
			printf("ERRO: Vetor nao ordenado\n");
        }
        tempo_medio = tempo_medio / 3.0;
    	comparacoes_medias = comparacoes_medias / 3.0;
		trocas_medias = trocas_medias / 3.0;
    	desvio_tempo = calcula_desvio(m->vet_tempo, tempo_medio);
    	desvio_comparacoes = calcula_desvio(m->vet_comparacoes, comparacoes_medias);
    	desvio_trocas = calcula_desvio(m->vet_trocas, trocas_medias);  
        gravar_resultado (arquivo, tempo_medio, comparacoes_medias, trocas_medias, desvio_tempo, desvio_comparacoes, desvio_trocas);

	
    if(arquivo)
	fclose(arquivo);
	if (Vetor[0].vetor)              //lberam os vetores que foram alocados
		free(Vetor[0].vetor);
    if (Vetor[1].vetor)
		free(Vetor[1].vetor);
    if (Vetor[2].vetor)
		free(Vetor[2].vetor);
        		
	if (copia)
		free(copia);
	
	if (m)
		free (m);
	
	return 0;
}




void bubble_sort (unsigned long int *v, int t, medidas m)
{
	// A funcao clock (void) devolve o tempo de CPU decorrido desde o inicio da execucao do seu programa. O tempo eh medido em ciclos do relogio interno. 
	// Para obeter o tempo em segundos divida o valor retornado pela funcao clock pela constante CLOCKS_PER_SEC.
	
	double start, finish, elapsed;
	int i, j;
	
	start=(double)clock()/CLOCKS_PER_SEC;
	
	for (i = t-1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			//comparacoes = comparacoes + 1; 

                        if (compara(v, j+1, j, m))
			{ 
                            swap(v,j+1,j,m);
			}
		}
	}
	
	finish=(double)clock()/CLOCKS_PER_SEC;
	
	elapsed = finish - start; //calcula o tempo gasto na execução da ordenacao
	
	m->tempo = elapsed;

}

//====================================================================================================================================================//
        //INSERÇÃO

void insercao(unsigned long int *v, int t, medidas m){
	double start, finish, elapsed;
	int i, j;
	start=(double)clock()/CLOCKS_PER_SEC;

            for(i = 1; i<t; ++i)
            {
                j = i - 1;

                while(j>=0 && compara(v,j+1,j,m))  
                {
                    swap(v,j+1,j,m);  //funcao de troca
                    j--;	 	
                }
            }
	
    finish=(double)clock()/CLOCKS_PER_SEC;
	
	elapsed = finish - start; //calcula o tempo gasto na execução da ordenacao
	
	m->tempo = elapsed;
}

//===============================================================================================================================================//
                //QUICK COMUM

void quick_sort(unsigned long int *v, int t, medidas m) {
    double start, finish, elapsed;
    start=(double)clock()/CLOCKS_PER_SEC;
    ordena(v,0,t-1, m);
    finish=(double)clock()/CLOCKS_PER_SEC;
	elapsed = finish - start; //calcula o tempo gasto na execução da ordenacao
	m->tempo = elapsed;
	return;
}


void ordena ( unsigned long int *v,int esq, int dir, medidas m){
   if (esq < dir) {
		int q = particao(v, esq, dir, m);
		ordena(v,esq, q-1, m);
		ordena(v,q+1, dir, m);
	}
}
//===============================================================================================//
//PARTIÇÃO

int particao(unsigned long int *v, int esq, int dir, medidas m){
    int i, j, x, pos;
    pos = calculamediana(esq,dir,m);
    swap(v,pos, dir,m);
    x = v[dir]; 
    i = esq-1;
    for (j = esq; j < dir; j++)
    if (comparaquick1(v,j,x,m)) {
        i++;
        swap(v,i,j,m);
    }
    swap(v,i+1, dir,m);
    return (i+1);
}
//=========================================================================================================================================================//
     // QUICK SORT TURBINADO

void quick_sort2(unsigned long int *v, int t, medidas m) {
    double start, finish, elapsed;
    start=(double)clock()/CLOCKS_PER_SEC;
	ordena2(v,0,t-1, m);
    finish=(double)clock()/CLOCKS_PER_SEC;
	elapsed = finish - start; //calcula o tempo gasto na execução da ordenacao
	m->tempo = elapsed;
	return;
}


void ordena2(unsigned long int *v,int esq, int dir, medidas m){
     if((dir-esq)<40){
      // Se a quantidade de elementos a ser ordenado é menor que 40 ordena por Insercao
      insercao2(v,esq,dir ,m);
     
   } else{
   		if (esq < dir) {
            int q = particao(v, esq, dir, m);
            ordena2(v,esq, q-1, m);
            ordena2(v,q+1, dir, m);
        }   
	}
}






void insercao2(unsigned long int *v, int inicio, int final, medidas m){
	int i, j;
        for(i = inicio+1; i<=final; ++i)
            {
                j = i - 1;
                while(j>=0 && compara(v,j+1,j,m))
                {
                    swap(v,j+1,j,m);
                j--;	 	
                }
            }
}

//=================================================================================================================================================================//
    //CALCULA MEDIANA

int calculamediana(int esq, int dir, medidas m){
    int i, aux;
    unsigned long int *v = (unsigned long int*) malloc(sizeof(unsigned long int)*3);
    for(i=0;i<3;i++){
       v[i]= (esq+rand()%((dir+1)-esq));    
    }
    insercao2(v,0,2, m);
    aux = v[1];
    free(v);
    return(aux);
}


//==============================================================================================================//


void preenche_vetor (unsigned long int *v, int t)
{
	// A funcao time (time_t *x) retorna o total de segundos decorridos desde 01/01/1970. Essa funcao tambem atribui o valor retornado (em segundos)
	// a variavel cujo endereco é x (a menos que x seja NULL). Uso típico: instante = time (NULL)
	
	int i;
	
	
	
	for (i = 0; i < t; i++)
	{
		v[i] = (rand() /(double)RAND_MAX) * t; //A constante RAND_MAX representa o valor maximo retornado pela funcao rand(), a qual gera numeros pseudo-aleatorios
	}
}

int ordenado_corretamente (unsigned long int *v, int t)
{
	int i;
	for (i = 0; i < t-1; i++) //vefifica se o vetor foi ordenado corretamente
	{
		if (v[i] > v[i+1])
			return 0;
	}
	
	return 1;
}
//===================================================================================================================================//
void copia_vetor (unsigned long int *c, unsigned long int *v, int t)
{
	int i;
	for (i = 0; i < t; i++)
	{	
		c[i] = v[i];
	}
}
//===========================================================================================================
void gravar_resultado (FILE *arquivo, double tempo_medio, double comparacoes_medias, double trocas_medias, double desvio_tempo, double desvio_comparacoes, double desvio_trocas)
{
        fprintf (arquivo, "Tempo médio gasto na ordenação considerando 3 execuções: %.5f segundos \n", tempo_medio);
        fprintf (arquivo, "Médias de comparações na ordenação considerando 3 execuções: %.2f comparações \n", comparacoes_medias);
        fprintf (arquivo, "Médias de trocas na ordenação considerando 3 execuções: %.2f trocas \n",trocas_medias);
        fprintf (arquivo, "Desvio padrão em relação ao tempo gasto na ordenação considerando 3 execuções: %.5f\n", desvio_tempo);
        fprintf (arquivo, "Desvio padrão em relação as comparacoes gasto na ordenação considerando 3 execuções: %.5f\n", desvio_comparacoes);
        fprintf (arquivo, "Desvio padrão em relação as trocas na ordenação considerando 3 execuções: %.5f\n", desvio_trocas);
        fprintf(arquivo,"===========================================================================================\n");
        
	
}
//=============================================================================================================================================//
double calcula_desvio(double *m, double media){

	return (sqrt( ( pow((m[0]-media),2)   +   pow((m[1]-media),2)  + pow((m[2]-media),2)  )     /2.0     ));  //CALCULA DESVIO 
}
//======================================================================================================================================//
//FUNCAO QUE FAZ A TROCA 
void swap(unsigned long int *v, int i, int j, medidas m){
    unsigned long int aux;
    m->trocas++;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int compara(unsigned long int *v, int i, int j, medidas m){
    m->comparacoes++;
    if(v[i]<v[j])
        return 1;
    else 
        return 0;
}

int comparaquick1(unsigned long int *v, int i, unsigned long int x, medidas m){
    m->comparacoes++;
    if(v[i]<x)
        return 1;
    else
        return 0;

}

int comparaquick2(unsigned long int *v, int i, unsigned long int x, medidas m){
    m->comparacoes++;
    if(v[i]>x)
        return 1;
    else
        return 0;

}

