/*
 * Course: CS 100 Summer Session 2 2013
 *
 * First Name: Ryan 
 * Last Name: Lee
 * Username: rlee023
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: assn 2
 * Filename : assn2.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <sys/wait.h>
#include <signal.h>

using namespace std;

void parse (char *cmd, char *args[])
{
    char *cmdPtr = cmd;
    while ( *cmdPtr == ' ')
    {
        cmdPtr ++;
    }
    while ( *cmdPtr != '\0')
    {
        *args = cmdPtr;
       if(**args == '~')
        {
            string path = getenv("HOME");
            char * PATH = new char; 
            for(unsigned i = 0; i < path.size(); ++i)
                PATH[i] = path[i];  
            *args = PATH; 
            cout << PATH << endl; 
        }
        args++; 
        while ( *cmdPtr!=' ' && *cmdPtr!='\t' && *cmdPtr!='\n' && *cmdPtr!='\0')
        {
            cmdPtr++; 
        }
        while ( *cmdPtr==' ' || *cmdPtr=='\t' || *cmdPtr=='\n')
        {
            *cmdPtr='\0';
            cmdPtr++;
        }
    }
    *args='\0';
}

void ctrl_q(int sig_num)
{
    pid_t pid; 
    cout << "quit\n"; 
    pid = getppid(); 
    kill(pid, SIGQUIT);
}
void ctrl_c(int sig_num)
{
    pid_t pid; 
    pid = getppid(); 
    kill(pid, SIGINT);
}
void handle_sig(pid_t pid)
{
    signal(SIGINT, ctrl_c);
    signal(SIGQUIT, ctrl_q);
}

void execute(char *args[])
{
   
    pid_t pid;

    pid = fork();

    int status;
	
    if(pid == -1)
        cerr << "fork failed!..\n";  
    else if(pid == 0)
    {
        if(execvp(*args,args) != 0)
        {
            cout << "failed to execute command " << args[0] << endl;
            exit(1);
        }
    }
    else
        wait(&status);
}

int main()
{
    pid_t pid; 

    handle_sig(pid); 
    size_t cmd_length = 512;
    int args_length = 512;
    char * cmd;
    char *args[args_length];
    string line; 
    while (1)
    {
        cout << "? ";
        getline(cin, line); 
        cmd = new char; 
        for(unsigned i = 0; i < line.size(); ++i)
            cmd[i] = line[i]; 
        
        parse(cmd, args);

        if(strcmp(args[0],"exit")==0)
            exit(0);
        else if(strcmp(args[0],"cd")==0)
	{
            if(args[1] == NULL || args[1] == "~")
                chdir(getenv("HOME"));
            else if( (chdir(args[1])) == -1)
                cout << "-bash: cd: " << args[1] << ": No such file or directory\n";
        }        
	else
            execute(args);
    }
}
