#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {struct expr* expr; int /*<<< orphan*/  sym; } ;
struct TYPE_3__ {struct expr* expr; int /*<<< orphan*/  sym; } ;
struct expr {int type; TYPE_2__ right; TYPE_1__ left; } ;

/* Variables and functions */
#define  E_AND 138 
#define  E_EQUAL 137 
#define  E_GEQ 136 
#define  E_GTH 135 
#define  E_LEQ 134 
#define  E_LIST 133 
#define  E_LTH 132 
#define  E_NOT 131 
#define  E_OR 130 
#define  E_SYMBOL 129 
#define  E_UNEQUAL 128 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  free (struct expr*) ; 
 int /*<<< orphan*/  memcpy (struct expr*,struct expr const*,int) ; 
 int /*<<< orphan*/  stderr ; 
 struct expr* xmalloc (int) ; 

struct expr *expr_copy(const struct expr *org)
{
	struct expr *e;

	if (!org)
		return NULL;

	e = xmalloc(sizeof(*org));
	memcpy(e, org, sizeof(*org));
	switch (org->type) {
	case E_SYMBOL:
		e->left = org->left;
		break;
	case E_NOT:
		e->left.expr = expr_copy(org->left.expr);
		break;
	case E_EQUAL:
	case E_GEQ:
	case E_GTH:
	case E_LEQ:
	case E_LTH:
	case E_UNEQUAL:
		e->left.sym = org->left.sym;
		e->right.sym = org->right.sym;
		break;
	case E_AND:
	case E_OR:
	case E_LIST:
		e->left.expr = expr_copy(org->left.expr);
		e->right.expr = expr_copy(org->right.expr);
		break;
	default:
		fprintf(stderr, "can't copy type %d\n", e->type);
		free(e);
		e = NULL;
		break;
	}

	return e;
}