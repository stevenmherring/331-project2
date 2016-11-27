

all: dirs call_shellcode exploit real_root stack

dirs:
	@mkdir -p bin

call_shellcode:
	gcc -z execstack -o bin/call_shellcode src/call_shellcode.c

stack:
	@echo "\nTYPE IN ROOT PASSWORD (seedubuntu) then PRESS CTRL-D\n"
	su root
	gcc -o bin/stack -z execstack -fno-stack-protector src/stack.c
	chmod 4755 bin/stack
	@exit

exploit:
	gcc -o bin/exploit src/exploit.c

real_root:
	gcc -o bin/real_root src/real_root.c

.PHONY: clean

clean:
	rm -rf bin
	rm -f badfile