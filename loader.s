.set MAGIC, 0x1badb002  #present in the bx register
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot 
	.long MAGIC
	.long FLAGS
	.long CHECKSUM
.section .text
.extern kernelMain
.global loader

loader:
	mov $kernel_stack,%esp
	push %eax
	push %ebx
	call kernelMain

_stop:
	cli
	hlt
	jmp _stop

.section .bss
.space 64*1024; # 2Mib
kernel_stack:
