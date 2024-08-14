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
struct qed_hwfn {int /*<<< orphan*/  cdev; } ;
struct aeu_invert_reg_bit {int flags; } ;

/* Variables and functions */
 int ATTENTION_BB_DIFFERENT ; 
 size_t ATTENTION_BB_MASK ; 
 size_t ATTENTION_BB_SHIFT ; 
 int /*<<< orphan*/  QED_IS_BB (int /*<<< orphan*/ ) ; 
 struct aeu_invert_reg_bit* aeu_descs_special ; 

__attribute__((used)) static struct aeu_invert_reg_bit *
qed_int_aeu_translate(struct qed_hwfn *p_hwfn,
		      struct aeu_invert_reg_bit *p_bit)
{
	if (!QED_IS_BB(p_hwfn->cdev))
		return p_bit;

	if (!(p_bit->flags & ATTENTION_BB_DIFFERENT))
		return p_bit;

	return &aeu_descs_special[(p_bit->flags & ATTENTION_BB_MASK) >>
				  ATTENTION_BB_SHIFT];
}