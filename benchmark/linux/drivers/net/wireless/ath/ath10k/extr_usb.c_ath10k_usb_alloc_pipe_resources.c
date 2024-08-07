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
struct ath10k_usb_pipe {int /*<<< orphan*/  urb_alloc; int /*<<< orphan*/  usb_pipe_handle; int /*<<< orphan*/  logical_pipe_num; int /*<<< orphan*/  urb_submitted; int /*<<< orphan*/  urb_list_head; } ;
struct ath10k_urb_context {struct ath10k_usb_pipe* pipe; } ;
struct ath10k {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATH10K_DBG_USB ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ath10k_dbg (struct ath10k*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ath10k_usb_free_urb_to_pipe (struct ath10k_usb_pipe*,struct ath10k_urb_context*) ; 
 int /*<<< orphan*/  init_usb_anchor (int /*<<< orphan*/ *) ; 
 struct ath10k_urb_context* kzalloc (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ath10k_usb_alloc_pipe_resources(struct ath10k *ar,
					   struct ath10k_usb_pipe *pipe,
					   int urb_cnt)
{
	struct ath10k_urb_context *urb_context;
	int i;

	INIT_LIST_HEAD(&pipe->urb_list_head);
	init_usb_anchor(&pipe->urb_submitted);

	for (i = 0; i < urb_cnt; i++) {
		urb_context = kzalloc(sizeof(*urb_context), GFP_KERNEL);
		if (!urb_context)
			return -ENOMEM;

		urb_context->pipe = pipe;

		/* we are only allocate the urb contexts here, the actual URB
		 * is allocated from the kernel as needed to do a transaction
		 */
		pipe->urb_alloc++;
		ath10k_usb_free_urb_to_pipe(pipe, urb_context);
	}

	ath10k_dbg(ar, ATH10K_DBG_USB,
		   "usb alloc resources lpipe %d hpipe 0x%x urbs %d\n",
		   pipe->logical_pipe_num, pipe->usb_pipe_handle,
		   pipe->urb_alloc);

	return 0;
}