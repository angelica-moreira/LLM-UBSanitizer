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
struct gb_hid {size_t bufsize; int /*<<< orphan*/  inbuf; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  kzalloc (size_t,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int gb_hid_alloc_buffers(struct gb_hid *ghid, size_t bufsize)
{
	ghid->inbuf = kzalloc(bufsize, GFP_KERNEL);
	if (!ghid->inbuf)
		return -ENOMEM;

	ghid->bufsize = bufsize;

	return 0;
}