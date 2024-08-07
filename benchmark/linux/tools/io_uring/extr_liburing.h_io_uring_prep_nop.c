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
struct io_uring_sqe {int /*<<< orphan*/  opcode; } ;

/* Variables and functions */
 int /*<<< orphan*/  IORING_OP_NOP ; 
 int /*<<< orphan*/  memset (struct io_uring_sqe*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void io_uring_prep_nop(struct io_uring_sqe *sqe)
{
	memset(sqe, 0, sizeof(*sqe));
	sqe->opcode = IORING_OP_NOP;
}