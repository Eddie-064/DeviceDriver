#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init helloworld_init(void) {
    printk(KERN_INFO "Hello, World!\n");
    return 0; // 非零值表示初始化失敗
}

static void __exit helloworld_exit(void) {
    printk(KERN_INFO "Goodbye, World!\n");
}

module_init(helloworld_init);
module_exit(helloworld_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Hello World kernel module");
