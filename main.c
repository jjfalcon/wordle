/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include "test.h"

/*
extern void TestOpen(void);
extern int Test(int received, int expected);
extern int TestStr(char * received, char * expected);
extern int TestClose(void);
*/

/*
#include <time.h>

int numErrors = 0, numTest = 0;
int Test(int received, int expected) {
  numTest++;
  if (received != expected){
    numErrors++;
    printf("[x] TEST %.2d ERROR\n", numTest);
    printf("    < received = %d\n", received);
    printf("    < expected = %d\n", expected); 
  } else
    printf("[v] TEST %.2d OK (%d = %d)\n", numTest,received, expected);
}

int TestStr(char * received, char * expected) {
  numTest++;

  if (strcmp(received, expected)) {
    numErrors++;
    printf("[x] Test %.2d ERROR\n", numTest);
    printf("    < received = %s\n", received);
    printf("    < expected = %s\n", expected); 
  } else
    printf("[v] Test %.2d OK (%s = %s)\n", numTest, received, expected);
//  return "00000";
}

clock_t start;
void TestOpen(void){
  printf("*** TEST Open ***\n");
  numErrors = 0; 
  start = clock();  
} 

void TestClose(void){
  printf("*** TEST Close ***\n");
  printf("    Errors = %d\n", numErrors);
  printf("    Passed = %d\n", numTest-numErrors);
  printf("    Time   = %.3f seconds\n", (double)(clock() - start)/CLOCKS_PER_SEC);
} 
*/

int wordle_intentos = 0;

#define DictionaryLength 5
char *Dictionary[DictionaryLength] = {
  "ABACO",
  "BASAL",
  "LIMON",
  "MELON",
  "PODER"
};


int
existsInDictionary (char *word)
{
  int i;

  for (i = 0; i < DictionaryLength - 1; i++)
    {
//    printf("%s\n", Dictionary[i]);
      if (!strcmp (word, Dictionary[i]))
	{
	  return 1;
	}
    }
  return 0;
}




int
kapikua (int num)
{
  int aux, resto = 0, numInv = 0;

  aux = num;

  while (aux > 0)
    {
      resto = aux % 10;
      aux = aux / 10;
      numInv = numInv * 10 + resto;
    }
  return numInv;
}

int
TestKapikua (void)
{
  TestOpen ();
  Test ("", kapikua (0), 0);
  Test ("", kapikua (12), 21);
  Test ("", kapikua (124), 421);
  Test ("", kapikua (10), 01);
  Test ("", kapikua (14567), 67542);
  return TestClose ();
}

char res[20];

char *
Wordle (char *input, char *expected)
{
  int i = 0;

  strcpy (res, "");
  while ((input[i] != 0) && (expected[i] != 0))
    {
      if (input[i] == expected[i])
	      strcat (res, "2");
      else if (strchr (expected, input[i]))
	      strcat (res, "1");
      else
	      strcat (res, "0");
      i++;
    }

  return res;
}

void 
wordle_enter(char * answer) {
char * resultado = "00000";
char * WordOfDay = "LIMON";

  if (strlen(answer) != 5) {
    printf("ERROR: la palabra introducida no tiene 5 letras\n");
    return;
  }
  if (!existsInDictionary(answer)) {
    printf("ERROR: la palabra introducida no existe en el diccionario\n");
    return;
  }
  
  wordle_intentos++;
//  printf("intento %d", wordle_intentos);
  resultado = Wordle(answer, WordOfDay);
  
  if (strcmp(resultado, "22222") == 0) {
    printf("PALABRA ACERTADA correctamente\n");
    return;
  }
  printf("%s intento %d\n", resultado, wordle_intentos);
}

int
TestWordle ()
{
  TestOpen ();

  TestSuite ("Wordle");
  //Wordle
  //1 palabra cada dia
  //5 letras cada palabra
  //6 intentos
  //https://hipertextual.com/2022/01/wordle-juego-trucos
  //0 indica que la letra no esta en la palabra
  //1 indica que la letra esta en la palabra, en posiciC3n incorrecta
  //2 indica que la letra estC! en la palabra, posicion correcta
  TestStr ("ABEJA=LIMON sin coincidencias",
	   Wordle ("ABEJA", "LIMON"), "00000");
  TestStr ("VELAS=LIMON L en distinta posicion",
	   Wordle ("VELAS", "LIMON"), "00100");
  TestStr ("LEVAS=LIMON L en misma posicion",
	   Wordle ("LEVAS", "LIMON"), "20000");
  TestStr ("CALOR=LIMON L en distinta posicion y O en misma posicion",
	   Wordle ("CALOR", "LIMON"), "00120");
  TestStr
    ("LIMON=LIMON palabra igual y coinciden todas las letras en misma posicion",
     Wordle ("LIMON", "LIMON"), "22222");

  TestSuite ("Dictionary");
  Test ("LIMON in Dictionary", existsInDictionary ("LIMON"), 1);
  Test ("ACALP not in Dictionary", existsInDictionary ("ACALP"), 0);

  return TestClose ();
}

void
TODO(void) {
/*
  "[v] Jugar con cadenas de 5\n"
  "[v] Introducir cadena que no existe en diccionario\n"

*/

  char * todoList = 
  ""
  ;

  if (strcmp(todoList, "") != 0) 
    printf("\nTODO\n%s", todoList);

}

void
wordle_help(void) {
  printf("\nCOMO JUGAR\n\n");
  printf("Adivina la palabra oculta en seis intentos.\n\n");
  printf("Cada intento debe ser una palabra válida de 5 letras.\n\n");
  printf("Después de cada intento el color de las letras cambia para mostra qué tan cerca estás de acertar la palabra.\n\n");
  printf("Ejemplos\n\n");
  printf("GATOS\n");
  printf("V****\n");
  printf("La letra G está en la palabra y en la posición correcta. El resto no está.\n\n");
  printf("VOCAL\n");
  printf("**-**\n");
  printf("La letra C está en la palabra pero en la posición icorrecta. El resto no está.\n\n");
  printf("Puede haber letras repetidas. Las pistas son independientes para cada letras.\n\n");
  printf("Después de cada intento el color de las letras cambia para mostra qué tan cerca estás de acertar la palabra.\n\n");
  printf("Puedes usar los siguientes comandos\n");
  printf("Help presenta esta ayuda\n");
  printf("Quit sale del juego\n");
  printf("Trad traduce última palabra\n");
  printf("Dict diccionario última palabra\n");

  printf("ccccc palabra de cinco letras del intento\n\n");
  printf("\nEnter a command or word:\n");
}

int
main ()
{
  int i;
  char answer[20];
//  TestKapikua();

  TestWordle ();
  
  wordle_help();
  do {

    scanf("%s",answer);
    for (i=0;i<strlen(answer);i++) answer[i] = toupper(answer[i]);
  //  printf("%s\n",answer);

    if (strcmp(answer, "C") == 0)          TestWordle (); 
    else if (strcmp(answer, "H") == 0)     wordle_help(); 
    else if (strcmp(answer, "T") == 0)     printf("*** TRADUCIR. No implementado\n");
    else if (strcmp(answer, "D") == 0)     printf("*** DICCIONARIO. No implementado\n");
    else if (strcmp(answer, "Q") == 0)  ;
    else if (strcmp(answer, "TODO") == 0)  TODO();
    else if (strlen(answer) == 5)          wordle_enter(answer);
    /* more else if clauses */
    else printf("%c\n", answer[0]);
 
 /*
    switch (answer) {
      case "C": TestWordle ();
                break;
      case "H": wordle_help();
                break;
      case "T": printf("*** TRADUCIR. No implementado\n");
                break;
      case "D": printf("*** DICCIONARIO. No implementado\n");
                break;
      case "Q": break;
      default:  printf("%c\n", answer[0]);
                break;
    }
   if (toupper(answer) == 'H') wordle_help();
    else if (toupper(answer) == 'T') printf("*** TRADUCIR. No implementado\n");
    else if (toupper(answer) == 'D') printf("*** DICCIONARIO. No implementado\n");
    else if (toupper(answer) == 'Q') ;
    else printf("%c\n", toupper(answer));
  } while (toupper(answer) != 'Q');
*/
  } while (strcmp(answer, "Q") && (wordle_intentos < 3));
  
  return 0;
}


