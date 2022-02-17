#include <stdio.h>
#include <time.h>
#include <string.h>

int SuiteErrors=0, SuiteTotal=0,  SuiteErrorStart=0;
int TestErrors = 0, TestTotal = 0;

int TestStr(char * msg, char * received, char * expected) {
  TestTotal++;

//  if (received != expected) {
  if (strcmp(received, expected)) {
//        ?
//        printf("strings are equal\n") :
//        printf("strings are not equal\n");
    TestErrors++;
    printf("[x] Test %.2d %s\n", TestTotal, msg);
    printf("    < received = %s\n", received);
    printf("    < expected = %s\n", expected); 
  } else
    printf("[v] Test %.2d %s (%s = %s)\n", TestTotal, msg, received, expected);

//  return "00000";
}

int Test(char * msg, int received, int expected) {
  TestTotal++;
  if (received != expected){
    TestErrors++;
    printf("[x] Test %.2d %s\n", TestTotal, msg);
    printf("    < received = %d\n", received);
    printf("    < expected = %d\n", expected); 
  } else
    printf("[v] Test %.2d %s (%d = %d)\n", TestTotal, msg, received, expected);
  
}

clock_t start;
void TestOpen(void){
  printf("*** TEST Open  ***\n");
  TestErrors = 0; 
  start = clock();  
} 

void TestSuite(char * msg){
  printf("\n%s\n", msg);
  SuiteTotal++; 
  if (SuiteErrorStart != TestErrors)
    SuiteErrors++;
  SuiteErrorStart = TestErrors;
//  start = clock();
} 

int TestClose(void) {
  if (SuiteErrorStart != TestErrors)
    SuiteErrors++;
  printf("\nTest Suites: %d errors, %d passed, %d total\n", SuiteErrors, SuiteTotal-SuiteErrors, SuiteTotal);
  printf("Tests:       %d errors, %d passed, %d total\n", TestErrors, TestTotal-TestErrors, TestTotal);
//Snapshots:   0 total
  printf("Time:        %.3f s\n", (double)(clock() - start)/CLOCKS_PER_SEC);

  printf("******************\n");
  printf(" Errors = %d\n", TestErrors);
  printf(" Passed = %d\n", TestTotal-TestErrors);
  printf(" Time   = %.3f seconds\n", (double)(clock() - start)/CLOCKS_PER_SEC);
  printf("*** TEST Close ***\n");
  return TestErrors;
  
/* JEST resumen
https://dev.to/danywalls/testing-errors-with-jest-hkj

dany@dany:~/Desktop/calculator(master)$ npm run test

> calculator@1.0.0 test /home/dany/Desktop/calculator
> jest

 PASS  src/tests/Calculator.test.ts
  Calculator
    ✓ should return a number (1 ms)
    ✓ should increment the number (1 ms)
    ✓ should return a calculation Object logic (1 ms)
    ✓ should return a error if is invalid action (1 ms)

Test Suites: 1 passed, 1 total
Tests:       4 passed, 4 total
Snapshots:   0 total
Time:        2.253 s
Ran all test suites.
*/
} 
