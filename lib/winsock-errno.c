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

#include <errno.h>
#include <windows.h>
#include <winsock2.h>

#ifndef _WIN32
#  error "winsock-errno.h included on a non-windows system."
#endif

/* https://learn.microsoft.com/en-us/windows/win32/winsock/windows-sockets-error-codes-2 */
/* https://learn.microsoft.com/en-us/windows/win32/winsock/error-codes-errno-h-errno-and-wsagetlasterror-2 */

/* Try to translate the value from WSAGetLastError() to a similar value for
   errno. */
/* TODO: More of these can probably be added. If the error number is not
   caught by the switch, ENOSYS is returned. */
int
winsock_errno (void)
{
  int last_error = WSAGetLastError ();

  switch (last_error)
    {
    case WSA_INVALID_HANDLE:
      return EBADF;
    case WSA_NOT_ENOUGH_MEMORY:
      return ENOMEM;
    case WSA_INVALID_PARAMETER:
      return EINVAL;
    case WSA_OPERATION_ABORTED:
      break;
    case WSA_IO_INCOMPLETE:
      break;
    case WSA_IO_PENDING:
      break;
    case WSAEINTR:
      return EINTR;
    case WSAEBADF:
      return EBADF;
    case WSAEACCES:
      return EACCES;
    case WSAEFAULT:
      return EFAULT;
    case WSAEINVAL:
      return EINVAL;
    case WSAEMFILE:
      return EMFILE;
    case WSAEWOULDBLOCK:
      return EWOULDBLOCK;
    case WSAEINPROGRESS:
      return EINPROGRESS;
    case WSAEALREADY:
      return EALREADY;
    case WSAENOTSOCK:
      return ENOTSOCK;
    case WSAEDESTADDRREQ:
      return EDESTADDRREQ;
    case WSAEMSGSIZE:
      return EMSGSIZE;
    case WSAEPROTOTYPE:
      return EPROTOTYPE;
    case WSAENOPROTOOPT:
      return ENOPROTOOPT;
    case WSAEPROTONOSUPPORT:
      return EPROTONOSUPPORT;
    case WSAESOCKTNOSUPPORT:
      break;
    case WSAEOPNOTSUPP:
      return EOPNOTSUPP;
    case WSAEPFNOSUPPORT:
      break;
    case WSAEAFNOSUPPORT:
      return EAFNOSUPPORT;
    case WSAEADDRINUSE:
      return EADDRINUSE;
    case WSAEADDRNOTAVAIL:
      return EADDRNOTAVAIL;
    case WSAENETDOWN:
      return ENETDOWN;
    case WSAENETUNREACH:
      return ENETUNREACH;
    case WSAENETRESET:
      return ENETRESET;
    case WSAECONNABORTED:
      return ECONNABORTED;
    case WSAECONNRESET:
      return ECONNRESET;
    case WSAENOBUFS:
      return ENOBUFS;
    case WSAEISCONN:
      return EISCONN;
    case WSAENOTCONN:
      return ENOTCONN;
    case WSAESHUTDOWN:
      break;
    case WSAETOOMANYREFS:
      break;
    case WSAETIMEDOUT:
      return ETIMEDOUT;
    case WSAECONNREFUSED:
      return ECONNREFUSED;
    case WSAELOOP:
      return ELOOP;
    case WSAENAMETOOLONG:
      return ENAMETOOLONG;
    case WSAEHOSTDOWN:
      break;
    case WSAEHOSTUNREACH:
      return EHOSTUNREACH;
    case WSAENOTEMPTY:
      return ENOTEMPTY;
    case WSAEPROCLIM:
      break;
    case WSAEUSERS:
      break;
    case WSAEDQUOT:
      break;
    case WSAESTALE:
      break;
    case WSAEREMOTE:
      break;
    case WSASYSNOTREADY:
      break;
    case WSAVERNOTSUPPORTED:
      break;
    case WSANOTINITIALISED:
      break;
    case WSAEDISCON:
      break;
    case WSAENOMORE:
      break;
    case WSAECANCELLED:
      break;
    case WSAEINVALIDPROCTABLE:
      break;
    case WSAEINVALIDPROVIDER:
      break;
    case WSAEPROVIDERFAILEDINIT:
      break;
    case WSASYSCALLFAILURE:
      break;
    case WSASERVICE_NOT_FOUND:
      break;
    case WSATYPE_NOT_FOUND:
      break;
    case WSA_E_NO_MORE:
      break;
    case WSA_E_CANCELLED:
      break;
    case WSAEREFUSED:
      break;
    case WSAHOST_NOT_FOUND:
      break;
    case WSATRY_AGAIN:
      break;
    case WSANO_RECOVERY:
      break;
    case WSANO_DATA:
      break;
    case WSA_QOS_RECEIVERS:
      break;
    case WSA_QOS_SENDERS:
      break;
    case WSA_QOS_NO_SENDERS:
      break;
    case WSA_QOS_NO_RECEIVERS:
      break;
    case WSA_QOS_REQUEST_CONFIRMED:
      break;
    case WSA_QOS_ADMISSION_FAILURE:
      break;
    case WSA_QOS_POLICY_FAILURE:
      break;
    case WSA_QOS_BAD_STYLE:
      break;
    case WSA_QOS_BAD_OBJECT:
      break;
    case WSA_QOS_TRAFFIC_CTRL_ERROR:
      break;
    case WSA_QOS_GENERIC_ERROR:
      break;
    case WSA_QOS_ESERVICETYPE:
      break;
    case WSA_QOS_EFLOWSPEC:
      break;
    case WSA_QOS_EPROVSPECBUF:
      break;
    case WSA_QOS_EFILTERSTYLE:
      break;
    case WSA_QOS_EFILTERTYPE:
      break;
    case WSA_QOS_EFILTERCOUNT:
      break;
    case WSA_QOS_EOBJLENGTH:
      break;
    case WSA_QOS_EFLOWCOUNT:
      break;
    case WSA_QOS_EUNKOWNPSOBJ:
      break;
    case WSA_QOS_EPOLICYOBJ:
      break;
    case WSA_QOS_EFLOWDESC:
      break;
    case WSA_QOS_EPSFLOWSPEC:
      break;
    case WSA_QOS_EPSFILTERSPEC:
      break;
    case WSA_QOS_ESDMODEOBJ:
      break;
    case WSA_QOS_ESHAPERATEOBJ:
      break;
    case WSA_QOS_RESERVED_PETYPE:
      break;
    }
  return ENOSYS;
}
