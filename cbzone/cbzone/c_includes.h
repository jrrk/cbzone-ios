#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <signal.h>
#include <errno.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <sys/file.h>
#include <sys/wait.h>
#include <sys/time.h>


#ifdef X11
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>
#include <X11/Shell.h>
#else
#define X11
#include "draw.h"
#include "missing.h"

typedef int Bool;

enum {False,True};

#endif

#include "c_defs.h"
#include "c_colors.h"
#include "c_structs.h"
#include "c_config.h"
#include "c_externs.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
};
#endif
