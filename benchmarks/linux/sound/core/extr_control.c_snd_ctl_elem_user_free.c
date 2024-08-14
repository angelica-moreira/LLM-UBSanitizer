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
struct user_element {int /*<<< orphan*/  priv_data; int /*<<< orphan*/  tlv_data; } ;
struct snd_kcontrol {struct user_element* private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct user_element*) ; 
 int /*<<< orphan*/  kvfree (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void snd_ctl_elem_user_free(struct snd_kcontrol *kcontrol)
{
	struct user_element *ue = kcontrol->private_data;

	kvfree(ue->tlv_data);
	kvfree(ue->priv_data);
	kfree(ue);
}