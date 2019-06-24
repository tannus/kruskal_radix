#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
       
    FILE *input1, *input3, *input4, *input5 , *input6 , *input7, *input8, *input9, *inputA;
    FILE *output;
    input1 = fopen(argv[1],"r+");
    input3 = fopen(argv[2],"r+");
    input4 = fopen(argv[3],"r+");
    input5 = fopen(argv[4],"r+");
    input6 = fopen(argv[5],"r+");
    input7 = fopen(argv[6],"r+");
    input8 = fopen(argv[7],"r+");
    input9 = fopen(argv[8],"r+");
    inputA = fopen(argv[9],"r+");
    output = fopen(argv[10],"w+");

    double i1,i3,i4,i5,i6,i7,i8,i9,iA;
    double d1,d3,d4,d5,d6,d7,d8,d9,dA;

    double seconds = 0.0,sum_min = 0.0,aux = 0.0;
    double sum_scd = 0.0;

    while (fscanf(input1,"%lfm%lfs", &i1,&d1)){
        fscanf(input3,"%lfm%lfs", &i3,&d3);
        fscanf(input4,"%lfm%lfs", &i4,&d4);
        fscanf(input5,"%lfm%lfs", &i5,&d5);
        fscanf(input6,"%lfm%lfs", &i6,&d6);
        fscanf(input7,"%lfm%lfs", &i7,&d7);
        fscanf(input8,"%lfm%lfs", &i8,&d8);
        fscanf(input9,"%lfm%lfs", &i9,&d9);
        fscanf(inputA,"%lfm%lfs", &iA,&dA);
        
        if(feof(input1)) break;
        sum_min = (i1 + i3 + i4 + i5 + i6 + i7 + i8 + i9 + iA)*60.0;
        sum_scd = d1 + d3 + d4 + d5 + d6 + d7 + d8 + d9 + dA;
        aux = sum_scd;
        seconds = sum_min + aux;
        seconds /= 2.0;
            
        fprintf(output,"%.3lf\n",seconds);
    }
    
    return 0;

}
