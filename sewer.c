// github.com/perras sewer.c - unoriginal and lazy static hostfile [null] routing.
// cc sewer.c -o /usr/bin/sewer 
#include <stdio.h>
#define STINKY "127.0.0.1"
#define MANHOLE "/etc/hosts"

int sewer(char domain[], char addr[])
{
FILE *hole;
hole=fopen(MANHOLE,"a+t");

if(hole==NULL)
 {
 printf("Can not access resource at %s \n", MANHOLE);
 return 0;
 }
fprintf(hole,"%s        %s\n",addr,domain);
fclose(hole);
}//sewer


int main (int argc, char *argv[])
{
if (argc <2)
 {
 printf("Usage: %s <domain> [route]\n \tEx: %s google.com 107.21.1.61\n\tIf [route] is not provided it will default to localhost.\n", argv[0],argv[0]);
 return 0;
 }

if (argv[2]==NULL)
 {
 sewer(argv[1],STINKY);
 return 0;
 }
sewer(argv[1],argv[2]);
return 0;
}//main


