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
struct intel_pt_decoder {int /*<<< orphan*/  stack; } ;

/* Variables and functions */
 int /*<<< orphan*/  free (struct intel_pt_decoder*) ; 
 int /*<<< orphan*/  intel_pt_free_stack (int /*<<< orphan*/ *) ; 

void intel_pt_decoder_free(struct intel_pt_decoder *decoder)
{
	intel_pt_free_stack(&decoder->stack);
	free(decoder);
}