/* write a program that converts strings of scientific notation into floating point numbers*/
#include<stdio.h>
#include<stdlib.h>
#include"scientific_to_float.h"

#define DIGIT(c)(c >= '0' && c <= '9')

char* a_scientific_string;
char* custom_base;
bool details_req;
int personal_base;
void get_arguements(int, char*[]), showUsage();

int main(int argc, char* argv[]) {
   // progCall string -b some_number
   if (argc == 1 || argc > 5) {
      callError("Not enough arguements given. Call the program with 'man' to get a usage guide.");
      exit(1);
   }
   get_arguements(argc, argv);

   double value = sc_atof(a_scientific_string, custom_base, details_req);
   printf("Conversion: %s -> %.12lf\n", a_scientific_string, value);
   return 0;
}

void get_arguements(int n, char* args[]) {
   int main_arguement_index = -1;
   for (int i = 1; i < n; ++i) {
      if (DIGIT(args[i][0])) { main_arguement_index = i; }
      else if (args[i][0] == '-') {
         if (args[i][1] == 'b' && (i < n - 1)) {
            personal_base = 1;
            custom_base = args[i + 1];
            ++i;
            continue;
         } else if (args[i][1] == 'd') {
            details_req = true;
         } else if (DIGIT(args[i][1])) {
            if (main_arguement_index > 0) {
               callError("Invalid Flag: Contains a number in it");
               exit(1);
            }
            main_arguement_index = i;
            continue;
         }
         else {
            callError("Incorrect Usage of Program");
            exit(1);
         }
      } else if (args[i][0] == 'm' || args[i][0] == 'M') {
        if (args[i][1] == 'a' || args[i][1] == 'A') {
           if (args[i][2] == 'n' || args[i][2] == 'N') {
              printf("Requested usage guide. The program will terminate after this\n");
              showUsage();
              exit(1);
           }
        } 
      }
   }
   if (main_arguement_index < 0) {
      callError("No input given.");
      exit(1);
   }
   if (!personal_base) { custom_base = "10"; }
   a_scientific_string = args[main_arguement_index];
}

void showUsage() {
   printf("SHOWING USAGE\n");
      /*Possible flags:
      -b number : set base to be the number
      -d : make it more verbose*/
}