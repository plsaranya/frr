
void pim6_cmd_init(void) {
	return;
}

/* This is just an entry point, we have v4 and v6 common code */
void pim_cmd_init(void) {

	pim6_cmd_init();

	return;
}
