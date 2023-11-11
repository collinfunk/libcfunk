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

/* This function is glibc specific. This function does not contain all possible
   error numbers for the host system. A valid ERRNUM may result in a NULL
   pointer being returned. */

/* Do not edit this function directly. See `generate-strerrorname-np.pl'. */
const char *
strerrorname_np (int errnum)
{
  switch (errnum)
    {
/* Error numbers required by C99. */
#if defined(EDOM)
    case EDOM:
      return "EDOM";
#endif
#if defined(EILSEQ)
    case EILSEQ:
      return "EILSEQ";
#endif
#if defined(ERANGE)
    case ERANGE:
      return "ERANGE";
#endif
/* Error numbers required by POSIX.1-2017. */
#if defined(E2BIG)
    case E2BIG:
      return "E2BIG";
#endif
#if defined(EACCES)
    case EACCES:
      return "EACCES";
#endif
#if defined(EADDRINUSE)
    case EADDRINUSE:
      return "EADDRINUSE";
#endif
#if defined(EADDRNOTAVAIL)
    case EADDRNOTAVAIL:
      return "EADDRNOTAVAIL";
#endif
#if defined(EAFNOSUPPORT)
    case EAFNOSUPPORT:
      return "EAFNOSUPPORT";
#endif
#if defined(EAGAIN)
    case EAGAIN:
      return "EAGAIN";
#endif
#if defined(EALREADY)
    case EALREADY:
      return "EALREADY";
#endif
#if defined(EBADF)
    case EBADF:
      return "EBADF";
#endif
#if defined(EBADMSG)
    case EBADMSG:
      return "EBADMSG";
#endif
#if defined(EBUSY)
    case EBUSY:
      return "EBUSY";
#endif
#if defined(ECANCELED)
    case ECANCELED:
      return "ECANCELED";
#endif
#if defined(ECHILD)
    case ECHILD:
      return "ECHILD";
#endif
#if defined(ECONNABORTED)
    case ECONNABORTED:
      return "ECONNABORTED";
#endif
#if defined(ECONNREFUSED)
    case ECONNREFUSED:
      return "ECONNREFUSED";
#endif
#if defined(ECONNRESET)
    case ECONNRESET:
      return "ECONNRESET";
#endif
#if defined(EDEADLK)
    case EDEADLK:
      return "EDEADLK";
#endif
#if defined(EDESTADDRREQ)
    case EDESTADDRREQ:
      return "EDESTADDRREQ";
#endif
#if defined(EDQUOT)
    case EDQUOT:
      return "EDQUOT";
#endif
#if defined(EEXIST)
    case EEXIST:
      return "EEXIST";
#endif
#if defined(EFAULT)
    case EFAULT:
      return "EFAULT";
#endif
#if defined(EFBIG)
    case EFBIG:
      return "EFBIG";
#endif
#if defined(EHOSTUNREACH)
    case EHOSTUNREACH:
      return "EHOSTUNREACH";
#endif
#if defined(EIDRM)
    case EIDRM:
      return "EIDRM";
#endif
#if defined(EINPROGRESS)
    case EINPROGRESS:
      return "EINPROGRESS";
#endif
#if defined(EINTR)
    case EINTR:
      return "EINTR";
#endif
#if defined(EINVAL)
    case EINVAL:
      return "EINVAL";
#endif
#if defined(EIO)
    case EIO:
      return "EIO";
#endif
#if defined(EISCONN)
    case EISCONN:
      return "EISCONN";
#endif
#if defined(EISDIR)
    case EISDIR:
      return "EISDIR";
#endif
#if defined(ELOOP)
    case ELOOP:
      return "ELOOP";
#endif
#if defined(EMFILE)
    case EMFILE:
      return "EMFILE";
#endif
#if defined(EMLINK)
    case EMLINK:
      return "EMLINK";
#endif
#if defined(EMSGSIZE)
    case EMSGSIZE:
      return "EMSGSIZE";
#endif
#if defined(EMULTIHOP)
    case EMULTIHOP:
      return "EMULTIHOP";
#endif
#if defined(ENAMETOOLONG)
    case ENAMETOOLONG:
      return "ENAMETOOLONG";
#endif
#if defined(ENETDOWN)
    case ENETDOWN:
      return "ENETDOWN";
#endif
#if defined(ENETRESET)
    case ENETRESET:
      return "ENETRESET";
#endif
#if defined(ENETUNREACH)
    case ENETUNREACH:
      return "ENETUNREACH";
#endif
#if defined(ENFILE)
    case ENFILE:
      return "ENFILE";
#endif
#if defined(ENOBUFS)
    case ENOBUFS:
      return "ENOBUFS";
#endif
#if defined(ENODATA)
    case ENODATA:
      return "ENODATA";
#endif
#if defined(ENODEV)
    case ENODEV:
      return "ENODEV";
#endif
#if defined(ENOENT)
    case ENOENT:
      return "ENOENT";
#endif
#if defined(ENOEXEC)
    case ENOEXEC:
      return "ENOEXEC";
#endif
#if defined(ENOLCK)
    case ENOLCK:
      return "ENOLCK";
#endif
#if defined(ENOLINK)
    case ENOLINK:
      return "ENOLINK";
#endif
#if defined(ENOMEM)
    case ENOMEM:
      return "ENOMEM";
#endif
#if defined(ENOMSG)
    case ENOMSG:
      return "ENOMSG";
#endif
#if defined(ENOPROTOOPT)
    case ENOPROTOOPT:
      return "ENOPROTOOPT";
#endif
#if defined(ENOSPC)
    case ENOSPC:
      return "ENOSPC";
#endif
#if defined(ENOSR)
    case ENOSR:
      return "ENOSR";
#endif
#if defined(ENOSTR)
    case ENOSTR:
      return "ENOSTR";
#endif
#if defined(ENOSYS)
    case ENOSYS:
      return "ENOSYS";
#endif
#if defined(ENOTCONN)
    case ENOTCONN:
      return "ENOTCONN";
#endif
#if defined(ENOTDIR)
    case ENOTDIR:
      return "ENOTDIR";
#endif
#if defined(ENOTEMPTY)
    case ENOTEMPTY:
      return "ENOTEMPTY";
#endif
#if defined(ENOTRECOVERABLE)
    case ENOTRECOVERABLE:
      return "ENOTRECOVERABLE";
#endif
#if defined(ENOTSOCK)
    case ENOTSOCK:
      return "ENOTSOCK";
#endif
/* May be the same value as EOPNOTSUPP. */
#if defined(ENOTSUP) && ENOTSUP != EOPNOTSUPP
    case ENOTSUP:
      return "ENOTSUP";
#endif
#if defined(ENOTTY)
    case ENOTTY:
      return "ENOTTY";
#endif
#if defined(ENXIO)
    case ENXIO:
      return "ENXIO";
#endif
#if defined(EOPNOTSUPP)
    case EOPNOTSUPP:
      return "EOPNOTSUPP";
#endif
#if defined(EOVERFLOW)
    case EOVERFLOW:
      return "EOVERFLOW";
#endif
#if defined(EOWNERDEAD)
    case EOWNERDEAD:
      return "EOWNERDEAD";
#endif
#if defined(EPERM)
    case EPERM:
      return "EPERM";
#endif
#if defined(EPIPE)
    case EPIPE:
      return "EPIPE";
#endif
#if defined(EPROTO)
    case EPROTO:
      return "EPROTO";
#endif
#if defined(EPROTONOSUPPORT)
    case EPROTONOSUPPORT:
      return "EPROTONOSUPPORT";
#endif
#if defined(EPROTOTYPE)
    case EPROTOTYPE:
      return "EPROTOTYPE";
#endif
#if defined(EROFS)
    case EROFS:
      return "EROFS";
#endif
#if defined(ESPIPE)
    case ESPIPE:
      return "ESPIPE";
#endif
#if defined(ESRCH)
    case ESRCH:
      return "ESRCH";
#endif
#if defined(ESTALE)
    case ESTALE:
      return "ESTALE";
#endif
#if defined(ETIME)
    case ETIME:
      return "ETIME";
#endif
#if defined(ETIMEDOUT)
    case ETIMEDOUT:
      return "ETIMEDOUT";
#endif
#if defined(ETXTBSY)
    case ETXTBSY:
      return "ETXTBSY";
#endif
/* May be the same value as EAGAIN. */
#if defined(EWOULDBLOCK) && EWOULDBLOCK != EAGAIN
    case EWOULDBLOCK:
      return "EWOULDBLOCK";
#endif
#if defined(EXDEV)
    case EXDEV:
      return "EXDEV";
#endif
    default:
      return NULL;
    }
  return NULL;
}
