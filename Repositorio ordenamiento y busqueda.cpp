#include <iostream>
using namespace std;

//Algoritmo de ordenamiento por selección
//Busca el menor elemento del arreglo y lo intercambia con el de la primera posición
void algortimo_seleccion(int a[], int n) {
    int i, j, aux, min;
    for (i=0; i<n; i++)
    {
        min=i;
        for (j=i+1; j<n; j++){
            if (a[j]<a[min]){
                min=j;
            }
        }
    }
    aux= a[i];
    a[i]=a[min];
    a[min]=aux;
}

//Encontar el menor elemento de un arreglo
void menorElemento(int a[], int n){
    int i, ab;
    ab=a[0];
    for (i=1;i<n;i++){
        if(ab>a[i]){
            ab=a[i];
        }
    }
    cout<<"El elemento menor es: "<<ab<<endl;
}
//Agregar elementos a un arreglo
void agregar_elem(int a[], int n){
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
}

//imprimir elementos del arreglo
void imprimir_a(int a[], int n){
    for (int i=0; i<n; i++){
        cout<<a[i]<<"|";
    }
}

// Algoritmo de ordenamiento por inserción
//Toma un elemento clave y los compara con todos los elementos 
//a la izquierda y realiza el intercambio donde corresponda
void insercion (int a[], int n){
    int aux; //Almacena de forma temporal un dato
    for (int i=0; i<n; i++){
        aux=a[i];
        int p=i;
        while (p>0){
            if (a[p-1]>aux){
                a[p]=a[p-1];
                a[p-1]=aux;
            }
            p--;
        }
    }
}

//Algoritmo de búsqueda por interpolación
// Se debe ordenar primero todos los elementos del arreglo
//Fórmula:
//medio=primero+((num-A[primero])+(ultimo-primero))/(A[ultimo]-A[primero])
void interpolacion(int a[], int n, int num){
    int primero=0;
    int ultimo=n-1;
    int medio;
    int contador=0;
    while (a[primero]!=num&& contador<n){
        medio=primero+((num-a[primero])*(ultimo-primero))/(a[ultimo]-a[primero]);
        if(a[medio]<num)
        primero=medio+1;
        else if(a[medio]>num)
        ultimo=medio-1;
        else
        primero=medio;

        contador++;
        break; //para evitar errores
    }
    if (a[primero]==num){
        cout<<"Elemento encontrado"<<endl;
    }
    else {
        cout<<"Elemento no encontrado"<<endl;
    }
}

//Algoritmo de ordamiento rápido mergesort
//Divide y venceras
//Se parte un arreglo de n elementos hasta que cada elemento este
//en un arreglo independiente, luego tomará dos arreglos y los fuciona
//desplzando a la izquierda los elementos menores y los mayoresa a la derecha
//Usa un proceso rescursivo

void dividir (int a[], int inicial, int final){
    //Dividir el arreglo en pequeños subarreglos
    int mitad;
    if(inicial<final){
        mitad=(inicial+final)/2;
        dividir(a, inicial, mitad); //mitad izquierda
        dividir(a, mitad+1, final); //mitad derecha
        fusionar(a, inicial, final, mitad);
    }
}

void fusionar(int a[], int pinicial, int pfinal, int medio){
    //Fusiona los sub arreglos
    int i, j, k, temp[pfinal-pinicial+1];
    i=pinicial;
    k=0;
    j=medio+1;
    //Fusionar mitad izquierda del arreglo
    while(i<=medio && j<=pfinal){
        if (a[i]<a[j]){
            temp[k]=a[i];
            k++;
            i++;
        }
        else{
            temp[k]=a[j];
            k++;
            j++;
        }
    }
    //Fusionar la mitad derecha del arreglo
    while(i<=medio){
        temp[k]=a[i];
        k++;
        i++;
    }
    while(j<=pfinal){
        temp[k]=a[j];
        k++;
        j++;
    }
    for(i=pinicial; i>pfinal; i++){
        a[i]=temp[i-pinicial];
    }
}

/*libreria ctime, para generar numero de manera aleatoria
    Comenzar con la semilla
    srand(time(0)); //genera numeros aletorios por cada ejecución
    for(i=0; i<n;i++){
        numeros[i]= rand()%100;
        //numero[i])=1+rand()%(20-1); ingresa numeros aleatorios en el arengo del 1-19
   }
   cout<<endl;
   for(int i=0; i<n; i++){
       cout<<"["<<numeros[i]<<"]";
   }
   cout<<endl;
   dividir(numeros, 0, 6);
   cout<<endl;
   for(int i=0; i<n; i++){
       cout<<"["<<numeros[i]<<"]";
   }
   cout<<endl;
*/

//Algoritmo de ordenamiento rápido Quicksort
//Dividir para vencer
//Usa un proceso recursivo, trabaja con pivote
//El pivoe puede ser el elemento del final, inicio o mitad del arreglo
//Usamos dos punteros uno al final y otro al inicio del arreglo
int mitad(int a[], int pinicial, int pfinal){
    return a[(pinicial+pfinal)/2];
}

void ordenar(int a[],int pinicial, int pfinal){
    int i=pinicial;
    int j=pfinal;
    int temp;
    int piv=mitad(a, pinicial, pfinal); //pfinal=tamaño arreglo-1
    do{
        while(a[i]<piv){
            //trabaja con la parte izquierda del arreglo
            i++;
        }
        while(a[j]<piv){
            j--;
        }
        if(i>=j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
    }
    while(i>=j);
    if(pinicial<j)
        ordenar(a, pinicial,j);
    if(i<pfinal)
        ordenar(a,i, pfinal);
}

//Librerias
//Permiten tener un código más limpio en main.cpp
//Se puede llamar a una libreria mediante <> o mediante ""
//Al archivo se le pone un nombre acompañado de un .h (Archivo cabecera)
//Tambien se puede invocar una libreria usando el using namespace palabra_clave
//no requieren declaracion de funciones, en las librerias se puede poner el prototipo de las fenciones
//en las librerias debemos impotar <iostream> para usar cout y cin
