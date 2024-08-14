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
struct scaler_context {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SCALER_INT_EN ; 
 int /*<<< orphan*/  scaler_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void scaler_disable_int(struct scaler_context *scaler)
{
	scaler_write(0, SCALER_INT_EN);
}