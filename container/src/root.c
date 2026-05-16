#include "common.h"

int32_t main(int32_t argc, char_t **argv)
{
    uid_t id = getuid();

    struct passwd *passwd = getpwuid(id);

    if (!passwd || !passwd->pw_dir)
    {
        error("Cannot read the home directory of user: %d.", id);
    }

    const char_t *relative = "/.local/bin/local-container";

    size_t length =
        strlen(passwd->pw_dir) +
        strlen(relative) + 1;

    char_t *path = malloc(length);

    sprintf(path, "%s%s", passwd->pw_dir, relative);

    if (setuid(0) != 0)
    {
        error("Cannot set the user id to 0 for %s.", passwd->pw_name);
    }

    int32_t count = argc + 1;

    char_t **arguments = malloc(count * sizeof(char_t *));

    arguments[0] = path;

    for (int32_t index = 1; index < argc; ++index)
    {
        arguments[index] = argv[index];
    }

    arguments[argc] = NULL;

    execv(path, arguments);

    free(arguments);
    free(path);
}
