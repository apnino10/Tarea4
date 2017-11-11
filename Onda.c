#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int cuerda1(){

	/*parametros del enunciado*/
	float d_pos=0.005;
	float d_amplitud=0.000250;
	float pos_max=0.64;
	float pos_min=0.0;
	int c=250;

	int n_pos=129;
	int n_amplitud=129; 
	/*puntero que guarda o separa espacio en la memoria
	pos es la estructura con el nuemero de puntos de la posicion y amplitud, la matriz guarda los nuevos valores calculados con cada paso*/
	double * pos=malloc(n_pos*sizeof(double));
	double ** matriz=malloc(n_amplitud*sizeof(double*));	

	/*Se inicializa el valor de la posicion en cero y de la matriz que contendra el numero de elementos de amplitud*/
	int i; 
	int j;

	for(i=0; i<n_pos;i++){
		pos[i]=0.0;
	}
	
	for(i=0; i<n_amplitud;i++){
		matriz[i]=malloc(n_pos*sizeof(double));
	}
	
	for(i=0; i<n_amplitud;i++){
		for(j=0; j<n_pos;j++){
			matriz[i][j]=0.0;		
		}
	}

	
	for(i=0;i<n_pos;i++){
		pos[i]= pos_min + (pos_max-pos_min)*i/(n_pos-1);
	}	
	
	d_pos=pos[1]-pos[0];
		
	for(i=0;i<n_pos;i++){
		if(fabs(pos[i])>=0.65){
			matriz[0][i]= 0.016;
		}
		else{
			matriz[0][i]= 0.0;
		}
	}
		
	for(i=1;i<n_amplitud;i++){
		matriz[i][0]= matriz[0][0];
		matriz[i][n_pos-1]=matriz[0][n_pos-1];
	}
	
	/*Utilizando diferencias finitas, dada en el enunciado del ejercicio del laboratorio*/
	for(i=0;i<n_amplitud-1;i++){
		for(j=1;j<n_pos-1;j++){
			matriz[i+1][j]=matriz[i][j]-c*(d_amplitud/d_pos)*(matriz[i][j]-matriz[i][j-1]);
		}
	}
	

	/*Se guardan los datos a trabajar en un archivo.txt*/
	FILE *datos_grafica;
	datos_grafica=fopen("puntos.txt", "w");
	for(i=0; i<n_pos;i++){
			fprintf(datos_grafica,"%f %f %f\n ", pos[i] , matriz[0][i] , matriz[128][i]);
			
		}
	
	return 0;
}

/*--------------------------------------------------------------------------------------------------------------------------------*/



int main(){

	/*parametros del enunciado*/
	float d_pos=0.005;
	float d_amplitud=0.000250;
	float pos_max=0.64;
	float pos_min=0.0;
	int c=250;
	double dt=0.0078125;

	int n_pos=129;
	int n_amplitud=129; 
	/*puntero que guarda o separa espacio en la memoria
	pos es la estructura con el nuemero de puntos de la posicion y amplitud, la matriz guarda los nuevos valores calculados con cada paso*/
	double * pos=malloc(n_pos*sizeof(double));
	double ** matriz=malloc(n_amplitud*sizeof(double*));	

	/*Se inicializa el valor de la posicion en cero y de la matriz que contendra el numero de elementos de amplitud*/
	int i; 
	int j;

	for(i=0; i<n_pos;i++){
		double L=0.64;
		double t = i*dt;
		double seno, numero;
		numero = (2*M_PI*c/L)*t;
	    	seno = sin(numero);
		pos[i]=0.0;
	}
	
	for(i=0; i<n_amplitud;i++){
		matriz[i]=malloc(n_pos*sizeof(double));
	}
	
	for(i=0; i<n_amplitud;i++){
		for(j=0; j<n_pos;j++){
			matriz[i][j]=0.0;		
		}
	}
	
	

	for(i=0;i<n_pos;i++){
		pos[i]= pos_min + (pos_max-pos_min)*i/(n_pos-1);
	}	
	
	d_pos=pos[1]-pos[0];
		
	for(i=0;i<n_pos;i++){
		if(fabs(pos[i])>=0.65){
			matriz[0][i]= 0.016;
		}
		else{
			matriz[0][i]= 0.0;
		}
	}
		
	for(i=1;i<n_amplitud;i++){
		matriz[i][0]= matriz[0][0];
		matriz[i][n_pos-1]=matriz[0][n_pos-1];
	}
	
	/*Utilizando diferencias finitas, dada en el enunciado del ejercicio del laboratorio*/
	for(i=0;i<n_amplitud-1;i++){
		for(j=1;j<n_pos-1;j++){
			matriz[i+1][j]=matriz[i][j]-c*(d_amplitud/d_pos)*(matriz[i][j]-matriz[i][j-1]);
		}
	}
	

	/*Se guardan los datos a trabajar en un archivo.dat*/
	FILE *datos2;
	datos2=fopen("puntos2.txt", "w");
	for(i=0; i<n_pos;i++){
			fprintf(datos2,"%f %f %f\n ", pos[i] , matriz[0][i] , matriz[128][i]);
			
		}
	return 0;

}

























