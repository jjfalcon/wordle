/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "test.c"

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

char userAnswer[20];
int  userAttemps = 0;
char * wordleWordOfDay;

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
 // userAttemps++;
  return res;
}

void 
wordle_enter(char * answer) {
  char * resultado = "00000";
//  char * WordOfDay = "LIMON";

  if (strlen(answer) != 5) {
    printf("ERROR: la palabra introducida no tiene 5 letras\n");
    return;
  }
  if (!existsInDictionary(answer)) {
    printf("ERROR: la palabra introducida no existe en el diccionario\n");
    return;
  }
  
  userAttemps++;
//  printf("intento %d", wordle_intentos);
  resultado = Wordle(answer, wordleWordOfDay);
  
  if (strcmp(resultado, "22222") == 0) {
    printf("PALABRA ACERTADA correctamente\n");
    return;
  }
  printf("%s intento %d\n", resultado, userAttemps);
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

int wordle_run(char * answer){

  if (strcmp(userAnswer, "C") == 0)          TestWordle (); 
  else if (strcmp(userAnswer, "H") == 0)     wordle_help(); 
  else if (strcmp(userAnswer, "T") == 0)     printf("*** TRADUCIR. No implementado\n");
  else if (strcmp(userAnswer, "D") == 0)     printf("*** DICCIONARIO. No implementado\n");
  else if (strcmp(userAnswer, "Q") == 0)     return 3;
  else if (strcmp(userAnswer, "TODO") == 0)  TODO();
  else if (strlen(userAnswer) == 5)          wordle_enter(userAnswer);
  /* more else if clauses */
  else printf("%c\n", userAnswer[0]);

//  if (strcmp(userAnswer, "Q"))       return 3;
  if (userAttemps > 5)                       return 2;
  if (strcmp(userAnswer, wordleWordOfDay)==0)return 1; 
  return 0;
}

void wordle_init(){
  TestWordle ();  
  wordle_help();  

  wordleWordOfDay =  Dictionary[0];
}

int
main ()
{
  int i;

  wordle_init();
  do {
 
    scanf("%s",userAnswer);
    for (i=0;i<strlen(userAnswer);i++) userAnswer[i] = toupper(userAnswer[i]);
    //printf("%s\n",answer);

  } while (wordle_run(userAnswer) == 0);
  
  return 0;
}


