#include <pg_query.h>
#include <pg_query_fingerprint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fingerprint_tests.c"

int main()
{
	size_t i;
	bool ret_code = 0;

	for (i = 0; i < testsLength; i += 2)
	{
		PgQueryFingerprintResult result = pg_query_fingerprint(tests[i]);

		if (result.error)
		{
			ret_code = -1;
			printf("%s\n", result.error->message);
			pg_query_free_fingerprint_result(result);
			continue;
		}

		// This is intentionally malloc-ed and will survive exiting the memory context
		char *actual;
		int err = asprintf(&actual, "%llx", result.fingerprint);
		if (err == -1)
		{
			ret_code = -1;
			printf("ERROR - asprintf failed\n");
			pg_query_free_fingerprint_result(result);
			continue;
		}

		if (strcmp(actual, tests[i + 1]) == 0)
		{
			printf(".");
		}
		else
		{
			ret_code = -1;
			printf("INVALID result for \"%s\"\nexpected: \"%s\"\nactual: \"%s\"\nactual tokens: ", tests[i], tests[i + 1], actual);
			pg_query_fingerprint_with_opts(tests[i], true);
		}

		free(actual);
		pg_query_free_fingerprint_result(result);
		}

	printf("\n");

	pg_query_exit();

	return ret_code;
}
