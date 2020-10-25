GCCPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = loader.o gdt.o port.o interruptstubs.o interrupts.o keyboard.o kernel.o


run: fusion.iso
	(killall VirtualBox && sleep 1) || true
	VirtualBox
	
%.o: %.cpp
	gcc $(GCCPARAMS) -c -o $@ $<

%.o: %.s
	as $(ASPARAMS) -o $@ $<

fusion.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

fusion.iso: fusion.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp fusion.bin iso/boot/fusion.bin
	echo 'set timeout=0'                      > iso/boot/grub/grub.cfg
	echo 'set default=0'                     >> iso/boot/grub/grub.cfg
	echo ''                                  >> iso/boot/grub/grub.cfg
	echo 'menuentry "Fegeya Fusion" {' >> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/fusion.bin'    >> iso/boot/grub/grub.cfg
	echo '  boot'                            >> iso/boot/grub/grub.cfg
	echo '}'                                 >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=fusion.iso iso
	rm -rf iso

install: fusion.bin
	sudo cp $< /boot/fusion.bin

.PHONY: clean
clean:
	rm -f $(objects) fusion.bin fusion.iso