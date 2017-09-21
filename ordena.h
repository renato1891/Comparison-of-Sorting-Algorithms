//Nomes: Samuel Gomes Duque / Matrículas : 0002857
//       Renato Boaventura  /              0021620  

#ifndef ORDENA_H
#define ORDENA_H
#define TAM 100 //tamanho do vetor

typedef struct medida *medidas;
typedef struct vet vetor;

void copia_vetor (unsigned long int *, unsigned long int *, int);
void preenche_vetor (unsigned long int *, int );
int ordenado_corretamente (unsigned long int *, int);
void gravar_resultado (FILE *, double, double, double, double, double, double);
//==========================================================================================//
//BUBBLE SORT
void bubble_sort (unsigned long int *, int, medidas);
//===========================================================================================//
//INSERCAO
void insercao(unsigned long int *v, int t, medidas m);
//==============================================================================================//
//QUICK
int particao(unsigned long int *v, int esq, int dir, medidas m);
void ordena ( unsigned long int *v,int esq, int dir, medidas m);
void quick_sort(unsigned long int *v, int t, medidas m);
//=======================================================================================//
//QUICK TURBINADO
void ordena2(unsigned long int *v,int esq, int dir, medidas m);
void quick_sort2(unsigned long int *v, int t, medidas m);
void insercao2(unsigned long int *v, int inicio, int final, medidas m);
//=======================================================================================//
// FUNCOES AUXILIARES
int calculamediana(int esq, int dir, medidas m);
void swap(unsigned long int *v, int i, int j, medidas m);
int compara(unsigned long int *v, int i, int j, medidas m);
double calcula_desvio(double *m, double media);
int comparaquick1(unsigned long int *v, int i, unsigned long int x, medidas m);
int comparaquick2(unsigned long int *v, int i, unsigned long int x, medidas m);
#endif /* ORDENA_H */
