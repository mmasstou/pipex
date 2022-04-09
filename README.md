# Pipex
### This project aims to make you understand a bit deeper two concepts that you already know: the redirections and the pipes. It is an introduction project.
<hr>
#External functs

### Description : This project is about handling pipes.
```
• access
• open
• unlink
• close
• read
• write
• malloc
• waitpid
• wait
• free
• pipe
• dup
• dup2
• execve
• fork
• perror
• strerror
• exit
```
# Mandatory Part:
Your program will be executed as follows:
```
 ./pipex file1 cmd1 cmd2 file2
```
## Exemple :
```
 $> ./pipex infile "ls -l" "wc -l" outfile
 ```
 ### Should behave like : < infile ls -l | wc -l > outfile
## Requirements:
### Your project must comply with the following rules:
   • You have to turn in a Makefile which will compile your source files. It must not
relink.
   • You have to handle errors thoroughly. In no way your program should quit unexpectedly (segmentation fault, bus error, double free, and so forth).
   • Your program mustn’t have memory leaks.
   • If you have any doubt, handle the errors like the shell command: ```< file1 cmd1 | cmd2 > file2 ```
# Bonus Part :
