// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/*
 * OPlus DT2W interfaces
 *
 * Copyright (C) 2022, Rudi Setiyawan <diphons@gmail.com>
 */

#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/seq_file.h>
#include <linux/irq.h>
#include <linux/gpio.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("diphons");
MODULE_DESCRIPTION("OPlus DT2W node link");
MODULE_VERSION("0.0.9");

#define tpdir "touchpanel"

#define d_tap "touchpanel/double_tap_enable"
#define tp_dt "/touchpanel/double_tap"
#define tpdir_fts "devices/platform/soc/a98000.i2c/i2c-3/3-0038/fts_gesture_mode"

static int __init oplus_dt2w_init(void) {
	char *driver_path;
	static struct proc_dir_entry *tp_dir;
	static struct proc_dir_entry *tp_oos;
	int ret = 0;

	printk(KERN_INFO "OPlus DT2W node link initial");

	tp_dir = proc_mkdir(tpdir, NULL);
	driver_path = kzalloc(PATH_MAX, GFP_KERNEL);
	if (!driver_path) {
		pr_err("%s: failed to allocate memory\n", __func__);
		ret = -ENOMEM;
	}

	sprintf(driver_path, "/sys%s", tp_dt);

	pr_err("%s: driver_path=%s\n", __func__, driver_path);

	tp_oos = proc_symlink(d_tap, NULL, driver_path);

	if (!tp_oos) {
		ret = -ENOMEM;
		printk(KERN_INFO "OPlus DT2W node link failed");
	} else
		printk(KERN_INFO "OPlus DT2W node link initialized");

	return ret;
}

static void __exit oplus_dt2w_exit(void) {
	printk(KERN_INFO "OPlus DT2W node link exit");
}

module_init(oplus_dt2w_init);
module_exit(oplus_dt2w_exit);

