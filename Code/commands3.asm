sleep:
sleep n: sleep for n seconds.
sleep 50 &: sleep for 50 seconds in the background.
jobs: display the background jobs running in the terminal.
fg %n: bring the nth job to the foreground.


gzip:
gzip file: compress the file.
gzip -k file: compress the file and keep the original file.
gzip -d file.gz: decompress the file.gz.


zip compresses the file size and tar is used to store multiple files in a single file.tar+zip is used to compress and store multiple files in a single file.
tar:
tar -cf file.tar file1 file2: create a tar file with the files file1 and file2. tar files are used to store multiple files in a single file.
tar -tf archive.tar : list the files in the archive.tar file.
extracting to a file in the current directory:
tar -xf file.tar: extract the files from the file.tar archive to the current directory.
tar -czf file.tar.gz file1 file2: create a compressed tar file with the files file1 and file2.
tar -xzf file.tar.gz: extract the files from the compressed file.tar.gz archive.-xzf is used to extract the files from the compressed tar file.

alias:(only for the current terminal session)
alias: display all the aliases.
alias name='command': create an alias for the command.when typed name in the terminal, the command will be executed.


xargs:
cat removefile.txt| xargs rm: remove the files listed in the removefile.txt file.
we simply cant not use rm because it will not take the file names as arguments.The reason is that rm command does not take the file names as arguments.xargs works as an adapter in this case.Places where xargs are used:
find / -name "*.txt" | xargs rm: remove all the files with the .txt extension.
find / -name "*.txt" | xargs grep "hello": search for the word hello in all the files with the .txt extension.
find / -name "*.txt" | xargs -I {} cp {} /tmp: copy all the files with the .txt extension to the /tmp directory.
etc......



ln:
this command is used to create a link to a file.
for example:
ln new.cpp new1.cpp : creates a link to the new.cpp file with the name new1.cpp. any changes to any of the files will be reflected in the other file. But even if we delete one file, the other file will not be deleted because it is just a link to the file.
ln -s new.cpp new1.cpp: creates a symbolic link to the new.cpp file with the name new1.cpp. any changes to any of the files will be reflected in the other file. But if we delete one file, the other file will also be deleted because it is just a link to the file.

su:
su: switch to the root user.
su username: switch to the username user.
su - username: switch to the username user and load the environment variables of the username user.

sudo:
super user do: execute the command as the root user. Sometimes we cant execute the command as a normal user because of the permissions. In that case, we use sudo to execute the command as the root user.


passwd:
passwd: change the password of the current user.
sudo passwd username: change the password of the username user as the root user.

chown full explanation:
chown: change the owner of the file.
examples:



Understanding Permissions:
d: directory
-: file
r: read
w: write
x: execute
permissions:
rwx rwx rwx-> first rwx is for the owner, second rwx is for the group, and the third rwx is for others.
-: no permission
-rw-r--r--:means:
owner: read, write
group_owner: read
others/world: read
we are in the field 



curl:
curl url: download the content of the url.
curl -o filename url: download the content of the url and save it in the filename file.
curl -O url: download the content of the url and save it in the same name as the url file.
curl -I url: display the headers of the url.


grep:
grep pattern file: search for the pattern in the file.
ie:
grep hello file.txt: search for the word hello in the file.txt file.
grep -w "AshMan" file.txt: search for the word AshMan in the file.txt file. -w is used to search for the exact word.
grep -i "ashman" file.txt: search for the word ashman in the file.txt file. -i is used to ignore the case.
grep -v "ashman" file.txt: search for the lines that do not contain the word ashman in the file.txt file. -v is used to invert the search.
grep -n "ashman" file.txt: search for the word ashman in the file.txt file and display the line number.
grep -B 2 "ashman" file.txt: search for the word ashman in the file and display the 2 lines before the line that contains the word ashman.
grep -A 2 "ashman" file.txt: search for the word ashman in the file and display the 2 lines after the line that contains the word ashman.
grep -C 2 "ashman" file.txt: search for the word ashman in the file and display the 2 lines before and after the line that contains the word ashman.
grep -win "ashman" ./*: search for the word ashman in all the files in the current directory. -win is used to search for the exact word, ignore the case, and display the line number.
grep -r "ashman" ./*.txt: search for the word ashman in all the .txt files in the current directory and its subdirectories.
grep -wirl "grep" .:just show the files  not the lines that contain the word grep.
grep -wric "grep" .:just show the count of the files that contain the word grep.
grep "\d{3}-\d{3}-\d{4}" file.txt: search for the phone number pattern in the file.txt file.The \d is used to search for the digit and {3} is used to search for the 3 digits. - is used to search for the hyphen.
grep -E "\d{3}-\d{3}-\d{4}" file.txt: search for the phone number pattern in the file.txt file. -E is used to enable the extended regular expression.
r



find:
find DirectoryName:find all in the DirectoryName

find . -type d:
name all the directory located in .

find . -type f:
name all the files . Maybe same as find DirectoryName

find . -type f -name new.cpp
find all the files located inside . and named new.cpp 

find . -type f -name "new*.cpp"
find all the files with a wildcard matching

find . -type f -iname "new*.cpp"
ignore the case 

find . -empty:
find all the empty files.

find Git-Crash-Course -type d -exec chmod 775 {} +:
this command 

find . -type f -name "*.pdf" -maxdepth 1
maxdepth forbids to go more than one depth(in this case the current directory).


ind . -type f -name "*.pdf" -maxdepth 1 -exec {} +
delete them {} is a place holder for each x in the left of exec.











