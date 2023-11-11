/*-
 * Copyright (c) 2023, Collin Funk
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <config.h>

#include <errno.h>
#include <stddef.h>
#include <string.h>

/* This function may return NULL on some OS-specific error numbers. */
const char *
strerrordesc_np (int errnum)
{
  switch (errnum)
    {
/* Error numbers required by C99. */
#if defined(EDOM)
    case EDOM:
      return "Numerical argument out of domain";
#endif
#if defined(EILSEQ)
    case EILSEQ:
      return "Invalid or incomplete multibyte or wide character";
#endif
#if defined(ERANGE)
    case ERANGE:
      return "Numerical result out of range";
#endif
/* Error numbers required by POSIX.1-2017. */
#if defined(E2BIG)
    case E2BIG:
      return "Argument list too long";
#endif
#if defined(EACCES)
    case EACCES:
      return "Permission denied";
#endif
#if defined(EADDRINUSE)
    case EADDRINUSE:
      return "Address already in use";
#endif
#if defined(EADDRNOTAVAIL)
    case EADDRNOTAVAIL:
      return "Cannot assign requested address";
#endif
#if defined(EAFNOSUPPORT)
    case EAFNOSUPPORT:
      return "Address family not supported by protocol";
#endif
#if defined(EAGAIN)
    case EAGAIN:
      return "Resource temporarily unavailable";
#endif
#if defined(EALREADY)
    case EALREADY:
      return "Operation already in progress";
#endif
#if defined(EBADF)
    case EBADF:
      return "Bad file descriptor";
#endif
#if defined(EBADMSG)
    case EBADMSG:
      return "Bad message";
#endif
#if defined(EBUSY)
    case EBUSY:
      return "Device or resource busy";
#endif
#if defined(ECANCELED)
    case ECANCELED:
      return "Operation canceled";
#endif
#if defined(ECHILD)
    case ECHILD:
      return "No child processes";
#endif
#if defined(ECONNABORTED)
    case ECONNABORTED:
      return "Software caused connection abort";
#endif
#if defined(ECONNREFUSED)
    case ECONNREFUSED:
      return "Connection refused";
#endif
#if defined(ECONNRESET)
    case ECONNRESET:
      return "Connection reset by peer";
#endif
#if defined(EDEADLK)
    case EDEADLK:
      return "Deadlock";
#endif
#if defined(EDESTADDRREQ)
    case EDESTADDRREQ:
      return "Destination address required";
#endif
#if defined(EDQUOT)
    case EDQUOT:
      return "Disk quota exceeded";
#endif
#if defined(EEXIST)
    case EEXIST:
      return "File exists";
#endif
#if defined(EFAULT)
    case EFAULT:
      return "Bad address";
#endif
#if defined(EFBIG)
    case EFBIG:
      return "File too large";
#endif
#if defined(EHOSTUNREACH)
    case EHOSTUNREACH:
      return "No route to host";
#endif
#if defined(EIDRM)
    case EIDRM:
      return "Identifier removed";
#endif
#if defined(EINPROGRESS)
    case EINPROGRESS:
      return "Operation in progress";
#endif
#if defined(EINTR)
    case EINTR:
      return "Interrupted system call";
#endif
#if defined(EINVAL)
    case EINVAL:
      return "Invalid argument";
#endif
#if defined(EIO)
    case EIO:
      return "Input/output error";
#endif
#if defined(EISCONN)
    case EISCONN:
      return "Transpoint endpoint is already connected";
#endif
#if defined(EISDIR)
    case EISDIR:
      return "Is a directory";
#endif
#if defined(ELOOP)
    case ELOOP:
      return "Too many levels of symbolic links";
#endif
#if defined(EMFILE)
    case EMFILE:
      return "Too many open files";
#endif
#if defined(EMLINK)
    case EMLINK:
      return "Too many links";
#endif
#if defined(EMSGSIZE)
    case EMSGSIZE:
      return "Message too long";
#endif
#if defined(EMULTIHOP)
    case EMULTIHOP:
      return "Multihop attempted";
#endif
#if defined(ENAMETOOLONG)
    case ENAMETOOLONG:
      return "File name too long";
#endif
#if defined(ENETDOWN)
    case ENETDOWN:
      return "Network is down";
#endif
#if defined(ENETRESET)
    case ENETRESET:
      return "Network dropped connection on reset";
#endif
#if defined(ENETUNREACH)
    case ENETUNREACH:
      return "Network is unreachable";
#endif
#if defined(ENFILE)
    case ENFILE:
      return "Too many open files in system";
#endif
#if defined(ENOBUFS)
    case ENOBUFS:
      return "No buffer space avaliable";
#endif
#if defined(ENODATA)
    case ENODATA:
      return "No data avaliable";
#endif
#if defined(ENODEV)
    case ENODEV:
      return "No such device";
#endif
#if defined(ENOENT)
    case ENOENT:
      return "No such file or directory";
#endif
#if defined(ENOEXEC)
    case ENOEXEC:
      return "Exec format error";
#endif
#if defined(ENOLCK)
    case ENOLCK:
      return "No locks avaliable";
#endif
#if defined(ENOLINK)
    case ENOLINK:
      return "Link has been served";
#endif
#if defined(ENOMEM)
    case ENOMEM:
      return "Out of memory";
#endif
#if defined(ENOMSG)
    case ENOMSG:
      return "No message of desired type";
#endif
#if defined(ENOPROTOOPT)
    case ENOPROTOOPT:
      return "Protocol not avaliable";
#endif
#if defined(ENOSPC)
    case ENOSPC:
      return "No space left on device";
#endif
#if defined(ENOSR)
    case ENOSR:
      return "Out of streams resources";
#endif
#if defined(ENOSTR)
    case ENOSTR:
      return "Device is not a stream";
#endif
#if defined(ENOSYS)
    case ENOSYS:
      return "Unsupported";
#endif
#if defined(ENOTCONN)
    case ENOTCONN:
      return "Transport endpoint is not connected";
#endif
#if defined(ENOTDIR)
    case ENOTDIR:
      return "Not a directory";
#endif
#if defined(ENOTEMPTY)
    case ENOTEMPTY:
      return "Directory not empty";
#endif
#if defined(ENOTRECOVERABLE)
    case ENOTRECOVERABLE:
      return "State not recoverable";
#endif
#if defined(ENOTSOCK)
    case ENOTSOCK:
      return "Socket operation on a non-socket";
#endif
/* May be the same value as EOPNOTSUPP. */
#if defined(ENOTSUP) && ENOTSUP != EOPNOTSUPP
    case ENOTSUP:
      return "Not supported";
#endif
#if defined(ENOTTY)
    case ENOTTY:
      return "No tty";
#endif
#if defined(ENXIO)
    case ENXIO:
      return "No such device";
#endif
#if defined(EOPNOTSUPP)
    case EOPNOTSUPP:
      return "Operation not supported";
#endif
#if defined(EOVERFLOW)
    case EOVERFLOW:
      return "Value too large for data type";
#endif
#if defined(EOWNERDEAD)
    case EOWNERDEAD:
      return "Owner died";
#endif
#if defined(EPERM)
    case EPERM:
      return "Operation not permitted";
#endif
#if defined(EPIPE)
    case EPIPE:
      return "Broken pipe";
#endif
#if defined(EPROTO)
    case EPROTO:
      return "Protocol error";
#endif
#if defined(EPROTONOSUPPORT)
    case EPROTONOSUPPORT:
      return "Protocol not supported";
#endif
#if defined(EPROTOTYPE)
    case EPROTOTYPE:
      return "Protocol wrong type for socket";
#endif
#if defined(EROFS)
    case EROFS:
      return "Read-only file system";
#endif
#if defined(ESPIPE)
    case ESPIPE:
      return "Illegal seek";
#endif
#if defined(ESRCH)
    case ESRCH:
      return "No such process";
#endif
#if defined(ESTALE)
    case ESTALE:
      return "Stale file handle";
#endif
#if defined(ETIME)
    case ETIME:
      return "Timer expired";
#endif
#if defined(ETIMEDOUT)
    case ETIMEDOUT:
      return "Connection timed out";
#endif
#if defined(ETXTBSY)
    case ETXTBSY:
      return "Text file busy";
#endif
/* May be the same value as EAGAIN. */
#if defined(EWOULDBLOCK) && EWOULDBLOCK != EAGAIN
    case EWOULDBLOCK:
      return "Resource temporarily unavailable";
#endif
#if defined(EXDEV)
    case EXDEV:
      return "Invalid cross-device link";
#endif
    default:
      return NULL;
    }
  return NULL;
}
