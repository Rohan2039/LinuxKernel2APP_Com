def main():
    handle = open('/proc/Rohan_Driver')
    kernel_space = handle.readline()
    print(kernel_space)
    handle.close()
    return

main()
