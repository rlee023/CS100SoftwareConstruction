#
# Course: CS 100 Summer Session 2 2013
#
# First Name: Ryan
# Last Name: Lee
# Username: rlee023
# email address: rlee023@ucr.edu
#
# Assignment: assn5
# Filename: my_find.sh
#
# I hereby certify that the contents of this file represent
# my own original individual work. Nowhere heren is there 
# code from any outside resources such as another individual, 
# a website, or publishings unless specifically designated as 
# permissible by the instructor or TA. 
#

# !/bin/bash
subdirectories=
directory=()
i=0
all_files=
output=
execute=

#Find the target in all the directories saved in the directory array and the target is the file. 
function f_name()
{
    files=
    i=0
    j=0
    for i in ${directory[*]}; do
        files=$(ls $i )
        for j in ${files[*]}; do
            if [ "$j" = "$target" ]; then
                output+="$i/$target "
            fi
            shift
        done
        shift
    done  
}
#I do ls -al to all the directory in directory array and save only the file name into the array called all_files. 
function find_all_files
{
    i=0
    for i in ${directory[*]}; do 
        files="$(ls -al $i | grep -v ^d | awk '{ print $9 }' | sed '/^$/d')"
        j=0
        dir="$i/"
        for j in ${files[*]}; do
            all_files+="$dir$j "
        done
    done
}

#The Array output stores either all the directories or all the files according to the type user put into the command.  
function f_type
{
    i=0  
    if [ "$type" = "d" ]; then
        for i in ${directory[*]}; do
            output+="$i "
        done
    elif [ "$type" = "f" ]; then
        find_all_files
        j=0
        for j in ${all_files[*]}; do
            output+="$j "
        done
    fi     
}

#Just prints the output of my_find. 
function print_output
{
    i=0
    for i in ${output[*]}; do
        echo $i
    done
}

#Save all the subdirectories into the array called directories. 
function fill_sub_dir
{
    directory+="$( ls -lR $tempdir | awk '{ print $1 }' | grep : | sed "s/:$//") "
}

#Basically finds all the files newer than the target and saves the result into the array called output
function newer_file
{
    find_all_files
    i=0
    for i in ${directory[*]}; do
        if [[ $i -nt $target ]]; then
            output+="$i "
        fi
    done
    i=0
    for i in ${all_files[*]}; do
        if [[ $i -nt $target ]]; then
            output+="$i "
        fi
    done
}

while [ "$1" != "" ]; do 
    case $1 in
    #Set the target to the file we want to find and call fname function, find name function.  
        -name ) target=$2
                f_name target
		#If there is no exec after this I would just output my output buffer that has all the output to the find name. 
                if [ "$3" != "-exec" ] ; then
                    print_output
                fi
                shift
                ;;
		#Set the type to the letter either -d or -f and call the find type function. It will find all the directories 
		# if it is -d and all the files if it is -f 
        -type ) type=$2
                f_type type
		#If there is no exec after this I would just output my output buffer that has all the output to the find name. 
                if [ "$3" != "-exec" ] ; then
                    print_output
                fi
                shift
                ;;
		#set the target to the file we want to compare to and save all th files that is newer than the target. 
        -newer ) target=$2
                 newer_file target
	         #If there is no exec after this I would just output my output buffer that has all the output to the find name. 
                 if [ "$3" != "-exec" ] ; then
                    print_output
                 fi
                 shift
                 ;;
		 #A string called execute saves all the commands after the exec and right before the '{}'. Execute the command with output
		 # as parameter. 
        -exec )  while [ "$2" != "" ]; do
                 case $2 in
                     {} ) shift
                          shift
                          k=0
                          for k in ${output[*]}; do
                          $execute $k
                          done
                         ;;
	              #Save all the parameters into the string, execute, because they are all commands after exec. 
                      *)   execute+="$2 "
                        ;;
                    esac
                    shift
                done
                ;;
#This would find all the sub-directories and set it to string directory 
        * )     tempdir=$1
                directory+="$1  "
                fill_sub_dir tempdir        
    esac
    shift
done
