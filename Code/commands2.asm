echo ~:
it expands ~ and echos it. 

echo *:
echo every file and folder in the current directory.

echo *.txt:
echo every file with .txt extension in the current directory.

echo a*:
echo every file starting with a in the current directory.

echo *.*:
it will echo every file with a . in the current directory.

echo *.???:
it will echo every file with a . and 3 characters after it in the current directory. ? means any character. * means any number of characters.

echo *.{cpp,txt}:
it will echo every file with .cpp or .txt extension in the current directory.

rm *.txt:
remove every file with .txt extension in the current directory.

echo {a,b,c}.txt:
echo a.txt b.txt c.txt

touch app.{cpp,txt,cpp,js}:
create app.cpp app.txt app.cpp app.js

echo {a..z}:  
echo a b c d e f g h i j k l m n o p q r s t u v w x y z

echo {1..10}:
echo 1 2 3 4 5 6 7 8 9 10

echo {1..10..2}:
echo 1 3 5 7 9

echo {a..z..2}:
echo a c e g i k m o q s u w y

echo Day{1..5}:
echo Day1 Day2 Day3 Day4 Day5

echo {01..5}:
echo 01 02 03 04 05

echo {01..5..2}:
echo 01 03 05

echo app.*:
echo app.cpp app.txt app.cpp app.js

rm app.*:
remove app.cpp app.txt app.cpp app.js


find .:
find all files and directories in the current directory.
ie:
.
./gg.txt
./new.cpp
./New Book For Aging Kids
./Directory
./Directory/apple.pdf
./b.txt
./a.txt
./newer.cpp
./cat.txt
./DrDre
./DrDre/new.cpp
./DrDre/apple.pdf

find . -name 'filename':
find all files and directories with the name filename in the current directory.
ie:
find . -name 'new.cpp'
./new.cpp
./DrDre/new.cpp 
new.cpp is in the current directory and in DrDre directory.

find . -name '*.*':
find all files with a . in the current directory.
* is a wildcard match

find . -name '*.txt':
find all files with .txt extension in the current directory.

find "a/b/c"  -name 'new.cpp':
find all files with the name new.cpp in the directory a/b/c.
ie:
find DrDre -name '*.*'  
DrDre/new.cpp
DrDre/apple.pdf
find ../../ -name '*.*':
find all the files located inside ../../ with a . in the name.

find . -type d:
find all directories in the current directory.
output:
.
./Directory
./DrDre

find . -type d -name '*Dir*':
find all directories with Dir in the name in the current directory.

find . -name '*.cpp' -or -name '*.txt':
Usage of or operator:
find all files with .cpp or .txt extension in the current directory.

find . -type f -size +100c:
find all files with size greater than 100 bytes/characters in the current directory.

find file size in range:
find . -type f -size +100k -size -200M:
find all the files in the range [100k 200M] bytes in the current directory.

Search files edited in the last 2 days:
find . -type f -mtime -2:

Search files edited more than 2 days ago:
find . -type f -mtime +2:

Search files edited in the last 2 hours:
find . -type f -mmin -120:

Search files edited more than 2 hours ago:
find . -type f -mmin +120:

Search files edited in the last 2 minutes:
find . -type f -mmin -2:

Search files edited more than 2 minutes ago:
find . -type f -mmin +2:

Search files edited in the last 2 seconds:
find . -type f -mmin -0.033:

Search files edited more than 2 seconds ago:
find . -type f -mmin +0.033:

Search files edited in the last 2 days and with .cpp extension:
find . -type f -name '*.cpp' -mtime -2:

Adding -delete to the above command will delete the files.
ie:
find . -type f -name '*.cpp' -mtime -2 -delete
it will delete all the files with .cpp extension edited in the last 2 days.



-exec:
examples:
find . -type f -name '*.cpp' -exec echo {} /tmp/ \;
explanation:
find all files with .cpp extension in the current directory and copy them to /tmp/ directory.The curley braces will be replaced with each of the found files.

find -type f -size +100k -exec ls -l {}\;
find all files with size greater than 100k in the current directory and list them.



grep:
grep 'pattern' filename:
search for a pattern in a file.


grep -n 1 a.txt:
search for 1 in a.txt and display the line number.

grep -n 1 a.txt b.txt:
search for 1 in a.txt and b.txt and display the line number.

grep -nC 1 1 a.txt:
search for 1 in a.txt and display the line number and the line before and after it.cool the way the format it as a set.

grep -nA 1 1 a.txt:
search for 1 in a.txt and display the line number and the line after it.

grep -nB 1 1 a.txt:
search for 1 in a.txt and display the line number and the line before it.

grep -r "a" .:
search for a in all files and directories in the current directory.
output example:
grep -r " " .
./gg.txt:Tue Jul 30 11:38:24 +06 2024
./new.cpp:New Book For Aging Kids
./a.txt:Indians are poop.1
./a.txt:<i class="fas fa-engine-warning    "></i>
./cat.txt:New Book For Aging Kids
./cat.txt:New Book For Aging Kids
./cat.txt:New Book For Aging Kids
./cat.txt:newer. cpp

du:
it gives size of current .s directory.
du -mh
  0B    ./Directory
  0B    ./tmp
4.0K    ./DrDre
 28K    .
 -h for human readable format.

du -h | sort -h:
Full explanation:
du -h: display the size of the current directory in human readable format.
| : pipe the output of du -h to the next command.
sort -h: sort the output of du -h in human readable format.


top 10 files in the current directory:
du -h | sort -h | tail -n 10:

top 10 files in the current directory with the largest size:
du -h | sort -rh | head -n 10:


df:
command details:
1.df: display the disk space usage of the current directory.
df -h: display the disk space usage of the current directory in human readable format.

2.df -hT: display the disk space usage of the current directory in human readable format with the file system type.

df -hT /dev/sda1: display the disk space usage of the /dev/sda1 directory in human readable format with the file system type.


history:
history: display the history of the commands executed in the terminal.

!n: execute the nth command in the history.

!!: execute the last command in the history.



ps:
ps: display the processes running in the terminal.
ps ax: display all the processes running in the terminal.
ps aux: display all the processes running in the terminal with the user name and the CPU and memory usage.
ps axww: display all the processes running in the terminal with the full command line.
ps axww | grep 'pattern': search for a pattern in the processes running in the terminal.
pa a: display all the processes running in the terminal with the user name and the CPU and memory usage.

top:
top: display the processes running in the terminal with the CPU and memory usage.(descending order of CPU usage)
   


kill:
kill PID: kill the process with the PID.
kill -9 PID: kill the process with the PID forcefully.
killall process_name: kill all the processes with the process_name. for example:
killall -9 node: kill all the node processes forcefully.


jobs:
jobs: display the background jobs running in the terminal.We can see all the "control+z" stopped jobs here.
fg %n: bring the nth job to the foreground.It will start running that resumed job.
bg %n: resume the nth job in the background.
ctrl+z: stop the current job and put it in the background.

sleep:
sleep n: sleep for n seconds.
sleep 50 &: sleep for 50 seconds in the background.
jobs: display the background jobs running in the terminal.
fg %n: bring the nth job to the foreground.






















