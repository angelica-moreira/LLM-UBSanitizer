#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {char* layers; } ;
struct TYPE_5__ {TYPE_1__ dp; int /*<<< orphan*/  spa; scalar_t__ hpa; int /*<<< orphan*/  iodc_io; } ;
struct TYPE_6__ {TYPE_2__ mem_cons; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENTRY_IO_COUT ; 
 TYPE_3__* PAGE0 ; 
 int /*<<< orphan*/  __pa (char*) ; 
 char* iodc_dbuf ; 
 char* iodc_retbuf ; 
 int /*<<< orphan*/  pdc_lock ; 
 int /*<<< orphan*/  real32_call (int /*<<< orphan*/ ,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

int pdc_iodc_print(const unsigned char *str, unsigned count)
{
	unsigned int i;
	unsigned long flags;

	for (i = 0; i < count;) {
		switch(str[i]) {
		case '\n':
			iodc_dbuf[i+0] = '\r';
			iodc_dbuf[i+1] = '\n';
			i += 2;
			goto print;
		default:
			iodc_dbuf[i] = str[i];
			i++;
			break;
		}
	}

print:
        spin_lock_irqsave(&pdc_lock, flags);
        real32_call(PAGE0->mem_cons.iodc_io,
                    (unsigned long)PAGE0->mem_cons.hpa, ENTRY_IO_COUT,
                    PAGE0->mem_cons.spa, __pa(PAGE0->mem_cons.dp.layers),
                    __pa(iodc_retbuf), 0, __pa(iodc_dbuf), i, 0);
        spin_unlock_irqrestore(&pdc_lock, flags);

	return i;
}