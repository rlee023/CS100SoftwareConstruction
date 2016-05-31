#include <iostream>
#include <stdio.h>

using namespace std; 

void strCat(char* dest, char* source)
{
            int i, j;
           for(i = 0; dest[i] != '\0'; i++)
         {}
          for(j = 0; source[j] != '\0'; j++)
          {
                  dest[i + j] = source[j];
          }
          dest[i + j] = '\0';
}

int strlen(char * c)
{
        int size = 0; 
        for(unsigned i = 0; c[i] != '\0'; ++i)
                size++; 
        return size; 
}

void Strcpy(char * destination, char * source)
{
        int size = 0; 
        for(unsigned i = 0; destination[i] != '\0'; ++i)
                size++; 
        destination = new char[size];
        for(unsigned i = 0; i < size; ++i)
                destination[i] = source[i];
        
}

int Strcmp(char * c1, char * c2)
{
        int size1 = strlen(c1); 
        int size2 = strlen(c2); 

        if(size1 == size2)
        {
                for(int i = 0; i < size1; ++i)
                {
                        if(c1[i] > c2[i])
                                return 1; 
                        else if(c1[i] < c2[i])
                                return -1; 
                }
                return 0; 
        }
        else if(size1 > size2)
        {
                for(int i = 0; i < size1; ++i)
                {
                        if(c1[i] > c2[i])
                                return 1; 
                        else if(c1[i] < c2[i])
                                return -1; 
                }
                return 1; 

        }
        else 
        {
                for(int i = 0; i < size2; ++i)
                {
                        if(c1[i] > c2[i])
                                return 1; 
                        else if(c1[i] < c2[i])
                                return -1; 
                }
                return -1;
        }
}

char * Strstr(char * str1, char * str2)
{
        int size1 = strlen(str1);
        int size2 = strlen(str2); 
        int s = size1;
        /*
        int size1 = strlen(str1);
        int size2 = strlen(str2); 
        if(size1 < size2)
                s = size1; 
        else if(size1 == size2)
                s = size1; 
        else
                s = size2;

*/
        for(unsigned i = 0; i < s; ++i)
        {
                if(str1[i] == str2[0])
                {
                        if(size2 >= size1-i)
                        {
                          int k = i; 
                          for(unsigned j = 0; j < size2; j++)
                          {
                                if(str2[j] != str1[k])
                                       goto stop;   
                                k++;         
                          }
                          char * ret; 
                          ret = new char; 

                          int n = 0; 
                          for(unsigned l = i; l < size1; ++l)
                          {
                                ret[n] = str1[l];
                                n++; 
                          }
                          str1 = ret;  
                          return ret; 
                        }
                }
                stop:
                int k;
        }
        return NULL; 
}

char * Strchr(char * str, char x)
{
        for(unsigned i = 0; i < strlen(str); i++)
        {
                if(str[i] == x){
                        char * c = new char;
                        int k = i; 
                        
                        for(unsigned j = 0; str[k] != '\0'; j++)
                        {
                                c[j] = str[k];       
                                k++; 
                        } 
                        return c; 
               }
        }
        return NULL;
}





