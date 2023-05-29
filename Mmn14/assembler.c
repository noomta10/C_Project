#define _CRT_SECURE_NO_WARNINGS
#include "assembler.h" 

static boolean process_file(char* file_name);

int main(int argc, char* argv[]) {
	int i;
	/* To break line if needed */
	boolean succeeded = TRUE;
	/* Process each file by arguments */
	for (i = 1; i < argc; ++i) {
		/* if last process failed and there's another file, break line: */
		if (!succeeded) puts("");
		/* foreach argument (file name), send it for full processing. */
		succeeded = process_file(argv[i]);
		/* Line break if failed */
	}
	return 0;
}



static boolean process_file(char* file_name) {
	FILE* file_pointer = NULL;

	/* Concatenate '.as' postfix to file name */
	char* full_file_name = add_file_postfix(file_name, ".as");

	printf("%s\n", full_file_name);

	file_pointer = fopen(full_file_name, "r");
	if (file_pointer == NULL) {
		printf("Error: The file %s couldn't be opened\n", full_file_name);
		free(full_file_name);
		return FALSE;
	}

	free(full_file_name);
	return TRUE;
}