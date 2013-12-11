#ifndef ERROR_H
#define ERROR_H

class Error {
public:
    static const int EPERM      = 1;
    static const int ENOENT     = 2;
    static const int ESRCH      = 3;
    static const int EINTR      = 4;
    static const int EIO        = 5;
    static const int ENXIO      = 6;
    static const int E2BIG      = 7;
    static const int ENOEXEC    = 8;
    static const int EBADF      = 9;
    static const int ECHILD     = 10;
    static const int EAGAIN     = 11;
    static const int ENOMEM     = 12;
    static const int EACCES     = 13;
    static const int EFAULT     = 14;
    static const int ENOTBLK    = 15;
    static const int EBUSY      = 16;
    static const int EEXIST     = 17;
    static const int EXDEV      = 18;
    static const int ENODEV     = 19;
    static const int ENOTDIR    = 20;
    static const int EISDIR     = 21;
    static const int EINVAL     = 22;
    static const int ENFILE     = 23;
    static const int EMFILE     = 24;
    static const int ENOTTY     = 25;
    static const int ETXTBSY    = 26;
    static const int EFBIG      = 27;
    static const int ENOSPC     = 28;
    static const int ESPIPE     = 29;
    static const int EROFS      = 30;
    static const int EMLINK     = 31;
    static const int EPIPE      = 32;
    static const int EDOM       = 33;
    static const int ERANGE     = 34;

};

#endif // ERROR_H
