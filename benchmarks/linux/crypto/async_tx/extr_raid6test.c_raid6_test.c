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

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int NDISKS ; 
 int /*<<< orphan*/  alloc_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * data ; 
 int /*<<< orphan*/  pr (char*,...) ; 
 int /*<<< orphan*/  put_page (int /*<<< orphan*/ ) ; 
 scalar_t__ test (int,int*) ; 

__attribute__((used)) static int raid6_test(void)
{
	int err = 0;
	int tests = 0;
	int i;

	for (i = 0; i < NDISKS+3; i++) {
		data[i] = alloc_page(GFP_KERNEL);
		if (!data[i]) {
			while (i--)
				put_page(data[i]);
			return -ENOMEM;
		}
	}

	/* the 4-disk and 5-disk cases are special for the recovery code */
	if (NDISKS > 4)
		err += test(4, &tests);
	if (NDISKS > 5)
		err += test(5, &tests);
	/* the 11 and 12 disk cases are special for ioatdma (p-disabled
	 * q-continuation without extended descriptor)
	 */
	if (NDISKS > 12) {
		err += test(11, &tests);
		err += test(12, &tests);
	}

	/* the 24 disk case is special for ioatdma as it is the boudary point
	 * at which it needs to switch from 8-source ops to 16-source
	 * ops for continuation (assumes DMA_HAS_PQ_CONTINUE is not set)
	 */
	if (NDISKS > 24)
		err += test(24, &tests);

	err += test(NDISKS, &tests);

	pr("\n");
	pr("complete (%d tests, %d failure%s)\n",
	   tests, err, err == 1 ? "" : "s");

	for (i = 0; i < NDISKS+3; i++)
		put_page(data[i]);

	return 0;
}