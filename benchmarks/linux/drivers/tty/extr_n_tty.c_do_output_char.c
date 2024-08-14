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
struct tty_struct {TYPE_1__* ops; struct n_tty_data* disc_data; } ;
struct n_tty_data {int column; int canon_column; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* write ) (struct tty_struct*,char*,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  O_OCRNL (struct tty_struct*) ; 
 int /*<<< orphan*/  O_OLCUC (struct tty_struct*) ; 
 int /*<<< orphan*/  O_ONLCR (struct tty_struct*) ; 
 int /*<<< orphan*/  O_ONLRET (struct tty_struct*) ; 
 int /*<<< orphan*/  O_ONOCR (struct tty_struct*) ; 
 int /*<<< orphan*/  O_TABDLY (struct tty_struct*) ; 
 int /*<<< orphan*/  XTABS ; 
 int /*<<< orphan*/  is_continuation (unsigned char,struct tty_struct*) ; 
 int /*<<< orphan*/  iscntrl (unsigned char) ; 
 int /*<<< orphan*/  stub1 (struct tty_struct*,char*,int) ; 
 int /*<<< orphan*/  stub2 (struct tty_struct*,char*,int) ; 
 unsigned char toupper (unsigned char) ; 
 int /*<<< orphan*/  tty_put_char (struct tty_struct*,unsigned char) ; 

__attribute__((used)) static int do_output_char(unsigned char c, struct tty_struct *tty, int space)
{
	struct n_tty_data *ldata = tty->disc_data;
	int	spaces;

	if (!space)
		return -1;

	switch (c) {
	case '\n':
		if (O_ONLRET(tty))
			ldata->column = 0;
		if (O_ONLCR(tty)) {
			if (space < 2)
				return -1;
			ldata->canon_column = ldata->column = 0;
			tty->ops->write(tty, "\r\n", 2);
			return 2;
		}
		ldata->canon_column = ldata->column;
		break;
	case '\r':
		if (O_ONOCR(tty) && ldata->column == 0)
			return 0;
		if (O_OCRNL(tty)) {
			c = '\n';
			if (O_ONLRET(tty))
				ldata->canon_column = ldata->column = 0;
			break;
		}
		ldata->canon_column = ldata->column = 0;
		break;
	case '\t':
		spaces = 8 - (ldata->column & 7);
		if (O_TABDLY(tty) == XTABS) {
			if (space < spaces)
				return -1;
			ldata->column += spaces;
			tty->ops->write(tty, "        ", spaces);
			return spaces;
		}
		ldata->column += spaces;
		break;
	case '\b':
		if (ldata->column > 0)
			ldata->column--;
		break;
	default:
		if (!iscntrl(c)) {
			if (O_OLCUC(tty))
				c = toupper(c);
			if (!is_continuation(c, tty))
				ldata->column++;
		}
		break;
	}

	tty_put_char(tty, c);
	return 1;
}