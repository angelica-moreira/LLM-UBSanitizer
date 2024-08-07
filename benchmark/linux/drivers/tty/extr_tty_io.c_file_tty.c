#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct tty_struct {int dummy; } ;
struct tty_file_private {struct tty_struct* tty; } ;
struct file {scalar_t__ private_data; } ;

/* Variables and functions */

__attribute__((used)) static inline struct tty_struct *file_tty(struct file *file)
{
	return ((struct tty_file_private *)file->private_data)->tty;
}