#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int ush ;
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_4__ {int Len; int Code; } ;
typedef  TYPE_1__ ct_data ;

/* Variables and functions */
 int /*<<< orphan*/  Assert (int,char*) ; 
 int MAX_BITS ; 
 int /*<<< orphan*/  Tracecv (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Tracev (int /*<<< orphan*/ ) ; 
 int bitrev32 (int /*<<< orphan*/ ) ; 
 scalar_t__ isgraph (int) ; 
 TYPE_1__* static_ltree ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static void gen_codes(
	ct_data *tree,             /* the tree to decorate */
	int max_code,              /* largest code with non zero frequency */
	ush *bl_count             /* number of codes at each bit length */
)
{
    ush next_code[MAX_BITS+1]; /* next code value for each bit length */
    ush code = 0;              /* running code value */
    int bits;                  /* bit index */
    int n;                     /* code index */

    /* The distribution counts are first used to generate the code values
     * without bit reversal.
     */
    for (bits = 1; bits <= MAX_BITS; bits++) {
        next_code[bits] = code = (code + bl_count[bits-1]) << 1;
    }
    /* Check that the bit counts in bl_count are consistent. The last code
     * must be all ones.
     */
    Assert (code + bl_count[MAX_BITS]-1 == (1<<MAX_BITS)-1,
            "inconsistent bit counts");
    Tracev((stderr,"\ngen_codes: max_code %d ", max_code));

    for (n = 0;  n <= max_code; n++) {
        int len = tree[n].Len;
        if (len == 0) continue;
        /* Now reverse the bits */
        tree[n].Code = bitrev32((u32)(next_code[len]++)) >> (32 - len);

        Tracecv(tree != static_ltree, (stderr,"\nn %3d %c l %2d c %4x (%x) ",
             n, (isgraph(n) ? n : ' '), len, tree[n].Code, next_code[len]-1));
    }
}