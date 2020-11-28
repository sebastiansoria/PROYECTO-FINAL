#include<iostream>
#include<conio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#define M 100
using namespace std;
//...Subfunciones Usadas en todas las funciones//
float verdad(int n,string nombres[],float opc[]);//Almacena valores de verdad
float guardarvalores(int n,string nombres[],float opc[],float val[],string unidades[]);//Guarda Valores numericos
float checkvalores(float val[],float val2[],int n,float opc[]);//Chequea que los valores ingresados no sean incoherentes
float mostrarvalores(int n,string nombres[],float opc[],float val[], string unidades[]);//Muestra Valores numericos de datos ausentes
float mostrarvalores2(int n,string nombres[],float opc[],float val[]);//No lo usamos//Muestra Valores numericos de datos dados

//...Funciones Particulares//
float formulas1(float val[],int n,float opc[]);
float formulas2(float val[],int n,float opc[]);
float caso1();
float caso2();
//...Funcion Para Guardar Archivos
float escribir(float val[],float val2[],float opc[],string nombres[],int n,int aux,string unidades[]);
int main(){
	int opcion1,con=1,a=1;
	//Aumentar unidades
	system("color 8E");//Cambiar de color la pantalla de la consola y las letras 8=Pantalla gris, F=letras blancas.
	cout<<"Los casos mas comunes a resolver en los examenes de Dinamica con Poleas de la UPSA son los siguientes: "<<endl;
	cout<<"1.Problema de Atwood o Polea fija"<<endl;
	cout<<"2.Polipasto con una polea fija y una movil"<<endl;
	cout<<endl<<"..........................................."<<endl<<endl;
	cout<<"Se abrira una ventana en internet mostrando el diagrama de cuerpo libre de cada caso."<<endl;
	cout<<"Si desea tener acceso a la imagen mientras que este offline, descargue el documento porfavor. "<<endl;
	
	system ("pause");//Pide que Presione suna tecla para continuar
	system(std::string("start https://drive.google.com/file/d/1hY7bZCJKLCwoVm1iusLN95Xs_Nc2ggWh/view?usp=drivesdk" ).c_str());
	//Direcciona al link
	while(con==1)
	{
	do
	{
	cout<<"Ingrese el caso que desea resolver:"<<endl;
	cin>>opcion1;	
	cout<<endl<<"................................."<<endl;
	}while((opcion1!=1)&&(opcion1!=2));	
	
	//Eliga el caso
	switch(opcion1)
	{
	case 1: caso1();break;
	case 2: caso2();break;	
	}
	
	while(a=1)
	{	
	cout<<"Ingrese 0 para salir"<<endl<<"Ingrese 1 para continuar "<<endl;
	cin>>con;
	cout<<endl<<"......................................."<<endl;
	if((con!=1)&&(con!=0))
	{
		cout<<endl<<"................................."<<endl<<endl;
		cout<<"Ingrese una opcion valida: "<<endl;
		a=1;
	}
	else
	{
	break;
	}	
	}	
	}
	
	getch();
	return 0;
	
	
}
	

//Funcion 1.............................................................................
float verdad(int n,string nombres[],float opc[])
{
	for(int i=0;i<n;i++)
	{
		do
		{
			cout<<i+1<<". "<<nombres[i]<<" : " ;
			cin>>opc[i];	
		}while((opc[i]!=0)&&(opc[i]!=1));
	}
}
//Funcion 2..............................................................................
float guardarvalores(int n,string nombres[],float opc[],float val[],string unidades[])
{
for(int i=0;i<n;i++)
	{
		if(opc[i]==1)
		{
			cout<<"Ingrese el valor de "<<nombres[i]<<" en "<<unidades[i]<<": ";
			cin>>val[i];	
		}
	}	
}
//Funcion 3..............................................................................
float checkvalores(float val[],float val2[],int n,int n2,int aux,float opc[])
{
//int f=0;cout<<"Un valor de 2 representa elementos iguales y uno de 3, elementos discordes:"<<endl;
	int check=0;
	for(int i=0;i<n-n2;i++)//Se hacen n-n2=7-4=3 rondas
	{	
//cout<<"Vuelta"<<i+1<<". Comparasion de elementos: "<<endl;
		for(int k=0;k<n2;k++)//Val2 agarra n2=4 valores para usar en las formulas
		
		{
			//La combinacion de los primeros 2 fors anidados permite guardar los primeros 3 valores de val[] en las primeras 3 
			//posiciones de val2[], luego del segundo valor hasta el cuarto valor de val[], en val2[] desde su 
			//segundo valor hasta su cuarto valor respectivamente, y asi sucesivamente...
			val2[i+k]=val[i+k];
			//LLamar a la funcion formulas1 hace que val2[] calcule los elementos restantes partiendo de los primeros 3
			//elemtos de v[1], de esta forma se verifica si los datos de ambos vectores coinciden din importar con cuales 3 valores 
			//base se partan
		}
		//Una vez agarrados los valores, se ejecutan las formulas para luego comparar los elementos y ver si el resultado es el mismo
			if(n==7)
			{
			formulas1(val,n,opc);
			formulas1(val2,n,opc);	
			}
			if(n==9)
			{
			formulas2(val,n,opc);
			formulas2(val2,n,opc);	
			}
			//
			for(int h=0;h<n;h++)
			{
			if((val[h]==val2[h])&&((val[h]-val[h])==0))//Los calculos coinciden al ejecutarlos multiples veces y estos no incluyen datos Inf,NAN o NULL
			//Compara los ELEMENTOS de cada arreglo, uno por uno
			{	
			aux=2;	
			}	
			else//Los calculos no coinciden al ejecutarlos multiples veces, por ende hay error de coherencia
			{
			check=1;//Pongo un check y no un aux aqui, ya que el ciclo puede cambiar el aux en alguna vuelta y el break 
			//no rompe todos los fors, solo este,lo que nos lleva al misimo problema del ciclo cambiando el aux	
//aux=3;	
			}
		
//cout<<"Elmento "<<h<<" --> "<<aux<<endl;
			
			}
/*			
f=f+1;
cout<<endl<<"Vuelta "<<f<<". Datos "<<endl;
for(int i=0;i<7;i++)
{
cout<<"Elemento "<<i<<" -- Vec1 -> "<<val[i]<<endl;
}
cout<<endl;
for(int i=0;i<7;i++)
{
cout<<"Elemento "<< i<<" --Vec2 -> "<<val2[i]<<endl;
}	
*/	
		
	}
	if(check==1)
	{
	aux=3;//Incoherencia
	}

	return aux;
	
	
	
}
//Funcion 4.................................................................................
float mostrarvalores(int n,string nombres[],float opc[],float val[],string unidades[])
{
	for(int i=0;i<n;i++)
	{
	if(opc[i]==0)
	{
	cout<<"El valor de "<<nombres[i]<<" es "<<val[i]<<" "<<unidades[i]<<endl;

	}
	
	}
}
//Funcion 5.................................................................................

float mostrarvalores2(int n,string nombres[],float opc[],float val[],string unidades[])
{
	for(int i=0;i<n;i++)
	{
	if(opc[i]==1)
	{
	cout<<"El valor de "<<nombres[i]<<" es "<<val[i]<<" "<<unidades[i]<<endl;
	
	}
	
	}
}
//Funcion 6
float formulas1(float val[],int n,float opc[])
{
	int i=0,aux=-1;
	while((val[0]==0)||(val[1]==0)||(val[2]==0)||(val[3]==0)||(val[4]==0)||(val[5]==0)||(val[6]==0)){
	//El codigo se repite hasta que todos los valores que eran ceros(Ya que los valores desconocidos son 0 predeterminadamente)
	//dejen de ser 0
	i++;//Iterador para coratar el ciclo si no hay datos suficientes para resolver
	//Formula Para aceleracion
	if((val[5]==0)&&(val[6]!=0)&&(val[4]!=0)&&(val[3]!=0))
	{
	val[5]=(val[6])*((val[4]-val[3])/(val[3]+val[4]));
	}
	//Formula para tension
	if((val[0]==0)&&(val[3]!=0)&&(val[5]!=0)&&(val[6]!=0))
	{
	val[0]=(val[3]*(val[5]+val[6]));//T=m1*(a+g)
	}
	
	//Formula para gravedad
	if((val[6]==0)&&(val[5]!=0)&&(val[4]!=0)&&(val[3]!=0))
	{
		val[6]=(val[5])*(val[3]+val[4])/(val[4]-val[3]);	
	}
	if((val[6]==0)&&(val[1]!=0)&&(val[3]!=0))
	{
		val[6]=(val[1])/(val[3]);	
	}
	if((val[6]==0)&&(val[2]!=0)&&(val[4]!=0))
	{
		val[6]=(val[2])/(val[4]);	
	}
	//Formula para masa1
	if((val[3]==0)&&(val[0]!=0)&&(val[5]!=0)&&(val[6]!=0))
	{
	val[3]=(val[0]/(val[5]+ val[6]));	
	}
	
	if((val[3]==0)&&(val[1]!=0)&&(val[6]!=0))
	{
	val[3]=(val[1]/val[6]);	
	}
	
	//Formula para masa2
	if((val[4]==0)&&(val[0]!=0)&&(val[6]!=0)&&(val[5]!=0))
	{
		val[4]=(val[0]/(val[6]-val[5]));	
		
	}
	
	if((val[4]==0)&&(val[2]!=0)&&(val[6]!=0))
	{
	val[4]=(val[2]/val[6]);	
	}
	
	//Formula para Peso1
	if((val[1]==0)&&(val[3]!=0)&&(val[6]!=0))
	{
		val[1]=val[3]*val[6];	
	}
	
	//Formula para Peso2
	if((val[2]==0)&&(val[4]!=0)&&(val[6]!=0))
	{
	val[2]=val[4]*val[6];	
	}
	//............................................formulario Termina.......................................................//
	
	//............................................Solucion de Errores Inicia......................................................//
	
	if(i==100)
	{
		//Contador para resolver el problema cuando ingresamos datos insuficientes opc[] , y los elemntos vacios son tomados como
		//0, por ende cumpliendo las condiciones de estatica pero porque los elementos vacios contienen 0 como valor 
		//predeterminado no porque sea un problema de estatica real
		int k=0;
		for(int i=0;i<n;i++)
		{
			if(opc[i]==1)
			{
			k++;	
			}
		}
		if((val[5]==0)&&(val[3]==val[4])&&(val[1]==val[2])&&(val[0]==0)&&(k>=4))
		//if((a==0)&&(m1==m2)&&(p1==p2)&&(T==0)//Solucion en caso de masas y pesos iguales entre si e iguales a cero
		//Lo que implica --> Estatica
		{
			//Solucion al caso de Estatica
			aux=0;
		}
		else
		{
			//Solucion para cuando el problema no tenga datos sufiecientes para hallar la solucion  
			aux=1;//Sin suficientes datos
		}
		break;	
			
	}

	
	}//acaba el while

	
		
	return aux;
}
//Funcion 7
float formulas2(float val[],int n,float opc[])
{
	int i=0,aux=-2;
	//	T1=2*T2;
	//	a2=2*a1;
	while((val[0]==0)||(val[1]==0)||(val[2]==0)||(val[3]==0)||(val[4]==0)||(val[5]==0)||(val[6]==0)||(val[7]==0)||(val[8]==0))
	{
		i++;//Iterador para coratar el ciclo si no hay datos suficientes para resolver	
	//Formula para Tensión 1
	//Clave
	
		if((val[0]==0)&&(val[1]!=0))
		{
			val[0]=2*val[1];
						//T1=2*T2
		}
		
//cout<<endl<<val[0]<<endl;
		
	//Formula para Tensión 2
		//1.
		if((val[1]==0)&&(val[2]!=0)&&(val[6]!=0)&&(val[8]!=0))
		{
			val[1]=(val[2]*2*val[7]+val[2]*val[8])/2;		//T2=(m1*2*a2+m1*g)/2
		}
		//2.//Clave
			if((val[1]==0)&&(val[0]!=0))
		{
			val[1]=0.5*val[0];			//T2=0.5*T1
		}
		//3.
			if((val[1]==0)&&(val[3]!=0)&(val[8]!=0)&(val[6]!=0))
		{
			val[1]=val[3]*val[8]-val[3]*2*val[6];			//T2=m2*g-m2*2*a1
		}
		//4.//IMPORTANTE
			if((val[1]==0)&&(val[3]!=0)&(val[8]!=0)&(val[7]!=0))
		{
			val[1]=val[3]*(val[8]-val[7]);			//T2=m2*(g-a2)
		}
		
//cout<<endl<<val[1]<<endl;
		
	//Formula para Masa 1
		
		//2.
		if ((val[2]==0)&&(val[4]!=0)&&(val[8]!=0))
		{
			val[2]=val[4]/val[8];		//m1=P1/g
		}
		//IMPORTANTE
		if((val[2]==0)&&(val[1]!=0)&&(val[4]!=0)&&(val[7]!=0))
		{
			val[2]=((2*val[1])-val[4])/(2*val[7]);		//m1=(2*T2-P1)/2a2
		}
		
//cout<<endl<<val[2]<<endl;		
		
	//Formula para Masa 2
		if((val[3]==0)&&(val[7]!=0)&&(val[1]!=0)&&(val[8]!=0))
		{
			val[3]=val[1]/(val[8]-val[7]);	//m2=T2/(g-a2)
		}
		if((val[3]==0)&&(val[5]!=0)&&(val[8]!=0))
		{
			val[3]=val[5]/val[8];		//m2=P2/g
		}
		
		
//cout<<endl<<val[3]<<endl;	
	
	//Formula para Peso 1
		if((val[4]==0)&&(val[2]!=0)&&(val[8]!=0))
		{
			val[4]=val[2]*val[8];		//P1=m1*g
		
		}
		if((val[4]==0)&&(val[2]!=0)&&(val[1]!=0)&&(val[6]!=0))
		{
			val[4]=2*val[1]-val[2]*val[6];		//P1=2*T2-m1*a1
			
		}
//cout<<endl<<val[4]<<endl;		
		
	//Formula para Peso 2
		if((val[5]==0)&&(val[3]!=0)&&(val[8]!=0))
		{
			val[5]=val[3]*val[8];		//P2=m2*g
		}
		if((val[5]==0)&&(val[3]!=0)&&(val[6]!=0)&&(val[1]!=0))
		{
			val[5]=val[3]*2*val[6]+val[1];		//P2=m2*2*a1+T2
		}
//cout<<endl<<val[5]<<endl;		
		
	//Formula para Aceleración 1
		//1//Clave
		if((val[6]==0)&&(val[7]!=0))
		{
			val[6]=0.5*val[7];			//a1=0.5*a2
		}
//cout<<endl<<val[6]<<endl;		
		
	//Formula para Aceleración 2
		if((val[7]==0)&&(val[6]!=0))
		{
			val[7]=2*val[6];			//a2=2*a1
		}
		//2//IMPORTANTE
		if((val[7]==0)&&(val[8]!=0)&&(val[3]!=0)&&(val[2]!=0))
		{
			val[7]=val[8]*(2*val[3]-val[2])/(2*val[2]+2*val[3]);			//a2=g*(2*m2-m1)/(2*m1+2*m2)
		}									
//cout<<endl<<val[7]<<endl;											
											
	//Formula para Gravedad
	/*	if((val[8]==0)&&(val[2]!=0)&&(val[6]!=0)&&(val[1]!=0))
		{
			val[8]=(-1*val[2]*val[6]+2*val[1])/val[2];	//g=(-m1*a1+2*T2)/m1
		}
		if((val[8]==0)&&(val[3]!=0)&&(val[6]!=0)&&(val[1]!=0))
		{
			val[8]=(val[3]*2*val[6]+val[1])/val[3];		//g=(m2*2*a1+T2)/m2
		}
		*/
		if((val[8]==0)&&(val[1]!=0)&&(val[2]!=0)&&(val[3]!=0))
		{
			val[8]=(2*val[1]*(val[3]+val[2])/(3*val[2]*val[3]));		//g=(2*T2*(m2+m1))/3*m1*m2
		}
		if((val[8]==0)&&(val[4]!=0)&&(val[2]!=0))
		{
			val[8]=val[4]/val[2];		//g=P1/m1
		}
		if((val[8]==0)&&(val[5]!=0)&&(val[3]!=0))
		{
			val[8]=val[5]/val[3];		//g=P2/m2
		}
//cout<<endl<<val[8]<<endl;	
	//............................................formulario Termina.......................................................//
	//............................................Solucion de Errores Inicia......................................................//
	
	if(i==100)
	{
		//Contador para resolver el problema cuando ingresamos datos insuficientes opc[] , y los elemntos vacios son tomados como
		//0, por ende cumpliendo las condiciones de estatica pero porque los elementos vacios contienen 0 como valor 
		//predeterminado no porque sea un problema de estatica real
		int k=0;
		for(int i=0;i<n;i++)
		{
			if(opc[i]==1)
			{
			k++;	
			}
		}
		//
		if((val[6]==0)&&(val[7]==0)&&(val[2]==val[3])&&(val[4]==val[5])&&(val[0]==0)&&(val[1]==0)&&(k>=4))
		//if((a1==0)&&(a2==0)&&(m1==m2)&&(p1==p2)&&(T1==0)//Solucion en caso de masas y pesos iguales entre si e iguales a cero
		//Lo que implica --> Estatica
		{
			//Solucion al caso de Estatica
			aux=0;
		}
		else
		{
			//Solucion para cuando el problema no tenga datos sufiecientes para hallar la solucion  
			aux=1;	
		}
		break;			
	}
	/*
	for(int i=0;i<n;i++)
	{
		cout<<endl<<i<<". "<<val[i]<<endl;
	}
	*/
	
	
	
}//acaba el while
	return aux;	
}

//Funcion 8.................................................................................
float caso1()
{
	float opc[M],val[M]={0,0,0,0,0,0,0},val2[M]={0,0,0,0,0,0,0};
	int n=7,n2=4,aux; 
	string nombres[] ={"Tension","Peso 1","Peso 2","Masa 1","Masa 2","Aceleracion","Gravedad"};
	string unidades[] ={"N","N","N","Kg","kg","m/s^2","m/s^2"};
	//n = Numero de variables del problema
	//n2= Minimo numero de datos que deben ser dados para resolver el problema
	//opc[M] guarda los valores 1 y 0 que funcionan como valores de verdad para saber si el dato es dado o no y 
	//val[M] guarda los valores reales de las variables 
	//val2[] copia los elementos del vector val[] para hacer la comparacion de coherencia despues

	cout<<"Para este tipo de problema las variables con las que se podria trabajar son: "<<endl;
	cout<<"1.Tension"<<endl;
	cout<<"2.Peso 1"<<endl;
	cout<<"3.Peso 2"<<endl;
	cout<<"4.Masa 1"<<endl;
	cout<<"5.Masa 2"<<endl;
	cout<<"6.Aceleracion"<<endl;
	cout<<"7.Gravedad"<<endl;
	cout<<endl;
	cout<<"Ingrese 1 si el dato es dado en el enunciado "<<endl;
	cout<<"Ingrese 0 si el dato no es dado en el enunciado "<<endl;
	cout<<"Los datos que no sean dados por el enunciado seran calculados y mostrados "<<endl;
	cout<<endl<<"......................................."<<endl;
	//Almacenar valores de verdad 0 o 1	
	verdad(n,nombres,opc);
	//Guardar valores numericos de las variables
	guardarvalores(n,nombres,opc,val,unidades);
	cout<<endl<<"......................................."<<endl;

	//Declarar y ejecutar todas las formulas: 
	aux=formulas1(val,n,opc);
	//Posibles respuestas y Debugging
	
	if(aux==0)
	{
	cout<<"Error: El sistema es estatico"<<endl;
	}
	else
	{
		if(aux==1)
		{
		cout<<"Error: Datos insuficientes"<<endl;	
		}
		else
			{
		//cout<<endl<<aux<<endl;	
		aux=checkvalores(val,val2,n,n2,aux,opc);
			if(aux==2)
			{
			//Mostrar valores de las variables restantes
			mostrarvalores(n,nombres,opc,val,unidades);		
			}
			else
			{
			cout<<"Error: Datos incoherentes"<<endl;
			}
			
			
			}
		}
	cout<<"......................................."<<endl;
	escribir(val,val2,opc,nombres,n,aux,unidades);
//	cout<<endl<<aux<<endl;
	}
	
//
float caso2()
{
	float opc[M], val[M]={0, 0, 0, 0, 0, 0, 0, 0, 0},val2[M]={0,0,0,0,0,0,0};
	int n=9,n2=5,aux; 
	string nombres []={"Tension 1","Tension 2", "Masa 1", "Masa 2", "Peso 1", "Peso 2", "Aceleracion 1", "Aceleracion 2", "Gravedad"};
	string unidades[] ={"N","N","Kg","kg","N","N","m/s^2","m/s^2","m/s^2"};
	//n = Numero de variables del problema
	//n2= Minimo numero de datos que deben ser dados para resolver el problema
	//opc[M] guarda los valores 1 y 0 que funcionan como valores de verdad para saber si el dato es dado o no y 
	//val[M] guarda los valores reales de las variables 
	//val2[] copia los elementos del vector val[] para hacer la comparacion de coherencia despues
	
 	cout<<"Para este tipo de problema las variables con las que se podria trabajar son: "<<endl;
    cout<<"1. Tension 1"<<endl;
    cout<<"2. Tension 2"<<endl;
    cout<<"3. Masa 1"<<endl;
    cout<<"4. Masa 2"<<endl;
    cout<<"5. Peso 1"<<endl;
    cout<<"6. Peso 2"<<endl;
    cout<<"7. Aceleracion 1"<<endl;
	cout<<"8. Aceleracion 2"<<endl;
    cout<<"9. Gravedad"<<endl;
    cout<<endl;
    cout<<"Ingrese 1 si el dato es dado en el enunciado: "<<endl;
	cout<<"Ingrese 0 si el dato no es dado en el enunciado: "<<endl<<endl;
    cout<<"Los datos que no sean dados por el enunciado seran calculados y mostrados "<<endl;
	cout<<endl<<"......................................."<<endl;
	
    //Almacenar valores de verdad 0 o 1	
	verdad(n,nombres,opc);
	
	//Guardar valores numericos de las variables
	guardarvalores(n,nombres,opc,val,unidades);
	cout<<endl<<"......................................."<<endl;

	//Declarar y ejecutar todas las formulas: 
	aux=formulas2(val,n,opc);
	//Posibles respuestas y Debugging
	if(aux==0)
	{
	cout<<"Error: El sistema es estatico"<<endl;
	}
	else
	{
		if(aux==1)
		{
		cout<<"Error: Datos insuficientes"<<endl;	
		}
		else
			{
			//cout<<endl<<aux<<endl;
			aux=checkvalores(val,val2,n,n2,aux,opc);
			if(aux==2)
			{
			//Mostrar valores de las variables restantes
			mostrarvalores(n,nombres,opc,val,unidades);		
			}
			else
			{
			cout<<"Error: Datos incoherentes"<<endl;
			}
			
			
			}
		}
	//Uso de Archivos para guradar ejercicios
	cout<<"......................................."<<endl;
	escribir(val,val2,opc,nombres,n,aux,unidades);
	//cout<<endl<<aux<<endl;

}
//
float escribir(float val[],float val2[],float opc[],string nombres[],int n,int aux,string unidades[])
{
	string a,name,frase;
	int opcion2;
	
	//Preguntar si desea usar el block de notas o no
	cout<<"Deseas guardar el ejercicio dentro de un archivo de block de notas?"<<endl;
	;
	do
	{
	cout<<"1.Si "<<endl<<"2.No "<<endl;
	cin>>opcion2;	
	}while((opcion2!=1)&&(opcion2!=2));
	cout<<endl<<"................................."<<endl<<endl;
	if(opcion2==1)
	{
	//
	ofstream archivo;
    //int numero;
   
    getline(cin,a);//Getline basura porque la compu no lee el primer getline super X
    cout<<"Escriba el nombre del archivo"<<endl<<"Nota: Si escribe el mismo nombre que el de un archivo anterior, este sera reemplazado"<<endl;
    getline(cin,name);//Getline para guardar el nombre del archivo
    archivo.open(name.c_str(),ios::out); //abrir o crear el archivo
	archivo<<"Ejercicio Nuevo"<<endl<<"................................."<<endl;//Se muestra como headline en el block de notas
    
    switch(aux)
    {
    case 0:	//Estatica
	{	for(int i=0;i<n;i++)
  	 	 {
  	 		if(opc[i]==1)
  	 		{
  	 		archivo<<"El valor de "<<nombres[i]<<" es "<<val[i]<<" "<<unidades[i]<<endl;	
			}			
		 }		
		archivo<<"Error: El sistema es estatico"<<endl;break;	
	}
    case 1:	//Datos insuficientes
	{
	for(int i=0;i<n;i++)
  	 	 {
  	 		if(opc[i]==1)
  	 		{
  	 		archivo<<"El valor de "<<nombres[i]<<" es "<<val[i]<<" "<<unidades[i]<<endl;
			}			
		 }		
	archivo<<"Error: Datos insuficientes"<<endl;break;	
	}
	case 2://Funciona
	{
		for(int i=0;i<n;i++)
  	 	 {
  		  	archivo<<"El valor de "<<nombres[i]<<" es "<<val[i]<<" "<<unidades[i]<<endl;	
		}	
	break;	
	}
	default://Datos incoherentes
	{
	for(int i=0;i<n;i++)
  	 	 {
  	 		if(opc[i]==1)
  	 		{
  	 			archivo<<"El valor de "<<nombres[i]<<" es "<<val[i]<<" "<<unidades[i]<<endl;
			}			
		 }		
	archivo<<"Error: Datos incoherentes"<<endl;	
	}
	}
    archivo.close();
	cout<<endl<<"................................."<<endl<<endl;
	}
}
  
   




    
    
	
	
	

			

