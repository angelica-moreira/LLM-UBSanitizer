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
struct fs_context {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 scalar_t__ init_pseudo (struct fs_context*,int) ; 

__attribute__((used)) static int drm_fs_init_fs_context(struct fs_context *fc)
{
	return init_pseudo(fc, 0x010203ff) ? 0 : -ENOMEM;
}