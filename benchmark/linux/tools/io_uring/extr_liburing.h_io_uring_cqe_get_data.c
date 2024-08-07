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
struct io_uring_cqe {scalar_t__ user_data; } ;

/* Variables and functions */

__attribute__((used)) static inline void *io_uring_cqe_get_data(struct io_uring_cqe *cqe)
{
	return (void *) (uintptr_t) cqe->user_data;
}