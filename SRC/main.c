#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int roll;
    float cgpa;
} Student;

int risk(float cgpa){
    if(cgpa < 4) return 2;
    if(cgpa < 6) return 1;
    return 0;
}

int main(){
    FILE *f = fopen("DATA/classA.csv", "r");
    if(!f){
        printf("DATA file not found\n");
        return 1;
    }

    Student s[500];
    int count = 0;

    char line[200];
    fgets(line,200,f); // skip header

    while(fgets(line,200,f)){
        sscanf(line,"%d,%f",&s[count].roll,&s[count].cgpa);
        count++;
    }
    fclose(f);

    int topper = 0, defaulter = 0;
    float sum = 0;

    for(int i=0;i<count;i++){
        sum += s[i].cgpa;
        if(s[i].cgpa > s[topper].cgpa) topper = i;
        if(s[i].cgpa < s[defaulter].cgpa) defaulter = i;
    }

    float avg = sum/count;

    FILE *out = fopen("OUTPUT/report.json","w");
    fprintf(out,"{\n");
    fprintf(out,"\"classAverage\": %.2f,\n",avg);
    fprintf(out,"\"topper\": {\"roll\": %d, \"cgpa\": %.2f},\n",s[topper].roll,s[topper].cgpa);
    fprintf(out,"\"defaulter\": {\"roll\": %d, \"cgpa\": %.2f},\n",s[defaulter].roll,s[defaulter].cgpa);
    fprintf(out,"\"students\": [\n");

    for(int i=0;i<count;i++){
        char *r = risk(s[i].cgpa)==2?"HIGH":risk(s[i].cgpa)==1?"MEDIUM":"SAFE";
        fprintf(out,"{\"roll\":%d,\"cgpa\":%.2f,\"risk\":\"%s\"}%s\n",
                s[i].roll,s[i].cgpa,r,(i<count-1?",":""));
    }
    fprintf(out,"]\n}");
    fclose(out);

    printf("Report generated successfully\n");
    return 0;
}