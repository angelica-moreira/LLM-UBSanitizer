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
struct seq_oss_devinfo {int /*<<< orphan*/  cseq; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_seq_client_ioctl_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_seq_client_ioctl_unlock (int /*<<< orphan*/ ) ; 
 int snd_seq_kernel_client_ctl (int /*<<< orphan*/ ,unsigned int,void*) ; 

__attribute__((used)) static inline int
snd_seq_oss_control(struct seq_oss_devinfo *dp, unsigned int type, void *arg)
{
	int err;

	snd_seq_client_ioctl_lock(dp->cseq);
	err = snd_seq_kernel_client_ctl(dp->cseq, type, arg);
	snd_seq_client_ioctl_unlock(dp->cseq);
	return err;
}