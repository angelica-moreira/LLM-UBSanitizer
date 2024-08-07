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
struct vcpu_svm {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  INTERCEPT_VINTR ; 
 int /*<<< orphan*/  clr_intercept (struct vcpu_svm*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void svm_clear_vintr(struct vcpu_svm *svm)
{
	clr_intercept(svm, INTERCEPT_VINTR);
}