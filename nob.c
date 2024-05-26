#define NOB_IMPLEMENTATION
#include "./thirdparty/nob.h"

#define BUILD_DIR "./build"

bool build_exe(Nob_Cmd *cmd, const char *input_path, const char *output_path, bool no_warnings)
{
    cmd->count = 0;
    nob_cmd_append(cmd, "gcc");
    if (no_warnings) {
        nob_cmd_append(cmd, "-w");
    } else {
        nob_cmd_append(cmd, "-Wall", "-Wextra");
    }
    nob_cmd_append(cmd, "-I./thirdparty/");
    nob_cmd_append(cmd, input_path);
    nob_cmd_append(cmd, "-o", output_path);
    nob_cmd_append(cmd, "-lm");
    return nob_cmd_run_sync(*cmd);
}

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);

    if (!nob_mkdir_if_not_exists(BUILD_DIR)) return 1;

    Nob_Cmd cmd = {0};
    if (!build_exe(&cmd, "./conway.orig.c",  BUILD_DIR"/conway.orig",  false)) return 1;
    if (!build_exe(&cmd, "./conway.obfus.c", BUILD_DIR"/conway.obfus", true))  return 1;
    if (!build_exe(&cmd, "./conway.c",       BUILD_DIR"/conway",       true))  return 1;
    if (!build_exe(&cmd, "./imgformat.c",    BUILD_DIR"/imgformat",    false)) return 1;
    return 0;
}
