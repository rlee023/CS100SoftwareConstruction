#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

using namespace std; 

int main(int argc, char ** argv )
{ 
  int status;
//  strcat(argv[2], "/");
//  strcat(argv[2], argv[1]); 
  
  status = link( argv[1], argv[2]);   
  cerr << status;
  unlink(argv[1]); 
  return 0; 
}
