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
typedef  int /*<<< orphan*/  WINDOW ;

/* Variables and functions */
 int /*<<< orphan*/  MAX_LEN ; 
 int /*<<< orphan*/  getyx (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 
 int strlen (char*) ; 
 char* strpbrk (char*,char*) ; 
 int /*<<< orphan*/  waddstr (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  wmove (int /*<<< orphan*/ *,int,int) ; 

void print_autowrap(WINDOW * win, const char *prompt, int width, int y, int x)
{
	int newl, cur_x, cur_y;
	int prompt_len, room, wlen;
	char tempstr[MAX_LEN + 1], *word, *sp, *sp2, *newline_separator = 0;

	strcpy(tempstr, prompt);

	prompt_len = strlen(tempstr);

	if (prompt_len <= width - x * 2) {	/* If prompt is short */
		wmove(win, y, (width - prompt_len) / 2);
		waddstr(win, tempstr);
	} else {
		cur_x = x;
		cur_y = y;
		newl = 1;
		word = tempstr;
		while (word && *word) {
			sp = strpbrk(word, "\n ");
			if (sp && *sp == '\n')
				newline_separator = sp;

			if (sp)
				*sp++ = 0;

			/* Wrap to next line if either the word does not fit,
			   or it is the first word of a new sentence, and it is
			   short, and the next word does not fit. */
			room = width - cur_x;
			wlen = strlen(word);
			if (wlen > room ||
			    (newl && wlen < 4 && sp
			     && wlen + 1 + strlen(sp) > room
			     && (!(sp2 = strpbrk(sp, "\n "))
				 || wlen + 1 + (sp2 - sp) > room))) {
				cur_y++;
				cur_x = x;
			}
			wmove(win, cur_y, cur_x);
			waddstr(win, word);
			getyx(win, cur_y, cur_x);

			/* Move to the next line if the word separator was a newline */
			if (newline_separator) {
				cur_y++;
				cur_x = x;
				newline_separator = 0;
			} else
				cur_x++;

			if (sp && *sp == ' ') {
				cur_x++;	/* double space */
				while (*++sp == ' ') ;
				newl = 1;
			} else
				newl = 0;
			word = sp;
		}
	}
}