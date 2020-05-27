/*
 Braden Borough
 Michael Didier
 CS 224 Lab1
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <memory.h>


unsigned setRegComma (char bufferIn[10]);
unsigned setReg (char bufferIn[10]);

int main(int argc, const char * argv[]) {
    
    //Check for proper input, if there are not two  arguments, print error
    if (argc != 2){
        printf("Usage: <input_file.s>\n");
        return 1;
    }
    //Store file name
    char* outFileName;
    char* str1 = (char*) argv[1];
    size_t len = strlen(str1);
    int lineNumber = 1;
    
    //Store the last two chars of filename
    char* fileExtension = (char*) malloc(2);
    fileExtension[0] = str1[len-2];
    fileExtension[1] = str1[len-1];
    
    //Verify file extension is .s, if not ".s" extension, print error to terminal
    if (strncmp(fileExtension, ".s", 2) != 0){
        printf("Please input a file with extension '.s'\n");
    }
    
    //Read in file
    FILE* inputFile = fopen(argv[1], "r" ); //open file
    char buffer[100];
    
    //Format output file name
    char* str2 = ".o";
    char* str3 = (char *) malloc(1 + strlen(str1) + strlen(str2));
    
    int a = 0;
    //get number of chars in str2 (file name from argv1)
    while (str1[a] != 0){
        a++;
    }
    //delete '.s' from back of char array
    for (int b = 1; b < 3; b++){
        str1[a-b] = 0;
    }
    strcpy (str3, str1);
    strcat (str3, str2);
    outFileName = str3;
    
    //Write file
    FILE* outputFile;
    outputFile = fopen(outFileName, "w");
    
    unsigned nop = 0b00010000; //1 0
    unsigned halt = 0b00000000; //0 0
    unsigned rrmovq = 0b00100000; //2 0
    unsigned cmovle = 0b00100001; //2 1
    unsigned cmovl = 0b00100010; //2 2
    unsigned cmove = 0b00100011; //2 3
    unsigned cmovne = 0b00100100; //2 4
    unsigned cmovge = 0b00100101; //2 5
    unsigned cmovg = 0b00100110; //2 6
    unsigned irmovq = 0b00110000; //3 0
    unsigned rmmovq = 0b01000000; //4 0
    unsigned mrmovq = 0b01010000; //5 0
    unsigned addq = 0b01100000; //6 0
    unsigned subq = 0b01100001; //6 1
    unsigned andq = 0b01100010; //6 2
    unsigned xorq = 0b01100011; //6 3
    
    unsigned rA;
    unsigned rB;
    unsigned registerVal;
    
    while (fscanf(inputFile,"%s", buffer) != EOF){
        if (strcmp(buffer, "nop") == 0){
            fwrite(&nop, 1, 1, outputFile);
//            printf("nop: %x\n", nop);
            lineNumber++;
        }
        else if (strcmp(buffer, "halt") == 0){
            fwrite(&halt, 1, 1, outputFile);
//            printf("halt: %x\n", halt);
            lineNumber++;
        }
        else if (strcmp(buffer, "rrmovq") == 0){
            fwrite(&rrmovq, 1, 1, outputFile);
            
            //            printf("rrmovq: %x\n", rrmovq);
//            printf("buffer: %s\n", buffer);
            
            //Set register A
            fscanf(inputFile,"%s", buffer); //Get next command (rA)
            if (setRegComma(buffer) < 16){
                rA = setRegComma(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            //Set register B
            fscanf(inputFile,"%s", buffer); //Get next command (rB)
//            printf("buffer register B: %s\n", buffer);
            if (setReg(buffer) < 16){
                rB = setReg(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            registerVal = ((rA << 4) | rB);
            fwrite(&registerVal, 1, 1, outputFile);
            
//            printf("rA: %x\n", rA); //DEBUG CODE
//            printf("rB: %x\n", rB); //DEBUG CODE
            lineNumber++;
        }
        else if (strcmp(buffer, "cmovle") == 0){
            fwrite(&cmovle, 1, 1, outputFile);
            //            printf("rrmovq: %x\n", rrmovq);
//            printf("buffer: %s\n", buffer);
            
            //Set register A
            fscanf(inputFile,"%s", buffer); //Get next command (rA)
            if (setRegComma(buffer) < 16){
                rA = setRegComma(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            //Set register B
            fscanf(inputFile,"%s", buffer); //Get next command (rB)
//            printf("buffer register B: %s\n", buffer);
            if (setReg(buffer) < 16){
                rB = setReg(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            registerVal = ((rA << 4) | rB);
            fwrite(&registerVal, 1, 1, outputFile);
            
//            printf("rA: %x\n", rA); //DEBUG CODE
//            printf("rB: %x\n", rB); //DEBUG CODE
            lineNumber++;
        }
        else if (strcmp(buffer, "cmovl") == 0){
            fwrite(&cmovl, 1, 1, outputFile);
            //            printf("rrmovq: %x\n", rrmovq);
//            printf("buffer: %s\n", buffer);
            
            //Set register A
            fscanf(inputFile,"%s", buffer); //Get next command (rA)
            if (setRegComma(buffer) < 16){
                rA = setRegComma(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            //Set register B
            fscanf(inputFile,"%s", buffer); //Get next command (rB)
//            printf("buffer register B: %s\n", buffer);
            if (setReg(buffer) < 16){
                rB = setReg(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            registerVal = ((rA << 4) | rB);
            fwrite(&registerVal, 1, 1, outputFile);
            
//            printf("rA: %x\n", rA); //DEBUG CODE
//            printf("rB: %x\n", rB); //DEBUG CODE
            lineNumber++;
        }
        else if (strcmp(buffer, "cmove") == 0){
            fwrite(&cmove, 1, 1, outputFile);
            //            printf("rrmovq: %x\n", rrmovq);
//            printf("buffer: %s\n", buffer);
            
            //Set register A
            fscanf(inputFile,"%s", buffer); //Get next command (rA)
            if (setRegComma(buffer) < 16){
                rA = setRegComma(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            //Set register B
            fscanf(inputFile,"%s", buffer); //Get next command (rB)
//            printf("buffer register B: %s\n", buffer);
            if (setReg(buffer) < 16){
                rB = setReg(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            registerVal = ((rA << 4) | rB);
            fwrite(&registerVal, 1, 1, outputFile);
            
//            printf("rA: %x\n", rA); //DEBUG CODE
//            printf("rB: %x\n", rB); //DEBUG CODE
            lineNumber++;
        }
        else if (strcmp(buffer, "cmovne") == 0){
            fwrite(&cmovne, 1, 1, outputFile);
            //            printf("rrmovq: %x\n", rrmovq);
//            printf("buffer: %s\n", buffer);
            
            //Set register A
            fscanf(inputFile,"%s", buffer); //Get next command (rA)
            if (setRegComma(buffer) < 16){
                rA = setRegComma(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            //Set register B
            fscanf(inputFile,"%s", buffer); //Get next command (rB)
//            printf("buffer register B: %s\n", buffer);
            if (setReg(buffer) < 16){
                rB = setReg(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            registerVal = ((rA << 4) | rB);
            fwrite(&registerVal, 1, 1, outputFile);
            
//            printf("rA: %x\n", rA); //DEBUG CODE
//            printf("rB: %x\n", rB); //DEBUG CODE
            lineNumber++;
        }
        else if (strcmp(buffer, "cmovge") == 0){
            fwrite(&cmovge, 1, 1, outputFile);
            //            printf("rrmovq: %x\n", rrmovq);
//            printf("buffer: %s\n", buffer);
            
            //Set register A
            fscanf(inputFile,"%s", buffer); //Get next command (rA)
            if (setRegComma(buffer) < 16){
                rA = setRegComma(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            //Set register B
            fscanf(inputFile,"%s", buffer); //Get next command (rB)
//            printf("buffer register B: %s\n", buffer);
            if (setReg(buffer) < 16){
                rB = setReg(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            registerVal = ((rA << 4) | rB);
            fwrite(&registerVal, 1, 1, outputFile);
            
//            printf("rA: %x\n", rA); //DEBUG CODE
//            printf("rB: %x\n", rB); //DEBUG CODE
            lineNumber++;
        }
        else if (strcmp(buffer, "cmovg") == 0){
            fwrite(&cmovg, 1, 1, outputFile);
            //            printf("rrmovq: %x\n", rrmovq);
//            printf("buffer: %s\n", buffer);
            
            //Set register A
            fscanf(inputFile,"%s", buffer); //Get next command (rA)
            if (setRegComma(buffer) < 16){
                rA = setRegComma(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            //Set register B
            fscanf(inputFile,"%s", buffer); //Get next command (rB)
//            printf("buffer register B: %s\n", buffer);
            if (setReg(buffer) < 16){
                rB = setReg(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            registerVal = ((rA << 4) | rB);
            int regValSize = sizeof(registerVal);
            printf("Size: %x\n", regValSize);
            fwrite(&registerVal, 1, 1, outputFile);
            
//            printf("rA: %x\n", rA); //DEBUG CODE
//            printf("rB: %x\n", rB); //DEBUG CODE
            lineNumber++;
        }
        
        //HARDER MOVES
        else if (strcmp(buffer, "irmovq") == 0){
            fwrite(&irmovq, 1, 1, outputFile);
            
            
//            printf("buffer: %s\n", buffer);
//
//            irmovq    $422, %rax
//            irmovq    $0xabcd, %rdx
            
            //Set register A
            fscanf(inputFile,"%s", buffer); //Get next command (V)
//            printf("BUFFER: %s\n", buffer);
            
            int a = 1; //start at the character after $; normally index 0 will be $
            char vVal[20] = {0};
            
            //if value isn't preceeded by $, return false
            if (buffer[0] != '$'){
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            // Get V value
            while (buffer[a] != ','){
                vVal[a-1] = buffer[a];
                a++;
                if (a > 20){ //If there are more than 20 characters to be stored in value D, throw an error
                    printf("Invalid instruction found on line %i.\n", lineNumber);
                    return false;
                }
            }
//            printf("vVal[0]: %c\n", vVal[0]);
//            printf("vVal[1]: %c\n", vVal[1]);
//            printf("vVal[2]: %c\n", vVal[2]);
//            printf("VALUE String: %s\n", vVal);
            
            fscanf(inputFile,"%s", buffer); //Get next command (rB)
            if (setReg(buffer) < 16){
                rB = setReg(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            if (setReg("%r15") < 16){
                rA = setReg("%r15");
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            unsigned long vTemp = strtol(vVal, NULL, 0);
//            printf("VALUE Unsigned: %lu\n", vTemp);
            
            registerVal = ((rA << 4) | rB);
            fwrite(&registerVal, 1, 1, outputFile);
            fwrite(&vTemp, 8, 1, outputFile);
            
            lineNumber++;
        }
        else if (strcmp(buffer, "rmmovq") == 0){
            
            fwrite(&rmmovq, 1, 1, outputFile); //write move to output file
            
            //Set register A
            fscanf(inputFile,"%s", buffer); //Get register command
            
            if (setRegComma(buffer) < 16){
                rA = setRegComma(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            fscanf(inputFile,"%s", buffer); //Get register command (D)
            
            // Get value D
            int a = 0;
            char dVal[20] = {0}; //Initialize dVal to zero or it will retain value from previous loop
            
            // Get D value
            while (buffer[a] != '('){
                dVal[a] = buffer[a];
                a++;
                if (a > 20){ //If there are more than 20 characters to be stored in value D, throw an error
                    printf("Invalid instruction found on line %i.\n", lineNumber);
                    return false;
                }
            }
            
            a++; //move to the next char in buffer to get start of register b
            int b = 0;
            char rBstring[5]; //to store the string value of register b while parsing the parenthesis out of the char array
            // Get regsiter B
            while (buffer[a] != ')'){
                rBstring[b] = buffer[a];
                b++;
                a++;
                if (a > 20 || b > 20){ // if there is no closing parenthesis, print error
                    printf("Invalid instruction found on line %i.\n", lineNumber);
                    return false;
                }
            }
            
            //Set register B
            if (setReg(rBstring) < 16){
                rB = setReg(rBstring);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            unsigned long dTemp = strtol(dVal, NULL, 0);
            registerVal = ((rA << 4) | rB);
            fwrite(&registerVal, 1, 1, outputFile);
            fwrite(&dTemp, 8, 1, outputFile);
            lineNumber++;
        }
        else if (strcmp(buffer, "mrmovq") == 0){
            //            mrmovq  0x15(%rax), %rdi
            //            mrmovq  (%rax), %rdi
            //            mrmovq  15(%rax), %rdi
            
            fwrite(&mrmovq, 1, 1, outputFile);
            
            fscanf(inputFile,"%s", buffer); //Get register/D value command
            
            // Get value D
            int a = 0;
            char dVal[20] = {0}; //
            
            // Get D value
            while (buffer[a] != '('){
                dVal[a] = buffer[a];
                a++;
                if (a > 20){ //If there are more than 20 characters to be stored in value D, throw an error
                    printf("Invalid instruction found on line %i.\n", lineNumber);
                    return false;
                }
            }
            
            //Set register A
            a++; //move to the next char in buffer to get start of register a, so the '(' isn't part of your string
            int b = 0;
            char rAstring[5]; //to store the string value of register b while parsing the parenthesis out of the char array
            while (buffer[a] != ')'){
                rAstring[b] = buffer[a];
                b++;
                a++;
                if (a > 20 || b > 20){ // if there is no closing parenthesis, print error
                    printf("Invalid instruction found on line %i.\n", lineNumber);
                    return false;
                }
            }
            
            if (setReg(rAstring) < 16){
                rB = setReg(rAstring);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            fscanf(inputFile,"%s", buffer); //Get register B
            
            //Set register B
            if (setReg(buffer) < 16){
                rA = setReg(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
//            printf("dVal: %s\n", dVal);
            unsigned long dTemp = strtol(dVal, NULL, 0);
            registerVal = ((rA << 4) | rB);
            fwrite(&registerVal, 1, 1, outputFile);
            fwrite(&dTemp, 8, 1, outputFile);
            
            lineNumber++;
        }
        else if (strcmp(buffer, "addq") == 0){
            fwrite(&addq, 1, 1, outputFile);
            //            printf("rrmovq: %x\n", rrmovq);
//            printf("buffer: %s\n", buffer);
            
            //Set register A
            fscanf(inputFile,"%s", buffer); //Get next command (rA)
            if (setRegComma(buffer) < 16){
                rA = setRegComma(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            //Set register B
            fscanf(inputFile,"%s", buffer); //Get next command (rB)
//            printf("buffer register B: %s\n", buffer);
            if (setReg(buffer) < 16){
                rB = setReg(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            registerVal = ((rA << 4) | rB);
            int regValSize = sizeof(registerVal);
//            printf("Size: %x\n", regValSize);
            fwrite(&registerVal, 1, 1, outputFile);
            
//            printf("rA: %x\n", rA); //DEBUG CODE
//            printf("rB: %x\n", rB); //DEBUG CODE
            lineNumber++;
        }
        else if (strcmp(buffer, "subq") == 0){
            fwrite(&subq, 1, 1, outputFile);
            //            printf("rrmovq: %x\n", rrmovq);
//            printf("buffer: %s\n", buffer);
            
            //Set register A
            fscanf(inputFile,"%s", buffer); //Get next command (rA)
            if (setRegComma(buffer) < 16){
                rA = setRegComma(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            //Set register B
            fscanf(inputFile,"%s", buffer); //Get next command (rB)
//            printf("buffer register B: %s\n", buffer);
            if (setReg(buffer) < 16){
                rB = setReg(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            registerVal = ((rA << 4) | rB);
            int regValSize = sizeof(registerVal);
//            printf("Size: %x\n", regValSize);
            fwrite(&registerVal, 1, 1, outputFile);
//
//            printf("rA: %x\n", rA); //DEBUG CODE
//            printf("rB: %x\n", rB); //DEBUG CODE
            lineNumber++;
        }
        else if (strcmp(buffer, "andq") == 0){
            fwrite(&andq, 1, 1, outputFile);
            //            printf("rrmovq: %x\n", rrmovq);
//            printf("buffer: %s\n", buffer);
            
            //Set register A
            fscanf(inputFile,"%s", buffer); //Get next command (rA)
            if (setRegComma(buffer) < 16){
                rA = setRegComma(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            //Set register B
            fscanf(inputFile,"%s", buffer); //Get next command (rB)
//            printf("buffer register B: %s\n", buffer);
            if (setReg(buffer) < 16){
                rB = setReg(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            registerVal = ((rA << 4) | rB);
            int regValSize = sizeof(registerVal);
//            printf("Size: %x\n", regValSize);
            fwrite(&registerVal, 1, 1, outputFile);
            
//            printf("rA: %x\n", rA); //DEBUG CODE
//            printf("rB: %x\n", rB); //DEBUG CODE
            lineNumber++;
        }
        else if (strcmp(buffer, "xorq") == 0){
            fwrite(&xorq, 1, 1, outputFile);
            //            printf("rrmovq: %x\n", rrmovq);
//            printf("buffer: %s\n", buffer);
            
            //Set register A
            fscanf(inputFile,"%s", buffer); //Get next command (rA)
            if (setRegComma(buffer) < 16){
                rA = setRegComma(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            //Set register B
            fscanf(inputFile,"%s", buffer); //Get next command (rB)
//            printf("buffer register B: %s\n", buffer);
            if (setReg(buffer) < 16){
                rB = setReg(buffer);
            }
            else{
                printf("Invalid instruction found on line %i.\n", lineNumber);
                return false;
            }
            
            registerVal = ((rA << 4) | rB);
            int regValSize = sizeof(registerVal);
//            printf("Size: %x\n", regValSize);
            fwrite(&registerVal, 1, 1, outputFile);
            
//            printf("rA: %x\n", rA); //DEBUG CODE
//            printf("rB: %x\n", rB); //DEBUG CODE
            lineNumber++;
        }
        else{
            printf("Invalid instruction found on line %i.\n", lineNumber);
            return false;
        }
    }
    return 0;
}

unsigned setRegComma (char bufferIn[10]) {
    unsigned regA;
    
//    printf("bufferIn A: %s\n", bufferIn); //DEBUG CODE
    
    //Register variables
    unsigned rax = 0b0000;
    unsigned rcx = 0b0001;
    unsigned rdx = 0b0010;
    unsigned rbx = 0b0011;
    unsigned rsp = 0b0100;
    unsigned rbp = 0b0101;
    unsigned rsi = 0b0110;
    unsigned rdi = 0b0111;
    unsigned r8 = 0b1000;
    unsigned r9 = 0b1001;
    unsigned r10 = 0b1010;
    unsigned r11 = 0b1011;
    unsigned r12 = 0b1100;
    unsigned r13 = 0b1101;
    unsigned r14 = 0b1110;
    unsigned r15 = 0b1111;
    
    //set register rA
    regA = (strcmp(bufferIn, "%rax,") == 0)? rax :
    (strcmp(bufferIn, "%rcx,") == 0)? rcx :
    (strcmp(bufferIn, "%rdx,") == 0)? rdx :
    (strcmp(bufferIn, "%rbx,") == 0)? rbx :
    (strcmp(bufferIn, "%rsp,") == 0)? rsp :
    (strcmp(bufferIn, "%rbp,") == 0)? rbp :
    (strcmp(bufferIn, "%rsi,") == 0)? rsi :
    (strcmp(bufferIn, "%rdi,") == 0)? rdi :
    (strcmp(bufferIn, "%r8,") == 0)? r8 :
    (strcmp(bufferIn, "%r9,") == 0)? r9 :
    (strcmp(bufferIn, "%r10,") == 0)? r10 :
    (strcmp(bufferIn, "%r11,") == 0)? r11 :
    (strcmp(bufferIn, "%r12,") == 0)? r12 :
    (strcmp(bufferIn, "%r13,") == 0)? r13 :
    (strcmp(bufferIn, "%r14,") == 0)? r14 : r15; //default to r15
    if (regA == r15 && (strcmp(bufferIn, "%r15,") != 0)){
        return 16; //invalid register string
    }
//    printf("register A from func: %u\n", regA);
    return regA;
}

unsigned setReg (char bufferIn[10]) {
    unsigned regB;
    
//    printf("bufferIn B: %s\n", bufferIn); //DEBUG CODE
    
    //Register variables
    unsigned rax = 0b0000;
    unsigned rcx = 0b0001;
    unsigned rdx = 0b0010;
    unsigned rbx = 0b0011;
    unsigned rsp = 0b0100;
    unsigned rbp = 0b0101;
    unsigned rsi = 0b0110;
    unsigned rdi = 0b0111;
    unsigned r8 = 0b1000;
    unsigned r9 = 0b1001;
    unsigned r10 = 0b1010;
    unsigned r11 = 0b1011;
    unsigned r12 = 0b1100;
    unsigned r13 = 0b1101;
    unsigned r14 = 0b1110;
    unsigned r15 = 0b1111;
    
    //set register rA
    //printf("A\n");
    regB = (strcmp(bufferIn, "%rax") == 0)? rax :
    (strcmp(bufferIn, "%rcx") == 0)? rcx :
    (strcmp(bufferIn, "%rdx") == 0)? rdx :
    (strcmp(bufferIn, "%rbx") == 0)? rbx :
    (strcmp(bufferIn, "%rsp") == 0)? rsp :
    (strcmp(bufferIn, "%rbp") == 0)? rbp :
    (strcmp(bufferIn, "%rsi") == 0)? rsi :
    (strcmp(bufferIn, "%rdi") == 0)? rdi :
    (strcmp(bufferIn, "%r8") == 0)? r8 :
    (strcmp(bufferIn, "%r9") == 0)? r9 :
    (strcmp(bufferIn, "%r10") == 0)? r10 :
    (strcmp(bufferIn, "%r11") == 0)? r11 :
    (strcmp(bufferIn, "%r12") == 0)? r12 :
    (strcmp(bufferIn, "%r13") == 0)? r13 :
    (strcmp(bufferIn, "%r14") == 0)? r14 : r15; //default to r15
    //printf("B\n");
    if (regB == r15 && (strcmp(bufferIn, "%r15") != 0)){
        //printf("C\n");
        return 16; //invalid register string
    }
//    printf("register B from func: %u\n", regB);
    return regB;
}
