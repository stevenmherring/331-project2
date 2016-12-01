

all: dirs call_shellcode exploit real_root stack

dirs:
	@mkdir -p bin

call_shellcode:
	gcc -z execstack -o bin/call_shellcode src/call_shellcode.c

stack:
	sudo gcc -o bin/stack -z execstack -fno-stack-protector -g -o bin/stackdebug src/stack.c
	sudo chmod 4755 bin/stack
	sudo chmod 4755 bin/stackdebug
	@exit

exploit:
	gcc -o bin/exploit src/exploit.c

real_root:
	gcc -o bin/real_root src/real_root.c

.PHONY: clean

clean:
	rm -rf bin
	rm -f badfile
