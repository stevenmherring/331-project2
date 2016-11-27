# Buffer-Overflow Vulnerability

### How to use:

`$ make clean all`
> This will prompt you for the root password, this is so it can make `bin/stack` a Set-UID program.
> All programs must be run from the source directory in the form `bin/*`

##### call_shellcode.c

Just an example of the shell code in raw binary and how it can be executed.

##### exploit.c

This program must generate the file in the correct format such that `stack` will gain root priviledges.

##### real_root.c

Small program to run after you've gained root to fix minor bugs having to do with effective/actual uid.

##### stack.c

This is the vunerablity exploit program. It is a Set-UID program that will read in badfile, that should be in the source directory before launch, and should gain root priviledges and exec a shell.

### Typical Usage:

```
$ make clean all
rm -rf bin
rm -f badfile
gcc -z execstack -o bin/call_shellcode src/call_shellcode.c
src/call_shellcode.c: In function ‘main’:
src/call_shellcode.c:24:4: warning: incompatible implicit declaration of built-in function ‘strcpy’ [enabled by default]
gcc -o bin/exploit src/exploit.c
gcc -o bin/real_root src/real_root.c

TYPE IN ROOT PASSWORD (seedubuntu) then PRESS CTRL-D

su root
Password:
# exit (Presses Ctrl-D here)
gcc -o bin/stack -z execstack -fno-stack-protector src/stack.c
chmod 4755 bin/stack
$ bin/exploit
$ bin/stack
# bin/real_root
```
