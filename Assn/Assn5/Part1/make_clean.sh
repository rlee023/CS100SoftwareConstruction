#
# Course: CS 100 Summer Session 2 2013
#
# First Name: Ryan
# Last Name: Lee
# Username: rlee023
# email address: rlee023@ucr.edu
#
# Assignment: assn5
# Filename: make_clean.sh
#
# I hereby certify that the contents of this file represent
# my own original individual work. Nowhere heren is there 
# code from any outside resources such as another individual, 
# a website, or publishings unless specifically designated as 
# permissible by the instructor or TA. 
#

# Check is the user passed in a directory or not. 
if [ -n $1  ] ; then
    DIRR=$PWD
else
    DIRR=$1
fi

# I need to save the current directory, because I manually go into 
# other directories later and remove them. 
CUR_DIR=$PWD

# Loop through the directories that contain makefile
for item in `find $DIRR -iname "makefile"`
do
    # Get rid of the makefile attatched to the end of the path
    dir=`dirname "$item"`
    # cd into the directory
    cd $dir
    # call make clean
    make clean
done

#Finally, cd back into the directory I was originally in. 
exec `cd $CUR_DIR`
