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
typedef  int /*<<< orphan*/  u64 ;

/* Variables and functions */
 int ECC_MAX_DIGITS ; 
 int /*<<< orphan*/  vli_mod_mult_fast (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  vli_mod_square_fast (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  vli_mod_sub (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  vli_set (int /*<<< orphan*/ *,int /*<<< orphan*/ *,unsigned int) ; 

__attribute__((used)) static void xycz_add(u64 *x1, u64 *y1, u64 *x2, u64 *y2, u64 *curve_prime,
		     unsigned int ndigits)
{
	/* t1 = X1, t2 = Y1, t3 = X2, t4 = Y2 */
	u64 t5[ECC_MAX_DIGITS];

	/* t5 = x2 - x1 */
	vli_mod_sub(t5, x2, x1, curve_prime, ndigits);
	/* t5 = (x2 - x1)^2 = A */
	vli_mod_square_fast(t5, t5, curve_prime, ndigits);
	/* t1 = x1*A = B */
	vli_mod_mult_fast(x1, x1, t5, curve_prime, ndigits);
	/* t3 = x2*A = C */
	vli_mod_mult_fast(x2, x2, t5, curve_prime, ndigits);
	/* t4 = y2 - y1 */
	vli_mod_sub(y2, y2, y1, curve_prime, ndigits);
	/* t5 = (y2 - y1)^2 = D */
	vli_mod_square_fast(t5, y2, curve_prime, ndigits);

	/* t5 = D - B */
	vli_mod_sub(t5, t5, x1, curve_prime, ndigits);
	/* t5 = D - B - C = x3 */
	vli_mod_sub(t5, t5, x2, curve_prime, ndigits);
	/* t3 = C - B */
	vli_mod_sub(x2, x2, x1, curve_prime, ndigits);
	/* t2 = y1*(C - B) */
	vli_mod_mult_fast(y1, y1, x2, curve_prime, ndigits);
	/* t3 = B - x3 */
	vli_mod_sub(x2, x1, t5, curve_prime, ndigits);
	/* t4 = (y2 - y1)*(B - x3) */
	vli_mod_mult_fast(y2, y2, x2, curve_prime, ndigits);
	/* t4 = y3 */
	vli_mod_sub(y2, y2, y1, curve_prime, ndigits);

	vli_set(x2, t5, ndigits);
}