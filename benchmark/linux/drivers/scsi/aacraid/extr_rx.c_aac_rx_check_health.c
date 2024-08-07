#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct aac_dev {TYPE_1__* pdev; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;
typedef  void* __le32 ;
struct TYPE_4__ {int /*<<< orphan*/ * IMRx; int /*<<< orphan*/ * OMRx; } ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  COMMAND_POST_RESULTS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int KERNEL_PANIC ; 
 int KERNEL_UP_AND_RUNNING ; 
 TYPE_2__ MUnit ; 
 int SELF_TEST_FAILED ; 
 void* cpu_to_le32 (int /*<<< orphan*/ ) ; 
 void* dma_alloc_coherent (int /*<<< orphan*/ *,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_coherent (int /*<<< orphan*/ *,int,...) ; 
 int hex_to_bin (char) ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  memset (char*,int /*<<< orphan*/ ,int) ; 
 int rx_readl (struct aac_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rx_sync_cmd (struct aac_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rx_writel (struct aac_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static int aac_rx_check_health(struct aac_dev *dev)
{
	u32 status = rx_readl(dev, MUnit.OMRx[0]);

	/*
	 *	Check to see if the board failed any self tests.
	 */
	if (unlikely(status & SELF_TEST_FAILED))
		return -1;
	/*
	 *	Check to see if the board panic'd.
	 */
	if (unlikely(status & KERNEL_PANIC)) {
		char * buffer;
		struct POSTSTATUS {
			__le32 Post_Command;
			__le32 Post_Address;
		} * post;
		dma_addr_t paddr, baddr;
		int ret;

		if (likely((status & 0xFF000000L) == 0xBC000000L))
			return (status >> 16) & 0xFF;
		buffer = dma_alloc_coherent(&dev->pdev->dev, 512, &baddr,
					    GFP_KERNEL);
		ret = -2;
		if (unlikely(buffer == NULL))
			return ret;
		post = dma_alloc_coherent(&dev->pdev->dev,
					  sizeof(struct POSTSTATUS), &paddr,
					  GFP_KERNEL);
		if (unlikely(post == NULL)) {
			dma_free_coherent(&dev->pdev->dev, 512, buffer, baddr);
			return ret;
		}
		memset(buffer, 0, 512);
		post->Post_Command = cpu_to_le32(COMMAND_POST_RESULTS);
		post->Post_Address = cpu_to_le32(baddr);
		rx_writel(dev, MUnit.IMRx[0], paddr);
		rx_sync_cmd(dev, COMMAND_POST_RESULTS, baddr, 0, 0, 0, 0, 0,
		  NULL, NULL, NULL, NULL, NULL);
		dma_free_coherent(&dev->pdev->dev, sizeof(struct POSTSTATUS),
				  post, paddr);
		if (likely((buffer[0] == '0') && ((buffer[1] == 'x') || (buffer[1] == 'X')))) {
			ret = (hex_to_bin(buffer[2]) << 4) +
				hex_to_bin(buffer[3]);
		}
		dma_free_coherent(&dev->pdev->dev, 512, buffer, baddr);
		return ret;
	}
	/*
	 *	Wait for the adapter to be up and running.
	 */
	if (unlikely(!(status & KERNEL_UP_AND_RUNNING)))
		return -3;
	/*
	 *	Everything is OK
	 */
	return 0;
}