#include<linux/init.h>
#include<linux/module.h>
#include <linux/kernel.h>
#include<linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rohan");
MODULE_DESCRIPTION("To Learn Kernel");


//Proc_ops function declaration 
ssize_t	Rohan_Read(struct file *File_PTR , char * userspace_buffer, size_t count, loff_t *offset);
ssize_t	Rohan_Write(struct file *File_PTR, const char * userspace_buffer , size_t, loff_t *offset);

//global Structure declaration 
struct proc_dir_entry *Pro_Output;
const struct proc_ops proc_operations={
    .proc_read = Rohan_Read,
    .proc_write = Rohan_Write
};

//global declaration
char kernel_space[100];
ssize_t len;

//Proc_ops Function definition 
ssize_t	Rohan_Read(struct file *File_PTR , char * userspace_buffer, size_t count, loff_t *offset){

    // char A[]="V\na\nl\ni\nd\n";
    // ssize_t len = strlen(A),result;
    // static int a=0;
    ssize_t result;
    result = copy_to_user(userspace_buffer,kernel_space,len);
    
    pr_info("Read\n");
    if(*offset>=len+1)
        return 0;
    
    *offset+=len;
    
    return len;
}

ssize_t	Rohan_Write(struct file *File_PTR, const char * userspace_buffer, size_t, loff_t *offset){

    len = strlen(userspace_buffer);
    ssize_t result;
    pr_info("write\n");
    result= copy_from_user(kernel_space,userspace_buffer,len);

    return len;
}

static int __init kernel_init(void){

    pr_info("kernel_init: entered\n");
    Pro_Output = proc_create("Rohan_Driver", 0,NULL, &proc_operations);
    pr_info("kernel_init: exited\n");

    return 0;
}

static void __exit kernel_exit(void){
    pr_info("kernel_exit: entered\n");
    proc_remove(Pro_Output);
    pr_info("kernel_exit: exited\n");
}

module_init(kernel_init);
module_exit(kernel_exit);
