/* Copyright (C) 2015-2021, Wazuh Inc.
 * All right reserved.
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 2) as published by the FSF - Free Software
 * Foundation.
 */

#include "active_responses.h"

int main (int argc, char **argv) {
    (void)argc;
    char args[COMMANDSIZE];
    char log_msg[LOGSIZE];
    char *command_ex = NULL;
    int action = OS_INVALID;
    cJSON *input_json = NULL;
    struct utsname uname_buffer;

    action = setup_and_check_message(argv, &input_json);
    if ((action != ADD_COMMAND) && (action != DELETE_COMMAND)) {
        return OS_INVALID;
    }

    // Detect username
    const char *user = get_username_from_json(input_json);
    if (!user) {
        write_debug_file(argv[0], "Cannot read 'dstuser' from data");
        cJSON_Delete(input_json);
        return OS_INVALID;
    }

    if (action == ADD_COMMAND) {
        char **keys = NULL;
        int action2 = OS_INVALID;

        os_calloc(2, sizeof(char *), keys);
        os_strdup(user, keys[0]);
        keys[1] = NULL;

        action2 = send_keys_and_check_message(argv, keys);

        os_free(keys);

        // If necessary, abort execution
        if (action2 != CONTINUE_COMMAND) {
            cJSON_Delete(input_json);

            if (action2 == ABORT_COMMAND) {
                write_debug_file(argv[0], "Aborted");
                return OS_SUCCESS;
            } else {
                return OS_INVALID;
            }
        }
    }

    if (!strcmp("root", user)) {
        write_debug_file(argv[0], "Invalid username");
        cJSON_Delete(input_json);
        return OS_INVALID;
    }

    if (uname(&uname_buffer) < 0) {
        write_debug_file(argv[0], "Cannot get system name");
        cJSON_Delete(input_json);
        return OS_INVALID;
    }

    if (!strcmp("Linux", uname_buffer.sysname) || !strcmp("SunOS", uname_buffer.sysname)) {
        // Checking if passwd is present
        if (access(PASSWD, F_OK) < 0) {
            memset(log_msg, '\0', LOGSIZE);
            snprintf(log_msg, LOGSIZE - 1, "The passwd file '%s' is not accessible: %s (%d)", PASSWD, strerror(errno), errno);
            write_debug_file(argv[0], log_msg);
            cJSON_Delete(input_json);
            return OS_SUCCESS;
        }

        os_strdup(PASSWD, command_ex);
        memset(args, '\0', COMMANDSIZE);
        if (action == ADD_COMMAND) {
            snprintf(args, COMMANDSIZE -1, "-l");
        } else {
            snprintf(args, COMMANDSIZE -1, "-u");
        }

    } else if (!strcmp("AIX", uname_buffer.sysname)) {
        // Checking if chuser is present
        if (access(CHUSER, F_OK) < 0) {
            memset(log_msg, '\0', LOGSIZE);
            snprintf(log_msg, LOGSIZE - 1, "The chuser file '%s' is not accessible: %s (%d)", CHUSER, strerror(errno), errno);
            write_debug_file(argv[0], log_msg);
            cJSON_Delete(input_json);
            return OS_SUCCESS;
        }

        os_strdup(CHUSER, command_ex);
        // Disabling an account
        memset(args, '\0', COMMANDSIZE);
        if (action == ADD_COMMAND) {
            snprintf(args, COMMANDSIZE -1, "account_locked=true");
        } else {
            snprintf(args, COMMANDSIZE -1, "account_locked=false");
        }

    } else {
        write_debug_file(argv[0], "Invalid system");
        cJSON_Delete(input_json);
        return OS_SUCCESS;
    }

    // Execute the command
    char *exec_cmd1[4] = { NULL, NULL, NULL, NULL };

    const char *arg1[4] = { command_ex, args, user, NULL };
    memcpy(exec_cmd1, arg1, sizeof(exec_cmd1));

    wfd_t *wfd = wpopenv(command_ex, exec_cmd1, W_BIND_STDERR);
    if (!wfd) {
        memset(log_msg, '\0', LOGSIZE);
        snprintf(log_msg, LOGSIZE -1, "Error executing '%s': %s", command_ex, strerror(errno));
        write_debug_file(argv[0], log_msg);
        cJSON_Delete(input_json);
        os_free(command_ex);
        return OS_INVALID;
    }
    wpclose(wfd);

    write_debug_file(argv[0], "Ended");

    cJSON_Delete(input_json);
    os_free(command_ex);

    return OS_SUCCESS;
}
