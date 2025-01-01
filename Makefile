obj-m += Ldd.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	sudo dmesg -C
	sudo insmod Ldd.ko
	sudo chmod a+w /proc/Rohan_Driver
	echo "welcome" >/proc/Rohan_Driver
	cat /proc/Rohan_Driver
	sudo dmesg

clean:
	sudo rmmod Ldd
	sudo dmesg -C
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
