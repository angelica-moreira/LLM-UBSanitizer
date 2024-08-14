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
struct TYPE_2__ {int /*<<< orphan*/ * scp_data; int /*<<< orphan*/  scp_data_len; } ;
struct ipl_parameter_block {TYPE_1__ fcp; } ;

/* Variables and functions */
 int /*<<< orphan*/  isascii (int /*<<< orphan*/ ) ; 
 scalar_t__ islower (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (char*,int /*<<< orphan*/ *,size_t) ; 
 size_t min (size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  scpdata_length (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 char tolower (int /*<<< orphan*/ ) ; 

__attribute__((used)) static size_t ipl_block_get_ascii_scpdata(char *dest, size_t size,
					  const struct ipl_parameter_block *ipb)
{
	size_t count;
	size_t i;
	int has_lowercase;

	count = min(size - 1, scpdata_length(ipb->fcp.scp_data,
					     ipb->fcp.scp_data_len));
	if (!count)
		goto out;

	has_lowercase = 0;
	for (i = 0; i < count; i++) {
		if (!isascii(ipb->fcp.scp_data[i])) {
			count = 0;
			goto out;
		}
		if (!has_lowercase && islower(ipb->fcp.scp_data[i]))
			has_lowercase = 1;
	}

	if (has_lowercase)
		memcpy(dest, ipb->fcp.scp_data, count);
	else
		for (i = 0; i < count; i++)
			dest[i] = tolower(ipb->fcp.scp_data[i]);
out:
	dest[count] = '\0';
	return count;
}