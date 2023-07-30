#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int log_level = 4; // 假設模塊定義了自己的printk參數，初始值為4

module_param(log_level, int, S_IRUGO); // 定義printk參數

static int __init helloworld_init(void) {
    printk(KERN_INFO "kernel INFO - Hello, World!\n");
    printk("Hello world - origin printk\n");
    pr_info("pr_info - Hello, World!\n");
    printk(KERN_ERR "kernel ERR - Hello, World!\n");
    printk(KERN_EMERG "kernel EMERG - Hello, World!\n");

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
