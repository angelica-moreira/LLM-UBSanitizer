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
struct TYPE_2__ {int type; int /*<<< orphan*/  right; int /*<<< orphan*/  left; } ;
struct tep_filter_arg {TYPE_1__ op; } ;
struct tep_event_filter {int dummy; } ;

/* Variables and functions */
#define  TEP_FILTER_OP_AND 130 
#define  TEP_FILTER_OP_NOT 129 
#define  TEP_FILTER_OP_OR 128 
 char* arg_to_str (struct tep_event_filter*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  asprintf (char**,char*,...) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 

__attribute__((used)) static char *op_to_str(struct tep_event_filter *filter, struct tep_filter_arg *arg)
{
	char *str = NULL;
	char *left = NULL;
	char *right = NULL;
	char *op = NULL;
	int left_val = -1;
	int right_val = -1;
	int val;

	switch (arg->op.type) {
	case TEP_FILTER_OP_AND:
		op = "&&";
		/* fall through */
	case TEP_FILTER_OP_OR:
		if (!op)
			op = "||";

		left = arg_to_str(filter, arg->op.left);
		right = arg_to_str(filter, arg->op.right);
		if (!left || !right)
			break;

		/* Try to consolidate boolean values */
		if (strcmp(left, "TRUE") == 0)
			left_val = 1;
		else if (strcmp(left, "FALSE") == 0)
			left_val = 0;

		if (strcmp(right, "TRUE") == 0)
			right_val = 1;
		else if (strcmp(right, "FALSE") == 0)
			right_val = 0;

		if (left_val >= 0) {
			if ((arg->op.type == TEP_FILTER_OP_AND && !left_val) ||
			    (arg->op.type == TEP_FILTER_OP_OR && left_val)) {
				/* Just return left value */
				str = left;
				left = NULL;
				break;
			}
			if (right_val >= 0) {
				/* just evaluate this. */
				val = 0;
				switch (arg->op.type) {
				case TEP_FILTER_OP_AND:
					val = left_val && right_val;
					break;
				case TEP_FILTER_OP_OR:
					val = left_val || right_val;
					break;
				default:
					break;
				}
				asprintf(&str, val ? "TRUE" : "FALSE");
				break;
			}
		}
		if (right_val >= 0) {
			if ((arg->op.type == TEP_FILTER_OP_AND && !right_val) ||
			    (arg->op.type == TEP_FILTER_OP_OR && right_val)) {
				/* Just return right value */
				str = right;
				right = NULL;
				break;
			}
			/* The right value is meaningless */
			str = left;
			left = NULL;
			break;
		}

		asprintf(&str, "(%s) %s (%s)", left, op, right);
		break;

	case TEP_FILTER_OP_NOT:
		op = "!";
		right = arg_to_str(filter, arg->op.right);
		if (!right)
			break;

		/* See if we can consolidate */
		if (strcmp(right, "TRUE") == 0)
			right_val = 1;
		else if (strcmp(right, "FALSE") == 0)
			right_val = 0;
		if (right_val >= 0) {
			/* just return the opposite */
			asprintf(&str, right_val ? "FALSE" : "TRUE");
			break;
		}
		asprintf(&str, "%s(%s)", op, right);
		break;

	default:
		/* ?? */
		break;
	}
	free(left);
	free(right);
	return str;
}