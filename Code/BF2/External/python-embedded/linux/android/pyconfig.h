/* Android (bionic, arm64-v8a) overlay for the Linux x86-64 pyconfig.h beside it.
 *
 * Found first via the include path (see CMakeLists.txt), then pulls in configure's real
 * pyconfig.h and corrects only what differs on bionic. arm64-v8a is LP64 and little-endian like
 * x86-64, so the type sizes carry over except fpos_t. [CHOSEN, not recovered] */
#ifndef BF2_ANDROID_PYCONFIG_OVERLAY_H
#define BF2_ANDROID_PYCONFIG_OVERLAY_H

#include_next "pyconfig.h"

/* bionic: fpos_t is a plain 8-byte off_t, not glibc's 16-byte struct. */
#undef SIZEOF_FPOS_T
#define SIZEOF_FPOS_T 8

/* bionic has no libutil/pty.h/stropts.h; skip os.openpty/forkpty and STREAMS code paths. */
#undef HAVE_PTY_H
#undef HAVE_LIBUTIL_H
#undef HAVE_STROPTS_H
#undef HAVE_OPENPTY
#undef HAVE_FORKPTY

#endif /* BF2_ANDROID_PYCONFIG_OVERLAY_H */
