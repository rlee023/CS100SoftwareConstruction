#include <unistd.h>
#include <vector>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

using namespace std; 

int main(int argc, char * argv [])
{ 

  unlink(argv[1]); 
  return 0; 
}
