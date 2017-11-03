//Creado por Guillermo Campollo y Daniela Becerra
//TRAGAMONEDAS CasinoFrutal
//Este codigo simula un tragamonedas el cual genera tres figuras aleatorias con un interfaz de juego facil y sencillo!


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//Creando nuestras funciones

void generador(int credito);//genera nuestros numeros y contiene el main loop
void opciones();//le escribe al usuario sus opciones, punto de partida en cada reiniciada
void limpiar();//limpia la pantalla
void finalizar();//te saca del programa
void gatica();//metodo de pregunta para poder obtener mas creditos
void numinvalido();//en caso de que el usuario ingresa un num invalido.

//estructura base la cual se usa para tener track de creditos y el dinero acumulado

typedef struct
{
    int credit;
    int money;
}d;

int choice;//esta variable es global y se usa para leer la opcion del usuario

//inicializando nuestra variable ya con el tipo de estrucutra que creamos
d debitcard = {0,0};

int main()
{
   //solo necesitamos dos funciones aqui


    limpiar();

    opciones();


return 0;}



void generador(int credit)
{
    int num1, num2, num3;

    //Creando nuestra semillita
    srand(time(NULL));
    //generando el numero aleatorio
    num1=rand() % 3;
    num2=rand() % 3;
    num3=rand() % 3;

 //Creando nuestra primera figura!!!

    switch(num1)
    {
    case 0:
        printf("La primera figura es...... CEREZA!\n");
        break;
    case 1:
        printf("La primera figura es...... MANZANA!\n");
        break;
    case 2:
        printf("La primera figura es...... FRESA!\n");
        break;
    }

    //Creando nuestra segunda figura!!


    switch(num2)
    {
    case 0:
        printf("La segunda figura es...... CEREZA!\n");
        break;
    case 1:
        printf("La segunda figura es...... MANZANA!\n ");
        break;
    case 2:
        printf("La segunda figura es...... FRESA!\n");
        break;
    }

    //Creando nuestra tercera figura!!

     switch(num3)
    {
    case 0:
        printf("La tercera figura es...... CEREZA!\n\n");
        break;
    case 1:
        printf("La tercera figura es...... MANZANA!\n\n");
        break;
    case 2:
        printf("La tercera figura es...... FRESA!\n\n");
        break;
    }
    //generando el resultado para nuestro usuario y tambien dandole la opcion de volver a jugar
    if (num1==num2 && num2==num3)
    {
        debitcard.money +=100;
        debitcard.credit -= 1;
        printf("felicidades ganaste!!\n\n Tu dinero acumulado es %i \nPara volver a jugar presione '1' para salir presione '2'\ncreditos:%i\n",debitcard.money,debitcard.credit);
        scanf("%i",& choice);
        if (choice == 1 && debitcard.credit >0)
            generador(debitcard.credit);
        else if(choice ==1 && debitcard.credit == 0)
        {

            printf("Ooops te faltan mas creditos\n\n");
            gatica();}
       else if(choice !=1 && choice!=2)
       {
           numinvalido();
       }

        else

        {finalizar();}


    }
    else
    {

        printf("Diablos!! Has perdido\n\nTeclea '1' para volver a jugar y '2' para salir\n\n");
        printf("Creditos restantes: %i, dinero acumulado: %i\n",debitcard.credit, debitcard.money);
        scanf("%i",& choice);
        debitcard.credit -= 1;
        if (choice == 1 && debitcard.credit >0)
            generador(debitcard.credit);
        else if(choice ==1 && debitcard.credit == 0)
            {
            printf("Ooops te faltan mas creditos\n\n");
            gatica();}
        else if(choice !=1 && choice!=2)
       {
           numinvalido();
       }
        else
            finalizar();
    }


}
void opciones()
{

    limpiar();
    printf("Bienvenido a CasinoFrutal\n ");
    printf("Aqui podras provar tu suerte\n");
    printf("Las instrucciones son muy sencillas\n ");
    printf("Escribe '1' Si quieres jugar (tendras 10 creditos)\n ");
    printf("Escribe '2' si quieres salir del juego\n");
    printf("Te mostraremos los resultados y veremos si ganaste(si ganas son $100 por juego ganado)!\n ");
    scanf("%i",& choice);

    if (choice == 1)
    {
        debitcard.credit = 10;
        generador(debitcard.credit);
    }
    else if (choice == 2)
    {
        finalizar();
    }
    else
    {
        numinvalido();
    }

}

void limpiar()
{
    int i;
    for (i=0;i<25;i++)
        printf("\n");
}

void finalizar()
{
    printf("Gracias por haber jugado");
    exit(0);
}


void gatica()
{
    int luis;
    while(1==1)
    {


    printf("Responde esta pregunta correctamente y podras seguir jugando, de otra manera, adios.\nQuien es el mejor programador de la historia?\n'1'-Luis Gatica\n'2'Dennis Ritchie\n");
    scanf("%i",&luis);


        if (luis ==1)
    {
        printf("Bien hecho");
        opciones();
    }

    else if (luis ==2)
    {
        break;
    }
    }
    finalizar();
}
void numinvalido()
{
    int i;
    while(1==1)
    {

    printf("Numero invalido por favor ingrese una opcion valida.\n");
    scanf("%i",&i);

        if (i==1)
    {
        debitcard.credit +=1;
        generador(debitcard.credit);
    }
   else if(i==2)
    break;
    }

finalizar();
}

