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

/*** This puts a space in between commands, because command without a space in between is an error */
void perfectInput(string & cmd)
{
     for(int i = 0;  i != cmd.size(); i++)
     {
        if(cmd[i]=='|' || cmd[i]=='>' || cmd[i]=='<' || cmd[i]=='&' || (cmd[i]=='2' && cmd[i+1] =='>')   ) 
        {
            if(cmd[i-1]!=' ')
                cmd.insert(i," ");
            else if (cmd[-1]==' ')
                return;
            return;
        }       
    }
}

void parse (char *cmd, char *args[], int *mode, char **part2, int& bg_ct)
{
/* I wanted to prevent magic numbers, so I made variables for these cases instead of just comparing it, e.g. == 1. */
    const int NORMAL     = 0;
    const int BACKGROUND = 1;
    const int PIPE       = 2;
    const int WRITE      = 3;
    const int APPEND     = 4;
    const int READ       = 5;
    const int ERROR      = 6;

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

        /* If **args is &, |, >, <, or 2, I want to set my mode appropriately. This is important
	because my execute function needs to be able to determine this. */	
        if(**args=='&' || **args=='|' || **args=='>' || **args=='<' || **args=='2')
        {
            if (**args == '&')                
            {
                *mode = BACKGROUND;
                bg_ct++;
            }
            else if (**args == '|')
            {
                *mode = PIPE;
            }
            else if (**args == '>')
            {                 
                *mode = WRITE;
                
                string temp = *args;
                
                if(temp[1] == '>')
                { 
                     *mode = APPEND; 
                     cmdPtr++;                     
                }
            }
            else if(**args == '2')
             {
                 string temp =*args;
                 if(temp[1] == '>')
                 {                     
                     *mode = ERROR;
                     cmdPtr++;                          
                 }
             }
            else if (**args == '<')
            {
                *mode = READ;
            }
            if(**args != '&')
            { 
                cmdPtr++;
                if(*cmdPtr == ' ')
                    cmdPtr++;

                *part2 = cmdPtr;
            }
            *args='\0';
            return;
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

void child(int sig_num)
{
    pid_t  pid;
    pid = getppid();
    waitpid(pid,0,WNOHANG);
    
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

/* arguments will hold the commands after it is parsed. mode is set in parse and is used to determine 
what actions need to be taken. part2 is used if there's >, |, >>, or 2>. If there is, I want to split what's
after that into another char**. bg_ct counts the background number. e.g. geany & also outputs [1] PID if it is the 
first background process running. */

void execute(char *argument[], int mode, char** part2, int & bg_ct )
{
/* Again, I wanted to prevent magic numbers. */

    const int NORMAL     = 0;
    const int BACKGROUND = 1;
    const int PIPE       = 2;
    const int WRITE      = 3;
    const int APPEND     = 4;
    const int READ       = 5;
    const int ERROR      = 6;

    pid_t pid;
    pid_t background_id;
    int status;

    int mode2=0;
    char* args2[512];
    char* part2_2;
    
    int pipes[2];
    pipe(pipes);    
    pid = fork();	

/* Checks mode to run a background process, >, <, etc */
    if(pid == -1)
        cerr << "fork failed!..\n";  
    else if(pid == 0)
    {
        if(mode == BACKGROUND)
        {
            setpgid(0,0);            
        }
        else if(mode == PIPE)
        {
            dup2(pipes[1],1);
            close(pipes[0]);
            close(pipes[1]);
        }
        else if(mode == WRITE)
        {
            parse(*part2, args2, &mode2, &part2_2,bg_ct);       
            
            freopen(args2[0], "w", stdout);
        }

        else if(mode == ERROR)
        {          
            parse(*part2, args2, &mode2, &part2_2,bg_ct);       
            
            freopen(args2[0], "w", stderr);
        }
        else if(mode == APPEND)
        {
            parse(*part2, args2, &mode2, &part2_2,bg_ct);       
            
            freopen(args2[0], "a", stdout);
        }
        
        else if(mode == READ)
        {
            parse(*part2, args2, &mode2, &part2_2, bg_ct);   
    
            freopen(args2[0], "r", stdin);
            
            /*
	       Is needed for >. For example, if I run ls > outfile, I want to write. However, if I run
               ls >> outfile again, I want to append the contents of ls to outfile.  
            */ 
            if(mode2== WRITE)
            {                 
                freopen(part2_2, "w", stdout);
            }
            else if(mode2==APPEND)
            {
                freopen(part2_2, "a", stdout);
            }
            else if(mode2==ERROR)
            {
                freopen(part2_2, "w", stderr);
            }
        }
        if(execvp(*argument,argument) != 0)
        {
            cerr << "failed to execute command " << argument[0] << endl;
            exit(1);
        }
    }
    else
    {
        if((mode != PIPE && mode != BACKGROUND) )
            wait(&status);
        else if(mode == PIPE)
        {
            parse(*part2, args2, &mode2,&part2_2,bg_ct);

            pid = fork();

            if(pid == -1)
                cerr << "fork failed!..\n";
            else if (pid == 0)
            {
                /*Second command reads from first command ex. 
                   ls | grep rlee023
                   ls is the first command and grep is the second command. 
                */
                dup2(pipes[0],0);
                close(pipes[0]);
                close(pipes[1]);

                if(execvp(*args2, args2) != 0) /* Executing second command */
                {
                    cerr << "failed to execute command " << argument[0] << endl;
                    exit(1);
                }
            }
        }
        else if(mode == BACKGROUND)
        {
            background_id = getpgid( pid); 
            cout << "[" << bg_ct <<"] " << background_id << endl;
            
            pid_t result = waitpid(0, &status, WNOHANG);
            
            if(result != 0)
            {
                cout << "[" << bg_ct <<"]   " << "Done\t\t\t" << *argument << endl;
                kill(background_id,SIGTERM);      
            }
        }
        if(mode == PIPE)
        {
            /* Close pipes and wait for execution*/
            close(pipes[0]);
            close(pipes[1]);
            wait(&status);
            wait(&status);
        }
    }
}

int main(int argc, char* argv[])
{
    pid_t pid; 
    int status;
    handle_sig(pid); 
   
    int args_length = 512;
    
    char *arguments[args_length];
    
    char *part2 = NULL;
    string line = "\0"; 

    int mode = 0;
    
    int bg_ct = 0;

    while (1)
    {
        line = "\0";
        
        int mode = 0;
        part2 = NULL;

        cout << "? ";
        getline(cin, line); 
        if(line.size() == 0)
            continue;
        perfectInput(line);        

        parse(&line[0], arguments, &mode, &part2, bg_ct);

        if(strcmp(arguments[0],"exit")==0)
            exit(0);
        else if(strcmp(arguments[0],"cd")==0)
        {
            int error = 0; 
            if(arguments[1] == NULL || arguments[1] == "~"){
                chdir(getenv("HOME"));
                cout << "~" << endl; 
            }    
            else if( (chdir(arguments[1]) == -1) )
            {
                cerr << "-bash: cd: " << arguments[1] << ": No such file or directory\n";
            }     
        }        
        else
            execute(arguments, mode, &part2,bg_ct);
    }
}
