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
typedef  int /*<<< orphan*/  u8 ;
struct cword {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline u8 *rep_xcrypt_cbc(const u8 *input, u8 *output, void *key,
				 u8 *iv, struct cword *control_word, int count)
{
	asm volatile (".byte 0xf3,0x0f,0xa7,0xd0"	/* rep xcryptcbc */
		      : "+S" (input), "+D" (output), "+a" (iv)
		      : "d" (control_word), "b" (key), "c" (count));
	return iv;
}