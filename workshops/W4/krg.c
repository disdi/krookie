/******************* Kernel Rookie Guide OSSEU'18 Edinburgh *******************
 *
 * (C) Andrzej Pietrasiewicz <andrzej.p@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>

struct data {
	int			id;
	struct list_head	entry;
};

static LIST_HEAD(collection);

/*
 * The module allocates 'number' instances (default: 3) of struct data
 * and adds them to 'collection'. 
 */
static int number = 3;
module_param(number, int, 0);

int krg_init(void)
{
	struct data *data;
	int i;

	/* we want our list to have some length, no more than 1000 */
	if (number <= 0 || number > 1000)
		return -EINVAL;

	/* TODO: ensure appropriate 'number' of iterations */
	for (i = 0; i < 0; ++i) {
		/*
		 * TODO: allocate a struct data
		 * use kzalloc()
		 */
		data = NULL;
		if (!data)
			goto no_memory;

		/* TODO: set the id member of struct data to i */

		/*
		 * TODO: add struct data after the last element of collection
		 * use list_add_tail()
		 */

		printk("%s added:%d@%px\n", __func__, data->id, data);
	}

	return 0;

no_memory:
	while (i--) {
		/*
		 * TODO: let 'data' point to last element of collection
		 * use list_last_entry()
		 */

		/*
		 * TODO: remove the element from the collection
		 * use list_del()
		 */

		/*
		 * TODO: free the memory occupied by the removed element
		 * use kfree()
		 */
	}
	return -ENOMEM;
}
module_init(krg_init);

void krg_exit(void)
{
	struct data *data;

	while (number--) {
		/*
		 * TODO: let 'data' point to last element of collection
		 * use list_last_entry()
		 */

		/*
		 * TODO: remove the element from the collection
		 * use list_del()
		 */

		printk("%s removed:%d@%px\n", __func__, data->id, data);

		/*
		 * TODO: free the memory occupied by the removed element
		 * use kfree()
		 */
	}
}
module_exit(krg_exit);

MODULE_LICENSE("GPL");
