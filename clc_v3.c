#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int welcomeMsg(void);

double caseB(double firstNum , double secondNum , char op);
double caseU(double firstNum , char op);
double caseAOption1(double a, double b , double c , double d , double e);
double caseAOption2(double a, double b , double c , double d , double e);
double caseV(double *a, double *b, double *c, double *d, double *e);
double caseM(int num1 , int i , double ventry[]);
double caseR (int num1 , int i , double ventry[]);
void caseX (void);

double addition(double a , double b);
double subtraction(double a , double b);
double multiplication(double a , double b);
double division(double a , double b);
double remainder(double a , double b);
double power(double a , double b);
double maximum(double a , double b);
double minimum(double a , double b);
double squareRoot(double a);
double logarithm(double a);
double exponential(double a);
double ceiling(double a);
double floorFunction(double a);
int chooseMsg(char op);

int main(void) {

	welcomeMsg();

	char operation1;

	char operation2;

	double ventry[1000];
	int i = 1;
	int num1 = 0;
	char choose[10];
    int num2;

	bool once = true;

	double a = 0;
	double b = 0;
	double c = 0;
	double d = 0;
	double e = 0;

	do {

		double firstNum = 0;
		double secondNum = 0;
		double result = 0;
		char op = ' ';
		char var = ' ';

		if (once == true){
		fflush(stdin);
		scanf("%c", &operation1);
		operation1 = toupper(operation1);
		once = false;
		}
		else{
            operation1 = chooseMsg(operation1);
		}

		switch (operation1) {

		case 'B':

            result = caseB (firstNum , secondNum , op);
            printf("The result is: %.2lf\n\n", result);
            ventry[i] = result;
            i++;
            num1++;

		    break;

		case 'U':

            result = caseU(firstNum , op);

		    printf("The result is: %.2lf\n\n", result);
		    ventry[i] = result;
		    i++;
		    num1++;

			break;

		case 'A':

		    puts("Select one of the following items:");
			puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
			puts("U) - Unary Mathematical Operations, such as square root, and log.");
			puts("X) - Exit and back to the main menu");

			do {
                firstNum = 0;
				secondNum = 0;
				char vnum1[10];
				char vnum2[10];
				double result = 0;
				op = ' ';

				while (getchar() != '\n');

				scanf("%c", &operation2);

				operation2 = toupper(operation2);

				switch (operation2) {

				case 'B':

				    result = caseAOption1(a , b , c , d , e);
                    printf("The result is: %.2lf\n\n", result);
                    ventry[i] = result;
		            i++;
		            num1++;
		            break;

                case 'U':

                    result = caseAOption2 (a , b , c , d , e);
                    printf("The result is: %.2lf\n\n", result);
                    ventry[i] = result;
		            i++;
		            num1++;
		            break;

                case 'X':

                    break;
               }
               if (operation2 != 'X')
					puts("Please select your option ( B (Binary operation), U (Unary operation), X (Exit and back to the main menu))");
			}
               while (operation2 != 'X');

			break;

		case 'V':

		    caseV(&a, &b, &c, &d, &e);

			break;

        case 'M':

            caseM(num1 , i , ventry);

            break;

        case 'R':
            puts ("Resetting all memory of Calculator until now.....\n");

            ventry[i] = caseR (num1 , i , ventry);

            i = 1;
            num1 = 0;
            puts ("Memory clean.\nHeading back to main menu\n");
            break;

		case 'X':
			break;
		}
	}
	while (operation1 != 'X');
	caseX ();

	return 0;
}

int welcomeMsg(void){

    char operation1;

    puts("Welcome to our Command-Line Calculator (CLC)");
	puts("Developer: Shobhit Kumar Biswal");
	puts("Version: 3, Assignment 3");
	puts("Date: November 2021");
	puts("------------------");
	puts("Select one of the following items:");
	puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
	puts("U) - Unary Mathematical Operations, such as square root, and log.");
	puts("A) - Advances Mathematical Operations, using variables, arrays.");
	puts("V) - Define variables and assign them values.");
	puts("M) - Access to memory (All the calculations performed until now).");
	puts("R) - Reset memory.");
	puts("X) - Exit.");

}

double caseB(double firstNum , double secondNum , char op){

    firstNum = 0;
    secondNum = 0;
    op = ' ';
    double result = 0;
    char var = ' ';
    do {
        while (getchar() != '\n');

        puts("Please enter the first number:");

    } while (scanf("%lf", &firstNum) != 1);

    do {

        while (getchar() != '\n');

        puts("Please enter the operation ( + , - , * , / , % , P (for power) , X (for maximum) , I (for minimum) ):");

        } while ((scanf("%c", &op) != 1) || ((op != '+') && (op != '-') && (op != '*') && (op != '/') && (op != '%') && (toupper(op) != 'P') && (toupper(op) != 'X') && (toupper(op) != 'I')));

    do {

        if (op == '/')
            puts("Please enter the second number (non-zero):");
        else
            puts("Please enter the second number:");
        while (getchar() != '\n');
    } while ((scanf("%lf", &secondNum) != 1) || ((op == '/') && (secondNum == 0) ));

    switch (op) {

        case '+':

            result = addition(firstNum , secondNum);

            break;

        case '-':

            result = subtraction(firstNum , secondNum);

            break;

        case '*':

            result = multiplication(firstNum , secondNum);

            break;

        case '/':

            if (secondNum != 0)

                result = division(firstNum , secondNum);

            else {

                puts("Denominator can't be zero.");
                result = 0;

            }
            break;

        case '%':

            result = remainder(firstNum , secondNum);

            break;

        case 'P':
        case 'p':

            result = power (firstNum,secondNum);

            break;

        case 'X':
        case 'x':

            result = maximum(firstNum , secondNum);
            break;

        case 'I':
        case 'i':

            result = minimum(firstNum , secondNum);
            break;


        default:

            puts("It seems you have selected an invalid operator.");
            result = 0;
        }

        return result;

}

double caseU(double firstNum , char op){
    double result;
    do {
            while (getchar() != '\n');

            puts("Please enter the operation ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ):");
           }
            while ((scanf("%c", &op) != 1) || ((toupper(op) != 'S') && (toupper(op) != 'L') && (toupper(op) != 'E')&& (toupper(op) != 'C') && (toupper(op) != 'F')));
          do {
            if ((op == 'S') || (op == 's') || (op == 'L') || (op == 'l'))
            puts("Enter a positive value.");

            else
                puts("Please enter a number:");

            while (getchar() != '\n');
        }
        while ((scanf("%lf", &firstNum) != 1) || (((toupper(op) == 'S') || (toupper(op) == 'L')) && (firstNum < 0)));

        switch (toupper(op)) {

            case 'S':

                result = squareRoot(firstNum);
                break;

            case 'L':

                result = logarithm(firstNum);
                break;

            case 'E':
                result = exponential(firstNum);
                break;

            case 'C':
                result = ceiling(firstNum);
                break;

            case 'F':
                result = floorFunction(firstNum);
                break;

            default:
                puts("It seems you have selected an invalid operator.");
                result = 0;
            }
    return result;
}

double caseAOption1(double a, double b , double c , double d , double e){

				double firstNum = 0;
				double secondNum = 0;
				char vnum1[10];
				char vnum2[10];
				double result = 0;
				char op = ' ';

					do {
						while (getchar() != '\n');

						puts("Please enter the first number or a variable name ('a' to 'e'):");

						if (scanf("%s", vnum1) != 1)

							continue;

						if (vnum1[0] == 'a' || vnum1[0] == 'b' || vnum1[0] == 'c' || vnum1[0] == 'd' || vnum1[0] == 'e') {

							switch (vnum1[0]) {

							case 'a':
								firstNum = a;
								break;
							case 'b':
								firstNum = b;
								break;
							case 'c':
								firstNum = c;
								break;
							case 'd':
								firstNum = d;
								break;
							case 'e':
								firstNum = e;
								break;
							}
							break;
						}
						else {
							firstNum = atof(vnum1);
							if (firstNum != 0.0)
								break;
						}
					}
					while (1);

					do {
						while (getchar() != '\n');

						puts("Please enter the operation ( + , - , * , / , % , P (for power) , X (for maximum) , I (for minimum) :");

					}
					while ((scanf("%c", &op) != 1) || ((op != '+') && (op != '-') && (op != '*') && (op != '/') && (op != '%') && (toupper(op) != 'P') && (toupper(op) != 'X') && (toupper(op) != 'I')));

					do {
						while (getchar() != '\n');
						puts("Please enter the second number or a variable name ('a' to 'e'):");
						if (scanf ("%s" , vnum2)!= 1)
                            continue;
                        if (vnum2[0] == 'a' || vnum2[0] == 'b' || vnum2[0] == 'c' || vnum2[0] == 'd' || vnum2[0] == 'e') {

                            switch (vnum2[0]) {

							case 'a':
								secondNum = a;
								break;
							case 'b':
								secondNum = b;
								break;
							case 'c':
								secondNum = c;
								break;
							case 'd':
								secondNum = d;
								break;
							case 'e':
								secondNum = e;
								break;
							}
							if ((op == '/') && (secondNum == 0.0)) {
								puts("Denominator can not be zero\n");
								continue;
							}
							break;
                        }
						else {
							secondNum = atof(vnum2);
							if (secondNum != 0.0)
								break;
						}
					}

					while (1);

					switch (op) {
					case '+':
						result = addition(firstNum , secondNum);
						break;
					case '-':
						result = subtraction(firstNum , secondNum);
						break;
					case '*':
						result = multiplication(firstNum , secondNum);
						break;
					case '/':
						if (secondNum != 0)
							result = division(firstNum , secondNum);
						else {
							puts("Denominator could not be zero.");
							result = 0;
						}
						break;
					case '%':
						result = remainder(firstNum,secondNum);
						break;
					case 'P':
					case 'p':
						result = power(firstNum,secondNum);
						break;
					case 'X':
					case 'x':
						result = maximum(firstNum , secondNum);
						break;
					case 'I':
					case 'i':
						result = minimum(firstNum , secondNum);
						break;

					default:
						puts("It seems you have selected an invalid operator.");
						result = 0;
						return result;
					}
					return result;
}

double caseAOption2(double a, double b , double c , double d , double e){

                double firstNum = 0;
				double secondNum = 0;
				char vnum1[10];
				double result = 0;
				char op = ' ';

					do {
						while (getchar() != '\n');

						puts("Please enter the operation ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ):");
					}
					while ((scanf("%c", &op) != 1) || ((toupper(op) != 'S') && (toupper(op) != 'L') && (toupper(op) != 'E') && (toupper(op) != 'C') && (toupper(op) != 'F')));
					op = toupper(op);
					do {
						if ((op == 'S') || (op == 'L'))
							puts("Please enter a positive number or a variable name ('a' to 'e'):");
						else
							puts("Please enter a number or a variable name ('a' to 'e'):");
						while (getchar() != '\n');
						if (scanf("%s", vnum1) != 1)
							continue;
						if (vnum1[0] == 'a' || vnum1[0] == 'b' || vnum1[0] == 'c' || vnum1[0] == 'd' || vnum1[0] == 'e') {
							switch (vnum1[0]) {
							case 'a':
								firstNum = a;
								break;
							case 'b':
								firstNum = b;
								break;
							case 'c':
								firstNum = c;
								break;
							case 'd':
								firstNum = d;
								break;
							case 'e':
								firstNum = e;
								break;
							}
							if (((op == 'S') || (op == 'L')) && (firstNum < 0)) {
								puts("The variable you selected has a negative value.");
								continue;
							}
							break;
						}
						else {
							firstNum = atof(vnum1);
							if (((op == 'S') || (op == 'L')) && (firstNum < 0)) {
								puts("The number you have entered is negative.");
								continue;
							}
							if (firstNum != 0.0)
								break;
						}
					} while (1);

					switch (op) {
					case 'S':
						result = squareRoot(firstNum);
						break;
					case 'L':
						result = logarithm(firstNum);
						break;
					case 'E':
						result = exponential(firstNum);
						break;
					case 'C':
						result = ceiling(firstNum);
						break;
					case 'F':
						result = floorFunction(firstNum);
						break;

					default:
						puts("It seems you have selected an invalid operator.");
						result = 0;
						return result;
					}

					return result;

}

double caseV(double *a, double *b, double *c, double *d, double *e){

    double firstNum;

    char var = ' ';
		    do {
               while (getchar() != '\n');

               puts("Please enter the name of the variable ( A single character between 'a' to 'e' ):");

           }
            while ((scanf("%c", &var) != 1) || ((var != 'a') && (var != 'b') && (var != 'c') && (var != 'd') && (var != 'e')));
			do {

				while (getchar() != '\n');
				puts("Please enter a value to assign to the variable:");
			}
			while (scanf("%lf", &firstNum) != 1);
			switch (var) {

			case 'a':
				*a = firstNum;
				break;
			case 'b':
				*b = firstNum;
				break;
			case 'c':
				*c = firstNum;
				break;
			case 'd':
				*d = firstNum;
				break;
			case 'e':
				*e = firstNum;
				break;
			}

            printf("Variable %c is set to: %.2lf\n", var, firstNum);
}

double caseM(int num1 ,  int i , double ventry[]){
    int num2;
    char choose[10];
    choose[0] = ' ';

    printf ("There are %d items stored in the memomy\n" , num1);
    if (num1 == 0){
        puts ("There are no entries. Do some calculations first");
    }
    while (num1 != 0){

    while (choose[0] != 'X' && choose[0] != 'x'){
        puts("Enter the directory you want to view. Press Z to view all and X to exit");
        if (scanf("%s" , choose) != 1)
            continue;

        if (choose[0] == 'Z' || choose[0] == 'z'){

            for (i=1 ; i < num1+1;i++){
                        printf ("Entry [%d] =  %.2lf\n" , i , ventry[i]);
            }
        }
        else if (choose[0] == 'X' || choose[0] == 'x') {
            puts ("Exiting Momory of calculator\n");
            break;
        }
        else if(atof(choose) != 0.0 ){
            num2 = atof(choose);
            if (num2 <= num1){
            printf ("Entry [%d] = %.2lf\n", num2 , ventry[num2]);
            }
            else{
                puts ("Entry invalid. Please give a valid input!!\n");
            }
        }
        }
        break;
    }
}

double caseR (int num1 , int i , double ventry[]){
    for (i = 1 ; i < num1+1 ; i++){
        ventry[i] = 0;
    }
    return ventry[i];
}

void caseX (void){
    puts("Thanks for using my Simple Calculator. Hope to see you soon again, Goodbye!");
}

double addition(double a , double b){

    double result = a + b;

    return result;

}

double subtraction(double a , double b){

    double result = a - b;

    return result;

}

double multiplication(double a , double b){

    double result = a * b;

    return result;

}

double division(double a , double b){

    double result = a / b;

    return result;

}

double remainder(double a , double b){

    double result = fmod(a , b);

    return result;

}

double power(double a , double b){

    double result = pow(a , b);

    return result;

}

double maximum(double a , double b){

    double result = a >= b ? a : b;

    return result;

}

double minimum(double a , double b){

    double result = a <= b ? a : b;

    return result;

}

double squareRoot(double a){

    double result = sqrt(a);

    return result;

}

double logarithm(double a){

    double result = log(a);

    return result;

}

double exponential(double a){

    double result = exp(a);

    return result;

}

double ceiling(double a){

    double result = ceil(a);

    return result;

}

double floorFunction(double a){

    double result = floor(a);

    return result;

}

int chooseMsg(char op){
    do {
        while (getchar() != '\n');

        puts("Please select your option ( B (Binary operation), U (Unary operation) , A (Advanced), V (Variables), M (View Memory) , R (Reset Memory) ,  X (Exit))");
    }
    while ((scanf(" %c", &op) != 1) || ((toupper(op) != 'B') && (toupper(op) != 'U') && (toupper(op) != 'A')&& (toupper(op) != 'V') && (toupper(op) != 'M') && (toupper(op) != 'R') && (toupper(op) != 'X')));

    op = toupper(op);

    return op;

}



