#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct tcf_ematch {int dummy; } ;
struct TYPE_2__ {scalar_t__ config; } ;

/* Variables and functions */
 TYPE_1__* EM_TEXT_PRIV (struct tcf_ematch*) ; 
 int /*<<< orphan*/  textsearch_destroy (scalar_t__) ; 

__attribute__((used)) static void em_text_destroy(struct tcf_ematch *m)
{
	if (EM_TEXT_PRIV(m) && EM_TEXT_PRIV(m)->config)
		textsearch_destroy(EM_TEXT_PRIV(m)->config);
}