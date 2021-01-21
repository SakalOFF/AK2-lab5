
#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

MODULE_AUTHOR("Volodymyr Sokolov");
MODULE_DESCRIPTION("Lab5_hello_world_output");
MODULE_LICENSE("Dual BSD/GPL");

static uint count = 1;
module_param(count,uint,S_IRUGO);
MODULE_PARM_DESC(count, "variable for quantity of hello world output");

static int __init hello(void)
{
  uint i = 0;

  printk(KERN_INFO "count: %d\n", count);

  if(count == 0) {
    pr_warning("Parameter=0");
  }else if(count >=5 && count <= 10) {
    pr_warning("Parameter is between 5 and 10");
  } else if(count > 10) {
    pr_err(KERN_ERR "Parameter>10");
    return -EINVAL;
  }

  for(i = 0; i < count; i++){
    pr_info(KERN_INFO "Hello, world!\n");
  }
  return 0;
}


static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello);
module_exit(hello_exit);
