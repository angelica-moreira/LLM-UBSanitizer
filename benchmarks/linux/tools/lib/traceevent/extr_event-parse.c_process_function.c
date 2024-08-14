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
struct tep_print_arg {int dummy; } ;
struct tep_function_handler {int dummy; } ;
struct tep_event {int /*<<< orphan*/  tep; } ;
typedef  enum tep_event_type { ____Placeholder_tep_event_type } tep_event_type ;

/* Variables and functions */
 int TEP_EVENT_ERROR ; 
 int /*<<< orphan*/  do_warning_event (struct tep_event*,char*,char*) ; 
 struct tep_function_handler* find_func_handler (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  free_token (char*) ; 
 int is_flag_field ; 
 int is_symbolic_field ; 
 int process_bitmask (struct tep_event*,struct tep_print_arg*,char**) ; 
 int process_dynamic_array (struct tep_event*,struct tep_print_arg*,char**) ; 
 int process_dynamic_array_len (struct tep_event*,struct tep_print_arg*,char**) ; 
 int process_flags (struct tep_event*,struct tep_print_arg*,char**) ; 
 int process_func_handler (struct tep_event*,struct tep_function_handler*,struct tep_print_arg*,char**) ; 
 int process_hex (struct tep_event*,struct tep_print_arg*,char**) ; 
 int process_hex_str (struct tep_event*,struct tep_print_arg*,char**) ; 
 int process_int_array (struct tep_event*,struct tep_print_arg*,char**) ; 
 int process_str (struct tep_event*,struct tep_print_arg*,char**) ; 
 int process_symbols (struct tep_event*,struct tep_print_arg*,char**) ; 
 scalar_t__ strcmp (char*,char*) ; 

__attribute__((used)) static enum tep_event_type
process_function(struct tep_event *event, struct tep_print_arg *arg,
		 char *token, char **tok)
{
	struct tep_function_handler *func;

	if (strcmp(token, "__print_flags") == 0) {
		free_token(token);
		is_flag_field = 1;
		return process_flags(event, arg, tok);
	}
	if (strcmp(token, "__print_symbolic") == 0) {
		free_token(token);
		is_symbolic_field = 1;
		return process_symbols(event, arg, tok);
	}
	if (strcmp(token, "__print_hex") == 0) {
		free_token(token);
		return process_hex(event, arg, tok);
	}
	if (strcmp(token, "__print_hex_str") == 0) {
		free_token(token);
		return process_hex_str(event, arg, tok);
	}
	if (strcmp(token, "__print_array") == 0) {
		free_token(token);
		return process_int_array(event, arg, tok);
	}
	if (strcmp(token, "__get_str") == 0) {
		free_token(token);
		return process_str(event, arg, tok);
	}
	if (strcmp(token, "__get_bitmask") == 0) {
		free_token(token);
		return process_bitmask(event, arg, tok);
	}
	if (strcmp(token, "__get_dynamic_array") == 0) {
		free_token(token);
		return process_dynamic_array(event, arg, tok);
	}
	if (strcmp(token, "__get_dynamic_array_len") == 0) {
		free_token(token);
		return process_dynamic_array_len(event, arg, tok);
	}

	func = find_func_handler(event->tep, token);
	if (func) {
		free_token(token);
		return process_func_handler(event, func, arg, tok);
	}

	do_warning_event(event, "function %s not defined", token);
	free_token(token);
	return TEP_EVENT_ERROR;
}