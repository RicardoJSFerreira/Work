#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX_POSICAO		9



typedef struct posicao {
	char x;
	char y;
	char vivo;
	char possivel[10];
} POSICAO;
typedef struct quadrado
{
	POSICAO cube[MAX_POSICAO];
	POSICAO x[10];
}quadrado;

typedef struct matriz {
	quadrado num[10];
	quadrado y[10];

}Matriz;

/*
Fornece o Sudoku inicial
*/
	int matriz [9] [9] = {{0,0,5, 0,2,0, 8,4,3},
						  {9,2,4, 0,0,0, 5,0,0},
						  {7,8,3, 1,4,5, 0,6,2},

						  {4,3,9, 5,0,0, 7,2,0},
						  {6,5,0, 8,0,0, 3,0,0},
						  {0,7,2, 9,3,0, 6,0,0},

						  {2,0,8, 4,0,6, 0,0,7},
						  {5,0,6, 3,1,0, 2,8,9},
						  {3,1,7, 0,9,8, 0,5,6}};
/*
struct quadrado para saber se tenho algum numero lá
quadrado.numero.verifica
numero vai de 1-> 9
verifica é 0 ou 1

struct numero em x e y posiçao
primeiro coluna e depois em que linha esta
x e y vao de 1->9
verifica 0 ou 1
num.y.verifica
num.x.verifica

*/
/*
verifica se o numero pode pertencer aquela linha coluna e cubo
*/
void verifica_q_linha(Matriz m, int k, int i, int j, int cube){

}
/*
Mete na struct todas os numeros possiveis para cada posicao ocupada por 0
*/
void verifica_possiveis (Matriz m){
	int i,j,k;
	for(k=1;k!=10;k++){
		j=1;
		for(i,j;j<10;j++){
			i=1;
				for(i,j;i<10;i++){
					if(m.y[j].x[i].vivo==0){
												verifica_q_linha(m,k,i,j,(verifica_cubo(i,j)));
					}
	}
}
}
}
/*
Testa as diferentes situaçoes e resolve a matriz atravez das posicoes possiveis para cada numero
*/
void resolve_possiveis (Matriz m){

}				  
/*
Verifica quantos zeros ainda faltam resolver 
*/						  
int esta_resolvido(Matriz m){
int k=0;
int j=1;	
int i;
		for(i,j;j<10;j++){
			i=1;
				for(i,j;i<10;i++){
					if(m.y[j].x[i].vivo==0){
			k++;

		}
	}

}
return k;
}
/*
Verifica se o numero de zeros é superior a 1, e se for continua a testar todos os numeros possiveis em cada espaço
*/
void resolve_tabuleiro(Matriz m){
	int i,j,k;
	do{
		verifica_possiveis(m);
		resolve_possiveis(m);

	}while(esta_resolvido(m)==0);

}
/*
Imprime o tabuleiro final
*/

void imprime_tabuleiro(Matriz m){
int i=1;
int j=1;
int x,y,z;
printf(" \n A matriz final é:\n");

for(i,j;i<10;i++){
	j=1;
	printf("\n");
	for(i,j;j<10;j++){
		printf("%d ",m.y[i].x[j].vivo );
	}

}
printf("\n %d \n ",esta_resolvido(m));
}
/*
Verifica qual o cubo a que pertence cada coordenada
*/

int verifica_cubo (int i, int j){
	int k,r;
	if(j<4){
		if(i<4)
			k=1;
			else if(i<7)
				k=2;
				else if(i<10)
					k=3;
	}
	else if(j<7){
		if(i<4)
			k=4;
			else if(i<7)
				k=5;
				else if(i<10)
					k=6;
	} 
	else if(j<10){
		if(i<4)
			k=7;
			else if(i<7)
				k=8;
				else if(i<10)
					k=9;

	}
	return k;
}
/*
Traduz a matriz dada para uma nova matriz struct m
*/
Matriz identifica_tabuleiro (){
		Matriz m = {{0}};

int i,j,k,l;
j=0; 		
for(i,j;j<9;j++){
	i=0;
	for(i,j;i<9;i++){
		m.y[(j+1)].x[(i+1)].vivo=(matriz [j] [i]);
		k=m.y[j].x[i].vivo;
		l=verifica_cubo((i+1),(j+1));
		if(l!=0){
		m.num[k].cube[l].x=i+1;
		m.num[k].cube[l].y=j+1;
		m.num[k].cube[l].vivo=1;
	}
			else {
				m.num[k].cube[l].vivo=0;
			}
}
}
/*m.num[1].cube[1].x=4;
m.num[1].cube[1].y=5;
m.y[1].x[2].vivo=1;
*/

	return m;
}


int main(){
/*int x,y,z;
		
m.num[1].cube[1].x=4;
m.num[1].cube[1].y=5;
zero.y[1].x[2].vivo=1;
z=zero.y[1].x[2].vivo;
x=m.num[1].cube[1].x;
y=m.num[1].cube[1].y;

printf("%d \n %d \n %d",x,y,z );
*/
		Matriz m = identifica_tabuleiro ();
				resolve_tabuleiro (m);
				imprime_tabuleiro (m);	








			

return 0;


}