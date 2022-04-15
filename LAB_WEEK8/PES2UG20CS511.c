#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1
int main()
{
char read_msg[BUFFER_SIZE] = "";
int fd[2];
pid_t pid;
if(pipe(fd)==-1) {
printf("Pipe Failed\n");
return 0;
}
pid = fork();
if(pid) {
FILE *fptr;
fptr = fopen("input.txt","r");
char buff[20],ch;
int i = 0;
while((ch = fgetc(fptr)) != EOF)
buff[i++] = ch;
buff[i] = 0;
close(fd[READ_END]);
write(fd[WRITE_END],buff,strlen(buff)+1);
close(fd[WRITE_END]);
wait(NULL);
fclose(fptr);
}
else if(pid == 0) {
int count = 0;
close(fd[WRITE_END]);
read(fd[READ_END],read_msg,BUFFER_SIZE);
printf("File Read by Child: %s\n",read_msg);
char *token = strtok(read_msg, " ");
while(token) {
//printf("%s\t",token);
if(!(strcmp(token,"the"))) {
count++;
}
token = strtok(NULL," ");
}
printf("No. of Occurences of 'the' as read by Child Process:
%d\n",count);
close(fd[READ_END]);
}
else {
printf("Fork Failed\n");
return 0;
}
}