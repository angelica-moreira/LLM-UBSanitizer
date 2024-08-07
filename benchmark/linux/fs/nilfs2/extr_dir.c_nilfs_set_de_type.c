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
typedef  size_t umode_t ;
struct nilfs_dir_entry {int /*<<< orphan*/  file_type; } ;
struct inode {size_t i_mode; } ;

/* Variables and functions */
 size_t S_IFMT ; 
 size_t S_SHIFT ; 
 int /*<<< orphan*/ * nilfs_type_by_mode ; 

__attribute__((used)) static void nilfs_set_de_type(struct nilfs_dir_entry *de, struct inode *inode)
{
	umode_t mode = inode->i_mode;

	de->file_type = nilfs_type_by_mode[(mode & S_IFMT)>>S_SHIFT];
}