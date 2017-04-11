#include <stdio.h>
#include <string.h>
#include <glib.h>

/* Prints a key-value pair in the hash table */
void print_word_count (gpointer key, gpointer value, gpointer format_str) {
	printf(format_str, key, value);
}

int main(int argc, char** argv) {
	// Instantiates a GLib hash table with string keys
	GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
	FILE *file;
	char buff[1000];

	// Opens the file supplied by the user
	file = fopen(argv[1], "r");
	// Exits if invalid filename
	if (!file) {
		printf("Invalid file name.\n");
		return 1;
	}

	int curr_count = 0;
	// Iterates through words in given file
	while (fscanf(file, "%s", buff) == 1) {
		// Looks up current word in hash table
		curr_count = GPOINTER_TO_INT(g_hash_table_lookup(hash, buff));		
		
		// g_hash_table_insert handles both of these cases:
		// If current word exists in table, increment its word count
		// Otherwise, insert word with a word count of 1
		g_hash_table_insert(hash, strdup(buff), GINT_TO_POINTER(curr_count+1));
	}

	// Iterate through each entry in the hash table and call print_word_count
	g_hash_table_foreach(hash, (GHFunc)print_word_count, "%s: %i\n");
	fclose(file);
	return 0;
}