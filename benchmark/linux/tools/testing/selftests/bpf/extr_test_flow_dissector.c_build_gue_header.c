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
typedef  int /*<<< orphan*/  uint8_t ;
struct guehdr {int /*<<< orphan*/  proto_ctype; } ;

/* Variables and functions */

__attribute__((used)) static void build_gue_header(void *header, uint8_t proto)
{
	struct guehdr *gueh = header;

	gueh->proto_ctype = proto;
}