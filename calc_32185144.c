#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[])
{
    FILE *fp = NULL;
    char *line = NULL;
    size_t len;
    ssize_t ret;
    int lineno =1;
    char init_filename [] = "/Users/nadiacandraa/Desktop/simple calc/input.txt";
    char *filename = init_filename;
    
    fp = fopen (filename, "r");
   
    while ((ret = getline (&line, &len, fp)) != -1)
    {
        char* input;
        char* input1;
        char* input2;
        
        input = strtok (line, " ");
        input1 = strtok (NULL, " ");
        input2 = strtok (NULL, " ");
        
        int r[9];
        int r0;
     
        int a = atoi(input1+2);
        int b = atoi(input2+2);
       // int c = atoi(input1+1);
        int d = atoi(input2+1);
        
        lineno++;
        
        if ((a != 0) && (b != 0)) { // defining it is hex
            if (input[0] == '+') {
                r[0] = a + b;
                printf ("R0: %d = %d + %d \n", r[0], a, b);
            } else if(input[0] == '-') {
                r[0] = a - b;
                printf("R0: %d = %d - %d \n", r[0], a, b);
            } else if(input[0] == '*') {
                r[0] = a * b;
                printf("R0: %d = %d * %d \n", r[0], a, b);
            } else if (input[0] == '/') {
                r[0] = a / b;
                printf("R0: %d = %d / %d \n", r[0], a, b);
            }
        }
        if (b != 0) { // for operands and hex number
            if( input[0] == 'M'){
                r[2] = b;
                printf("R2: %d \n", r[2]);
            }
        }
        if (d != 0) { //defining it is registers
            if (input[0] == '+') {
                r0 = r[0];
                r[0] = r[0] + r[2];
                printf("R0: %d = %d + %d\n", r[0], r0, r[2]);
                break;
            }
        }
        if (input [0] == 'H') {
            return r[0];
        }
    }
    

    if (ret == 0) return 0;
    
    if (fp==NULL) {
        printf("no file found\n");
        return 0;
    }
    free(line);
    
    fclose(fp);
    
    return 0;
    }

