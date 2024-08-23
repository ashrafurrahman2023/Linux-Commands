1.whoami:
this command is used to know the current user name.
2.man:
this command is used to display the manual of any command. press q to exit from the manual.

3.ls:
this command is used to list the files and directories in the current directory.

4. pwd(print working directory):
this command is used to display the current working directory.


5. cd:
this command is used to change the directory.

6.
ls -l:
files in long format 

7.
ls -a:
list all files including hidden files

8.
cd ..:
move to the parent directory of the current one 

9.
cd ~:
move to the home directory of the current user(everything we do resides in this folder /home/username)

10.
cd /:
move to the root directory(cant move any back further)

11.
mkdir directoryname:
create a new directory named directoryname

12.
mkdir "abc"  "abc def":
create two directories named abc and abc def

mkdir "a/b/c" a/b must exist before creating c

13.
mkdir -p a/b/c:
create a directory named a and inside it create b and inside b create c. even if a exists and inside a exists something other a/b/c will be created.(Tested)
makes necessary directories in the way 

14.
touch filename:
create a new file named filename and if it already exists update the timestamp of the file. 


15.
rmdir directoryname:
remove the directory named directoryname if it is empty.

16.
rm:
remove the file for example rm new.cpp 
it should be used with caution as it deletes the file permanently


17.
rm -r directoryname:
remove the directory named directoryname and all its contents recursively.

18. 
rm -ri directoryname:
remove the directory named directoryname and all its contents recursively but ask for confirmation before deleting each file.
example:
rm -ri code
examine files in directory code? y
remove code/a.cpp? y
examine files in directory code/a? y
examine files in directory code/a/b? y
remove code/a/b? y
remove code/a? y
remove code? y

19.
rm -rv directoryname:
remove the directory named directoryname and all its contents recursively and show the files being deleted.
ie:
rm -rv code
code//a/b/c
code//a/b
code//a
code/ 
ls:


20.
open .: to open the current directory in the file manager
open new.cpp: to open the file new.cpp in the file manager
these are mac specific
for ubantu xdg-open is used

21.
mv:
move the contents of one file to another file 
if new.cpp and new.txt both exists and we do mv new.cpp new.txt then the contents of new.cpp will be moved to new.txt and new.cpp will be deleted.
we can also do: 
mv "" "a/b/c"
we can remove things around . if the thing to where is being placed is not present it will be 
created and the thing will be moved there.


22.
cp:
copy the contents of one file to another 
ie> cp new.cpp newer.cpp will create a new file named newer.cpp with the contents of new.cpp
to copy a directory we use cp -r directoryname1 directoryname2 r stands for recursive
we can do cp new.cpp "a/b/c" to copy new.cpp to a/b/c 
we can do cp new.cpp "a/b/c/newer.cpp" to copy new.cpp to a/b/c and rename it to newer.cpp while new.cpp remains as it is.


23.
head filename:
display the first 10 lines of the file named filename.

24.
head -n 5 filename:
display the first 5 lines of the file named filename.

25.
tail filename:
display the last 10 lines of the file named filename.


in general head/tail -n filename where n is the number of lines to be displayed.(tested)


26.
tail -f -1 new.cpp :
display the last line of the file new.cpp and keep the file open and display the last line as it is updated in the file.(Useful for log files) control c to quit 

27.
date:
display the current date and time.
ie:
Wed 14 Jul 2021 12:00:00 PM IST

28.
>: 
redirect the output of a command to a file.
ie:
ls > new.txt
this will create a new file named new.txt and write the output of ls command to it.
date > gg.txt:
this will create a new file named gg.txt and write the output of date command to it.


29.
>>:
append the output of a command to a file.
ie:
ls >> new.txt
this will append the output of ls command to the file new.txt.
date >> gg.txt:
this will append the output of date command to the file gg.txt.


30.
cat:(gives entire file)
display the contents of a file.
cat file1 file2 ...
cat new.cpp new.cpp new.cpp > cat.t
xt:
this will create a new file named cat.txt and write the contents of new.cpp three times to it.
cat -n new.cpp:
this will display the contents of new.cpp with line numbers.



31.
less filename:
if there is a huge file we can read it by pressing lines.Can press space to go one page at a time

echo:(outputs whatever is given to it)
echo "hello fomr lab" >newer.txt
echo "{js-module:"none"}" >> a.txt


32
wc:
wc filename:
no_of_lines #words #bytes filename
5       9      58 new.cpp


33
wc -l filename:
wc -w filename:
type man wc to know "how to know detail about a file"


34
|:(piping operator or giving the output of left side to the right part)
cat a.txt a.txt | wc
output:       4       6      60
expla: concatenate a.txt with a.txt and pass it to wc as an argument

cat a.txt a.txt | wc -l (number of lines):
       4


35:
sort:
sort a.txt > b.txt:
sort a.txt in aplhabetical order (without changing the a.txt) and 
put the output in b.txt
sort -n a.txt >b.txt: in numerical order.


sort -nu a.txt:
sort in number but only unique numbers only. 



cat a.txt a.txt | sort :
concatenate and pass it to sort.


uniq a.txt:
remove duplicate lines from a.txt

sort a.txt | uniq:
sort a.txt and pass it to uniq which will remove duplicate lines.

sort a.txt | uniq -d:
sort a.txt and pass it to uniq which will display only the duplicate lines.

sort a.txt | uniq -u:
sort a.txt and pass it to uniq which will display only the unique lines.

sort a.txt | uniq -c:
sort a.txt and pass it to uniq which will display the count of each line.

sort a.txt | uniq -c | sort -n:
sort a.txt and pass it to uniq which will display the count of each line and then sort it in numerical order.
ie:
   1 are
   1 because they are 
   1 eaters 
   1 indians
   1 litelarry poop eaters
   2 Poop
be careful "a" and "a " are different lines for uniq











