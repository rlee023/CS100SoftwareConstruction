/*
* Course: CS 100 Summer Session 2 2013
*
* First Name: Ryan
* Last Name: Lee
* Username: rlee023
* email address: this must be your cs or UCR student email address
*
*
* Assignment: assn 1
* Filename : assn1.cc
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
/**
Used pubs.opengroup.org/onlinepubs/009696699/functions/stat.html to figure out
how to get the group name--#include, syntax.

Used getpwid link given in assignment references to figure out how to get the user id.
From there, I also got the idea that there must be a gid similar to getpwuid.
Indeed, after some research, I found an example
*/
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

int visit(string path)
{
  DIR * dirp;
  struct stat inode;

  if( (dirp = opendir(path.c_str())) < 0) {
    cerr << "error \n";
      return -1;
  }

  //time_t T;
  struct passwd *pwd;
  struct group *grp;
  struct tm *Time;
  dirent * direntp;
  vector <string> store_directory_path;
  int blocks = 0;

  string out_path = path;
  out_path += ":";
  cout << out_path;

  lstat(path.c_str(), &inode);
  //int bsize = inode.st_blksize;
  //cout << endl << "total " << (long) inode.st_blksize << endl;
  //cout << endl << "total " << (int) inode.st_blksize << endl;
  vector<int> setw_size;
  vector<int> setw_size_nlink;
  vector<string>files;

  while((direntp = readdir(dirp)) != NULL)
  {
      string dp = direntp->d_name;
      if(dp[0]!='.')
         files.push_back(dp);
  }
  
  for(unsigned i = 0; i < files.size(); i++)
  {
    string s = path;
    s+= "/";
    s+= files[i];
    lstat(s.c_str(), & inode);
    blocks+= (inode.st_blocks);
  }

  blocks = blocks / 2;
  cout << endl << "total " << blocks << endl;

  for(unsigned i = 0; i < files.size(); i++)
  {
    string s = path;
    s+= "/";
    s+= files[i];
    lstat(s.c_str(), & inode);
    int s1 = inode.st_nlink;
    stringstream ss;
    ss << s1;
    string size = ss.str();
    setw_size_nlink.push_back(size.length());
  }
  for(unsigned i = 0; i < files.size(); i++)
  {
    string s = path;
    s+= "/";
    s+= files[i];
    lstat(s.c_str(), & inode);
    int s1 = inode.st_size;
    stringstream ss;
    ss << s1;
    string size = ss.str();
    setw_size.push_back(size.length());
  }

int set_size_nlink=0;

for(unsigned i = 0; i < setw_size_nlink.size(); ++i)
{
  if(setw_size_nlink[i] > set_size_nlink)
    set_size_nlink = setw_size_nlink[i];
}

int set_size = 0;
for(unsigned i = 0; i < setw_size.size(); ++i)
{
  if(setw_size[i] > set_size)
    set_size = setw_size[i];
}

  //sort(files.begin(), files.end());
  for(int i = 0; i < files.size(); i++)
  {
    for(int j = 0; j < i; j++)
    {
      if(tolower(files[i][0]) < tolower(files[j][0]) )
        swap(files[i], files[j]);
      else if(toupper(files[i][0]) == toupper(files[j][0]))
      {
        if(files[i][0] > files[j][0])
swap(files[i], files[j]);
      }
    }
  }
  for(int i = 0; i< files.size(); i++)
  {
      string s = path;
      string out = ".";
      s += "/";
      s += files[i];

      lstat(s.c_str(), &inode);
              if(inode.st_mode & S_IFDIR)
                cout << "d";
else
                cout << "-";
              
if(inode.st_mode & S_IRUSR)
                cout << "r";
              else
                cout << "-";
              if(inode.st_mode & S_IWUSR)
                cout << "w";
              else
                cout << "-";
              if(inode.st_mode & S_IXUSR)
                cout << "x";
              else
                cout << "-";
              if(inode.st_mode & S_IRGRP)
                cout << "r";
              else
                cout << "-";
              if(inode.st_mode & S_IWGRP)
                cout << "w";
              else
                cout << "-";
              if(inode.st_mode & S_IXGRP)
                cout << "x";
              else
                cout << "-";
              if(inode.st_mode & S_IROTH)
                cout << "r";
              else
                cout << "-";
              if(inode.st_mode & S_IWOTH)
                cout << "w";
              else
                cout << "-";
              if(inode.st_mode & S_IXOTH)
                cout << "x";
              else
                cout << "-";

              if(( inode.st_mode & S_IFDIR ))
              {
                store_directory_path.push_back(s);
              }
              cout << " ";
              
              cout << setw(set_size_nlink+0) << inode.st_nlink << " ";

              if((pwd = getpwuid(inode.st_uid)) != NULL)
                cout << pwd->pw_name;

              if((grp = getgrgid(inode.st_gid)) != NULL)
                cout << " " << grp->gr_name;
              
              cout << setw(set_size+1) << inode.st_size << " ";
              
              string Time = ctime(&inode.st_mtime);
// cout << Time;

              for(unsigned i = 4; i < 7; ++i)
                cout << Time[i];
              cout << " ";
              
              string year = Time.substr(20, 22);
              
              for( int i = 4; i < year.size(); i++)
                year[i]='\0';
              
/*
cout << Time[8] << Time[9] << Time[10] << " ";
for(unsigned i = 11; i < 16; i++)
cout << Time[i];
cout << " ";
*/
              time_t rawtime;
              time(&rawtime);
              string curtime = ctime(&rawtime);
                
              stringstream ss;
              ss << curtime;
              string currentYear;
              ss >> currentYear;
              ss >> currentYear;
              ss >> currentYear;
              ss >> currentYear;
              ss >> currentYear;
             

              for(int i = 4; i< currentYear.size(); i++)
                currentYear[i]='\0';
                   

              for(int i = 0; i<4; i++)
              {
                  if(currentYear[i]==year[i])
                  {
                        if(i==3)
                        {

                              cout << Time[8] << Time[9] << Time[10] ;
                              for(unsigned i = 11; i < 16; i++)
                                cout << Time[i];
                              cout << " ";

                        }
                  
                  }
                  else
                  {
                        cout << Time [8] << Time[9] << Time[10] << " " << year << " ";
                        i = 4;
                  }
              }
        

              if(S_IFDIR & inode.st_mode && !(S_IFLNK & inode.st_mode) ){
                string temp = files[i];
                temp+="/";
                cout << temp << " ";
              }
              else if(inode.st_mode & S_IXUSR)
              {
                string temp = files[i];
                temp+="*";
                cout << temp << " ";
              }
              else
                cout << files[i] << " ";
              cout << endl;
           }
cout << endl;

  for(unsigned i = 0; i < store_directory_path.size(); ++i)
    visit(store_directory_path[i]);
  closedir(dirp);

}

int main(int argc, char *argv[])
{
  
   if(argc == 1)
   {
     visit(".");
   }
   else
   {
     visit(argv[1]);
   }
}
